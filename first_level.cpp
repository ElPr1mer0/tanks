#include "first_level.h"



first_level::first_level(){
    setGeometry(600,200,800,600);
    SetCurrentLevel(1);
    player = new green_tank(100,100,this);
    //player->SetCurrentTankImage(player->images.up[0]);
    show();
}

void first_level::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_A :
        player->Move(move_direction::left);
        break;
    case Qt::Key_D :
        player->Move(move_direction::right);
        break;
    case Qt::Key_W :
        player->Move(move_direction::up);
        break;
    case Qt::Key_S :
        player->Move(move_direction::down);
        break;
    case Qt::Key_Space :
        player->Attack();
        break;
    }
}

void first_level::keyReleaseEvent(QKeyEvent *event){
   // player->Move(move_direction::stop);
}
