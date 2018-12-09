#include <QFormLayout>
#include <iostream>
#include "gitpp.h"
#include <QLineEdit>
#include <QLayoutItem>
#include <QLabel>

class MyLayout : public QFormLayout {
	Q_OBJECT


	public slots:
	void saveEdit() {

		GITPP::REPO r;
		std::string name = "";
		std::string value = "";
		//QList<QLineEdit *> allLineEdits = this->findChildren<QLineEdit *>();  //Return all LineEdit controls that have been created.
		std::cout << "/* message */" << this->count() <<"\n";


		for (int i = 0; i < this->count(); ++i)
		{
			QWidget *widget = this->itemAt(i)->widget();
			if (widget != NULL)
			{
				std::string type = widget->metaObject()->className();

				if(type == "QLineEdit")
				{
					QLineEdit *valueLineEdit =  qobject_cast<QLineEdit *>(widget);
					value = valueLineEdit->text().toStdString();
					std::cout<< value<<"\n";
					saveConfig(name, value);
				}
				else
				{
					QLabel *nameLabel =  qobject_cast<QLabel*>(widget);
					name = nameLabel->text().toStdString();
					std::cout<<name<<" ";
				}


				//widget->setVisible(false);
			}
			else
			{
				// You may want to recurse, or perform different actions on layouts.
				// See gridLayout->itemAt(i)->layout()
			}
		}

	}

private:
		void saveConfig(std::string name, std::string value) {
		GITPP::REPO r;
		auto c = r.config();
		c.create(name);
		c[name] = value;

	}

};
