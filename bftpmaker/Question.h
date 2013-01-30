#ifndef QUESTION_H
#define QUESTION_H

#include <QJsonArray>
#include <QJsonObject>
#include <QList>

#include "Answer.h"

class Question
{
public:
	explicit Question(QJsonObject o);
	explicit Question();
	QString text();
	QList<Answer> answers();
	void removeAnswer(int at);
	QJsonObject toJson();
	void setText(QString t);
	void addAnswer(Answer a);
	
private:
	QJsonObject main;
};

#endif // QUESTION_H
