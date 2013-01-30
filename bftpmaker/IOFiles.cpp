#include "IOFiles.h"

#include <QDebug>

IOFiles::IOFiles(QObject *parent) :
        QObject(parent)
{
}

QJsonObject IOFiles::readTest(QString fileName)
{
	QFile f;
	f.setFileName(fileName);
	f.open(QIODevice::ReadOnly);
	QJsonDocument d = QJsonDocument::fromJson(f.readAll());
	f.close();
	return d.object();
}

bool IOFiles::writeTest(QString fileName, QJsonObject test)
{
	QFile f;
	f.setFileName(QString(TEST_DIR + fileName) + FILENAME_EXTENSION);
	if (!(f.open(QIODevice::WriteOnly)))
		return false;
	if (-1 == f.write(QJsonDocument(test).toJson()))
		return false;
	f.close();
	return true;
}
