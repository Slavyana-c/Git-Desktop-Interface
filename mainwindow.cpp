#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gitpp.h"
#include <map>
#include <iostream>
#include <string.h>
#include <QScrollArea>
// #include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  GITPP::REPO r; // open the repo here to use it for opening
  // QScrollArea* scroll =new QScrollArea(); // for future development

  // count the commits
  int counter = 0;
  for (auto i : r.commits()) {
    counter ++;
    QString name1 = QString::fromStdString(i.signature().name()); // having this
    // code because of the Warning that variable 'i' has not been used
    // I know that it should be auto& i but gitpp.h does not allow it
  }
  // set up the ui
  ui->setupUi(this);
  // display the commits on the 'lcd'
  ui->lcdNumber->display(counter);

  // count the number of contributers
  // making a map that keps the developers name as a key and the number of
  // commits as a value
  std::map<std::string, int> name_map;
  for (auto i : r.commits()) {
    std::string key = i.signature().name(); // getting the developer's name
    if (name_map.count(key) == 0) {
      name_map.insert(std::pair<std::string, int>(key, 1));
    } else {
      int score = name_map[key];
      name_map[key] = ++score;
    }
  }

  // printing the developers
  int number_of_contributors = 0;
  std::map<std::string, int>::iterator i;
  int counter_for_position = 1;
  for (i = name_map.begin(); i != name_map.end(); i++) {
    QString name = QString::fromStdString(std::to_string(counter_for_position) +
    ". " + i->first);
    QLabel *label =  new QLabel();
    label->setText(name);
    ui->verticalLayout_2->addWidget(label);
    //  printing the commits of the corresponding name
    QString commits = QString::number(i->second);
    QLabel *label2 =  new QLabel();
    label2->setText(commits);
    ui->verticalLayout_4->addWidget(label2);

    counter_for_position++;
    number_of_contributors++;
  }
  ui->lcdNumber_2->display(number_of_contributors); // one of the team members
  // has a glitch when commiting and it counts her name thrice and also
  // some of the users have been made up

  // printing the e-mails
  int counter_for_position1 = 1;
  std::map<std::string, int>::iterator p;
  for (p = name_map.begin(); p != name_map.end(); p++) {
    for (auto i : r.commits()) {
      if (p->first == i.signature().name()) {
        QString email = QString::fromStdString(
        std::to_string(counter_for_position1) + ". " + i.signature().email());
        QLabel *label3 =  new QLabel();
        label3->setText(email);
        ui->verticalLayout_3->addWidget(label3);
        break;
      }
  }
  counter_for_position1++;
}
  // ui->horizontalLayout_4->addWidget(scroll);

  // // Search Show popup
  // connect(saveButton, SIGNAL(clicked()), formLayout, SLOT(saveEdit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
