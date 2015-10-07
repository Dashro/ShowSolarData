#ifndef FOLDERCHOOSEWINDOW_H
#define FOLDERCHOOSEWINDOW_H

#include <QWidget>
#include <QFileSystemModel>
#include "ui_FolderChooseWindow.h"


class CFolderChoose;

class CFolderChooseWindow : public QWidget
{
	Q_OBJECT

	enum class ChooseMode { ChooseSolarData, ChooseConsuptionData };

public:
	CFolderChooseWindow(CFolderChoose *m_FolderChoose_, QWidget *parent = 0);
	~CFolderChooseWindow();

	void setMode(ChooseMode mode_);
	ChooseMode getMode()	{ return mode; };

private slots:
	void pushedOpen();

signals:
	void newSolarDataFolder(QString solarDataFolder);
	void newConsuptionDataFolder(QString consuptionDataFolder);
	
private:
	Ui::CFolderChooseWindow ui;

	CFolderChoose			*m_FolderChoose;


	QFileSystemModel		*fModel;
	ChooseMode				mode;
};

#endif // FOLDERCHOOSEWINDOW_H
