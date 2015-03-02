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

public slots:
    void labelChanged();
    void kelvinSliderChanged(int);
    void celsiusSliderChanged(int);
    void farenheitSliderChanged(int);

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
