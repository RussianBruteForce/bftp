#include "AnswerWidget.h"
#include "ui_AnswerWidget.h"

#include <QDebug>

AnswerWidget::AnswerWidget(QString t, bool rad, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AnswerWidget)
{
	ui->setupUi(this);

	_rad  = rad;
	if (rad) {
		ui->aC->setVisible(false);
		ui->aR->setText(t);
		connect(ui->aR, &QRadioButton::clicked,
		        this, &AnswerWidget::radChecked);
	}
	else {
		ui->aR->setVisible(false);
		ui->aC->setText(t);
	}
}

AnswerWidget::~AnswerWidget()
{
	delete ui;
}

bool AnswerWidget::isChecked()
{

	if (ui->aC->isChecked())
		return true;
	else if (ui->aR->isChecked())
		return true;
	else return false;
}

void AnswerWidget::setChecked(bool c)
{
	if (_rad)
		ui->aR->setChecked(c);
	else
		ui->aC->setChecked(c);
}

void AnswerWidget::radChecked()
{
	emit radCheck();
	ui->aR->setChecked(true);
}
