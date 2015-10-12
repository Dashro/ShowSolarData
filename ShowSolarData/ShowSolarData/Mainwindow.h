#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>


#include "ui_Mainwindow.h"
#include "SolarData/SolarData.h"
#include "ConsumptionData\ConsumptionData.h"
#include "FolderChoose\FolderChoose.h"
#include "StartPage\StartPage.h"
#include "Plotter\Plotter.h"
#include "WebSocketClient\WebSocketClient.h"

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

	//int getRandomNo(int low, int high);


public slots:
	//void newSolarDataFile(QString);


	void showStartpage();
	void showPlotter();
	void showFolderChoose();

	void newData();

	

private:
	Ui::CMainWindowClass ui;
	CData					*m_Data;

	CFolderChoose			*m_FolderChoose;
	CStartPage				*m_StartPage;
	CPlotter				*m_Plotter;
	CWebSocketClient		*m_WebSocketClient;

	QList< double >			DataHeaderList;
	QList< double > 		DataUnitList;
	QList< double >			DataTimeStamps;
				  







};

#endif // MAINWINDOW_H
