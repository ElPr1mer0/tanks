#include "shell.h"


shell::shell(int x, int y, flight_direction dir, int speed, QWidget *parent):dir(dir),speed(speed),parent(parent){
    qDebug()<<"shell()";
    setParent(parent);
    move(x,y);
    setVisible(true);

    SetImage();
    time_flight = new QTimer(parent);
    connect(time_flight,SIGNAL(timeout()),this,SLOT(ShellFlight()));
    time_flight->start(40);
}

void shell::ShellFlight(){
    switch(dir){
    case fl_up:
        move(x(),y()-Speed());
        break;
    case fl_down:
        move(x(),y()+Speed());
        break;
    case fl_left:
        move(x()-Speed(),y());
        break;
    case fl_right:
        move(x()+Speed(),y());
        break;
    }
    ++ms;
    if(ms > 50) delete this;
}


void shell::SetImage(){
    QString path;
    switch(dir){
    case fl_up:
        path = ":/shell/shell/up.png";
        break;
    case fl_down:
        path = ":/shell/shell/down.png";
        break;
    case fl_left:
        path = ":/shell/shell/left.png";
        break;
    case fl_right:
        path = ":/shell/shell/right.png";
        break;
    }
    QPixmap image;
    image.load(path);
    resize(image.size());
    setPixmap(image);
}
