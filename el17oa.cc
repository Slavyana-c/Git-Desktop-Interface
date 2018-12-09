#include "globals.h"
#include "gitpp.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <QSlider>






namespace{

class HelloWorldLabel : public QWidget{


public:
	HelloWorldLabel() : QWidget(){
		QHBoxLayout* h = new QHBoxLayout;
		//QHBoxLayout *buttonLayout = new QHBoxLayout();

		QFormLayout* layout1 = new QFormLayout;
		QPushButton *searchButton = new QPushButton("Search Commits!!");

		QFormLayout* search = new QFormLayout;



    layout1->addRow(new QLabel("<u><b>Commits:</b></u>"));
		layout1->addRow(new QLabel(" "));


    search->addRow(new QLabel(" "));
		search->addRow(new QLineEdit(""));
		search->addWidget(searchButton);
		searchButton->setIcon(QIcon("searchIcon.png"));


    connect(searchButton, SIGNAL(clicked()), search, SLOT(showEdit()));


    int x=0,counter=0;

    GITPP::REPO r;

    for (auto i : r.commits()){
			QString name1 = QString::fromStdString(i.signature().name());
			counter++;
		}

		for (auto i : r.commits()){



			QString name = QString::fromStdString(i.signature().name());
			QString message = QString::fromStdString(i.message());
			QString time1 = QString::fromStdString(i.time());

      
      layout1->addRow(new QLabel("Author: "),new QLabel(name));
			layout1->addRow(new QLabel("Commit message: "),new QLabel(message));
			layout1->addRow(new QLabel("Time: "),new QLabel(time1));
			layout1->addRow(new QLabel("************************************************"));



			x++;

			if(x==5){
				break;
			}

		}

		layout1->addRow(new QLabel("Total number of commits:"),new QLabel(QString::number(counter)));
    h->addStretch();
		h->addLayout(layout1);
		h->addLayout(search);
		setLayout(h);

	}
};




INSTALL_TAB(HelloWorldLabel, "List Commits");



}
