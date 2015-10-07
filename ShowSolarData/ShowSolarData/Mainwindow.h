#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>


#include "ui_Mainwindow.h"
#include "Customplot/qcustomplot.h"
#include "SolarData/SolarData.h"
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
	double toTime_t(QString TimeStamp);

public slots:
	void ansichtActionTriggered(bool);
	void nextPage();
	

private:
	Ui::CMainWindowClass ui;
	CSolarData				*m_SolarData;
	CFolderChoose			*m_FolderChoose;
	CStartPage				*m_StartPage;
	CPlotter				*m_Plotter;

	QStringList	unitList;
	QStringList headerList;

	QStringList timeStamps;
	QList<QStringList> dataMatrix;







};

#endif // MAINWINDOW_H
