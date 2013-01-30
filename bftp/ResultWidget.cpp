#include "ResultWidget.h"
#include "ui_ResultWidget.h"

#include <QDebug>

ResultWidget::ResultWidget(Test &t, int result, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ResultWidget)
{
	ui->setupUi(this);
	int p = (double)result/t.questions().size()*100;

	ui->percent->setValue(result);
	ui->percent->setMaximum(t.questions().size());
	ui->right->setFontPointSize(48);
	qDebug() << "ppp " << p;
	if (p < 50)
		ui->right->setTextColor(Qt::red);
	else if (p < 75)
		ui->right->setTextColor(Qt::yellow);
	else if (p < 90)
		ui->right->setTextColor(Qt::green);
	else
		ui->right->setTextColor(Qt::blue);

	ui->right->setText(QString::number(result) + QString(tr(" of ") + QString::number(t.questions().size())));
	ui->right->textCursor().setPosition(1);
	ui->right->setAlignment(Qt::AlignCenter);
}

ResultWidget::~ResultWidget()
{
	delete ui;
}

void ResultWidget::on_save_clicked()
{

}

void ResultWidget::on_send_clicked()
{

}

void ResultWidget::on_sm_clicked()
{
	emit showMistakes();
	this->accept();
}
