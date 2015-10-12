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

void CPlotter::plottDataListGraph(QList<double> dataList, QList<double> timeStamps, QString name, QColor color)
{
	//======================================================================================================================================
	//convert dataLists
	QVector<double> xA(timeStamps.size()), yA(dataList.size());
	for (int i = 0; i < dataList.size(); i++)
	{
		xA[i] = timeStamps.at(i);
		yA[i] = dataList.at(i);

	}
	//======================================================================================================================================
	for (int i = 0; i < graphList.size(); i++)
	{
		if (!graphList.at(i).first.compare(name))
		{
			graphList.at(i).second->setData(xA, yA);
			graphList.at(i).second->rescaleAxes(true);
			m_PlotterWindow->ui.m_Plotter->replot();
			return;
		}
	}
	//======================================================================================================================================
	//setting up the new Graph
	QCPGraph *newGraph = m_PlotterWindow->ui.m_Plotter->addGraph();
	newGraph->setData(xA, yA);
	//newGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 0.7), QBrush(Qt::white), 3));
	newGraph->setPen(QPen(color, 1.5));
	newGraph->setName(name);

	graphList << QPair<QString, QCPGraph*>(name, newGraph);
	//======================================================================================================================================
	//Axis
	m_PlotterWindow->ui.m_Plotter->xAxis->setRange(xA[0], xA[timeStamps.size() - 2]);
	newGraph->rescaleAxes(true);
	m_PlotterWindow->ui.m_Plotter->replot();
}