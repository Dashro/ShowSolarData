//Plotter.cpp
#include "Plotter.h"
#include "PlotterWindow.h"

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
