#include "Test.h"

#include <QDebug>

Test::Test(QJsonObject o)
{
	main = o;
}

Test::Test()
{
}


QString Test::name()
{
	return main.value("name").toString();
}

int Test::class_()
{
	return main.value("class").toDouble();
}

int Test::time()
{
	return main.value("time").toDouble();
}

QString Test::author()
{
	return main.value("author").toString();
}

QList<Question> Test::questions()
{
	QList<Question> ret;
	QJsonArray a = main.value("questions").toArray();
	for (int i = 0; i < a.size(); i++) {
		Question b(a.at(i).toObject());
		ret.append(b);
	}
	return ret;
}

void Test::removeQuestion(int at)
{
	QJsonArray a = main.value("questions").toArray();
	a.removeAt(at);
	main.insert("questions", a);
}

bool Test::showMistakes()
{
	return main.value("showMistakes").toBool();
}

bool Test::showRightAnswers()
{
	return main.value("showRight").toBool();
}

QJsonObject Test::toJson()
{
	return main;
}

void Test::setName(QString n)
{
	main.insert("name", n);
}


void Test::addQuestion(Question q)
{
	QJsonArray a = main.value("questions").toArray();
	a.append(q.toJson());
	main.insert("questions", a);
}

void Test::insertQuestion(int pos, Question q)
{
	QJsonArray a = main.value("questions").toArray();
	a.insert(pos, q.toJson());
	main.insert("questions", a);
}

void Test::setShowMistakes(bool s)
{
	main.insert("showMistakes", s);
}

void Test::setShowRightAnswers(bool s)
{
	main.insert("showRight", s);
}


void Test::setAuthor(QString a)
{
	main.insert("author", a);
}

void Test::setTime(int t)
{
	main.insert("time", t);
}


void Test::setClass(int c)
{
	main.insert("class", c);
}
