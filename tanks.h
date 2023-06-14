#ifndef TANKS_H
#define TANKS_H

#include "gun.h"

#include <QWidget>
#include <QLabel>
#include <QDebug>

enum move_direction{
    left = 0,
    right = 1,
    down = 2,
    up = 3
};


class tanks: public QLabel{

private:
    int hp = 0;
    int damage = 0;
    int speed = 0;
    flight_direction fl_dir = fl_up;
    int current_tank_image_index = 0;

protected:
    //QWidget *parent = nullptr;
    gun usully_gun;

public:
    tanks(){};
    tanks(int x, int y,QWidget *parent);
    virtual ~tanks();

    virtual void Move(const move_direction &dir);
    virtual void Attack();
    virtual bool IsDie(){return Hp() <= 0? true : false;};

    int Hp(){return hp;};
    int Damage(){return damage;};
    float Speed(){return speed;};

    void SetHp(int hp){this->hp = hp;};
    void SetDamage(int damage){this->damage = damage;};
    void SetSpeed(float speed){this->speed = speed;};


    void SetCurrentTankImageIndex(int index){current_tank_image_index = index;};
    virtual void ChangeCurrentTankImage(const move_direction &dir) = 0;
    int CurrentTankImageIndex(){return current_tank_image_index;};


};

#endif // TANKS_H
