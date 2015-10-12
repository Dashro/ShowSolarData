#include "StartPageWindow.h"
#include "StartPage.h"

CStartPageWindow::CStartPageWindow(CStartPage *m_StartPage_, QWidget *parent)
	: QWidget(parent), m_StartPage(m_StartPage_)
{
	ui.setupUi(this);
}



CStartPageWindow::~CStartPageWindow()
{

}


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