#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet("QGroupBox {font-weight: bold; border: 1px solid gray; border-radius: 2px; margin-top: .5em; padding-top: .2em} QGroupBox::title {subcontrol-origin: margin; left: 6px; padding: 0 3px;}");

    QCommandLineParser parser;
    QCommandLineOption fontSizeOption("fontsize", "Font size", "font size in pt");

    parser.addOption(fontSizeOption);
    parser.process(a);

    int fontSize = 11;
    if(parser.isSet(fontSizeOption))
        fontSize = parser.value(fontSizeOption).toInt();
    QFont font = QApplication::font();
    font.setPointSize(fontSize);
    QApplication::setFont(font);

    MainWindow w;
    w.showMaximized();

    return a.exec();
}
