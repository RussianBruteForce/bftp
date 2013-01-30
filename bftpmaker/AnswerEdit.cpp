#include "AnswerEdit.h"
#include "ui_AnswerEdit.h"

AnswerEdit::AnswerEdit(Answer a, int __id, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AnswerEdit)
{
	ui->setupUi(this);
	setAnswer(a, __id);
}

AnswerEdit::~AnswerEdit()
{
	delete ui;
}

void AnswerEdit::setAnswer(Answer a, int __id)
{
	ui->answer->setText(a.text());
	ui->right->setChecked(a.right());
	_id = __id;
}

Answer AnswerEdit::answer()
{
	return Answer(ui->answer->text(), ui->right->isChecked());
}

int AnswerEdit::id_()
{
	return _id;
}

void AnswerEdit::on_remove_clicked()
{
	emit remove(_id);
}
