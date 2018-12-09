#include "globals.h"
#include "tabs.h"
#include "window.h"

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QPalette>

namespace{

class HelloWorldLabel : public QWidget{
	public:
		HelloWorldLabel() : QWidget(){
			QHBoxLayout* h = new QHBoxLayout;
			QHBoxLayout* fontlabel = new QHBoxLayout;
			QVBoxLayout* v1 = new QVBoxLayout;
			QVBoxLayout* v2 = new QVBoxLayout;

			QCheckBox* darktheme = new QCheckBox("- Dark Theme", this);

			connect(darktheme, SIGNAL(clicked(bool)), pQMainWndow, SLOT(HelloWindow::dark()));

			QRadioButton* normal = new QRadioButton("Normal", this);
			QRadioButton* colourful = new QRadioButton("Colourful", this);
			QRadioButton* colourblind = new QRadioButton("Colour Blind", this);

			QCheckBox* activetab = new QCheckBox("- Active Tabs Bold", this);
			QSpinBox* fontsize = new QSpinBox();
			fontsize->setRange(5, 50);
			fontsize->setValue(14);

			v1->addWidget(darktheme);
			v1->addWidget(new QLabel("Themes"));
			v1->addWidget(normal);
			v1->addWidget(colourful);
			v1->addWidget(colourblind);

			activetab->setChecked(1);
			v2->addWidget(activetab);
			fontlabel->addWidget(fontsize);
			fontlabel->addWidget(new QLabel("- Font Size"));
			v2->addLayout(fontlabel);

			h->addLayout(v1);
			h->addLayout(v2);

			setLayout(h);

			//IF DARK THEME IS ACTIVE
			//https://wiki.qt.io/How_to_Change_the_Background_Color_of_QWidget
			/*if(darktheme -> isChecked()){
				//TODO SET INACTIVE TABS TO #212121
				//HelloWindow(_mainWidget)->setStyleSheet("background-color: #424242");
			} else {
			//TODO SET INACTIVE TABS TO #F5F5F5
				//HelloWindow(_mainWidget)->setStyleSheet("background-color: #FAFAFA");
			}*/

			/*IF THEME PROFILES
			if(normal->isChecked()){
				//HelloWindow(_mainWidget)->setStyleSheet("background-color: red;");
			} else if(colourful->isChecked()){

			} else {

			}*/

			//IF ACTIVETAB IS CHECKED
		}
};



INSTALL_TAB(HelloWorldLabel, "Settings");
}
