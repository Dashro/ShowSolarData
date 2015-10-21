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

	arguments.append("ip");
	arguments.append("127.0.0.1:80");

	QCoreApplication::setOrganizationName("Fabian Production");
	QCoreApplication::setApplicationName("ShowSolarData");

	CMainWindow w;

	if (arguments.contains("f"))
		w.showFullScreen();
	else
		w.show();

	//if(arguments.contains("ip"))
	//{
	//	w.onNewURL(arguments.at(arguments.indexOf("ip") + 1));
	//	QSettings settings;
	//	settings.setValue("IPAdress", arguments.at(arguments.indexOf("ip") + 1).split(":").first());
	//	settings.setValue("Port", arguments.at(arguments.indexOf("ip") + 1).split(":").last());
	//}

	return a.exec();
}
