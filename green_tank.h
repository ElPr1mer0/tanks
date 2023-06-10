#ifndef GREEN_TANK_H
#define GREEN_TANK_H

#include "tanks.h"

class green_tank_move_images{
public:
    QVector<QString> up;
    QVector<QString> down;
    QVector<QString> left;
    QVector<QString> right;
public:
    void SetGreenTankMoveImages();
};



class green_tank:public tanks{
private:
    static green_tank_move_images images;
public:
    green_tank(int x, int y, QWidget *parent);
    void ChangeCurrentTankImage(const move_direction &dir);
    void SetCurrentTankImage(const QString tank_image_path);
//    virtual void SetShellImage(const QString shell_image_path) override;
};




#endif // GREEN_TANK_H
