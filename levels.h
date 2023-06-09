#ifndef LEVELS_H
#define LEVELS_H
#include <QWidget>
#include <green_tank.h>
#include <QKeyEvent>

class levels: public QWidget{
private:
    int current_level = 0;

protected:
    tanks *player = nullptr;

public:
    virtual void SetCurrentLevel(int level){current_level = level;};
    virtual int CurrentLevel(){return current_level;};

private slots:
    virtual void keyPressEvent(QKeyEvent *event) = 0;
    virtual void keyReleaseEvent(QKeyEvent *event) = 0;
};

#endif // LEVELS_H
