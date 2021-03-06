#include "Data.h"

CData::CData(QObject *parent)
	: QObject(parent)
{
	m_SMLProcess = new QProcess(this);
	//m_SMLProcess->setProcessChannelMode(QProcess::ForwardedChannels);
}

CData::~CData()
{

}

void CData::recievedInitialScript(QJsonObject json)
{
	clear();
	headerList << "Timestamp" << "Einspeisung" << "Bezug" << "ETotal";
	unitList << json["Timestamp"].toString() << json["Einspeisung"].toString() << json["Bezug"].toString() << "kWh";
}
void CData::recievedDataScript(QJsonObject json)
{
	QStringList buffer;
	buffer << json["Timestamp"].toString() << json["Einspeisung"].toString() << json["Bezug"].toString() << getSMLValue("ETotal");
	setRow(buffer);
}

void CData::processSMLOutput()
{
}

void CData::clear()
{
	unitList.clear();
	headerList.clear();

	timeStampList.clear();
	dataMatrix.clear();
}

//int CData::openDatafile(QString fileName_)
//{
//	fileName = fileName_;
//
//	int row = 0;
//
//	unitList.clear();
//	headerList.clear();
//	dataMatrix.clear();
//	timeStampList.clear();
//
//	QFile dataFile(fileName);
//	if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text))
//	{
//		QMessageBox msgBox;
//		msgBox.setText(QString("Can't open %1").arg(fileName));
//		msgBox.setIcon(QMessageBox::Critical);
//		msgBox.exec();
//		return 0;
//	}
//	while (!dataFile.atEnd()) {
//		QString line = dataFile.readLine();
//		prozessLine(line, row);
//		row++;
//	}
//	return 1;
//}

QList<double> CData::consumption()
{
	QList<double> Consumtion;
	QList<double> Bezug = collumRelative(headerList.indexOf("Bezug"), "W");
	QList<double> Einspeisung = collumRelative(headerList.indexOf("Einspeisung"), "W");
	QList<double> Produktion = collumRelative(headerList.indexOf("ETotal"), "W");

	for (int i = 0; i < Bezug.size(); i++)
	{
		Consumtion.append(Bezug.at(i) - Einspeisung.at(i) + Produktion.at(i));
	}

	return Consumtion;
}
QList<double> CData::production()
{
	return collumRelative(headerList.indexOf("ETotal"), "W");
}
QList<double> CData::surplus()
{
	QList<double> Surplus;
	QList<double> Produktion = production();
	QList<double> Consumtion = consumption();

	for (int i = 0; i < Produktion.size(); i++)
	{
		Surplus.append(Produktion.at(i) - Consumtion.at(i));
	}

	return Surplus;
}

void CData::setRow(QString line)
{
	setRow(line.split(";"));
}
void CData::setRow(QStringList line)
{
	bool ok;
	QList<double> bufferDbl;
	QLocale german(QLocale::German);

	QStringList bufferStr = line;

	qDebug() << QStringLiteral("recive new Values : ") << bufferStr;


	if (headerList.contains("Timestamp"))
	{
		timeStampList.append(toTime_t(bufferStr.at(headerList.indexOf("Timestamp"))));
		bufferDbl.append(timeStampList.last());
	}
	else
	{
		qCritical() << "This DataLine contains no Timestamp, the current Time will used instead";
		timeStampList.append(QDateTime::currentDateTime().toTime_t());
		bufferStr.prepend(QString("%1").arg(timeStampList.last()));
	}
	for (int i = 1; i < bufferStr.size(); i++)
	{
		bufferDbl.append(bufferStr.at(i).toDouble(&ok));
		if (!ok)
			bufferDbl.last() = german.toDouble(bufferStr.at(i), &ok);

		if (!ok)
		{
			qCritical() << "Cant convert" << bufferStr.at(i) << "to double";
			bufferDbl[i] = 0.0;
		}
	}
	dataMatrix.append(bufferDbl);

	emit NewDataRecieved();
}

QString CData::getSMLValue(QString key)
{
	static int test = 0;
	QString test_str;
	QStringList lines;
	QString buffer;
#ifdef _WIN32
	m_SMLProcess->start("C:/Users/Fabian/Documents/Tests/ConsolePrinter/Win32/Debug/ConsolePrinter.exe");
#else
	m_SMLProcess->start("/home/pi/SMA/SMAspot/SMAspot", QStringList() << "-v" << "-finq");
#endif


	if (!m_SMLProcess->waitForStarted())
	{
		qCritical() << "Cant start SMLProgramm";
		m_SMLProcess->close();
		return NULL;
	}
	if (!m_SMLProcess->waitForFinished())
	{
		qCritical() << "waiting-for-SMLData timeout";
		m_SMLProcess->close();
		return NULL;
	}
	buffer = QString::fromLatin1(m_SMLProcess->readAllStandardOutput());
	lines = buffer.split(QRegExp("\n"), QString::SkipEmptyParts);
	m_SMLProcess->close();
	lines = lines.filter(key, Qt::CaseInsensitive);

	if (lines.size() != 1)
	{

		qWarning() << "key is not clearly :" << key << "(" << "results :" << lines.size() << ")";
		qDebug() << buffer;
		return NULL;
	}
	lines.first().remove(QRegExp("[ \\rA-Za-z:]"));

	qDebug() << key << " : " << lines.first();
	return lines.first();

}

QList<double> CData::collum(int index, QString asUnit)
{
	QList<double>  buffer;
	for (int i = 0; i < dataMatrix.size(); i++)
	{
		buffer.append(dataMatrix.at(i).at(index));
	}

	if (asUnit != 0)
	{
		return toUnit(buffer, headerList.at(index), asUnit);
	}
	return buffer;
}
QList<double> CData::collumRelative(int index, QString asUnit)
{
	QLocale german(QLocale::German);
	QList<double>  buffer;
	for (int i = 1; i < dataMatrix.size(); i++)
	{
		buffer.append((dataMatrix.at(i).at(index)) - (dataMatrix.at(i - 1).at(index)));
	}
	if (asUnit != 0)
	{
		return toUnit(buffer, unitList.at(index), asUnit);
	}
	return buffer;
}

double CData::toTime_t(QString TimeStamp_)
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

QList<double> CData::toUnit(QList<double> dataList, QString unitFrom, QString unitTo, double multiplier)
{
	QLocale german(QLocale::German);
	double value;

	double multiplierFrom;
	double multiplierTo;

	if (unitFrom.startsWith("k"))
		multiplierFrom = 1000;
	else if (unitFrom.startsWith("M"))
		multiplierFrom = 1000000;
	else if (unitFrom.startsWith("m"))
		multiplierFrom = 1. / 1000;
	else if (unitFrom.startsWith("u"))
		multiplierFrom = 1. / 1000000;
	else
		multiplierFrom = 1;

	if (unitTo.startsWith("k"))
		multiplierTo = 1000;
	else if (unitTo.startsWith("M"))
		multiplierTo = 1000000;
	else if (unitTo.startsWith("m"))
		multiplierTo = 1. / 1000;
	else if (unitTo.startsWith("u"))
		multiplierTo = 1. / 1000000;
	else
		multiplierTo = 1;

	for (int i = 0; i < dataList.size(); i++)
	{
		value = (dataList.at(i) * multiplierFrom * multiplier) / multiplierTo;
		if (value < 20000 && value > -20000)
			dataList[i] = value;
		else
			value = NAN;
	}

	if (unitFrom.contains("Wh") && unitTo.contains("W"))
	{
		for (int i = 0; i < dataList.size(); i++)
		{
			double s = timeStampList.at(i + 1) - timeStampList.at(i);
			value = dataList.at(i) / (s / 3600);
			if (value < 20000 && value > -20000 && s > 4.5)
				dataList[i] = value;
			else
				value = NAN;
		}
	}
	return dataList;
}