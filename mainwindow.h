#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gitpp.h"
#include <QMainWindow>

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
};

#endif // MAINWINDOW_H
