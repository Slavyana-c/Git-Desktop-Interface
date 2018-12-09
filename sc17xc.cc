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
#include <QObject>
#include <QSignalMapper>

namespace{

class HelloWorldLabel : public QWidget{
	Q_OBJECT
public:
	HelloWorldLabel() : QWidget(){
		QVBoxLayout *layout = new QVBoxLayout(this);
		GITPP::REPO r;
    int noOfBranches = 0;
		QSignalMapper *mapper = new QSignalMapper();

		QButtonGroup* group = new QButtonGroup();
		group->setExclusive(true);

 		for(GITPP::BRANCH i : r.branches()){
 			QString name = QString::fromStdString(i.name());
 			noOfBranches++;

			QRadioButton *button = new QRadioButton(name);
			layout->addWidget(button);
			group->addButton(button,noOfBranches);
			connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
			mapper->setMapping(button, button->text());
			//std::cout << "hi\n";
			//std::cout << button->text().toUtf8().constData();
			connect(mapper, SIGNAL(mapped(QString)), this, SLOT(changePath(QString)));
			//connect(button,&SIGNAL(clicked()),SLOT(changePath(button)));
 			if (name == "master"){
				group->button(noOfBranches)->setChecked(true);
 			}
 		}
		setLayout(layout);
	}
private slots:
	void  changePath(const QString& name){
		GITPP::REPO r;
		//std::string fileName;
		//QString name = button->objectName();
		std::string utf8_text = name.toUtf8().constData();
		//std::cout<<utf8_text;
		//r.checkout( utf8_text);
		std::string fileName = utf8_text;
		//sINSTALL_TAB(HelloWorldLabel, "List Commits");
	}

};

INSTALL_TAB(HelloWorldLabel, "Branches");
}

#include "sc17xc.moc"
