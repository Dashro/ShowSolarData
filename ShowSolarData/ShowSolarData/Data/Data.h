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

	//int openDatafile(QString fileName_);

	QStringList	units() { return unitList; }
	QStringList header() { return headerList; }

	void setUnits(QStringList unitList_) { unitList = unitList_; }
	void setHeader(QStringList headerList_) { headerList = headerList_; }

	QList < double > timeStamps() { return timeStampList; }

	QList < double > collum(int index, QString asUnit = 0);
	QList < double > collumRelative(int index, QString asUnit = 0);

	QList < double > consumption();
	QList < double > production();
	QList < double > surplus();


	void setRow(QString line);
	void setRow(QStringList line);

signals:
	void NewDataRecieved();

private:
	
	QList <double> toUnit(QList < double > dataList, QString unitFrom, QString unitTo, double multiplier = 1);


	double toTime_t(QString TimeStamp);


	//Attributes
	QString fileName;


	QStringList	unitList;
	QStringList headerList;

	QList< double > timeStampList;
	QList< QList < double > > dataMatrix;

};

#endif // DATA_H
