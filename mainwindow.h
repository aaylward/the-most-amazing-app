#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
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
    static int const coldR = 212;
    static int const coldG = 240;
    static int const coldB = 255;
    static int const hotR = 255;
    static int const hotG = 109;
    static int const hotB = 49;
    QVector<QColor> backgroundColors;
    QVector<QColor> foregroundColors;
};



#endif // MAINWINDOW_H
