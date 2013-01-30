#ifndef ANSWER_H
#define ANSWER_H

#include <QJsonObject>
#include <QStringList>

class Answer
{
public:
	explicit Answer(QJsonObject o);
	explicit Answer(QString text, bool right);
	QString text();
	bool right();
	QJsonObject toJson();
	void setText(QString t_);
	void setRight(bool r);
	
private:
	QString t;
	QJsonObject main;
};

#endif // ANSWER_H
