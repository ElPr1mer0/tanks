#ifndef TANKS_H
#define TANKS_H

#include "gun.h"

#include <QWidget>
#include <QLabel>
#include <QDebug>

enum move_direction{
    //stop = 0,
    left = 1,
    right = 2,
    down = 3,
    up = 4
};


class tanks: public QLabel{

private:
    int hp = 0;
    int damage = 0;
    int speed = 0;

//    int x = 0;
//    int y = 0;
//    int width = 0;
//    int height = 0;
    int current_tank_image_index = 0;

protected:
    //QLabel *tank_image = nullptr;
    QWidget *parent = nullptr;
    gun usully_gun;

public:
    tanks(){};
    tanks(int x, int y,QWidget *parent);
    virtual ~tanks();


    //virtual void CreateTank(QWidget *parent); //создает QLabel* для отображения танка
    //virtual void DestroyTank(){delete tank_image;};

    virtual void Move(const move_direction &dir);
    virtual void Attack();
    virtual bool IsDie(){return Hp() <= 0? true : false;};

    int Hp(){return hp;};
    int Damage(){return damage;};
    float Speed(){return speed;};
//    int X(){return x;};
//    int Y(){return y;};
//    int Width(){return width;};
//    int Height(){return height;};

    void SetHp(int hp){this->hp = hp;};
    void SetDamage(int damage){this->damage = damage;};
    void SetSpeed(float speed){this->speed = speed;};
//    void SetX(int x){this->x = x;};
//    void SetY(int y){this->y = y;};
//    void SetXY(int x, int y){this->x = x; this->y = y;};
//    void SetWidth(int width){this->width = width;};
//    void SetHeight(int height){this->height = height;};


    //void SetCurrentTankImage(const QString tank_image_path) = 0;
    void SetCurrentTankImageIndex(int index){current_tank_image_index = index;};
    virtual void ChangeCurrentTankImage(const move_direction &dir) = 0;
    int CurrentTankImageIndex(){return current_tank_image_index;};


};

#endif // TANKS_H
