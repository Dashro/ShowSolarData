#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>
#include <QMouseEvent>
#include <QKeyEvent>


class CEventFilter : public QObject
{
	Q_OBJECT

public:
	static CEventFilter* Signleton();


signals:
	void reciveDoubleClick();
	void reciveClick();

protected:
	bool eventFilter(QObject *obj, QEvent *event);

private:
	static CEventFilter				*Instance;

	CEventFilter(QObject *parent = 0);
	~CEventFilter();
};

#endif // EVENTFILTER_H
