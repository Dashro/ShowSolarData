#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>


#include "ui_Mainwindow.h"

#include "EventFilter.h"

#include "Data/Data.h"
#include "StartPage/StartPage.h"
#include "Plotter/Plotter.h"
#include "WebSocketClient/WebSocketClient.h"

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

public slots:
	void showStartpage();
	void showPlotter();

	void showNextPage();

	void newData();

private:
	Ui::CMainWindowClass ui;

	CEventFilter			*m_EventFilter;

	CData					*m_Data;

	CStartPage				*m_StartPage;
	CPlotter				*m_Plotter;
	CWebSocketClient		*m_WebSocketClient;

	QList< double >			DataHeaderList;
	QList< double > 		DataUnitList;
	QList< double >			DataTimeStamps;
};

#endif // MAINWINDOW_H