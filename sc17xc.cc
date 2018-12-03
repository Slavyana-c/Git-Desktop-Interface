#include "globals.h"
#include <iostream>
#include <string>
#include <gitpp.h>
#include <QLabel>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QString>
#include <QStatusBar>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QAbstractButton>
#include <QButtonGroup>
#include <QRadioButton>

namespace{

class HelloWorldLabel : public QWidget{
public:
	HelloWorldLabel() : QWidget(){
		QVBoxLayout *layout = new QVBoxLayout(this);
		GITPP::REPO r;
    int noOfBranches = 0;

		QButtonGroup* group = new QButtonGroup();
		group->setExclusive(true);

 		for(GITPP::BRANCH i : r.branches()){
 			QString name = QString::fromStdString(i.name());
 			noOfBranches++;

			QRadioButton *button = new QRadioButton(name);
			layout->addWidget(button);
			group->addButton(button,noOfBranches);
			// connect(button,SIGNAL(troggled(bool),this,SLOT)
 			if (name == "master"){
				group->button(noOfBranches)->setChecked(true);
 			}

 		}

		setLayout(layout);
	}
};
INSTALL_TAB(HelloWorldLabel, "Branches");
}
