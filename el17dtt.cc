#include "globals.h"

#include <QLabel>
#include <QHBoxLayout>

namespace{

class HelloWorldLabel : public QWidget{
public:
	HelloWorldLabel() : QWidget(){
		QHBoxLayout* h=new QHBoxLayout;

		h->addWidget(new QLabel("left"));
		h->addWidget(new QLabel("right"));
		//h->setText("Config repository:");
		setLayout(h);

		QLabel *label = new QLabel(this);
    QHBoxLayout *layout = new QHBoxLayout();
    label->setText("Config repo");

	}
};
INSTALL_TAB(HelloWorldLabel, "Statistics");
}
