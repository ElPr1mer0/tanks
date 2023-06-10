#include "shell.h"


shell::shell(flight_direction dir, int speed, QWidget *parent):dir(dir),speed(speed),parent(parent){
    setParent(parent);
    SetImage();
    time_flight = new QTimer(parent);
    connect(time_flight,SIGNAL(timeout()),this,SLOT(ShellFlight()));
    time_flight->start(500);
}

void shell::ShellFlight(){
    switch(dir){
    case fl_up:
        //SetY(Y()-Speed());
        //setGeometry(x(),y()-Speed(),width(),height());
        move(x(),y()-Speed());
        break;
    case fl_down:
        //SetY(Y()+Speed());
        //setGeometry(x(),y()+Speed(),width(),height());
        move(x(),y()+Speed());
        break;
    case fl_left:
        //SetX(X()-Speed());
        move(x()-Speed(),y());
        break;
    case fl_right:
        //SetX(X()+Speed());
        move(x()+Speed(),y());
        break;
    }
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

    setPixmap(path);
    //setGeometry()
    //SetHeight(height());
    //SetWidth(width());
}
