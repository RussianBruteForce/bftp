#include "Answer.h"

Answer::Answer(QJsonObject o)
{
	main = o;
	t = main.keys().first();
}

Answer::Answer(QString text, bool right)
{
	main.insert(text, right);
	t = text;
}

QString Answer::text()
{
	return t;
}

bool Answer::right()
{
	return main.value(t).toBool();
}

QJsonObject Answer::toJson()
{
	return main;
}

void Answer::setText(QString t_)
{
	bool b = main.take(t).toBool();
	main.insert(t_,b);
}

void Answer::setRight(bool r)
{
	main.insert(t,r);
}
