#ifndef SHELL_H
#define SHELL_H
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QDebug>

enum flight_direction{
    fl_left = 0,
    fl_right = 1,
    fl_down = 2,
    fl_up = 3
};


class shell:public QLabel{
    Q_OBJECT
private:
    flight_direction dir = fl_up;
    int speed = 0;
    int ms = 0;

protected:
    QWidget *parent = nullptr;
    QTimer *time_flight = nullptr;

public:
    shell(int x, int y, flight_direction dir, int speed, QWidget *parent);
    ~shell(){delete time_flight;qDebug()<<"~shell()";};

    float Speed(){return speed;};

    void SetSpeed(int speed){this->speed = speed;};
    void SetImage();

public slots:
    void ShellFlight();
};

#endif // SHELL_H
