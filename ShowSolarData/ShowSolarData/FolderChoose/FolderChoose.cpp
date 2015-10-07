#include "FolderChoose.h"
#include "FolderChooseWindow.h"

#include <qmessagebox.h>
#include <qsettings.h>

CFolderChoose::CFolderChoose(QObject *parent)
	: QObject(parent)
{
	m_FolderChooseWindow = new CFolderChooseWindow(this);

	QSettings settings;

	connect(m_FolderChooseWindow, SIGNAL(newSolarDataFolder(QString)), this, SLOT(reciveNewSolarDataFolder(QString)));
	connect(m_FolderChooseWindow, SIGNAL(newConsumptionDataFolder(QString)), this, SLOT(reciveNewConsumptionDataFolder(QString)));

	solarDataPath = settings.value("solarDataPath").toString();
	consumptionDataPath = settings.value("consumptionDataPath").toString();
	
}

CFolderChoose::~CFolderChoose()
{

}

QWidget* CFolderChoose::getView()
{
	return m_FolderChooseWindow->window();
}

QString CFolderChoose::getSolarDataFile()
{
	m_FolderChooseWindow->setMode(CFolderChooseWindow::ChooseMode::ChooseSolarData);
	return solarDataPath;
}

QString CFolderChoose::getConsumptionDataFile()
{
	m_FolderChooseWindow->setMode(CFolderChooseWindow::ChooseMode::ChooseConsuptionData);
	return consumptionDataPath;
}

void CFolderChoose::reciveNewSolarDataFolder(QString newPath)
{
	if (!QFileInfo(newPath).isDir() && !QFileInfo(newPath).isFile())
	{
		QMessageBox msgBox;
		msgBox.setText("Please select a file or directory!");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
		return;
	}

	solarDataPath = newPath;
	QSettings settings;

	settings.setValue("solarDataPath", solarDataPath);

	if (QFileInfo(newPath).isFile())
	{
		emit NewSolarDataFile(newPath);
	}
}

void CFolderChoose::reciveNewConsumptionDataFolder(QString newPath)
{
	if (!QFileInfo(newPath).isDir() && !QFileInfo(newPath).isFile())
	{
		QMessageBox msgBox;
		msgBox.setText("Please select a file or directory!");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
		return;
	}

	consumptionDataPath = newPath;
	QSettings settings;

	settings.setValue("consumptionDataPath", consumptionDataPath);

	if (QFileInfo(newPath).isFile())
	{
		emit NewConsumptionDataFile(newPath);
	}
}