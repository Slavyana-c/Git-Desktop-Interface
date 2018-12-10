#include "globals.h"

#include <QLabel>
#include <QHBoxLayout>
#include "gitpp.h"
#include "window.h"
#include <QLabel>
#include <QString>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QFormLayout>
#include <QStackedWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>

#include "mainwindow.h"
#include "ui_mainwindow.h"
namespace{

class HelloWorldLabel : public QWidget{
public:
	HelloWorldLabel() : QWidget(){

		MainWindow* w = new MainWindow();
		mainLayout->addWidget(w);
		setLayout(mainLayout);
	}
	QHBoxLayout *mainLayout = new QHBoxLayout();

private:
  GITPP::REPO r;

};

INSTALL_TAB(HelloWorldLabel, "Statistics");
}
