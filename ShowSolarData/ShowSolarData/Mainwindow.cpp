#include "Mainwindow.h"


CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//======================================================================================================================================
	ui.setupUi(this);
	m_EventFilter = CEventFilter::Signleton();
	m_Data = new CData;
	m_WebSocketClient = new CWebSocketClient(QUrl(QStringLiteral("ws://localhost:1234")), m_Data);
	//======================================================================================================================================
	QLocale german(QLocale::German);
	//======================================================================================================================================
	//Actions	
    QAction *action_Close = new QAction(QIcon(QString::fromUtf8(":/Resources/cancel.png")), "Close", this);
	QAction *action_FullScreen = new QAction(QIcon(QString::fromUtf8(":/Resources/slideshow_full_screen.png")), "Fullsreen", this);
	QAction *action_HomePage = new QAction(QIcon(QString::fromUtf8(":/Resources/home_page.png")), "Home Page", this);
	QAction *action_Plotter = new QAction(QIcon(QString::fromUtf8(":/Resources/chart_curve.png")), "Plotter", this);
	//======================================================================================================================================
	//Toolbar
	ui.toolBar->addAction(action_Close);
	ui.toolBar->addAction(action_FullScreen);
	ui.toolBar->addSeparator();
	ui.toolBar->setIconSize(QSize(20, 20));
	ui.toolBar->addAction(action_HomePage);
	ui.toolBar->addAction(action_Plotter);
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
	//======================================================================================================================================
	connect(action_Close,			SIGNAL(triggered()), this, SLOT(close()));
	connect(action_FullScreen,		SIGNAL(triggered()), this, SLOT(showFullScreen()));
	connect(m_EventFilter,			SIGNAL(reciveClick()), this, SLOT(showNextPage()));

	connect(action_HomePage,		SIGNAL(triggered()), this, SLOT(showStartpage()));
	connect(action_Plotter,			SIGNAL(triggered()), this, SLOT(showPlotter()));

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


void CMainWindow::showStartpage()
{
	ui.stackedWidget->setCurrentIndex(0);
}
void CMainWindow::showPlotter()
{
	ui.stackedWidget->setCurrentIndex(1);
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


