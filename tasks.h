#ifndef TASKS_H
#define TASKS_H

#include <QMainWindow>
#include<QIcon>
#include <QListWidgetItem>
#include<QKeyEvent>
#include<QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class tasks; }
QT_END_NAMESPACE

class tasks : public QMainWindow
{
    Q_OBJECT

public:
    tasks(QWidget *parent = nullptr);
    ~tasks();
    void read(QString myfile);
     void write(QString myfile);
protected:
   // void timerEvent(QTimerEvent *e)override;
    //void keyPressEvent(QKeyEvent *e)override;


private slots:
    void on_actionExit_triggered();

    void on_actiontoday_task_triggered();

    void on_actionpending_task_triggered();

    void on_actionfinished_task_triggered();

    void on_actionAlarme_triggered();

    void on_Delete_clicked();

    void on_Finished_clicked();



    void on_listWidget1_currentRowChanged(int currentRow);

    void on_listWidget2_currentRowChanged(int currentRow);

    void on_listWidget3_currentRowChanged(int currentRow);

    void on_isFinished_clicked();











    //void on_pushButton_2_clicked();

    //void on_comboBox_activated(const QString &arg1);

    void on_comboBox_1_activated(const QString &arg1);



    void on_comboBox_4_activated(const QString &arg1);

    void on_comboBox_7_activated(const QString &arg1);




    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::tasks *ui;
    int mnSelected1= -1 ;
      int mnSelected2= -1 ;
        int mnSelected3= -1 ;
        int lifeTime;
        QString  filename="C:\\Users\\UEMF\\Desktop\\task.txt";


};
#endif // TASKS_H
