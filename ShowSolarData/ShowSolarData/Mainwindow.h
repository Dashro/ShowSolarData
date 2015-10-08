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

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

	int getRandomNo(int low, int high);


public slots:
	void ansichtActionTriggered(bool);
	void nextPage();

	void newSolarDataFile(QString);
	void newConsumptionDataFile(QString);
	

private:
	Ui::CMainWindowClass ui;
	CSolarData				*m_SolarData;
	CConsumptionData		*m_ConsumptionData;
	CFolderChoose			*m_FolderChoose;
	CStartPage				*m_StartPage;
	CPlotter				*m_Plotter;

	QStringList				SolarDataHeaderList;
	QList<QStringList>		SolarDataMatrix;
	QStringList				SolarDataUnitList;
	QList<double>			SolarDataTimeStamps;
	
	QStringList				ConsumptionDataHeaderList;
	QList<QStringList>		ConsumptionDataMatrix;
	QStringList				ConsumptionDataUnitList;
	QList<double>			ConsumptionDataTimeStamps;







};

#endif // MAINWINDOW_H
