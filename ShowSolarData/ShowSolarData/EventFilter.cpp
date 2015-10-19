#include "EventFilter.h"
#include <QDebug>

CEventFilter::CEventFilter(QObject *parent)
	: QObject(parent)
{

}

CEventFilter::~CEventFilter()
{

}

CEventFilter* CEventFilter::Instance = 0;

CEventFilter* CEventFilter::Signleton()
{
	if (!Instance)
	{
		Instance = new CEventFilter();
	}
	return Instance;
}

bool CEventFilter::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		qDebug() << "click";
		emit reciveClick();
	}
	else if (event->type() == QEvent::MouseButtonDblClick)
	{
		qDebug() << "double click";
		emit reciveDoubleClick();
	}
	else {
		// standard event processing
		return QObject::eventFilter(obj, event);
	}
}