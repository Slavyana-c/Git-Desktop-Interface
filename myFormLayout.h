#include <QFormLayout>
#include <iostream>
class MyLayout : public QFormLayout {
	Q_OBJECT
public slots:
void showEdit() {

   //FormLayout *tempLayout = new FormLayout();
   //*tempLayout = *mainLayout
   std::cout << "/* message */" <<'\n';
   // QFormLayout *formLayout = new QFormLayout();
   // delete mainLayout;
   // qDeleteAll(this->children());
   //
   // GITPP::REPO r;
   //
   // for (auto i : r.config())
   // {
   // 	QString name = QString::fromStdString(i.name());
   // 	QString value = QString::fromStdString(i.value());
     //formLayout->addRow(new QLabel(name), new QTextEdit(value));
   //}

   // mainLayout->addLayout(formLayout);
   // setLayout(mainLayout);

   // QPushButton *button1 = new QPushButton("Edit");
   //
   // QHBoxLayout *buttonLayout = new QHBoxLayout();
   // buttonLayout->addWidget(button1);
   //
   //
   // 		setLayout(buttonLayout);

 }

};
