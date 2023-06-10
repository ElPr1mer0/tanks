#include "tanks.h"

#include <QPixmap>


tanks::tanks(int x, int y, QWidget *parent):parent(parent){
    setParent(parent);
    move(x,y);
}

tanks::~tanks(){}

void tanks::Move(const move_direction &dir){
    switch(dir){
    case move_direction::left:
        move(x()-Speed(),y());
        break;
    case move_direction::right:
        move(x()+Speed(),y());
        break;
    case move_direction::up:
        move(x(),y()-Speed());
        break;
    case move_direction::down :
        move(x(),y()+Speed());
        break;
    }
    ChangeCurrentTankImage(dir);
}

void tanks::Attack(){
   // CreateShell(parent);
  //  SetShellSpeed(3);
}
