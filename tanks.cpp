#include "tanks.h"

#include <QPixmap>


tanks::~tanks(){}

void tanks::Move(const move_direction &dir){
    switch(dir){
    case move_direction::left:
        SetX(X()-Speed());
        break;
    case move_direction::right:
        SetX(X()+Speed());
        break;
    case move_direction::up:
        SetY(Y()-Speed());
        break;
    case move_direction::down :
        SetY(Y()+Speed());
        break;
    //case move_direction::stop:
        //qDebug()<<"stop";
    //    break;
    }
    ChangeCurrentTankImage(dir);
    tank_image->setGeometry(X(),Y(),Width(),Height());
}

void tanks::Attack(){
    CreateShell(parent);
    SetShellSpeed(3);
}


void tanks::CreateTank(QWidget *parent){
    tank_image = new QLabel(parent);
}

void tanks::CreateShell(QWidget *parent){
    shell_image = new QLabel(parent);
}

