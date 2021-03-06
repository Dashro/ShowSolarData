//PlotterWindow.cpp
#include "PlotterWindow.h"
#include "Plotter.h"

#include "EventFilter.h"


CPlotterWindow::CPlotterWindow(CPlotter *m_Plotter_, QWidget *parent)
	: QWidget(parent), m_Plotter(m_Plotter_)
{
	ui.setupUi(this);
	ui.m_Plotter->setBackground(QColor(0, 0, 0, 0));

	this->installEventFilter(CEventFilter::Signleton());
	ui.m_Plotter->installEventFilter(CEventFilter::Signleton());

	//======================================================================================================================================
	//Axis
	ui.m_Plotter->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	ui.m_Plotter->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	//======================================================================================================================================
	ui.m_Plotter->setLocale(QLocale(QLocale::German));
	ui.m_Plotter->xAxis->setTickLabelType(QCPAxis::ltDateTime);
	ui.m_Plotter->xAxis->setDateTimeFormat("HH:mm");
	//======================================================================================================================================
	//Grid
	ui.m_Plotter->xAxis->grid()->setPen(QPen(QColor(200, 200, 200, 200), 1, Qt::DotLine));
	ui.m_Plotter->yAxis->grid()->setPen(QPen(QColor(200, 200, 200, 200), 1, Qt::DotLine));
	//======================================================================================================================================
	//SubGrid
	QLinearGradient axisRectGradient;
	axisRectGradient.setStart(0, 0);
	axisRectGradient.setFinalStop(0, 350);
	axisRectGradient.setColorAt(0, QColor(100, 100, 100, 50));
	axisRectGradient.setColorAt(1, QColor(180, 180, 180, 200));
	ui.m_Plotter->xAxis->grid()->setSubGridPen(QPen(QBrush(axisRectGradient), 0.8, Qt::DotLine));
	ui.m_Plotter->yAxis->grid()->setSubGridPen(QPen(QBrush(axisRectGradient), 0.8, Qt::DotLine));
	ui.m_Plotter->xAxis->grid()->setSubGridVisible(true);
	ui.m_Plotter->yAxis->grid()->setSubGridVisible(true);
	//======================================================================================================================================
	//Legend 
	ui.m_Plotter->legend->setVisible(true);
	ui.m_Plotter->legend->setBrush(QBrush(QColor(255, 255, 255, 150)));
	ui.m_Plotter->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop); // make legend align in top left corner or axis rect
	//======================================================================================================================================

}

CPlotterWindow::~CPlotterWindow()
{

}
