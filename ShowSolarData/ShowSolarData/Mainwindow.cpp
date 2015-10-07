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
    QAction *emitter = static_cast<QAction*>(sender());
	QString test = emitter->text();

	plotDataList(test);
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

void CMainWindow::showDataStartPage(QString data)
{

	//QLocale german(QLocale::German);

	//QStringList dataList = m_SolarData->getCollum(headerList.indexOf(data));
	//QString produced_now = QString("%1").arg(german.toDouble(dataList.last()));
	//QString need_now = "1000";
	//QString available_now = QString("%1").arg(german.toDouble(produced_now) - german.toDouble(need_now));


	//QString produced_last = QString("%1").arg((german.toDouble(dataList.at(dataList.size() - 1)) +
	//	german.toDouble(dataList.at(dataList.size() - 2)) +
	//	german.toDouble(dataList.at(dataList.size() - 3))) / 3);
	//QString need_last = "1300";
	//QString available_last = QString("%1").arg((produced_last.toFloat() - need_last.toFloat()) * 3);

	//ui.label_showProducedNow->setText(QString("<html><head/><body><p><span style=\" font-size:12pt;\">%1W</span></p></body></html>").arg(produced_now));
	//ui.label_showUsedNow->setText(QString("<html><head/><body><p><span style=\" font-size:12pt;\">%1W</span></p></body></html>").arg(need_now));
	//ui.label_showavAilableNow->setText(QString("<html><head/><body><p><span style=\" font-size:12pt;\">%1W</span></p></body></html>").arg(available_now));

	//ui.label_showProducedLast->setText(QString("<html><head/><body><p><span style=\" font-size:12pt;\">%1W</span></p></body></html>").arg(produced_last));
	//ui.label_showUsedLast->setText(QString("<html><head/><body><p><span style=\" font-size:12pt;\">%1W</span></p></body></html>").arg(need_last));
	//ui.label_showavAilableLast->setText(QString("<html><head/><body><p><span style=\" font-size:12pt;\">%1W</span></p></body></html>").arg(available_last));
}
void CMainWindow::plotDataList(QString data, int smoothingFactor)
{
	//static int index = 0;

	//QLocale german(QLocale::German);

	//QStringList dataList = m_SolarData->getCollum(headerList.indexOf(data));
	//QVector<double> x(dataList.size()), y(dataList.size());

	//for (int i = 0; i < dataList.size(); i++)
	//{
	//	x[i] = toTime_t(timeStamps.at(i));

	//}
 //   double buffer1 = 0;

 //   QVector<double> buffer(smoothingFactor);

	//for (int i = 0; i < dataList.size() - smoothingFactor; i++)
	//{
	//	for (int k = 0; k < smoothingFactor; k++)
	//	{
	//		buffer[k] = german.toDouble(dataList.at(i + k));
	//		buffer1 += german.toDouble(dataList.at(i + k));
	//	}
	//	buffer1 = buffer1 / smoothingFactor;
	//	y[i] = buffer1;
	//	buffer1 = 0;
	//}

	//for (int i = 0; i < smoothingFactor; i++)
	//{
	//	y[(dataList.size() - (smoothingFactor)) + i] = buffer.at(i);
	//}




	//ui.m_Plot->setLocale(QLocale(QLocale::German));

	//double now = QDateTime::currentDateTime().toTime_t();

	//ui.m_Plot->addGraph();
	//ui.m_Plot->graph(index)->setPen(QPen(QColor(getRandomNo(0, 250), getRandomNo(0, 250), getRandomNo(0, 250), 255)));
	//ui.m_Plot->graph(index)->setBrush(QBrush(QColor(getRandomNo(0, 250), getRandomNo(0, 250), getRandomNo(0, 250), 20)));

	//ui.m_Plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
	//ui.m_Plot->xAxis->setDateTimeFormat("HH:mm:ss");
	//ui.m_Plot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
	//ui.m_Plot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
	//ui.m_Plot->xAxis2->setVisible(true);
	//ui.m_Plot->yAxis2->setVisible(true);
	//ui.m_Plot->xAxis2->setTicks(false);
	//ui.m_Plot->yAxis2->setTicks(false);
	//ui.m_Plot->xAxis2->setTickLabels(false);
	//ui.m_Plot->yAxis2->setTickLabels(false);
	//// set axis ranges to show all data:
	//ui.m_Plot->xAxis->setRange(x[0], x[dataList.size() - 1]);
	////ui.m_Plot->yAxis->setRange(0, 60);
	//// show legend:
	//ui.m_Plot->graph(index)->setData(x, y);
	//ui.m_Plot->graph(index)->rescaleAxes(true);
	//ui.m_Plot->legend->setVisible(true);

	//index++;

	//ui.m_Plot->replot();
}


int CMainWindow::getRandomNo(int low, int high)
{
	return qrand() % ((high + 1) - low) + low;
}