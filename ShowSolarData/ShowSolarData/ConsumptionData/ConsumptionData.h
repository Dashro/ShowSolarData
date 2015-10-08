#pragma once
#ifndef CONSUMPTIONDATA_H
#define CONSUMPTIONDATA_H

#include <QObject>
#include <QtCore>
#include <qmessagebox.h>

#include "Data/Data.h"

class CConsumptionData : public CData
{
	Q_OBJECT

public:
	CConsumptionData(QObject *parent = 0);
	~CConsumptionData();


private:


};

#endif // CONSUMPTIONDATA_H
