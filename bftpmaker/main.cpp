#include "BftpMaker.h"
#include <QApplication>

#include "IOFiles.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	BftpMaker w;
	w.show();

	return a.exec();
}
