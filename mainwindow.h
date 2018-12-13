#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gitpp.h"
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GITPP::REPO r;

public slots:
  void showPopup() {
			QMessageBox::information(this,"Sccess!","Changes saved successfully.");
  }
};

#endif // MAINWINDOW_H
