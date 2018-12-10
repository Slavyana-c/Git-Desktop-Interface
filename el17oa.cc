#include "globals.h"
#include "gitpp.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <QSlider>
#include <QWidget>
#include <QScrollArea>




namespace{

class HelloWorldLabel : public QWidget{


public:
	HelloWorldLabel() : QWidget(){
		QVBoxLayout* w = new QVBoxLayout();
		QScrollArea* scroll =new QScrollArea();
		QWidget* tmp = new QWidget();
		QVBoxLayout* h = new QVBoxLayout(tmp);

		 QFormLayout* layout1 = new QFormLayout;
		 QPushButton *searchButton = new QPushButton("Search Commits!!");

		QFormLayout* search = new QFormLayout;


    w->addWidget(new QLabel("<u><b>Commits:</b></u>"));



    search->addRow(new QLabel(" "));
		h->addWidget(searchButton);
		h->addWidget(new QLineEdit("search.."));
		searchButton->setIcon(QIcon("searchIcon.png"));




    int x=0,counter=0;

    GITPP::REPO r;

    for (auto i : r.commits()){
			QString name1 = QString::fromStdString(i.signature().name());
			counter++;
		}

    layout1->addRow(new QLabel("Total number of commits:"),new QLabel(QString::number(counter)));
		layout1->addRow(new QLabel("=================="));
		for (auto i : r.commits()){



			QString name = QString::fromStdString(i.signature().name());
			QString message = QString::fromStdString(i.message());
			QString time1 = QString::fromStdString(i.time());


      layout1->addRow(new QLabel("Author: "),new QLabel(name));
			layout1->addRow(new QLabel("Commit message: "),new QLabel(message));
			layout1->addRow(new QLabel("Time: "),new QLabel(time1));
			layout1->addRow(new QLabel("****************************************************"));

			x++;
		}

		
    scroll->setWidget(tmp);
		scroll->setWidgetResizable(true);
		h->addLayout(layout1);
		h->addLayout(search);
		w->addWidget(scroll);
		setLayout(w);

	}
};



INSTALL_TAB(HelloWorldLabel, "List Commits");



}
