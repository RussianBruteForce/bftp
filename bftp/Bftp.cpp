#include "Bftp.h"
#include "ui_Bftp.h"

#include <QDebug>

Bftp::Bftp(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::Bftp)
{
	ui->setupUi(this);

	finishT = new QToolButton(ui->mainToolBar);
	finishT->setText(tr("FINISH"));
	ui->mainToolBar->addWidget(finishT);
	connect(finishT, &QToolButton::clicked,
	        this, &Bftp::count);

	QWidget* spacer = new QWidget(ui->mainToolBar);
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui->mainToolBar->addWidget(spacer);

	testProgress = new QLabel(ui->mainToolBar);
	ui->mainToolBar->addWidget(testProgress);

	prevQ = new QToolButton(ui->mainToolBar);
	prevQ->setText("<-");
	ui->mainToolBar->addWidget(prevQ);
	connect(prevQ, &QToolButton::clicked,
	        this, &Bftp::prev);

	nextQ = new QToolButton(ui->mainToolBar);
	nextQ->setText("->");
	ui->mainToolBar->addWidget(nextQ);
	connect(nextQ, &QToolButton::clicked,
	        this, &Bftp::next);

	ui->centralWidget->setDisabled(true);
	ui->mainToolBar->setDisabled(true);


	connect(ui->actionOpen, &QAction::triggered,
	        this, &Bftp::open);
	connect(ui->actionE_xit, &QAction::triggered,
	        this, &Bftp::close);
}

Bftp::~Bftp()
{
	delete ui;
}

void Bftp::load(QString testName)
{
	_currentQ = 0;
	_test = Test(IOFiles::readTest(testName));
	checkingGrid.clear();
	for (int i = 0; i < _test.questions().size(); i++) {
		QList<QPair<bool, bool> > c;
		for (int j = 0; j < _test.questions()[i].answers().size(); j++) {
			c.append(QPair<bool, bool>(
			                 false,
			                 _test.questions()[i].answers()[j].right()));
		}
		checkingGrid.append(c);
	}

	setQuestion(_currentQ);

	ui->centralWidget->setEnabled(true);
	ui->mainToolBar->setEnabled(true);
}

void Bftp::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Test..."),
	                                                QDir::currentPath() + "/tests",
	                                                tr("Test Files (*.json *.bftp)"));
	if (!fileName.isEmpty()) {
		load(fileName);
	}
}

void Bftp::next()
{
	rememberAnswers();
	if (_currentQ < _test.questions().size() - 1)
		setQuestion(++_currentQ);
}

void Bftp::prev()
{
	rememberAnswers();
	if (_currentQ != 0)
		setQuestion(--_currentQ);
}

void Bftp::count()
{
	//ui->centralWidget->setDisabled(true);

	rememberAnswers();
	_score = 0;
	for (int i = 0; i < checkingGrid.size(); i++) {
		_score++;
		for (int j = 0; j < checkingGrid.at(i).size(); j++) {
			if (checkingGrid.at(i)[j].first != checkingGrid.at(i)[j].second) {
				_score--;
				break;
			}
		}
	}
	qDebug() << "SCORE " << _score;

	resultW = new ResultWidget(_test, _score, this);
	resultW->exec();

	//ui->centralWidget->setEnabled(true);
}

void Bftp::setQuestion(int q)
{
	qDebug() << "sQ";
	_rightCount = 0;
	Question buf = _test.questions().at(q);
	ui->textBrowser->setText(QString(" "));
	ui->textBrowser->setText(buf.text());
	this->clearAnsList();

	for (int i = 0; i < buf.answers().size(); i++) {
		if (buf.answers()[i].right())
			_rightCount++;
	}

	for (int i = 0; i < buf.answers().size(); i++) {
		if (_rightCount == 1)
			ansList.append(new AnswerWidget(buf.answers()[i].text(),
			                                true));
		else
			ansList.append(new AnswerWidget(buf.answers()[i].text(),
			                                false));
		connect(ansList.at(i), &AnswerWidget::radCheck,
		        this, &Bftp::uncheckRad);
		ansList.at(i)->setChecked(checkingGrid[_currentQ][i].first);
		ui->answers->addWidget(ansList.at(i));
	}
	testProgress->setText(QString::number(_currentQ + 1) + QString(QString("/") + QString::number(_test.questions().size())));
}

void Bftp::rememberAnswers()
{
	for (int i = 0; i < _test.questions()[_currentQ].answers().size(); i++) {
		checkingGrid[_currentQ][i].first = ansList.at(i)->isChecked();
	}
}

void Bftp::clearAnsList()
{
	for (int i = 0; i < ansList.size(); i++) {
		ansList.at(i)->deleteLater();
	}
	ansList.clear();
}

void Bftp::uncheckRad()
{
	for (int i = 0; i < ansList.size(); i++) {
		ansList.at(i)->setChecked(false);
	}
}
