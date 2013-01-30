#include "MistakesAndRightAnswersDialog.h"
#include "ui_MistakesAndRightAnswersDialog.h"

#include <QDebug>

MistakesAndRightAnswersDialog::MistakesAndRightAnswersDialog(QList<QList<QPair<bool, bool> > > _checkingGrid,
                                                             QList<Question> _ans,
		                                             bool showRight):
        ui(new Ui::MistakesAndRightAnswersDialog)
{
	ui->setupUi(this);
	if (showRight) ui->showRightButton->setEnabled(true);
	else ui->showRightButton->setDisabled(true);
	ans = _ans;
	checkingGrid = _checkingGrid;
	_r = false;

	update();
}

MistakesAndRightAnswersDialog::~MistakesAndRightAnswersDialog()
{
	delete ui;
}

void MistakesAndRightAnswersDialog::update()
{
	text.clear();
	qCounter = 0;
	for (int i = 0; i < checkingGrid.size(); i++) {
		addQuestion(ans[i].text());
		for (int j = 0; j < checkingGrid.at(i).size(); j++) {
			if (checkingGrid.at(i)[j].first && ans[i].answers()[j].right())
				addRightAnswer(tr("(choosen) ") + ans[i].answers()[j].text());
			else if (_r && ans[i].answers()[j].right())
				addRightAnswer(ans[i].answers()[j].text());
			else if(checkingGrid.at(i)[j].first)
				addWrongAnswer(tr("(choosen) ") + ans[i].answers()[j].text());
		}
	}
	ui->textBrowser->setText(text);
}

void MistakesAndRightAnswersDialog::addQuestion(QString str)
{
	text += "<h3>";
	text += QString(QString::number(++qCounter) + ") ");
	ui->textBrowser->setText(str);
	text += ui->textBrowser->toPlainText();
	text += "</h3>";
}

void MistakesAndRightAnswersDialog::addRightAnswer(QString str)
{
	text += "&emsp;";
	text += "<font style=\"color:#00FF00\">";
	text += str;
	text += "</font>";
	text += "<br>";
}

void MistakesAndRightAnswersDialog::addWrongAnswer(QString str)
{
	text += "&emsp;";
	text += "<font style=\"color:#FF0000\">";
	text += str;
	text += "</font>";
	text += "<br>";
}

void MistakesAndRightAnswersDialog::on_showRightButton_clicked()
{
	if (!_r) _r = true;
	else _r = false;
	update();
}
