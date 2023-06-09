#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class levels;

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

public:
    levels *level = nullptr;
private:
    const int BUT_HEIGHT= 50;
    const int BUT_WIDTH = 250;


private slots:
    void ButStartClicked();
    void ButSettingsClicked();
    void ButExitClicked();

    void keyPressEvent (QKeyEvent *event) override;
    void keyReleaseEvent (QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
