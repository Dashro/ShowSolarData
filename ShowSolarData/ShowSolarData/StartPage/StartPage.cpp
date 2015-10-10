#include "StartPage.h"
#include "StartPageWindow.h"

CStartPage::CStartPage(QObject *parent)
	: QObject(parent)
{
	m_StartPageWindow = new CStartPageWindow(this);
}

CStartPage::~CStartPage()
{

}


QWidget* CStartPage::getView()
{
	return m_StartPageWindow->window();
}

void CStartPage::showData(QStringList SolarData, QStringList ConsumptionData, QList<double> timeStamps, QTime minutes)
{
	QLocale german(QLocale::German);

	QString prodActual;
	QString consumptionActual;
	QString SummActual;

	QString prodLast;
	QString consumptionLast;
	QString SummLast;

	//Actual
	prodActual = SolarData.last();
	consumptionActual = ConsumptionData.last();
	SummActual = german.toDouble(prodActual) - german.toDouble(consumptionActual);

	//Last ... mins

}
