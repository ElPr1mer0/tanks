#ifndef TANKS_H
#define TANKS_H

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


class tanks{

private:
    int hp = 0;
    int damage = 0;
    float speed = 0;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    int current_tank_image_index = 0;

    int shell_x = 0;
    int shell_y = 0;
    int shell_width = 0;
    int shell_height = 0;
    float shell_speed = 0;

protected:
    QLabel *tank_image = nullptr;
    QLabel *shell_image = nullptr;
    QWidget *parent = nullptr;

public:
    virtual ~tanks();


    virtual void CreateTank(QWidget *parent); //создает QLabel* для отображения танка
    virtual void DestroyTank(){delete tank_image;};
    virtual void CreateShell(QWidget *parent);
    virtual void DestroyShell(){delete shell_image;};

    virtual void Move(const move_direction &dir);
    virtual void Attack();
    virtual bool IsDie(){return Hp() <= 0? true : false;};

    virtual int Hp(){return hp;};
    virtual int Damage(){return damage;};
    virtual float Speed(){return speed;};
    virtual int X(){return x;};
    virtual int Y(){return y;};
    virtual int Width(){return width;};
    virtual int Height(){return height;};
    virtual int ShellX(){return shell_x;};
    virtual int ShellY(){return shell_y;};
    virtual int ShellWidth(){return shell_width;};
    virtual int ShellHeight(){return shell_height;};
    virtual float ShellSpeed(){return shell_speed;};


    virtual void SetHp(int hp){this->hp = hp;};
    virtual void SetDamage(int damage){this->damage = damage;};
    virtual void SetSpeed(float speed){this->speed = speed;};
    virtual void SetX(int x){this->x = x;};
    virtual void SetY(int y){this->y = y;};
    virtual void SetXY(int x, int y){this->x = x; this->y = y;};
    virtual void SetWidth(int width){this->width = width;};
    virtual void SetHeight(int height){this->height = height;};
    virtual void SetShellX(int x){shell_x = x;};
    virtual void SetShellY(int y){shell_y = y;};
    virtual void SetShellWidth(int width){shell_width = width;};
    virtual void SetShellHeight(int height){shell_height = height;};
    virtual void SetShellSpeed(float speed){shell_speed = speed;};

    virtual void SetCurrentTankImage(const QString tank_image_path) = 0;
    virtual void SetCurrentTankImageIndex(int index){current_tank_image_index = index;};
    virtual void ChangeCurrentTankImage(const move_direction &dir) = 0;
    virtual int CurrentTankImageIndex(){return current_tank_image_index;};

    virtual void SetShellImage(const QString shell_image) = 0;
};

#endif // TANKS_H
