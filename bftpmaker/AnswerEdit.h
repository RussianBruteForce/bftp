#ifndef ANSWEREDIT_H
#define ANSWEREDIT_H

#include <QWidget>

#include "Answer.h"

namespace Ui {
class AnswerEdit;
}

class AnswerEdit : public QWidget
{
	Q_OBJECT
	
public:
	explicit AnswerEdit(Answer a, int __id, QWidget *parent = 0);
	~AnswerEdit();
	void setAnswer(Answer a, int __id);
	Answer answer();
	int id_();
	
private slots:
	void on_remove_clicked();

private:
	Ui::AnswerEdit *ui;
	int _id;

signals:
	void remove(int __id);
};

#endif // ANSWEREDIT_H
