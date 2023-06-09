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
    green_tank(QWidget *parent);
    virtual void ChangeCurrentTankImage(const move_direction &dir) override;
    virtual void SetCurrentTankImage(const QString tank_image_path) override;
    virtual void SetShellImage(const QString shell_image_path) override;
};




#endif // GREEN_TANK_H
