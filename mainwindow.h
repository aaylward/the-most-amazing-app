#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setName(const QString &name);
    QString name() const;

    void setupUiMore();
    void setNewValue(QLabel *label, QSlider *slider, int value);
    void fadeColor(int percentHot);

public slots:
    void labelChanged();
    void kelvinSliderChanged(int);
    void celsiusSliderChanged(int);
    void farenheitSliderChanged(int);

private:
    Ui::MainWindow *ui;
    QPalette mainWindowPalette;
    static const int coldR = 212;
    static const int coldG = 240;
    static const int coldB = 255;
    static const int hotR = 255;
    static const int hotG = 109;
    static const int hotB = 49;
};



#endif // MAINWINDOW_H
