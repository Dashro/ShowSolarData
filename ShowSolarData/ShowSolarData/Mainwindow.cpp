#include "Mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//======================================================================================================================================
	ui.setupUi(this);
	m_Data = new CData;
	m_WebSocketClient = new CWebSocketClient(QUrl(QStringLiteral("ws://localhost:1234")), m_Data);
	//======================================================================================================================================
	QLocale german(QLocale::German);
	//======================================================================================================================================
	//Actions
	QAction *action_Close = new QAction(QIcon("Resources/cancel.png"), "Close", this);
	QAction *action_FullScreen = new QAction(QIcon("Resources/slideshow_full_screen.png"), "Fullsreen", this);
	QAction *action_HomePage = new QAction(QIcon("Resources/home_page.png"), "Home Page", this);
	QAction *action_Plotter = new QAction(QIcon("Resources/chart_curve.png"), "Plotter", this);
	QAction *action_FolderChoose = new QAction(QIcon("Resources/folder_explorer.png"), "Folder Choose", this);
	//QAction *action_HomePage = new QAction(QIcon("Resources/home_page.png"), "Home Page", this);
	//======================================================================================================================================
	//Toolbar
	ui.toolBar->addAction(action_Close);
	ui.toolBar->addAction(action_FullScreen);
	ui.toolBar->addSeparator();
	ui.toolBar->setIconSize(QSize(20, 20));
	ui.toolBar->addAction(action_HomePage);
	ui.toolBar->addAction(action_Plotter);
	ui.toolBar->addAction(action_FolderChoose);
	
	//======================================================================================================================================
	//StartPage
	m_StartPage = new CStartPage(this);
	ui.stackedWidget->addWidget(m_StartPage->getView());
	//======================================================================================================================================
	//Plotter
	m_Plotter = new CPlotter(this);
	ui.stackedWidget->addWidget(m_Plotter->getView());
	//======================================================================================================================================
	//FolderChoose
	m_FolderChoose = new CFolderChoose(this);
	ui.stackedWidget->addWidget(m_FolderChoose->getView());
	//======================================================================================================================================
	//======================================================================================================================================
	connect(action_Close,			SIGNAL(triggered()), this, SLOT(close()));
	connect(action_FullScreen,		SIGNAL(triggered()), this, SLOT(showFullScreen()));

	connect(action_HomePage,		SIGNAL(triggered()), this, SLOT(showStartpage()));
	connect(action_Plotter,			SIGNAL(triggered()), this, SLOT(showPlotter()));
	connect(action_FolderChoose,	SIGNAL(triggered()), this, SLOT(showFolderChoose()));


	connect(m_FolderChoose,			SIGNAL(NewSolarDataFile(QString)), this, SLOT(newSolarDataFile(QString)));
	connect(m_FolderChoose,			SIGNAL(NewConsumptionDataFile(QString)), this, SLOT(newConsumptionDataFile(QString)));

	connect(m_Data,					SIGNAL(NewDataRecieved()), this, SLOT(newData()));


	//======================================================================================================================================
	//======================================================================================================================================
	resize(480, 320);

	ui.stackedWidget->setCurrentIndex(0);
}

CMainWindow::~CMainWindow()
{

}

void CMainWindow::newData()
{
	if (m_Data->timeStamps().size() >= 4)
	{
		QList<double> test = m_Data->production();
		if (!test.isEmpty())
		{
			m_Plotter->plottDataListGraph(m_Data->production(), m_Data->timeStamps(), "Produktion /W", QColor(Qt::darkGreen));
			m_Plotter->plottDataListGraph(m_Data->consumption(), m_Data->timeStamps(), "Verbrauch /W", QColor(Qt::darkRed));
			m_StartPage->showData(m_Data->production(), m_Data->consumption(), m_Data->surplus(), m_Data->timeStamps());
		}
	}
}


//void CMainWindow::newSolarDataFile(QString newFile)
//{
//
//	if (!m_SolarData->openDatafile(newFile))
//	{
//		QMessageBox msgBox;
//		msgBox.setText("Please select the Solar-Data-Folder");
//		msgBox.exec();
//		ui.stackedWidget->setCurrentIndex(ui.stackedWidget->indexOf(m_FolderChoose->getView()));
//	}
//	//======================================================================================================================================
//	else
//	{
//		SolarDataHeaderList = m_SolarData->getheaderList();
//		SolarDataUnitList = m_SolarData->getunitList();
//		SolarDataTimeStamps = m_SolarData->getTimeStamps();
//	}
//}
//void CMainWindow::newConsumptionDataFile(QString newFile)
//{
//	if (!m_ConsumptionData->openDatafile(newFile))
//	{
//		QMessageBox msgBox;
//		msgBox.setText("Please select the Consumption-Data-Folder");
//		msgBox.exec();
//		ui.stackedWidget->setCurrentIndex(ui.stackedWidget->indexOf(m_FolderChoose->getView()));
//	}
//	else
//	{
//		ConsumptionDataHeaderList	= m_ConsumptionData->getheaderList();
//		ConsumptionDataUnitList		= m_ConsumptionData->getunitList();
//		ConsumptionDataTimeStamps	= m_ConsumptionData->getTimeStamps();
//	}
//}

void CMainWindow::showStartpage()
{
	ui.stackedWidget->setCurrentIndex(0);
}
void CMainWindow::showPlotter()
{
	ui.stackedWidget->setCurrentIndex(1);
}
void CMainWindow::showFolderChoose()
{
	ui.stackedWidget->setCurrentIndex(2);
}


//int CMainWindow::getRandomNo(int low, int high)
//{
//	return qrand() % ((high + 1) - low) + low;
//}