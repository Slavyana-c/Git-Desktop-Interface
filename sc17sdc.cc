/********************************************************************************
** Configure Repository Tab (sc17sdc.cc)
**
** Created by: Slavyana Dianova Chervenkondeva - sc17sdc
********************************************************************************/

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

namespace
{

class HelloWorldLabel : public QWidget
{
public:
  HelloWorldLabel() : QWidget()
  {

    // Go through each configuration item and assign the widgets
    for (auto i : r.config())
    {
      QString name = QString::fromStdString(i.name());
      QString value = QString::fromStdString(i.value());
      formLayout->addRow(new QLabel(name), new QLineEdit(value));
    }

    // Add everything to the main layout
    mainLayout->addLayout(formLayout);
    buttonLayout->addWidget(saveButton);
    mainLayout->addLayout(buttonLayout);

    // Create button connections
    connect(saveButton, SIGNAL(clicked()), formLayout, SLOT(saveEdit()));
		connect(saveButton, &QPushButton::clicked, this, &HelloWorldLabel::showPopup);
    // Display the layout
    setLayout(mainLayout);
  }

private:
  QVBoxLayout *mainLayout = new QVBoxLayout();
  QFormLayout *formLayout = new MyFormLayout();
  QPushButton *saveButton = new QPushButton("Save");
  QHBoxLayout *buttonLayout = new QHBoxLayout();
  GITPP::REPO r;

public slots:
  void showPopup() {
			QMessageBox::information(this,"Success!","Changes saved successfully.");
  }

};

INSTALL_TAB(HelloWorldLabel, "Configure Repository");
}
