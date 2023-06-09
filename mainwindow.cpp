#include "mainwindow.h"
#include "first_level.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QKeyEvent>



MainWindow::MainWindow(){
    setGeometry(600,200,800,600);

    QVBoxLayout *v_main_l = new QVBoxLayout(this); // главный Layout для стартовой формы
    this->setLayout(v_main_l);
    v_main_l->setAlignment(Qt::AlignCenter);

    QPushButton *but_start = new QPushButton("Старт");
    QPushButton *but_settings= new QPushButton("Настройки");
    QPushButton *but_exit = new QPushButton("Выход");

    but_start->setFixedSize(BUT_WIDTH,BUT_HEIGHT);
    but_settings->setFixedSize(BUT_WIDTH,BUT_HEIGHT);
    but_exit->setFixedSize(BUT_WIDTH,BUT_HEIGHT);


    v_main_l->addWidget(but_start);
    v_main_l->addWidget(but_settings);
    v_main_l->addWidget(but_exit);

    connect(but_start,SIGNAL(clicked()),this,SLOT(ButStartClicked()));
    connect(but_settings,SIGNAL(clicked()),this,SLOT(ButSettingsClicked()));
    connect(but_exit,SIGNAL(clicked()),this,SLOT(ButExitClicked()));

}

MainWindow::~MainWindow(){
    delete level;
}

void MainWindow::ButStartClicked(){
    level = new first_level();
}

void MainWindow::ButSettingsClicked(){
    qDebug()<<"SETTINGS CLICKED";
}

void MainWindow::ButExitClicked(){
    close();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
   // qDebug()<<"нажал!";
    //qDebug()<<QString::number(event->key());
   // if(Qt::Key_A == event->key())
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){

}



