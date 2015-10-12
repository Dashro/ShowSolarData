//Plotter.h
#ifndef PLOTTER_H
#define PLOTTER_H

#include <QObject>
#include <QtCore>

#include "Customplot/qcustomplot.h"

class CPlotterWindow;

class CPlotter : public QObject
{
	Q_OBJECT

public:
	CPlotter(QObject *parent);
	~CPlotter();

	QWidget *getView();

	void plottDataListGraph(QList<double> dataList, QList<double> timeStamps, QString name, QColor color);

private:
	CPlotterWindow	*m_PlotterWindow;

	QList < QPair < QString, QCPGraph*> > graphList;
};

#endif // PLOTTER_H
