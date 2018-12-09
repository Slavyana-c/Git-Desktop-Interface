// Window subclassing example - class implementation
// (NDE, 2016-09-08)

#include "window.h"
#include "tabs.h"
#include "globals.h"

#include <QHBoxLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QApplication>
#include <QCoreApplication>
#include <QSize>
#include <QDesktopWidget>

HelloWindow::HelloWindow()
{
	createWindowContent();
	createMenuAndStatusBar();
	pQMainWndow = this;
	dark();
}


void HelloWindow::createWindowContent()
{
	// Create layout
	//QString tabname = HelloWorldLabel;
	QCoreApplication::setApplicationName("GitLab");
	TabDialog* tabs=new TabDialog();

	//TabDialog

	QHBoxLayout* layout=new QHBoxLayout();

	// transfer ownership?
	layout->addWidget(tabs);

	// Put layout in the middle of the window
	_mainWidget = new QWidget();
	_mainWidget->setLayout(layout);
	_mainWidget->setMinimumSize(508, 0);

	QRect resolution = QApplication::desktop()->screenGeometry();
	_mainWidget->setMaximumSize(resolution.width(), resolution.height());

	setCentralWidget(_mainWidget);
}


void HelloWindow::createMenuAndStatusBar()
{
	QMenu* fileMenu = menuBar()->addMenu("&File");

	QAction* open = fileMenu->addAction("&Open");
	open->setShortcuts(QKeySequence::Open);
	open->setStatusTip("Open an existing file");

	QAction* quit = fileMenu->addAction("Quit");
	quit->setShortcuts(QKeySequence::Quit);
	quit->setStatusTip("Quit the application");

	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}


void HelloWindow::dark()
{
	_mainWidget->setStyleSheet("background-color: #ADD8E6");
}
