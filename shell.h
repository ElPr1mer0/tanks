#ifndef SHELL_H
#define SHELL_H
#include <QWidget>
#include <QLabel>
#include <QTimer>

enum flight_direction{
    //stop = 0,
    fl_left = 1,
    fl_right = 2,
    fl_down = 3,
    fl_up = 4
};


class shell:public QLabel{
    Q_OBJECT
private:
    flight_direction dir = fl_up;
//    int shell_x = 0;
//    int shell_y = 0;
//    int shell_width = 0;
//    int shell_height = 0;
    int speed = 0;

protected:
    QWidget *parent = nullptr;
    QTimer *time_flight = nullptr;

public:
    shell(flight_direction dir, int speed, QWidget *parent);
    ~shell(){delete time_flight;};
    void ShellFlight();

//    int X(){return shell_x;};
//    int Y(){return shell_y;};
//    int Width(){return shell_width;};
//    int Height(){return shell_height;};
    float Speed(){return speed;};

//    void SetX(int x){this->x() x;};
//    void SetY(int y){shell_y = y;};
//    void SetWidth(int width){shell_width = width;};
//    void SetHeight(int height){shell_height = height;};
    void SetSpeed(float speed){speed = speed;};

    void SetImage();
};

#endif // SHELL_H
