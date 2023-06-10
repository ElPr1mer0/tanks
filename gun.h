#ifndef GAN_H
#define GAN_H
#include <QLabel>
#include <QWidget>



class gun{

public:
    gun(){};
    virtual ~gun(){};

    virtual void Shoot();
    //shell_image = new QLabel(parent);
};

#endif // GAN_H
