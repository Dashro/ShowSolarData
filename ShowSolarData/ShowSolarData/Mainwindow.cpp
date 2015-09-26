#include "Mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_SolarData = new CSolarData;

	m_SolarData->openDatafile("MyPlant-Spot-20150829.csv");


	headerList = m_SolarData->getheaderList();
	
	for (int i = 5; i < headerList.size(); i++)
	{
		QAction *tempAction = new QAction(QString("%1").arg(headerList.at(i)), this);
		ui.menuAnsicht_Alle->addAction(tempAction);
		tempAction->setData(i);
		connect(tempAction, SIGNAL(triggered(bool)), this, SLOT(ansichtActionTriggered(bool)));

	}

}

CMainWindow::~CMainWindow()
{

}

void CMainWindow::ansichtActionTriggered(bool)
{
	int index = static_cast<QAction*>(sender())->data().toInt();
}