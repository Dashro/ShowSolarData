#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QObject>

class CStartPageWindow;

class CStartPage : public QObject
{
	Q_OBJECT

public:
	CStartPage(QObject *parent);
	~CStartPage();

	QWidget* getView();


private:
	CStartPageWindow	*m_StartPageWindow;


};

#endif // STARTPAGE_H
