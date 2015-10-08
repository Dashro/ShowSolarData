#pragma once
#ifndef SOLARDATA_H
#define SOLARDATA_H

#include <QObject>
#include <QtCore>
#include <qmessagebox.h>

class CSolarData : public QObject
{
	Q_OBJECT

public:
	CSolarData(QObject *parent = 0);
	~CSolarData();

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

#endif // SOLARDATA_H
