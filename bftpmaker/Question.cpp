#include "Question.h"

Question::Question(QJsonObject o)
{
	main = o;
}

Question::Question()
{
}

QString Question::text()
{
	return main.value("text").toString();
}

QList<Answer> Question::answers()
{
	QJsonArray a = main.value("answers").toArray();
	QList<Answer> ret;
	for(int i = 0; i < a.size(); i++) {
		Answer b(a.at(i).toObject());
		ret.append(b);
	}
	return ret;
}


void Question::setText(QString t)
{
	main.insert("text", t);
}

void Question::addAnswer(Answer a)
{
	QJsonArray b = main.value("answers").toArray();
	b.append(a.toJson());
	main.insert("answers", b);
}


QJsonObject Question::toJson()
{
	return main;
}


void Question::removeAnswer(int at)
{
	main.value("answers").toArray().removeAt(at);
}
