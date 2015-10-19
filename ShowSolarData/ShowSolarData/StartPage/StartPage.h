#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QObject>
#include <QTime>

#include <qpushbutton.h>

class CStartPageWindow;

class CStartPage : public QObject
{
	Q_OBJECT

public:
	CStartPage(QObject *parent);
	~CStartPage();

	QWidget* getView();

	void showData(QList < double > production, QList < double > consumption, QList < double > surplus, QList<double> timeStamps);

private:
	CStartPageWindow	*m_StartPageWindow;


};

#endif // STARTPAGE_H
