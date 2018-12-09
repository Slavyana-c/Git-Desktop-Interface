/********************************************************************************
** Form Layout for the Configure Repository Tab (myFormLayout.h)
**
** Created by: Slavyana Dianova Chervenkondeva - sc17sdc
********************************************************************************/

#include <QFormLayout>
#include <iostream>
#include "gitpp.h"
#include <QLineEdit>
#include <QLayoutItem>
#include <QLabel>
#include <QMessageBox>

class MyFormLayout : public QFormLayout
{
	Q_OBJECT
  public slots:
  	// Executed when the "Save" button is selected
	void saveEdit()
	{
		// Go through each item in the layout
		for (int i = 0; i < this->count(); ++i)
		{
			QWidget *widget = this->itemAt(i)->widget();
			if (widget != NULL)
			{
				std::string type = widget->metaObject()->className();

				// Check if the widget is the value of the configuration
				if (type == "QLineEdit")
				{
					QLineEdit *valueLineEdit = qobject_cast<QLineEdit *>(widget);
					value = valueLineEdit->text().toStdString();
					std::cout << value << "\n";
					saveConfig(name, value);
				}

				// Check if the widget is the name of the configuration
				else
				{
					QLabel *nameLabel = qobject_cast<QLabel *>(widget);
					name = nameLabel->text().toStdString();
					std::cout << name << " ";
				}
			}
		}
	}

  private:
	// Saves the configurations
	void saveConfig(std::string name, std::string value)
	{
		GITPP::REPO r;
		auto c = r.config();
		c.create(name);
		c[name] = value;
	}

	GITPP::REPO r;
	std::string name = "";
	std::string value = "";
};
