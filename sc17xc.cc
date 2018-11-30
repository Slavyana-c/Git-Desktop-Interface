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

namespace{

class HelloWorldLabel : public QWidget{
public:
	HelloWorldLabel() : QWidget(){
		QVBoxLayout *layout = new QVBoxLayout(this);
		GITPP::REPO r;
		// h->addWidget(new QLabel("left"));
		// h->addWidget(new QLabel("right
		// QCheckBox *master = new QCheckBox("master", this);
		// QCheckBox *branch1 = new QCheckBox("branch1", this);

		// for (GITPP::BRANCH i : r.branches())
    // {
    //   //name->setText(QString::fromStdString(i.name()));
    //   //h->addWidget(new QLabel(i.value()));
		//
    //   QString branchName = QString::fromStdString(i);
    //   layout->addRow(new QLabel(branchName));
    // }

		// QLabel *label = new QLabel(this);
    // QHBoxLayout *layout1 = new QHBoxLayout();
    // label->setText("Branches");
		for(GITPP::BRANCH i : r.branches()){

			QString name = QString::fromStdString(i.name());
		  QCheckBox *box = new QCheckBox(name);
			box->setChecked (true);
		  //dynamic.setChecked (true);
		  layout->addWidget(box);
		}

				setLayout(layout);

	}
};

INSTALL_TAB(HelloWorldLabel, "Branches");
}

// GITPP::REPO r;
// std::cout << "found these branches\n";
//
// for(GITPP::BRANCH i : r.branches()){
// 	std::cout << i << "\n";
// }
//
// try{
// 	r.branches().create("new_branch");
// }catch(GITPP::EXCEPTION_INVALID const&){
// 	std::cout << "seems to exist already\n";
// }
//
// // careful, only works if index is sufficiently clean
// std::cout << "switching branches\n";
// r.checkout("new_branch");
// r.checkout("master");
// std::cout << "that worked, cleaning up\n";
//
// r.branches().erase("new_branch");
