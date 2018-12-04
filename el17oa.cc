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


namespace{

class HelloWorldLabel : public QWidget{


public:
	HelloWorldLabel() : QWidget(){
		QHBoxLayout* h = new QHBoxLayout;
		QLabel *label = new QLabel(this);
		QHBoxLayout *buttonLayout = new QHBoxLayout();

		QFormLayout* layout1 = new QFormLayout;
		QPushButton *searchButton = new QPushButton("Search Commits!!");

		QFormLayout* search = new QFormLayout;




		label->setText("<u>Your commits:</u>\n");
		layout1->addRow(new QLabel(" "));
		layout1->addRow(new QLabel("====\t\t\t\t\t======"));
		layout1->addRow(new QLabel("Name\t\t\t\t\tComment"));
		layout1->addRow(new QLabel("====\t\t\t\t\t======"));


    search->addRow(new QLabel(" "));
		search->addRow(new QLineEdit("search..."));
		search->addWidget(searchButton);


    connect(searchButton, SIGNAL(clicked()), search, SLOT(showEdit()));


    GITPP::REPO r;
		for (auto i : r.commits()){

			layout1->addRow(new QLabel(" "));

			QString name = QString::fromStdString(i.signature().name());
			QString message = QString::fromStdString(i.message());


			layout1->addRow(new QLabel(name),new QLabel(message));

			//layout1->addRow(new QLabel(id1));
		}
		h->addLayout(layout1);
		h->addLayout(search);
		setLayout(h);

	}
};




INSTALL_TAB(HelloWorldLabel, "List Commits");

}
