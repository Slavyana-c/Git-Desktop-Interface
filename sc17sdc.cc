#include "globals.h"
#include "gitpp.h"
#include "window.h"

#include <QLabel>
#include <QString>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QFormLayout>
#include <QStackedWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>

#include "myFormLayout.h"

namespace{

class HelloWorldLabel : public QWidget{
public:
	HelloWorldLabel() : QWidget() {

    QFormLayout *formLayout = new MyLayout();
		QPushButton *button1 = new QPushButton("Save");
		QHBoxLayout *buttonLayout = new QHBoxLayout();

    GITPP::REPO r;
    for (auto i : r.config())
    {
      QString name = QString::fromStdString(i.name());
      QString value = QString::fromStdString(i.value());
      formLayout->addRow(new QLabel(name), new QLineEdit(value));
    }

		mainLayout->addLayout(formLayout);

		buttonLayout->addWidget(button1);

		mainLayout->addLayout(buttonLayout);

		connect(button1, SIGNAL(clicked()), formLayout, SLOT(saveEdit()));

    setLayout(mainLayout);

	}

QVBoxLayout *mainLayout = new QVBoxLayout();



public slots:

};


INSTALL_TAB(HelloWorldLabel, "Configure Repository");


}
