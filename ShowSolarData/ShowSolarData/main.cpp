#include "Mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);	
	CMainWindow w;
	w.show();
	QCoreApplication::setOrganizationName("Fabian Production");
	QCoreApplication::setApplicationName("ShowSolarData");

	return a.exec();
}
