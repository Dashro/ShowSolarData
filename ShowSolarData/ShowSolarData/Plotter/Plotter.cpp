//Plotter.cpp
#include "Plotter.h"
#include "PlotterWindow.h"
#include "qvector.h"

CPlotter::CPlotter(QObject *parent)
	: QObject(parent)
{
	m_PlotterWindow = new CPlotterWindow(this);
}

CPlotter::~CPlotter()
{

}

QWidget* CPlotter::getView()
{
	return m_PlotterWindow->window();
}

void CPlotter::plottDataListGraph(QStringList dataList, QList<double> timeStamps)
{
	QLocale german(QLocale::German);
	//======================================================================================================================================
	//convert dataLists
	QVector<double> xA(timeStamps.size()), yA(dataList.size());
	for (int i = 0; i < timeStamps.size(); i++)
	{
		xA[i] = timeStamps.at(i);
	}
	for (int i = 0; i < dataList.size(); i++)
	{
		yA[i] = german.toDouble(dataList.at(i));
	}
	//======================================================================================================================================
	//setting up the Graph
	QCPGraph *newGraph = m_PlotterWindow->ui.m_Plotter->addGraph();
	newGraph->setData(xA, yA);
	newGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1), QBrush(Qt::white), 5));
	newGraph->setPen(QPen(QColor(120, 120, 120), 2));
	//======================================================================================================================================
	//Axis
	m_PlotterWindow->ui.m_Plotter->xAxis->setRange(xA[0], xA[timeStamps.size() - 1]);
	newGraph->rescaleAxes(true);
	m_PlotterWindow->ui.m_Plotter->replot();
}