#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fullscreenShortcut(this),
    fontSizeIncreaseShortCut(this),
    fontSizeDecreaseShortCut(this)
{
    ui->setupUi(this);

    fullscreenShortcut.setKey(QKeySequence("Ctrl+F"));
    fullscreenShortcut.setContext(Qt::ApplicationShortcut);
    connect(&fullscreenShortcut, SIGNAL(activated()), this, SLOT(slotFullscreen()));

    fontSizeIncreaseShortCut.setKey(QKeySequence("Ctrl+I"));
    fontSizeIncreaseShortCut.setContext(Qt::ApplicationShortcut);
    connect(&fontSizeIncreaseShortCut, SIGNAL(activated()), this, SLOT(slotFontsizeIncrease()));

    fontSizeDecreaseShortCut.setKey(QKeySequence("Ctrl+D"));
    fontSizeDecreaseShortCut.setContext(Qt::ApplicationShortcut);
    connect(&fontSizeDecreaseShortCut, SIGNAL(activated()), this, SLOT(slotFontsizeDecrease()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotFullscreen()
{
    if(windowState() == Qt::WindowFullScreen)
        showMaximized();
    else
        showFullScreen();
}

void MainWindow::slotFontsizeIncrease()
{
    QFont font = QApplication::font();
    int fontsize = font.pointSize();
    if(fontsize > 5 && fontsize < 35)
        font.setPointSize(fontsize + 1);
    QApplication::setFont(font);
}

void MainWindow::slotFontsizeDecrease()
{
    QFont font = QApplication::font();
    int fontsize = font.pointSize();
    if(fontsize > 5 && fontsize < 35)
        font.setPointSize(fontsize - 1);
    QApplication::setFont(font);
}
