#include "SolarData.h"

CSolarData::CSolarData(QObject *parent)
	: QObject(parent)
{

}

CSolarData::~CSolarData()
{

}


int CSolarData::openDatafile(QString fileName_)
{
	fileName = fileName_;

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

void CSolarData::prozessLine(QString line)
{
	static int Row = 0;

	QStringList buffer = line.split(";");

	if (Row > 4)
	{
		timeStamps.append(buffer.first());
		dataMatrix.append(buffer);
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
	for (int i = 0; i < dataMatrix.size(); i++)
	{
		buffer.append(dataMatrix.at(i).at(index));
	}
	return buffer;
}
