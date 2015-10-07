#ifndef STARTPAGEWINDOW_H
#define STARTPAGEWINDOW_H

#include <QWidget>
#include "ui_StartPageWindow.h"

class CStartPage;

class CStartPageWindow : public QWidget
{
	Q_OBJECT

public:
	CStartPageWindow(CStartPage *m_StartPage_, QWidget *parent = 0);

	~CStartPageWindow();


	Ui::CStartPageWindow ui;
private:


	CStartPage *m_StartPage;
};

#endif // STARTPAGEWINDOW_H
