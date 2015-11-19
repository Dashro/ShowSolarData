#include "Mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);	

	QCoreApplication::setOrganizationName("Fabian_Production");
	QCoreApplication::setApplicationName("ShowSolarData");

	CMainWindow w(argc, argv);
	w.show();
	return a.exec();
}
