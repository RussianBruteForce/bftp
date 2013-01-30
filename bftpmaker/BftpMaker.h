#ifndef BFTPMAKER_H
#define BFTPMAKER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QToolButton>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QLabel>
#include <QList>
#include <QTime>
#include <QTimer>

#include "IOFiles.h"
#include "AnswerEdit.h"
#include "TextEditor.h"

namespace Ui {
class BftpMaker;
}

class BftpMaker : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit BftpMaker(QWidget *parent = 0);
	~BftpMaker();
	void load(QString testName);
	
private:
	Ui::BftpMaker *ui;
	TextEditor *textEdit;
	QToolButton *nextQ, *prevQ, *delQ, *addQ, *addA;
	QLabel *testProgress;
	Test _test;
	QList<AnswerEdit*> ansList;

	int _currentQ;

	void setQuestion(int q);
	void clearAnsList();

private slots:
	void open();
	void save();
	void removeAnswer(int _id);
	void addAnswer();
	void next();
	void prev();
	void del();
	void add();
};

#endif // BFTPMAKER_H
