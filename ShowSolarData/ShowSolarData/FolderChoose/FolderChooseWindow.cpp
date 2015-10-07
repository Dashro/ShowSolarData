#include "FolderChooseWindow.h"
#include "FolderChoose.h"

CFolderChooseWindow::CFolderChooseWindow(CFolderChoose *m_FolderChoose_, QWidget *parent)
	: QWidget(parent), m_FolderChoose(m_FolderChoose_)
{
	ui.setupUi(this);	

	fModel = new QFileSystemModel;
	fModel->setRootPath("");

	ui.treeView_FolderChoose->setModel(fModel);
	ui.treeView_FolderChoose->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

}

CFolderChooseWindow::~CFolderChooseWindow()
{

}
