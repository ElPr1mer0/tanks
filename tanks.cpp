#include "tanks.h"

#include <QPixmap>
//#include <QDegub>


tanks::tanks(int x, int y, QWidget *parent){
    setParent(parent);
    move(x,y);
    //setMaximumSize(width(),height());
    //usully_gun.SetParent(parent);
}

tanks::~tanks(){}

void tanks::Move(const move_direction &dir){
    switch(dir){
    case move_direction::left:
        move(x()-Speed(),y());
        fl_dir = fl_left;
        break;
    case move_direction::right:
        move(x()+Speed(),y());
        fl_dir = fl_right;
        break;
    case move_direction::up:
        move(x(),y()-Speed());
        fl_dir = fl_up;
        break;
    case move_direction::down:
        move(x(),y()+Speed());
        fl_dir = fl_down;
        break;
    }
    ChangeCurrentTankImage(dir);
}

void tanks::Attack(){
    int x,y;
    if(width() > height() && fl_dir == fl_right){ //смотрит вправо
        x = this->x() + width()+width()/5;
        y = this->y() + height()/2;
    }else if(width() > height() && fl_dir == fl_left){//смотрит влево
        x = this->x() + 0 - width()/5;
        y = this->y() + height()/2;
    }else if(width() < height() && fl_dir == fl_down){//смотрит вниз
        x = this->x() + width()/2;
        y = this->y() + height() + height()/5;
    }else{//смотрит вверх
        x = this->x() + width()/2;
        y = this->y() + 0 - height()/5;
    }
    qDebug()<<"x "<<this->x()<<"; y "<<this->y()<<"; widht "<<width()<<"; height "<<height();
    qDebug()<<"x "<<x<<"; y"<<y;
    usully_gun.Shoot(x, y,parentWidget(),fl_dir);//передаем координаты откуда идет выстрел

}
