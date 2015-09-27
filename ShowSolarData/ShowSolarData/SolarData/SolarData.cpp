#include "SolarData.h"

CSolarData::CSolarData(QObject *parent)
	: QObject(parent)
{

}

CSolarData::~CSolarData()
{

}


void CSolarData::openDatafile(QString fileName_)
{
	fileName = fileName_;

	QFile dataFile(fileName);
	if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}
	while (!dataFile.atEnd()) {
		QString line = dataFile.readLine();
		prozessLine(line);
	}

}

void CSolarData::prozessLine(QString line)
{
	static int Row = 0;

	QStringList buffer = line.split(";");

	if (Row > 4)
	{
		timeStamps.append(buffer.first());
		dataList.append(buffer);
	}
	else if (Row == 3)
	{
		unitList.operator=(buffer);
	}
	else if (Row == 4)
	{
		headerList.operator=(buffer);
	}

	Row++;

}

void CSolarData::reloadDataFile()
{

}

QStringList CSolarData::getCollum(int index)
{
	QStringList buffer;
	for (int i = 0; i < dataList.size(); i++)
	{
		buffer.append(dataList.at(i).at(index));
	}
	return buffer;
}
