#include "BftpMaker.h"
#include "ui_BftpMaker.h"

BftpMaker::BftpMaker(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::BftpMaker)
{
	ui->setupUi(this);
	textEdit = new TextEditor(this);
	textEdit->setText(tr("Load test"));
	ui->editor->addWidget(textEdit);

	delQ = new QToolButton(ui->mainToolBar);
	delQ->setText("DQ");
	ui->mainToolBar->addWidget(delQ);
	connect(delQ, &QToolButton::clicked,
	        this, &BftpMaker::del);

	addQ = new QToolButton(ui->mainToolBar);
	addQ->setText("AQ");
	ui->mainToolBar->addWidget(addQ);
	connect(addQ, &QToolButton::clicked,
	        this, &BftpMaker::add);

	ui->mainToolBar->addSeparator();

	addA = new QToolButton(ui->mainToolBar);
	addA->setText("AA");
	ui->mainToolBar->addWidget(addA);
	connect(addA, &QToolButton::clicked,
	        this, &BftpMaker::addAnswer);

	QWidget* spacer = new QWidget(ui->mainToolBar);
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui->mainToolBar->addWidget(spacer);

	testProgress = new QLabel(ui->mainToolBar);
	ui->mainToolBar->addWidget(testProgress);

	prevQ = new QToolButton(ui->mainToolBar);
	prevQ->setText("<-");
	ui->mainToolBar->addWidget(prevQ);
	connect(prevQ, &QToolButton::clicked,
	        this, &BftpMaker::prev);

	nextQ = new QToolButton(ui->mainToolBar);
	nextQ->setText("->");
	ui->mainToolBar->addWidget(nextQ);
	connect(nextQ, &QToolButton::clicked,
	        this, &BftpMaker::next);

	ui->centralWidget->setDisabled(true);
	ui->mainToolBar->setDisabled(true);

	ui->timeEdit->setDisplayFormat("hh.mm");

	connect(ui->actionOpen, &QAction::triggered,
	        this, &BftpMaker::open);
	connect(ui->actionSave, &QAction::triggered,
	        this, &BftpMaker::save);
	connect(ui->actionE_xit, &QAction::triggered,
	        this, &BftpMaker::close);
}

BftpMaker::~BftpMaker()
{
	clearAnsList();
	delete ui;
}

void BftpMaker::load(QString testName)
{
	_currentQ = 0;
	_test = Test(IOFiles::readTest(testName));
	setQuestion(_currentQ);
	ui->nameEdit->setText(_test.name());
	ui->authorEdit->setText(_test.author());
	ui->classSpinBox->setValue(_test.class_());
	ui->timeEdit->setTime(QTime(_test.time()/60,
	                            _test.time()%60));
	ui->mistCB->setChecked(_test.showMistakes());
	ui->rightCB->setChecked(_test.showRightAnswers());

	ui->centralWidget->setEnabled(true);
	ui->mainToolBar->setEnabled(true);


	testProgress->setText(tr("<b>Loaded!</b> ") + testProgress->text());
}

void BftpMaker::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Test..."),
	                                                QDir::currentPath() + "/tests",
	                                                tr("Test Files (*.json *.bftp)"));
	if (!fileName.isEmpty()) {
		load(fileName);
	}
}

void BftpMaker::save()
{
	_test.setName(ui->nameEdit->text());
	_test.setAuthor(ui->authorEdit->text());
	_test.setClass(ui->classSpinBox->value());
	_test.setTime(ui->timeEdit->time().minute() +
	              ui->timeEdit->time().hour()*60
	              );
	_test.setShowMistakes(ui->mistCB->isChecked());
	_test.setShowRightAnswers(ui->rightCB->isChecked());
	QString fileName;
	fileName += QString::number(_test.class_());
	fileName += ' ';
	fileName += _test.name();
	IOFiles::writeTest(fileName, _test.toJson());

	setQuestion(_currentQ);
	testProgress->setText(tr("<b>Saved!</b> ") + testProgress->text());
}

void BftpMaker::setQuestion(int q)
{
	Question buf = _test.questions().at(q);
	textEdit->setText(QString(" "));
	textEdit->setText(buf.text());
	this->clearAnsList();
	for (int i = 0; i < buf.answers().size(); i++) {
		ansList.append(new AnswerEdit(buf.answers().at(i), i));
		ui->answers->addWidget(ansList.at(i));
		connect(ansList.at(i), &AnswerEdit::remove,
		        this, &BftpMaker::removeAnswer);
	}
	testProgress->setText(QString::number(_currentQ + 1) + QString(QString("/") + QString::number(_test.questions().size())));
}

void BftpMaker::clearAnsList()
{
	for (int i = 0; i < ansList.size(); i++) {
		ansList.at(i)->deleteLater();
	}
	ansList.clear();
}

void BftpMaker::removeAnswer(int _id)
{
	for (int i = 0; i < ansList.size(); i++) {
		if (ansList.at(i)->id_() == _id) {
			ansList.takeAt(i)->deleteLater();
			return;
		}
	}
}

void BftpMaker::addAnswer()
{
	qsrand(QTime::currentTime().msec());
	ansList.append(new AnswerEdit(Answer(tr("empty"), false), ansList.size() + qrand()));
	ui->answers->addWidget(ansList.last());
	connect(ansList.last(), &AnswerEdit::remove,
	        this, &BftpMaker::removeAnswer);
}

void BftpMaker::next()
{
	_test.removeQuestion(_currentQ);
	Question q;
	q.setText(textEdit->text());
	for (int i = 0; i < ansList.size(); i++) {
		q.addAnswer(ansList[i]->answer());
	}
	_test.insertQuestion(_currentQ, q);

	if (_currentQ < _test.questions().size() - 1)
		setQuestion(++_currentQ);
}

void BftpMaker::prev()
{
	_test.removeQuestion(_currentQ);
	Question q;
	q.setText(textEdit->text());
	for (int i = 0; i < ansList.size(); i++) {
		q.addAnswer(ansList[i]->answer());
	}
	_test.insertQuestion(_currentQ, q);

	if (_currentQ != 0)
		setQuestion(--_currentQ);
}

void BftpMaker::del()
{
	_test.removeQuestion(_currentQ);
	if (_currentQ != 0)
		--_currentQ;
	setQuestion(_currentQ);
}

void BftpMaker::add()
{
	Question q;
	q.setText(tr("empty"));
	q.addAnswer(Answer(tr("empty"), false));
	q.addAnswer(Answer(tr("empty"), false));
	q.addAnswer(Answer(tr("empty"), false));
	_test.insertQuestion(++_currentQ, q);
	setQuestion(_currentQ);
}
