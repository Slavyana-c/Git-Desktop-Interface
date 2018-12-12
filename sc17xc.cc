/*******************************************************************************
** Branches Tab (sc17xc.cc)
**
** Created by: Xiangdi Chai
*******************************************************************************/

#include "globals.h"
#include "gitpp.h"
#include "window.h"
#include "sc17xc.h"

#include <iostream>
#include <string>
#include <QString>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QObject>
#include <QSignalMapper>
#include <QMessageBox>
#include <QSplitter>
#include <QLabel>
#include <QFormLayout>


namespace{

class HelloWorldLabel : public QWidget{
	Q_OBJECT
public:
	HelloWorldLabel() : QWidget(){
		left->setFrameShape( QFrame::StyledPanel);
		left->setFrameShadow(QFrame::Sunken);
    int noOfBranches = 0;

		group->setExclusive(true);

 		for(GITPP::BRANCH i : r.branches()){
 			QString name = QString::fromStdString(i.name());
 			noOfBranches++;

			QRadioButton *button = new QRadioButton(name);
			layoutLeft->addWidget(button);
			group->addButton(button,noOfBranches);
			connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
			mapper->setMapping(button, button->text());
 			if (name == "master"){
				group->button(noOfBranches)->setChecked(true);
				int x=0;
				layoutRight->addRow(new QLabel(""));
				layoutRight->addRow(new QLabel("Your commits in : "), new QLabel(name));
				layoutRight->addRow(new QLabel("______________________________________________________________"));
			  layoutRight->addRow(new QLabel(""));
				for (auto i : r.commits()){
					QString message = QString::fromStdString(i.message());
          QString author = QString::fromStdString(i.signature().name());
					layoutRight->addRow(new QLabel("Author: "),new QLabel(author));
					layoutRight->addRow(new QLabel("Commit message: "),new QLabel(message));
					layoutRight->addRow(new QLabel("______________________________________________________________"));
					x++;
					if(x==4){
						break;
				}
			 }
 			}

 		}
		connect(mapper, SIGNAL(mapped(QString)), this, SLOT(changePath(QString)));


		left->setLayout(layoutLeft);
		right->setLayout(layoutRight);
    splitter -> addWidget(left);
		splitter -> addWidget(right);
	}
private:
	QSplitter *splitter = new QSplitter (this);
	QVBoxLayout *layoutLeft = new QVBoxLayout();
	QFormLayout *layoutRight = new QFormLayout();
	QFrame *left = new QFrame();
	QWidget *right = new QWidget();
	GITPP::REPO r;
	QSignalMapper *mapper = new QSignalMapper();
	QButtonGroup* group = new QButtonGroup();



	void clearLayout(QFormLayout *layout){
    if (layout) {
        while(layout->count() > 0){
            QLayoutItem *item = layout->takeAt(0);
            QWidget* widget = item->widget();
            if(widget)
                delete widget;
            delete item;
        }
    }
}


private slots:
	void changePath(const QString& name){
		GITPP::REPO r;
		std::string file = name.toUtf8().constData();
		r.checkout(file);
		QMessageBox::information(this,"successful","switched to branch "+ name);
		clearLayout(layoutRight);
		layoutRight->addRow(new QLabel(""));
		layoutRight->addRow(new QLabel("Your commits in : "), new QLabel(name));
		layoutRight->addRow(new QLabel("______________________________________________________________"));
		layoutRight->addRow(new QLabel(""));
		int x=0;
		for (auto i : r.commits()){
			QString message = QString::fromStdString(i.message());
			QString author = QString::fromStdString(i.signature().name());
			layoutRight->addRow(new QLabel("Author: "),new QLabel(author));
			layoutRight->addRow(new QLabel("Commit message: "),new QLabel(message));
			layoutRight->addRow(new QLabel("______________________________________________________________"));
			x++;

			if(x==4){
				break;
		}
	}
 }
};

INSTALL_TAB(HelloWorldLabel, "Branches");
}

#include "sc17xc.moc"
