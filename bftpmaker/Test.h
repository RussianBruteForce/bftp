#ifndef TEST_H
#define TEST_H

#include <QJsonArray>
#include <QJsonObject>
#include <QList>

#include "Question.h"

class Test
{
public:
	explicit Test(QJsonObject o);
	explicit Test();
	QString name();
	int class_();
	int time();
	QString author();
	QList<Question> questions();
	void removeQuestion(int at);
	bool showMistakes();
	bool showRightAnswers();
	QJsonObject toJson();

	void setName(QString n);
	void setClass(int c);
	void setAuthor(QString a);
	void setTime(int t);
	void addQuestion(Question q);
	void insertQuestion(int pos, Question q);
	void setShowMistakes(bool s);
	void setShowRightAnswers(bool s);
	
private:
	QJsonObject main;
};

#endif // TEST_H
