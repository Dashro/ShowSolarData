#include "Mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);	

	QStringList arguments;

	for (int i = 0; i < argc; i++)
	{
		arguments.append(argv[i]);

		arguments[i].remove("-");
	}

	QCoreApplication::setOrganizationName("Fabian Production");
	QCoreApplication::setApplicationName("ShowSolarData");

	CMainWindow w;

	if (arguments.contains("f"))
	{
		w.showFullScreen();
	}
	else
	{
		w.show();
	}

	return a.exec();
}
