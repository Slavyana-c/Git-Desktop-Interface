#include "globals.h"
#include <iostream>
#include <string>
#include <gitpp.h>
#include <QLabel>
#include <QString>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QObject>
#include <QSignalMapper>
#include <QMessageBox>


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
 			if (name == "master"){
				group->button(noOfBranches)->setChecked(true);
 			}

 		}
		connect(mapper, SIGNAL(mapped(QString)), this, SLOT(changePath(QString)));

		setLayout(layout);
	}
	private slots:
		void changePath(const QString& name){
			GITPP::REPO r;
			std::string file = name.toUtf8().constData();
			r.checkout(file);
			//this -> parentWidget ()-> update();
			//window->update();
			QMessageBox::information(this,"successful","switched to branch "+ name);
		}

	};

INSTALL_TAB(HelloWorldLabel, "Branches");
}

#include "sc17xc.moc"
