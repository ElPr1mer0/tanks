#ifndef FIRST_LEVEL_H
#define FIRST_LEVEL_H

#include "levels.h"

class first_level : public levels{


public:
    first_level();

private slots:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // FIRST_LEVEL_H
