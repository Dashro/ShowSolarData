#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QObject>
#include <QTime>

class CStartPageWindow;

class CStartPage : public QObject
{
	Q_OBJECT

public:
	CStartPage(QObject *parent);
	~CStartPage();

	QWidget* getView();

	void showData(QStringList SolarData, QStringList ConsumptionData, QList<double> timeStamps, QTime minutes);

private:
	CStartPageWindow	*m_StartPageWindow;


};

#endif // STARTPAGE_H
