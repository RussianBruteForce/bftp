#ifndef MISTAKESANDRIGHTANSWERSDIALOG_H
#define MISTAKESANDRIGHTANSWERSDIALOG_H

#include <QDialog>

namespace Ui {
class MistakesAndRightAnswersDialog;
}

class MistakesAndRightAnswersDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit MistakesAndRightAnswersDialog(QWidget *parent = 0);
	~MistakesAndRightAnswersDialog();
	
private:
	Ui::MistakesAndRightAnswersDialog *ui;
};

#endif // MISTAKESANDRIGHTANSWERSDIALOG_H
