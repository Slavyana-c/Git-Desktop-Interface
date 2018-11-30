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
    QHBoxLayout *layout = new QHBoxLayout();
		QFormLayout *layout1 = new QFormLayout;
    //label->setText("<u><b>These are your commits:</b></u>\n\n\n\n");

    GITPP::REPO r;
		for (auto i : r.commits()){

			//name->setText(QString::fromStdString(i.name()));
			//h->addWidget(new QLabel(i.value()));

			QString name = QString::fromStdString(i.signature().name());
			QString message = QString::fromStdString(i.message());
			//QString time1 = QString::fromStdString(i.time_seconds());
			//QString value = QString::fromStdString(i.name());
			layout1->addRow(new QLabel(name),new QLabel(message)/*,new QLabel(time1)*/);
		}
		setLayout(layout1);
		// for(auto i : r.commits()){
		//
		// 	h->addWidget( << i << " " << i.signature().name() <</* i.message()<<*/"\n");
		// }
		// setLayout(h);
	}
};




INSTALL_TAB(HelloWorldLabel, "List Commits");

}
