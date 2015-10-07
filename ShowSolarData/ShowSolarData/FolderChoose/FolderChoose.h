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

private:
	CFolderChooseWindow		*m_FolderChooseWindow;
	
};

#endif // FOLDERCHOOSE_H
