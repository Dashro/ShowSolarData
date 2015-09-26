#include "Mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_SolarData = new CSolarData;

	m_SolarData->openDatafile("MyPlant-Spot-20150829.csv");

	connect(ui.action_nextPage, SIGNAL(triggered()), this, SLOT(nextPage()));

	headerList = m_SolarData->getheaderList();
	dataList = m_SolarData->getDataList();
	unitList = m_SolarData->getunitList();

	
	for (int i = 5; i < headerList.size(); i++)
	{
		QAction *tempAction = new QAction(QString("%1").arg(headerList.at(i)), this);
		ui.menuAnsicht_Alle->addAction(tempAction);
		tempAction->setData(i);
		connect(tempAction, SIGNAL(triggered(bool)), this, SLOT(ansichtActionTriggered(bool)));
	}
	QLocale german(QLocale::German);


	QStringList dataList_PacTot = m_SolarData->getCollum(headerList.indexOf("PacTot"));
	QString produced_now = QString("%1").arg(german.toDouble(dataList_PacTot.last()));
	QString need_now = "1000";
	QString available_now = QString("%1").arg(german.toDouble(produced_now) - german.toDouble(need_now));


	QString produced_last = QString("%1").arg((german.toDouble(dataList_PacTot.at(dataList_PacTot.size() - 1)) + 
		german.toDouble(dataList_PacTot.at(dataList_PacTot.size() - 2)) +
		german.toDouble(dataList_PacTot.at(dataList_PacTot.size() - 3))) / 3 );
	QString need_last = "1300";
	QString available_last = QString("%1").arg((produced_last.toFloat() - need_last.toFloat()) *3 );

	showDataStartPage(produced_now, need_now, available_now, produced_last, need_last, available_last);
}

CMainWindow::~CMainWindow()
{

}

void CMainWindow::ansichtActionTriggered(bool)
{
	int index = static_cast<QAction*>(sender())->data().toInt();
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


void CMainWindow::showDataStartPage(QString produced_now, QString need_now, QString available_now, QString produced_last, QString need_last, QString available_last)
{
	ui.label_showProducedNow->setText(QString("<html><head/><body><p><span style=\" font-size:14pt;\">%1W</span></p></body></html>").arg(produced_now));
	ui.label_showUsedNow->setText(QString("<html><head/><body><p><span style=\" font-size:14pt;\">%1W</span></p></body></html>").arg(need_now));
	ui.label_showavAilableNow->setText(QString("<html><head/><body><p><span style=\" font-size:14pt;\">%1W</span></p></body></html>").arg(available_now));

	ui.label_showProducedLast->setText(QString("<html><head/><body><p><span style=\" font-size:14pt;\">%1W</span></p></body></html>").arg(produced_last));
	ui.label_showUsedLast->setText(QString("<html><head/><body><p><span style=\" font-size:14pt;\">%1W</span></p></body></html>").arg(need_last));
	ui.label_showavAilableLast->setText(QString("<html><head/><body><p><span style=\" font-size:14pt;\">%1W</span></p></body></html>").arg(available_last));
}