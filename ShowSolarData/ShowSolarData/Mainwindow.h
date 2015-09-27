#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_Mainwindow.h"
#include "Customplot/qcustomplot.h"
#include "SolarData/SolarData.h"

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

	void showDataStartPage(QString produced_now, QString need_now = "0", QString available_now = "0", QString produced_last = "0", QString need_last = "0", QString available_last = "0");

public slots:
	void ansichtActionTriggered(bool);
	void nextPage();
	

private:
	Ui::CMainWindowClass ui;
	CSolarData				*m_SolarData;

	QStringList	unitList;
	QStringList headerList;

	QStringList timeStamps;
	QList<QStringList> dataList;


};

#endif // MAINWINDOW_H
