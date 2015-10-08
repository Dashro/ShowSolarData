#include "ConsumptionData.h"

CConsumptionData::CConsumptionData(QObject *parent)
	: QObject(parent)
{

}

CConsumptionData::~CConsumptionData()
{

}


int CConsumptionData::openDatafile(QString fileName_)
{
	fileName = fileName_;

	Row = 0;

	unitList.clear();
	headerList.clear();
	dataMatrix.clear();
	timeStamps.clear();

	QFile dataFile(fileName);
	if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox msgBox;
		msgBox.setText(QString("Can't open %1").arg(fileName));
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();
		return 0;
	}
	while (!dataFile.atEnd()) {
		QString line = dataFile.readLine();
		prozessLine(line);

	}
	return 1;
}

void CConsumptionData::prozessLine(QString line)
{

	QStringList buffer = line.split(";");

	if (Row > 4)
	{
		timeStamps.append(toTime_t(buffer.first()));
		dataMatrix.append(buffer);
	}
	else if (Row == 3)
	{
		unitList = buffer;
	}
	else if (Row == 4)
	{
		headerList = buffer;
	}

	Row++;

}


QStringList CConsumptionData::getCollum(int index)
{
	QStringList buffer;
	for (int i = 0; i < dataMatrix.size(); i++)
	{
		buffer.append(dataMatrix.at(i).at(index));
	}
	return buffer;
}

double CConsumptionData::toTime_t(QString TimeStamp_)
{
	QString TimeStamp = TimeStamp_;
	QStringList buffer = TimeStamp.split(' ');

	QStringList buffer_Date = buffer.at(0).split('/');
	QStringList buffer_Time = buffer.at(1).split(':');

	QDateTime dateTime;

	//dateTime.addYears(buffer_Date.at(2).toInt());
	//dateTime.addMonths(buffer_Date.at(1).toInt());
	//dateTime.addDays(buffer_Date.at(0).toInt());

	dateTime.setDate(QDate(buffer_Date.at(2).toInt(), buffer_Date.at(1).toInt(), buffer_Date.at(0).toInt()));
	dateTime.setTime(QTime(buffer_Time.at(0).toInt(), buffer_Time.at(1).toInt(), buffer_Time.at(2).toInt()));

	return dateTime.toTime_t();
}