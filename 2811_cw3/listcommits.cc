#include "globals.h"

#include <QLabel>

namespace{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
		setText("These are your commits:");
	}
};

INSTALL_TAB(HelloWorldLabel, "List Commits");
//INSTALL_TAB(HelloWorldLabel, "config");

}
