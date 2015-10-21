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
#include "Settings/Settings.h"

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(int argc, char *argv[], QWidget *parent = 0);
	~CMainWindow();

public slots:

//Internal Slots
	void showStartpage();
	void showPlotter();
	void showSettings();

	void showNextPage();


//Data
	void onNewData();

//Settings
	void onNewURL(QString url);

private:
	Ui::CMainWindowClass ui;

	CEventFilter			*m_EventFilter;
	CSettings				*m_Settings;
	CData					*m_Data;

	CStartPage				*m_StartPage;
	CPlotter				*m_Plotter;
	CWebSocketClient		*m_WebSocketClient;

	QList< double >			DataHeaderList;
	QList< double > 		DataUnitList;
	QList< double >			DataTimeStamps;
};

#endif // MAINWINDOW_H