#include "MistakesAndRightAnswersDialog.h"
#include "ui_MistakesAndRightAnswersDialog.h"

MistakesAndRightAnswersDialog::MistakesAndRightAnswersDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MistakesAndRightAnswersDialog)
{
	ui->setupUi(this);
}

MistakesAndRightAnswersDialog::~MistakesAndRightAnswersDialog()
{
	delete ui;
}
