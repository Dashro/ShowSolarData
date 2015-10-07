#include "StartPageWindow.h"
#include "StartPage.h"

CStartPageWindow::CStartPageWindow(CStartPage *m_StartPage_, QWidget *parent)
	: QWidget(parent), m_StartPage(m_StartPage_)
{
	ui.setupUi(this);

	ui.label->setText("Dies ist ein test!");

}



CStartPageWindow::~CStartPageWindow()
{

}
