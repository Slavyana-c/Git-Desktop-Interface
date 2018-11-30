#include "globals.h"
#include "gitpp.h"
#include "window.h"

#include <QLabel>
#include <QString>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QFormLayout>


namespace{

class HelloWorldLabel : public QWidget{
public:
	HelloWorldLabel() : QWidget(){

		// QHBoxLayout* h=new QHBoxLayout;
    QFormLayout *layout = new QFormLayout;

    GITPP::REPO r;
    for (auto i : r.config())
    {
      //name->setText(QString::fromStdString(i.name()));
      //h->addWidget(new QLabel(i.value()));
    
      QString name = QString::fromStdString(i.name());
      QString value = QString::fromStdString(i.value());
      layout->addRow(new QLabel(name), new QLabel(value));
    }

		//h->setText("Config repository:");
		//setLayout(h);

  //  layout->addRow(new QLabel(tr("Line 1:")), new QLabel(tr("Line 1:")));
    setLayout(layout);

		// QLabel *label = new QLabel(this);
    // QHBoxLayout *layout = new QHBoxLayout();
    // label->setText("Config repo");
    //HelloWindow::statusBar()->showMessage("Program developed and owned by ...");

	}
};

INSTALL_TAB(HelloWorldLabel, "Configure Repository");

}
