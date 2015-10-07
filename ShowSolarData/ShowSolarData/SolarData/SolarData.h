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
	QStringList getTimeStamps() { return timeStamps; }

	QStringList getCollum(int index);

private:
	void reloadDataFile();
	void prozessLine(QString line);


//Attributes
	QString fileName;


	QStringList	unitList;
	QStringList headerList;

	QStringList timeStamps;
	QList<QStringList> dataMatrix;
};

#endif // SOLARDATA_H
