#include "Mainwindow.h"


CMainWindow::CMainWindow(int argc, char *argv[], QWidget *parent)
	: QMainWindow(parent)
{
	//======================================================================================================================================
	qSetMessagePattern("[%{time h:mm:ss} %{if-debug}D%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] %{file}: - %{message}");
	QStringList arguments;

	for (int i = 0; i < argc; i++)
	{
		arguments.append(argv[i]);

		arguments[i].remove("-");
	}
	//======================================================================================================================================
	ui.setupUi(this);
	QSettings settings;
	m_EventFilter = CEventFilter::Signleton();
	m_Data = new CData;
	//======================================================================================================================================
	if (arguments.contains("ip"))
	{
		m_WebSocketClient = new CWebSocketClient(QUrl(QString("ws://%1").arg((arguments.at(arguments.indexOf("ip") + 1)))), m_Data);		
		settings.setValue("IPAdress", arguments.at(arguments.indexOf("ip") + 1).split(":").first());
		settings.setValue("Port", arguments.at(arguments.indexOf("ip") + 1).split(":").last());
	}
	else
		m_WebSocketClient = new CWebSocketClient(QUrl(QString("ws://%1:%2").arg(settings.value("IPAdress").toString()).arg(settings.value("Port").toString())), m_Data);
	//======================================================================================================================================
	////Actions	
	//QAction *action_Close = new QAction(QIcon(QString::fromUtf8(":/Resources/cancel.png")), "Close", this);
	//QAction *action_FullScreen = new QAction(QIcon(QString::fromUtf8(":/Resources/slideshow_full_screen.png")), "Fullsreen", this);
	//QAction *action_HomePage = new QAction(QIcon(QString::fromUtf8(":/Resources/home_page.png")), "Home Page", this);
	//QAction *action_Plotter = new QAction(QIcon(QString::fromUtf8(":/Resources/chart_curve.png")), "Plotter", this);
	////======================================================================================================================================
	////Toolbar
	//ui.toolBar->addAction(action_Close);
	//ui.toolBar->addAction(action_FullScreen);
	//ui.toolBar->addSeparator();
	//ui.toolBar->setIconSize(QSize(20, 20));
	//ui.toolBar->addAction(action_HomePage);
	//ui.toolBar->addAction(action_Plotter);
	//======================================================================================================================================
	//StartPage
	m_StartPage = new CStartPage(this);
	ui.stackedWidget->addWidget(m_StartPage->getView());
	//======================================================================================================================================
	//Plotter
	m_Plotter = new CPlotter(this);
	ui.stackedWidget->addWidget(m_Plotter->getView());
	//======================================================================================================================================
	//Settings
	m_Settings = new CSettings(this);
	ui.stackedWidget->addWidget(m_Settings);
	//======================================================================================================================================
	//======================================================================================================================================
	connect(m_EventFilter,		SIGNAL(reciveClick()),							this,		SLOT(showNextPage()));
	connect(m_EventFilter,		SIGNAL(reciveDoubleClick()),					this,		SLOT(showSettings()));
	
	connect(m_Data,				SIGNAL(NewDataRecieved()),						this,		SLOT(onNewData()));

	connect(m_Settings,			SIGNAL(reciveNewURL(QString)),					this,		SLOT(onNewURL(QString)));
	connect(m_Settings,			SIGNAL(ready()),								this,		SLOT(showStartpage()));

	connect(m_WebSocketClient,	SIGNAL(serverConnected(QString)),				m_Settings, SLOT(onServerConnected(QString)));
	connect(m_WebSocketClient,	SIGNAL(serverDisconnected()),					m_Settings, SLOT(onServerDisconnected()));

	connect(m_WebSocketClient,	SIGNAL(recievedInitialScript(QJsonObject)),		m_Data,		SLOT(recievedInitialScript(QJsonObject)));
	connect(m_WebSocketClient,	SIGNAL(recievedDataScript(QJsonObject)),		m_Data,		SLOT(recievedDataScript(QJsonObject)));

	//======================================================================================================================================
	//======================================================================================================================================
	resize(480, 320);

	ui.stackedWidget->setCurrentIndex(0);
}

CMainWindow::~CMainWindow()
{

}

void CMainWindow::showStartpage()
{
	ui.stackedWidget->setCurrentIndex(0);
}
void CMainWindow::showPlotter()
{
	ui.stackedWidget->setCurrentIndex(1);
}
void CMainWindow::showSettings()
{
	ui.stackedWidget->setCurrentIndex(2);
}
void CMainWindow::showNextPage()
{
	if (ui.stackedWidget->currentIndex() == 0)
	{
		ui.stackedWidget->setCurrentIndex(1);
	}
	else
	{
		ui.stackedWidget->setCurrentIndex(0);
	}
}

void CMainWindow::onNewData()
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

void CMainWindow::onNewURL(QString ipAdress)
{
	m_WebSocketClient->connectToServer(QUrl(QString("ws://%1").arg(ipAdress)));
}




