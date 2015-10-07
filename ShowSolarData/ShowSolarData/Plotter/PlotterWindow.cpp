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


//static int index = 0;

//QLocale german(QLocale::German);

//QStringList dataList = m_SolarData->getCollum(headerList.indexOf(data));
//QVector<double> x(dataList.size()), y(dataList.size());

//for (int i = 0; i < dataList.size(); i++)
//{
//	x[i] = toTime_t(timeStamps.at(i));

//}
//   double buffer1 = 0;

//   QVector<double> buffer(smoothingFactor);

//for (int i = 0; i < dataList.size() - smoothingFactor; i++)
//{
//	for (int k = 0; k < smoothingFactor; k++)
//	{
//		buffer[k] = german.toDouble(dataList.at(i + k));
//		buffer1 += german.toDouble(dataList.at(i + k));
//	}
//	buffer1 = buffer1 / smoothingFactor;
//	y[i] = buffer1;
//	buffer1 = 0;
//}

//for (int i = 0; i < smoothingFactor; i++)
//{
//	y[(dataList.size() - (smoothingFactor)) + i] = buffer.at(i);
//}




//ui.m_Plot->setLocale(QLocale(QLocale::German));

//double now = QDateTime::currentDateTime().toTime_t();

//ui.m_Plot->addGraph();
//ui.m_Plot->graph(index)->setPen(QPen(QColor(getRandomNo(0, 250), getRandomNo(0, 250), getRandomNo(0, 250), 255)));
//ui.m_Plot->graph(index)->setBrush(QBrush(QColor(getRandomNo(0, 250), getRandomNo(0, 250), getRandomNo(0, 250), 20)));

//ui.m_Plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
//ui.m_Plot->xAxis->setDateTimeFormat("HH:mm:ss");
//ui.m_Plot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
//ui.m_Plot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
//ui.m_Plot->xAxis2->setVisible(true);
//ui.m_Plot->yAxis2->setVisible(true);
//ui.m_Plot->xAxis2->setTicks(false);
//ui.m_Plot->yAxis2->setTicks(false);
//ui.m_Plot->xAxis2->setTickLabels(false);
//ui.m_Plot->yAxis2->setTickLabels(false);
//// set axis ranges to show all data:
//ui.m_Plot->xAxis->setRange(x[0], x[dataList.size() - 1]);
////ui.m_Plot->yAxis->setRange(0, 60);
//// show legend:
//ui.m_Plot->graph(index)->setData(x, y);
//ui.m_Plot->graph(index)->rescaleAxes(true);
//ui.m_Plot->legend->setVisible(true);

//index++;

//ui.m_Plot->replot();