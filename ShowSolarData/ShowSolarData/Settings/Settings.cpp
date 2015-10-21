#include <QSettings>
#include "Settings.h"


CSettings::CSettings(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pBtn_Save,			SIGNAL(clicked()), this, SLOT(clickedSave()));
	connect(ui.pBtn_Cancel,			SIGNAL(clicked()), this, SLOT(clickedCancel()));
	connect(ui.pBtn_ShowFullScreen, SIGNAL(clicked()), this, SLOT(clickedShowFullScreen()));
	connect(ui.pBtn_Close,			SIGNAL(clicked()), this, SLOT(clickedClose()));
	connect(ui.pBtn_Connect,		SIGNAL(clicked()), this, SLOT(clickedConnect()));

	QSettings settings;
	ui.lineEdit_IPAdress->setText(settings.value("IPAdress").toString());
	ui.lineEdit_Port->setText(settings.value("Port").toString());
}

CSettings::~CSettings()
{

}

QString CSettings::ipAdress()
{
	QSettings settings;

	return settings.value("IPAdress").toString();
}

void CSettings::clickedSave()
{
	QSettings settings;

	if (ui.lineEdit_IPAdress->text() != settings.value("IPAdress").toString() || ui.lineEdit_Port->text() != settings.value("Port").toString())
	{
		settings.setValue("IPAdress", ui.lineEdit_IPAdress->text());
		settings.setValue("Port", ui.lineEdit_Port->text());
		emit reciveNewURL(ui.lineEdit_IPAdress->text() + ":" + ui.lineEdit_Port->text());
	}
	emit ready();
}
void CSettings::clickedCancel()
{
	QSettings settings;

	emit reciveNewURL(QString("%1:%2").arg(settings.value("IPAdress").toString()).arg(settings.value("Port").toString()));
	emit ready();
}
void CSettings::clickedShowFullScreen()
{
	nativeParentWidget()->showFullScreen();
}
void CSettings::clickedClose()
{
	nativeParentWidget()->close();
}
void CSettings::clickedConnect()
{
	emit reciveNewURL(ui.lineEdit_IPAdress->text() + ":" + ui.lineEdit_Port->text());
}


void CSettings::onServerConnected(QString url)
{
	ui.label_Status->setText("Verbunden");
}

void CSettings::onServerDisconnected()
{
	ui.label_Status->setText("Getrennt");
}

