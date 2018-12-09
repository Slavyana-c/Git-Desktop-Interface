#pragma once

#include <QDialog>
#include <QString>

class QTabWidget;
class QDialogButtonBox;

class TabDialog : public QDialog
{
	Q_OBJECT

public:
	explicit TabDialog(QWidget *parent = 0);
	/*QString settabtext(QString input){
		tabtext = input;
	};
	QString gettabtext(){
		return tabtext;
	};*/

private:
	//QString tabtext;
	QTabWidget *_tabWidget;
	QDialogButtonBox *buttonBox;
};
