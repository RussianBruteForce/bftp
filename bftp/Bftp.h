#ifndef BFTP_H
#define BFTP_H

#include <QMainWindow>
#include <QFileDialog>
#include <QToolButton>
#include <QLabel>

#include "AnswerWidget.h"
#include "ResultWidget.h"
#include "MistakesAndRightAnswersDialog.h"
#include "../bftpmaker/IOFiles.h"
#include "../bftpmaker/Answer.h"
#include "../bftpmaker/Question.h"
#include "../bftpmaker/Test.h"

namespace Ui {
class Bftp;
}

class Bftp : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit Bftp(QWidget *parent = 0);
	~Bftp();

public slots:
	void load(QString testName);
	void open();
	void next();
	void prev();
	void count();
	
private:
	Ui::Bftp *ui;
	ResultWidget *resultW;
	MistakesAndRightAnswersDialog *mAndRD;
	Test _test;
	QToolButton *nextQ, *prevQ, *finishT;
	QLabel *testProgress;
	QList<AnswerWidget*> ansList;
	QList<QList<QPair<bool, bool> > > checkingGrid;
	int _rightCount;
	int _score;

	int _currentQ;

	void setQuestion(int q);
	void rememberAnswers();
	void clearAnsList();
	void uncheckRad();

private slots:
	void showMistakes();

};

#endif // BFTP_H
