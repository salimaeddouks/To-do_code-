#include "tasks.h"
#include "digitalclock.h"
#include "ui_tasks.h"
#include "dialog.h"
//#include "ui_dialog.h"
#include<QListWidgetItem>
#include <QIcon>
#include<QMessageBox>
#include<QListWidgetItem >
#include<QFile>
#include<QDebug>
#include<QTextStream>
#include<QDate>
#include<QFont>


#include<QIODevice>




#include <QString>
tasks::tasks(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tasks)
{
    ui->setupUi(this);
    write(filename);
    read(filename);

startTimer(1000);
 lifeTime =0;

 }







tasks::~tasks()
{
    delete ui;
}


void tasks::on_actionExit_triggered()
{

  QApplication::exit();
  write(this->filename);
  read(this->filename);
}




void tasks::on_actiontoday_task_triggered()
{
    Dialog f;

     auto reply =  f.exec();
     auto text = f.get();



     QString tmp{"C:\\Users\\UEMF\\Documents\\Tasks\\icon\\today task.png"};
     QIcon icon(tmp.arg(text));
     auto item = new QListWidgetItem(icon, text);

      item->setBackgroundColor(Qt::white);

    ui->listWidget1->addItem(item);

    write(this->filename);
    read(this->filename);
}

void tasks::on_actionpending_task_triggered()
{
    Dialog f;

     auto reply =  f.exec();

     auto text = f.get();

     QString tmp{"C:\\Users\\UEMF\\Documents\\Tasks\\icon\\pending task.png"};
     QIcon icon(tmp.arg(text));
     auto item = new QListWidgetItem(icon, text);

     item->setBackgroundColor(Qt::white);

ui->listWidget2->addItem(item);
write(this->filename);
read(this->filename);



}

void tasks::on_actionfinished_task_triggered()
{

    Dialog f;

     auto reply =  f.exec();
     auto text = f.get();
     QString tmp{"C:\\Users\\UEMF\\Documents\\Tasks\\icon\\finished task.png"};
     QIcon icon(tmp.arg(text));
     auto item = new QListWidgetItem(icon, text);





     item->setBackgroundColor(Qt::white);

ui->listWidget3->addItem(item);
write(this->filename);
read(this->filename);


}

void tasks::on_actionAlarme_triggered()
{
    write(this->filename);
    read(this->filename);
}



void tasks::on_Delete_clicked()
{
if(mnSelected1 != -1 ){
QListWidgetItem *it1 = ui->listWidget1->takeItem(mnSelected1);
delete it1;
ui->listWidget1->setCurrentRow(-1);
write(this->filename);
read(this->filename);
}
if(mnSelected2 != -1 ){
QListWidgetItem *it2 = ui->listWidget2->takeItem(mnSelected2);
delete it2;
ui->listWidget2->setCurrentRow(-1);
write(this->filename);
read(this->filename);
}
if(mnSelected3 != -1 ){
QListWidgetItem *it3 = ui->listWidget3->takeItem(mnSelected3);
delete it3;
ui->listWidget3->setCurrentRow(-1);
write(this->filename);
read(this->filename);

}


}




void tasks::on_Finished_clicked()
{

}


void tasks::on_listWidget1_currentRowChanged(int currentRow)
{
    mnSelected1=currentRow;
}

void tasks::on_listWidget2_currentRowChanged(int currentRow)
{
    mnSelected2=currentRow;
}

void tasks::on_listWidget3_currentRowChanged(int currentRow)
{
    mnSelected3=currentRow;
}

void tasks::on_isFinished_clicked()
{
    if(mnSelected1 != -1 ){
    QListWidgetItem *it1 = ui->listWidget1->takeItem(mnSelected1);

    ui->listWidget3->addItem(it1);
    write(this->filename);
    read(this->filename);
    }
    if(mnSelected2 != -1 ){
    QListWidgetItem *it2 = ui->listWidget2->takeItem(mnSelected2);

    ui->listWidget3->addItem(it2);
    write(this->filename);
    read(this->filename);
    }
    if(mnSelected3 != -1 ){
    QListWidgetItem *it3 = ui->listWidget3->takeItem(mnSelected3);

    ui->listWidget3->addItem(it3);
    write(this->filename);
    read(this->filename);

    }
}

void tasks::on_comboBox_1_activated(const QString &arg1)
{
    QListWidgetItem *item= ui->listWidget1->currentItem();
     if( ui->comboBox_1->currentText()=="red"){
    item->setBackgroundColor(Qt::red);
     }
     else if( ui->comboBox_1->currentText()=="Black"){
     item->setBackgroundColor(Qt::black);
     }
     else if( ui->comboBox_1->currentText()=="blue"){
     item->setBackgroundColor(Qt::blue);
     }
     else if( ui->comboBox_1->currentText()=="cyan"){
     item->setBackgroundColor(Qt::cyan);
     }
     else if( ui->comboBox_1->currentText()=="yellow"){
     item->setBackgroundColor(Qt::yellow);
     }
     else if( ui->comboBox_1->currentText()=="green"){
     item->setBackgroundColor(Qt::green);
     }
     else if( ui->comboBox_1->currentText()=="gray"){
     item->setBackgroundColor(Qt::gray);
     }



}

void  tasks:: write(QString myfile){


for(auto i=0;i<ui->listWidget1->count();i++){

    QFile file(this->filename);

   if(!file.open(QFile::WriteOnly|QFile::Text)){
       qDebug()<<" ";
       return;
   }

QTextStream out (& file);

for(auto i=0;i<ui->listWidget1->count();i++){
    out<< ui->listWidget1->item(i)->text();
    out<<"\n";
}



for(auto i=0;i<ui->listWidget2->count();i++){
out<< ui->listWidget2->item(i)->text();
    out<<"\n";

}
for(auto i=0;i<ui->listWidget3->count();i++){
 out<< ui->listWidget3->item(i)->text();
    out<<"\n";

}
out<<"\n";
file.flush();
file.close();
}
}


void  tasks:: read(QString myfile){

QFile file(filename);

if(!file.open(QFile::ReadOnly|QFile::Text)){
    qDebug()<<" ";
    return;

QTextStream in (& file);
while(!in.atEnd()){

    QString line=in.readLine();
    if(!line.isEmpty()){

        auto splitLine=line.split("\t");
        QString status=splitLine[3].remove(0,10);
        QRegExp exp("(\\d{2})[/](\\d{2})[/](\\d{4})");

       exp.indexIn(line);
       auto dateString=exp.capturedTexts()[0].trimmed();
       if(status=="No"){
           auto dateList= dateString.split("/");
           auto date= QDate(dateList.at(2).toInt(),dateList.at(1).toInt(),dateList.at(0).toInt());
           if(date==QDate::currentDate())
               ui->listWidget1->addItem(line);
           else if(date>QDate::currentDate())
               ui->listWidget2->addItem(line);
           else
               ui->listWidget3->addItem(line);
       }
       else
           ui->listWidget3->addItem(line);
    }
}
 file.close();
}

}


void tasks::on_comboBox_4_activated(const QString &arg1)
{
    QListWidgetItem *item= ui->listWidget2->currentItem();
     if( ui->comboBox_4->currentText()=="red"){
    item->setBackgroundColor(Qt::red);
     }
     else if( ui->comboBox_4->currentText()=="Black"){
     item->setBackgroundColor(Qt::black);
     }
     else if( ui->comboBox_4->currentText()=="blue"){
     item->setBackgroundColor(Qt::blue);
     }
     else if( ui->comboBox_4->currentText()=="cyan"){
     item->setBackgroundColor(Qt::cyan);
     }
     else if( ui->comboBox_4->currentText()=="yellow"){
     item->setBackgroundColor(Qt::yellow);
     }
     else if( ui->comboBox_4->currentText()=="green"){
     item->setBackgroundColor(Qt::green);
     }
     else if( ui->comboBox_4->currentText()=="gray"){
     item->setBackgroundColor(Qt::gray);
     }


}

void tasks::on_comboBox_7_activated(const QString &arg1)
{
    QListWidgetItem *item= ui->listWidget3->currentItem();
     if( ui->comboBox_7->currentText()=="red"){
    item->setBackgroundColor(Qt::red);
     }
     else if( ui->comboBox_7->currentText()=="Black"){
     item->setBackgroundColor(Qt::black);
     }
     else if( ui->comboBox_7->currentText()=="blue"){
     item->setBackgroundColor(Qt::blue);
     }
     else if( ui->comboBox_7->currentText()=="cyan"){
     item->setBackgroundColor(Qt::cyan);
     }
     else if( ui->comboBox_7->currentText()=="yellow"){
     item->setBackgroundColor(Qt::yellow);
     }
     else if( ui->comboBox_7->currentText()=="green"){
     item->setBackgroundColor(Qt::green);
     }
     else if( ui->comboBox_7->currentText()=="gray"){
     item->setBackgroundColor(Qt::gray);
     }


}





void tasks::on_pushButton_clicked()
{
    QFont font("Times",15 ,QFont::Bold) ;
    QListWidgetItem *item= ui->listWidget1->currentItem();
    item->setFont(font);
}

void tasks::on_pushButton_3_clicked()
{
    QFont font("Times",15 ,QFont::Bold) ;
    QListWidgetItem *item= ui->listWidget2->currentItem();
    item->setFont(font);

}

void tasks::on_pushButton_5_clicked()
{
    QFont font("Times",15 ,QFont::Bold) ;
    QListWidgetItem *item= ui->listWidget3->currentItem();
    item->setFont(font);

}

void tasks::on_pushButton_2_clicked()
{
     QListWidgetItem *item= ui->listWidget1->currentItem();
     item->setTextColor(Qt::red);
}

void tasks::on_pushButton_4_clicked()
{
    QListWidgetItem *item= ui->listWidget2->currentItem();
    item->setTextColor(Qt::red);
}

void tasks::on_pushButton_6_clicked()
{
    QListWidgetItem *item= ui->listWidget3->currentItem();
    item->setTextColor(Qt::red);
}
