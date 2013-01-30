#ifndef ANSWERWIDGET_H
#define ANSWERWIDGET_H

#include <QWidget>

namespace Ui {
class AnswerWidget;
}

class AnswerWidget : public QWidget
{
	Q_OBJECT
	
public:
	explicit AnswerWidget(QString t, bool rad, QWidget *parent = 0);
	~AnswerWidget();
	bool isChecked();

public slots:
	void setChecked(bool c);
	
private:
	Ui::AnswerWidget *ui;
	bool _rad;

private slots:
	void radChecked();

signals:
	void radCheck();
};

#endif // ANSWERWIDGET_H
