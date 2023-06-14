#include "green_tank.h"
green_tank_move_images green_tank::images;

void green_tank_move_images::SetGreenTankMoveImages(){
    up.clear();
    left.clear();
    down.clear();
    right.clear();

    for(int i = 0; i<5;++i){
        up.push_back(":/up/green_tank_up/"+QString::number(i)+".png");
        left.push_back(":/left/green_tank_left/"+QString::number(i)+".png");
        down.push_back(":/down/green_tank_down/"+QString::number(i)+".png");
        right.push_back(":/right/green_tank_right/"+QString::number(i)+".png");
    }
};

green_tank::green_tank(int x, int y, QWidget *parent){
    SetDamage(40);
    SetHp(100);
    SetSpeed(2.5);

    //this->parent = parent;
    setParent(parent);
    //this->parentWidget()
    move(parent->x()/2,parent->y()/2);

    SetCurrentTankImageIndex(0);
    images.SetGreenTankMoveImages();
    SetCurrentTankImage(images.up[0]);
}

void green_tank::ChangeCurrentTankImage(const move_direction &dir){
    SetCurrentTankImageIndex(CurrentTankImageIndex()+1);
    switch(dir){
    case move_direction::left:
        if(CurrentTankImageIndex() >= images.left.size()) SetCurrentTankImageIndex(0);
        SetCurrentTankImage(images.left[CurrentTankImageIndex()]);
        break;
    case move_direction::right:
        if(CurrentTankImageIndex() >= images.right.size()) SetCurrentTankImageIndex(0);
        SetCurrentTankImage(images.right[CurrentTankImageIndex()]);
        break;
    case move_direction::up:
        if(CurrentTankImageIndex() >= images.up.size()) SetCurrentTankImageIndex(0);
        SetCurrentTankImage(images.up[CurrentTankImageIndex()]);
        break;
    case move_direction::down:
        if(CurrentTankImageIndex() >= images.down.size()) SetCurrentTankImageIndex(0);
        SetCurrentTankImage(images.down[CurrentTankImageIndex()]);
        break;
    }
}

void green_tank::SetCurrentTankImage(const QString tank_image_path){
    QPixmap image;
    image.load(tank_image_path);
    resize(image.size());
    setPixmap(image);
    setGeometry(x(),y(),width(),height());
}
