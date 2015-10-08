#pragma once
#ifndef CONSUMPTIONDATA_H
#define CONSUMPTIONDATA_H

#include <QObject>
#include <QtCore>
#include <qmessagebox.h>

class CConsumptionData : public QObject
{
	Q_OBJECT

public:
	CConsumptionData(QObject *parent = 0);
	~CConsumptionData();

	int openDatafile(QString fileName_);

	QStringList	getunitList() { return unitList; }
	QStringList getheaderList() { return headerList; }

	QList<QStringList> getdataMatrix() { return dataMatrix; }
	QList<double> getTimeStamps() { return timeStamps; }

	QStringList getCollum(int index);

private:
	void prozessLine(QString line);

	double toTime_t(QString TimeStamp);


	//Attributes
	QString fileName;


	QStringList	unitList;
	QStringList headerList;

	QList<double> timeStamps;
	QList<QStringList> dataMatrix;

	int Row;
};

#endif // CONSUMPTIONDATA_H
