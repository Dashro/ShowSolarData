//Plotter.h
#ifndef PLOTTER_H
#define PLOTTER_H

#include <QObject>

class CPlotterWindow;

class CPlotter : public QObject
{
	Q_OBJECT

public:
	CPlotter(QObject *parent);
	~CPlotter();

	QWidget *getView();

private:
	CPlotterWindow	*m_PlotterWindow;
};

#endif // PLOTTER_H
