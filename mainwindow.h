#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotFullscreen();
    void slotFontsizeIncrease();
    void slotFontsizeDecrease();

private:
    Ui::MainWindow *ui;
    QShortcut fullscreenShortcut;
    QShortcut fontSizeIncreaseShortCut;
    QShortcut fontSizeDecreaseShortCut;
};

#endif // MAINWINDOW_H
