#include "globals.h"
#include "gitpp.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QLineEdit>


namespace{

class HelloWorldLabel : public QWidget{


public:
	HelloWorldLabel() : QWidget(){
		//QHBoxLayout* h=new QHBoxLayout;
		QLabel *label = new QLabel(this);
    //QHBoxLayout *layout = new QHBoxLayout();
		QFormLayout *layout1 = new QFormLayout;
    // label->setText("<u><b>These are your commits:</b></u>");
		//label->setText("\n");

		label->setText("<u>Your commits:</u>\n");
		layout1->addRow(new QLabel(" "));
		layout1->addRow(new QLabel("====\t\t\t\t\t======"));
		layout1->addRow(new QLabel("Name\t\t\t\t\tComment"));
		layout1->addRow(new QLabel("====\t\t\t\t\t======"));

		
    GITPP::REPO r;
		for (auto i : r.commits()){



			// label->setText("<u>Your commits:</u>");
			// layout1->addRow(new QLabel("Name\t\tCommment"));
			layout1->addRow(new QLabel(" "));

			QString name = QString::fromStdString(i.signature().name());
			QString message = QString::fromStdString(i.message());


			layout1->addRow(new QLabel(name),new QLabel(message));

			//layout1->addRow(new QLabel(id1));
		}

		setLayout(layout1);

	}
};




INSTALL_TAB(HelloWorldLabel, "List Commits");

}
