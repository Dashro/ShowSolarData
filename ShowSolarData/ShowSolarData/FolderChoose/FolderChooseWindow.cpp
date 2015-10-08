#include "FolderChooseWindow.h"
#include "FolderChoose.h"
#include <qdebug.h>

CFolderChooseWindow::CFolderChooseWindow(CFolderChoose *m_FolderChoose_, QWidget *parent)
	: QWidget(parent), m_FolderChoose(m_FolderChoose_)
{
	ui.setupUi(this);	

	fModel = new QFileSystemModel;
	fModel->setRootPath("");


	ui.treeView_FolderChoose->setModel(fModel);
	ui.treeView_FolderChoose->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

	connect(ui.pBtn_Open, SIGNAL(clicked()), this, SLOT(pushedOpen()));

	setMode(ChooseMode::ChooseSolarData);

}

CFolderChooseWindow::~CFolderChooseWindow()
{

}

void CFolderChooseWindow::pushedOpen()
{
	if (mode == ChooseMode::ChooseSolarData)
	{
		QModelIndex mIndex = ui.treeView_FolderChoose->currentIndex();

		QString filePath = fModel->filePath(mIndex);
		emit newSolarDataFolder(filePath);
		//setMode(ChooseMode::ChooseConsuptionData);
	}
	else if (mode == ChooseMode::ChooseConsuptionData)
	{
		QModelIndex mIndex = ui.treeView_FolderChoose->currentIndex();

		QString filePath = fModel->filePath(mIndex);
		emit newConsumptionDataFolder(filePath);
		//setMode(ChooseMode::ChooseSolarData);
	}
	else
		qDebug() << "Ungültiger Mode";
}

void CFolderChooseWindow::setMode(ChooseMode newMode)
{
	mode = newMode;
	if (mode == ChooseMode::ChooseSolarData)
	{
		ui.label_Description->setText("Choose SolarData File");
	}
	else if (mode == ChooseMode::ChooseConsuptionData)
	{
		ui.label_Description->setText("Choose ConsuptionData File");
	}
	else
		qDebug() << "Ungültiger Mode gesetzt";
}