#pragma once
#ifndef SOLARDATA_H
#define SOLARDATA_H

#include <QObject>
#include <QtCore>
#include <qmessagebox.h>

#include "Data/Data.h"

class CSolarData : public CData
{
	Q_OBJECT

public:
	CSolarData(QObject *parent = 0);
	~CSolarData();


private:
};

#endif // SOLARDATA_H
