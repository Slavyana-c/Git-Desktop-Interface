// Window subclassing example - class implementation
// (NDE, 2016-09-08)

#include "window.h"
#include "tabs.h"

//#include <QtWidgets> // qt5 only?
#include <QHBoxLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QApplication>


HelloWindow::HelloWindow()
{
	createWindowContent();
	createMenuAndStatusBar();
}


void HelloWindow::createWindowContent()
{
	// Create layout

	TabDialog* tabs=new TabDialog();

	QHBoxLayout* layout=new QHBoxLayout();
	layout->addStretch();

	// transfer ownership?
	layout->addWidget(tabs);
	layout->addStretch();

	// Put layout in the middle of the window
	_mainWidget = new QWidget();

	setMinimumHeight(650);
	_mainWidget->setLayout(layout);

	//_mainWidget->setStyleSheet("background-color: #00FF00");

	setCentralWidget(_mainWidget);
}


void HelloWindow::createMenuAndStatusBar()
{
	//statusBar()->showMessage("Program developed and owned by Omar");

	QMenu* fileMenu = menuBar()->addMenu("&File");

	QAction* open = fileMenu->addAction("&Open");
	open->setShortcuts(QKeySequence::Open);
	open->setStatusTip("Open an existing file");

	QAction* quit = fileMenu->addAction("Quit");
	quit->setShortcuts(QKeySequence::Quit);
	quit->setStatusTip("Quit the application");

	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
