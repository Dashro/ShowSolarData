#pragma once
#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QtCore>
#include <qmessagebox.h>

class CData : public QObject
{
	Q_OBJECT

public:
	CData(QObject *parent = 0);
	~CData();

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

#endif // DATA_H
