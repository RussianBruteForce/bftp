#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QDialog>

#include <../bftpmaker/Test.h>

namespace Ui {
class ResultWidget;
}

class ResultWidget : public QDialog
{
	Q_OBJECT
	
public:
	explicit ResultWidget(Test &t , int result, QWidget *parent = 0);
	~ResultWidget();
	
private slots:
	void on_save_clicked();

	void on_send_clicked();

	void on_sm_clicked();

private:
	Ui::ResultWidget *ui;

signals:
	void showMistakes();
};

#endif // RESULTWIDGET_H
