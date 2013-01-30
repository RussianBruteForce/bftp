#ifndef MISTAKESANDRIGHTANSWERSDIALOG_H
#define MISTAKESANDRIGHTANSWERSDIALOG_H

#include <QDialog>
#include "../bftpmaker/Question.h"

namespace Ui {
class MistakesAndRightAnswersDialog;
}

class MistakesAndRightAnswersDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit MistakesAndRightAnswersDialog(QList<QList<QPair<bool, bool> > > _checkingGrid,
	                                       QList<Question> _ans,
	                                       bool showRight);
	~MistakesAndRightAnswersDialog();
	
private slots:
	void on_showRightButton_clicked();

private:
	Ui::MistakesAndRightAnswersDialog *ui;
	QList<QList<QPair<bool, bool> > > checkingGrid;
	QList<Question> ans;
	bool _r;
	int qCounter;
	QString text;
	void update();
	void addQuestion(QString str);
	void addRightAnswer(QString str);
	void addWrongAnswer(QString str);
};

#endif // MISTAKESANDRIGHTANSWERSDIALOG_H
