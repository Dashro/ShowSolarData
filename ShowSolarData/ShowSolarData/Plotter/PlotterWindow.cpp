//PlotterWindow.cpp
#include "PlotterWindow.h"
#include "Plotter.h"

CPlotterWindow::CPlotterWindow(CPlotter *m_Plotter_, QWidget *parent)
	: QWidget(parent), m_Plotter(m_Plotter_)
{
	ui.setupUi(this);
}

CPlotterWindow::~CPlotterWindow()
{

}
