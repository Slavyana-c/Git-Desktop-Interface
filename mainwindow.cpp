#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gitpp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  GITPP::REPO r;

  // count the commits
  int counter = 0;
  for (auto i : r.commits())
  {
    counter ++;
  }
  // set up the ui
  ui->setupUi(this);
  //QString number_of_commits = QString::number(counter);
  ui->lcdNumber->display(counter);

}

// void count_commits() {
 //}
MainWindow::~MainWindow()
{
    delete ui;
}
