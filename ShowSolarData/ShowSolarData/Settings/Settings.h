#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "ui_Settings.h"

class CSettings : public QWidget
{
	Q_OBJECT

public:
	CSettings(QWidget *parent = 0);
	~CSettings();

	QString ipAdress();
signals:
	void reciveNewURL(QString);
	void ready();


private slots:
	void clickedSave();
	void clickedCancel();
	void clickedShowFullScreen();
	void clickedClose();
	void clickedConnect();

	void onServerConnected(QString);
	void onServerDisconnected();
private:
	Ui::CSettings ui;
};

#endif // SETTINGS_H
