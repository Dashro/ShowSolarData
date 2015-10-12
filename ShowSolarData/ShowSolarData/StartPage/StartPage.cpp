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

void CStartPage::showData(QList < double > production, QList < double > consumption, QList < double > surplus ,QList<double> timeStamps)
{
	QLocale german(QLocale::German);

	QString prodLast;
	QString consumptionLast;
	QString SummLast;

	//Actual
	m_StartPageWindow->ui.label_ProdActual->setText(QString("%1").arg(production.last()));
	m_StartPageWindow->ui.label_ConsumptionActual->setText(QString("%1").arg(consumption.last()));
	m_StartPageWindow->ui.label_SummActual->setText(QString("%1").arg(surplus.last()));

	//Last 15 mins

	int size = production.size();

	prodLast = QString("%1").arg((production.at(size - 1) + production.at(size - 2) + production.at(size - 3))/3);
	consumptionLast = QString("%1").arg((consumption.at(size - 1) + consumption.at(size - 2) + consumption.at(size - 3)) / 3);
	SummLast = QString("%1").arg((surplus.at(size - 1) + surplus.at(size - 2) + surplus.at(size - 3)) / 3);

	m_StartPageWindow->ui.label_ProdLast->setText(prodLast);
	m_StartPageWindow->ui.label_ConsumptionLast->setText(consumptionLast);
	m_StartPageWindow->ui.label_SummLast->setText(SummLast);
}
