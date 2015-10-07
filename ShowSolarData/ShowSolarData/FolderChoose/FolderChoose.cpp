#include "FolderChoose.h"
#include "FolderChooseWindow.h"

CFolderChoose::CFolderChoose(QObject *parent)
	: QObject(parent)
{
	m_FolderChooseWindow = new CFolderChooseWindow(this);

	connect(m_FolderChooseWindow, SIGNAL(newSolarDataFolder(QString)), this, SLOT(reciveNewSolarDataFolder(QString)));
	connect(m_FolderChooseWindow, SIGNAL(newConsumptionDataFolder(QString)), this, SLOT(reciveNewConsumptionDataFolder(QString)));
}

CFolderChoose::~CFolderChoose()
{

}

QWidget* CFolderChoose::getView()
{
	return m_FolderChooseWindow->window();
}

void CFolderChoose::reciveNewSolarDataFolder(QString newPath)
{
	if (QFileInfo(newPath).isFile())
	{
		emit NewSolarDataFile(newPath);
	}
}

void CFolderChoose::reciveNewConsumptionDataFolder(QString newPath)
{
	if (QFileInfo(newPath).isFile())
	{
		emit NewConsumptionDataFile(newPath);
	}
}