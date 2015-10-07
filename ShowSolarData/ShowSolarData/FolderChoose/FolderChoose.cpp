#include "FolderChoose.h"
#include "FolderChooseWindow.h"

CFolderChoose::CFolderChoose(QObject *parent)
	: QObject(parent)
{
	m_FolderChooseWindow = new CFolderChooseWindow(this);
}

CFolderChoose::~CFolderChoose()
{

}

QWidget* CFolderChoose::getView()
{
	return m_FolderChooseWindow->window();
}