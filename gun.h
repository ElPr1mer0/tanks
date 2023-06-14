#ifndef GAN_H
#define GAN_H
#include <QLabel>
#include <QWidget>
#include "shell.h"


class gun{
private:
    int speed_shell = 0;
    int width_shell = 0;
    int height_shell = 0;

public:
    gun(){speed_shell = 10;};
    virtual ~gun(){};

    int ShellSpeed(){return speed_shell;};

    void SetSpeedShell(int speed){speed_shell = speed;};

    virtual void Shoot(int x, int y, QWidget *parent, const flight_direction &dir);

};

#endif // GAN_H
