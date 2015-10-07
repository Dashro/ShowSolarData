#include "Mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//======================================================================================================================================
	ui.setupUi(this);
	m_SolarData = new CSolarData;
	//======================================================================================================================================
	QLocale german(QLocale::German);
	//======================================================================================================================================
    if (!m_SolarData->openDatafile("C:/Users/Fabian/Documents/GitHub/ShowSolarData/ShowSolarData/ShowSolarData/MyPlant-Spot-20150829.csv"))
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("The Programm will exit now");
		msgBox.exec();
        exit(1);
	}
	//======================================================================================================================================
	headerList = m_SolarData->getheaderList();
	dataMatrix = m_SolarData->getdataMatrix();
	unitList = m_SolarData->getunitList();
	timeStamps = m_SolarData->getTimeStamps();
	//======================================================================================================================================
	connect(ui.action_nextPage, SIGNAL(triggered()), this, SLOT(nextPage()));
	//======================================================================================================================================
	//for (int i = 5; i < headerList.size(); i++)
	//{
	//	QAction *tempAction = new QAction(QString("%1").arg(headerList.at(i)), this);
	//	ui.menuAnsicht_Alle->addAction(tempAction);
	//	tempAction->setData(i);
	//	connect(tempAction, SIGNAL(triggered(bool)), this, SLOT(ansichtActionTriggered(bool)));
	//}
	//======================================================================================================================================
	//FolderChoose
	m_FolderChoose = new CFolderChoose(this);
	ui.stackedWidget->addWidget(m_FolderChoose->getView());
	//======================================================================================================================================
	//StartPage
	m_StartPage = new CStartPage(this);
	ui.stackedWidget->addWidget(m_StartPage->getView());
	//======================================================================================================================================
	//Plotter
	m_Plotter = new CPlotter(this);
	ui.stackedWidget->addWidget(m_Plotter->getView());
	//======================================================================================================================================

	resize(480, 320);


}

CMainWindow::~CMainWindow()
{

}

void CMainWindow::ansichtActionTriggered(bool)
{
 //   QAction *emitter = static_cast<QAction*>(sender());
	//QString test = emitter->text();

	//plotDataList(test);
}

void CMainWindow::nextPage()
{

	if (ui.stackedWidget->currentIndex() < ui.stackedWidget->count() - 1)
	{
		ui.stackedWidget->setCurrentIndex(ui.stackedWidget->currentIndex() + 1);
	}
	else
	{
		ui.stackedWidget->setCurrentIndex(0);
	}
}

double CMainWindow::toTime_t(QString TimeStamp)
{
	QStringList buffer = TimeStamp.split(' ');

	QStringList buffer_Date = buffer.at(0).split('/');
	QStringList buffer_Time = buffer.at(1).split(':');

	QDateTime dateTime;

	//dateTime.addYears(buffer_Date.at(2).toInt());
	//dateTime.addMonths(buffer_Date.at(1).toInt());
	//dateTime.addDays(buffer_Date.at(0).toInt());

	dateTime.setDate(QDate(buffer_Date.at(2).toInt(), buffer_Date.at(1).toInt(), buffer_Date.at(0).toInt()));
	dateTime.setTime(QTime(buffer_Time.at(0).toInt(), buffer_Time.at(1).toInt(), buffer_Time.at(2).toInt()));

	return dateTime.toTime_t();
}

int CMainWindow::getRandomNo(int low, int high)
{
	return qrand() % ((high + 1) - low) + low;
}