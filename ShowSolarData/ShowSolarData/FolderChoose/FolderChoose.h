#ifndef FOLDERCHOOSE_H
#define FOLDERCHOOSE_H

#include <QObject>

class CFolderChooseWindow;

class CFolderChoose : public QObject
{
	Q_OBJECT

public:
	CFolderChoose(QObject *parent = 0);
	~CFolderChoose();

	QWidget* getView();

	QString getSolarDataFile();
	QString getConsumptionDataFile();

private slots:
	void reciveNewSolarDataFolder(QString newFolder);
	void reciveNewConsumptionDataFolder(QString newFolder);

signals:
	void NewSolarDataFile(QString newFolder);
	void NewConsumptionDataFile(QString newFolder);

private:
	CFolderChooseWindow		*m_FolderChooseWindow;

	QString					solarDataPath;
	QString					consumptionDataPath;
	
};

#endif // FOLDERCHOOSE_H
