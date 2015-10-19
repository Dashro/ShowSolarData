#include "StartPageWindow.h"
#include "StartPage.h"

#include "EventFilter.h"

CStartPageWindow::CStartPageWindow(CStartPage *m_StartPage_, QWidget *parent)
	: QWidget(parent), m_StartPage(m_StartPage_)
{
	ui.setupUi(this);

	this->installEventFilter(CEventFilter::Signleton());

	ui.groupBox->installEventFilter(CEventFilter::Signleton());
	ui.groupBox_2->installEventFilter(CEventFilter::Signleton());
}



CStartPageWindow::~CStartPageWindow()
{

}

