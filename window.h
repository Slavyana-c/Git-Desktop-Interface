#pragma once

#include <QMainWindow>

class QLabel;
class QWidget;

class HelloWindow: public QMainWindow {
Q_OBJECT;
public:
	HelloWindow();

public slots:
	void dark();

private:
	void createWindowContent();
	void createMenuAndStatusBar();
	//void centerAndResize();

private: // widgets we own
	QLabel* _label;
	QWidget* _mainWidget;
};
