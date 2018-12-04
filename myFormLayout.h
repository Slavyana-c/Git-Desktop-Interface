#include <QFormLayout>
#include <iostream>
#include "gitpp.h"
#include <QLineEdit>
#include <QLayoutItem>

class MyLayout : public QFormLayout {
	Q_OBJECT


public slots:
void saveEdit() {

    GITPP::REPO r;

    QList<QLineEdit *> allLineEdits = this->findChildren<QLineEdit *>();  //Return all LineEdit controls that have been created.
    std::cout << "/* message */" << this->count() <<"\n";


    for (int i = 0; i < this->count(); ++i)
  {
  QWidget *widget = this->itemAt(i)->widget();
  if (widget != NULL)
  {
    std::string type = widget->metaObject()->className();

    if(type == "QLineEdit")
    {
      QLineEdit *edited =  qobject_cast<QLineEdit *>(widget);

      std::cout<<type<<"\n";
      std::cout<< edited->text().toStdString()<<"\n";
    }
    //widget->setVisible(false);
  }
  else
  {
    // You may want to recurse, or perform different actions on layouts.
    // See gridLayout->itemAt(i)->layout()
  }
}

        if (allLineEdits.count() > 0){
            for (int i =0; i < allLineEdits.count(); i++)
            {
                QString myValue = allLineEdits.at(i)->text();
                std::string text = myValue.toUtf8().constData();
                std::cout<< text;
            }
        }
 }

};
