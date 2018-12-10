#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gitpp.h"
#include <map>
#include <iostream>
#include <string.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  GITPP::REPO r;

  // count the commits
  int counter = 0;
  for (auto i : r.commits()) {
    counter ++;
  }
  // set up the ui
  ui->setupUi(this);
  //QString number_of_commits = QString::number(counter);
  ui->lcdNumber->display(counter);

  // count the number of contributers
  std::map<std::string, int> name_map;
  for (auto i : r.commits()) {
    std::string key = i.signature().name();
    if (name_map.count(key) == 0) {
      name_map.insert(std::pair<std::string, int>(key, 1));
    } else {
      int score = name_map[key];
      name_map[key] = ++score;
    }
  }
  int number_of_contributors = 0;
  std::map<std::string, int>::iterator i;
  // iterate through
  int counter_for_position = 1;
  for (i = name_map.begin(); i != name_map.end(); i++) {
    QString name = QString::fromStdString(std::to_string(counter_for_position) +
    ". " + i->first);
    QLabel *label =  new QLabel();
    label->setText(name);
    ui->verticalLayout_2->addWidget(label);

    QString commits = QString::number(i->second);
    QLabel *label2 =  new QLabel();
    label2->setText(commits);
    ui->verticalLayout_4->addWidget(label2);

    counter_for_position++;
    number_of_contributors++;
  }
  ui->lcdNumber_2->display(number_of_contributors-3); // one of the team members
  // has a glitch when commiting and it counts her name thrice

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
}

MainWindow::~MainWindow()
{
    delete ui;
}
