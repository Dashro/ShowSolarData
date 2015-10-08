#include "Mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//======================================================================================================================================
	ui.setupUi(this);
	m_SolarData = new CSolarData;
	m_ConsumptionData = new CConsumptionData;
	//======================================================================================================================================
	QLocale german(QLocale::German);
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
	//======================================================================================================================================
	connect(ui.action_nextPage, SIGNAL(triggered()), this, SLOT(nextPage()));

	connect(m_FolderChoose, SIGNAL(NewSolarDataFile(QString)), this, SLOT(newSolarDataFile(QString)));
	connect(m_FolderChoose, SIGNAL(NewConsumptionDataFile(QString)), this, SLOT(newConsumptionDataFile(QString)));
	//======================================================================================================================================
	m_SolarData->openDatafile(m_FolderChoose->getSolarDataFile());
	newSolarDataFile(m_FolderChoose->getSolarDataFile());
	m_ConsumptionData->openDatafile(m_FolderChoose->getConsumptionDataFile());
	newConsumptionDataFile(m_FolderChoose->getConsumptionDataFile());
	//======================================================================================================================================
	resize(480, 320);

	ui.stackedWidget->setCurrentIndex(2);

	m_Plotter->plottDataListGraph(m_SolarData->getCollum(SolarDataHeaderList.indexOf("Pac1")), SolarDataTimeStamps);
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

void CMainWindow::newSolarDataFile(QString newFile)
{

	if (!m_SolarData->openDatafile(newFile))
	{
		QMessageBox msgBox;
		msgBox.setText("Please select the Solar-Data-Folder");
		msgBox.exec();
		ui.stackedWidget->setCurrentIndex(ui.stackedWidget->indexOf(m_FolderChoose->getView()));
	}
	//======================================================================================================================================
	else
	{
		SolarDataHeaderList = m_SolarData->getheaderList();
		SolarDataMatrix = m_SolarData->getdataMatrix();
		SolarDataUnitList = m_SolarData->getunitList();
		SolarDataTimeStamps = m_SolarData->getTimeStamps();
	}
}


void CMainWindow::newConsumptionDataFile(QString newFile)
{
	if (!m_ConsumptionData->openDatafile(newFile))
	{
		QMessageBox msgBox;
		msgBox.setText("Please select the Consumption-Data-Folder");
		msgBox.exec();
		ui.stackedWidget->setCurrentIndex(ui.stackedWidget->indexOf(m_FolderChoose->getView()));
	}
	else
	{
		ConsumptionDataHeaderList	= m_ConsumptionData->getheaderList();
		ConsumptionDataMatrix		= m_ConsumptionData->getdataMatrix();
		ConsumptionDataUnitList		= m_ConsumptionData->getunitList();
		ConsumptionDataTimeStamps	= m_ConsumptionData->getTimeStamps();
	}
}


int CMainWindow::getRandomNo(int low, int high)
{
	return qrand() % ((high + 1) - low) + low;
}