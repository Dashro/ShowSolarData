#include "Mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);	
	QCoreApplication::setOrganizationName("Fabian Production");
	QCoreApplication::setApplicationName("ShowSolarData");
	CMainWindow w;
	w.show();
	return a.exec();
}
