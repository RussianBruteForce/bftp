#ifndef IOFILES_H
#define IOFILES_H

#define TEST_DIR "tests/"
#define FILENAME_EXTENSION ".json"

#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDir>

#include "Test.h"

class IOFiles : public QObject
{
	Q_OBJECT
public:
	explicit IOFiles(QObject *parent = 0);
	static QJsonObject readTest(QString fileName);
	static bool writeTest(QString fileName, QJsonObject test);
	
signals:
	
public slots:
	
};

#endif // IOFILES_H
