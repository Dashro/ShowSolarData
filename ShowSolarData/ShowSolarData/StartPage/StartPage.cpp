#include "StartPage.h"
#include "StartPageWindow.h"

CStartPage::CStartPage(QObject *parent)
	: QObject(parent)
{
	m_StartPageWindow = new CStartPageWindow(this);
}

CStartPage::~CStartPage()
{

}


QWidget* CStartPage::getView()
{
	return m_StartPageWindow->window();
}

