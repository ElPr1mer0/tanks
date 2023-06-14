#include "gun.h"



void gun::Shoot(int x, int y, QWidget *parent, const flight_direction &dir){
    shell *sh = new shell(x,y,dir,ShellSpeed(),parent);
    sh->move(x,y);
}

