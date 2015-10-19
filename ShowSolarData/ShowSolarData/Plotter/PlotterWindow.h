//PlotterWindow.h
#ifndef PLOTTERWINDOW_H
#define PLOTTERWINDOW_H

#include <QWidget>
#include "ui_PlotterWindow.h"



class CPlotter;

class CPlotterWindow : public QWidget
{
	Q_OBJECT

public:
	CPlotterWindow(CPlotter *m_Plotter_, QWidget *parent = 0);
	~CPlotterWindow();

	Ui::CPlotterWindow ui;
private:
	CPlotter		*m_Plotter;


};

#endif // PLOTTERWINDOW_H
