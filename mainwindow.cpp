#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUiMore();
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(labelChanged()));
    connect(ui->celsiusSlider, SIGNAL(valueChanged(int)), this, SLOT(celsiusSliderChanged(int)));
    connect(ui->kelvinSlider, SIGNAL(valueChanged(int)), this, SLOT(kelvinSliderChanged(int)));
    connect(ui->farenheitSlider, SIGNAL(valueChanged(int)), this, SLOT(farenheitSliderChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUiMore()
{
    ui->kelvinSlider->setRange(273, 373);
    ui->celsiusSlider->setRange(0, 100);
    ui->farenheitSlider->setRange(32, 212);

    mainWindowPalette = palette();
    mainWindowPalette.setColor(backgroundRole(), QColor(coldR, coldG, coldB));
    mainWindowPalette.setColor(foregroundRole(), QColor(0,0,0));
    setPalette(mainWindowPalette);
}

void MainWindow::setName(const QString &name)
{
    if (name.isEmpty()) {
        ui->label_2->setText("");
    } else {
        ui->label_2->setText(name + " is your name.");
    }

}

void MainWindow::setNewValue(QLabel *label, QSlider *slider, int newValue)
{
    label->setText(QString::number(newValue));
    slider->setSliderPosition(newValue);
}

QString MainWindow::name() const
{
    return ui->lineEdit->text();
}

void MainWindow::labelChanged()
{
    setName(name());
}

void MainWindow::fadeColor(int percentHot)
{
    int inversePercent = 100 - percentHot;
    int newR = (((hotR - coldR) * inversePercent)/100) + coldR;
    int newG = (((coldG - hotG) * inversePercent)/100) + hotG;
    int newB = (((coldB - hotB) * inversePercent)/100) + hotB;
    int newText = 255 - (inversePercent * 255)/100;
    mainWindowPalette.setColor(backgroundRole(), QColor(newR, newG, newB));
    mainWindowPalette.setColor(foregroundRole(), QColor(newText, newText, newText));
    setPalette(mainWindowPalette);
}

void MainWindow::kelvinSliderChanged(int newValue)
{
    ui->kelvinValueLabel->setText(QString::number(newValue));
    int newCelsius = newValue - 273;
    int newFarenheit = ((9*newCelsius) / 5) + 32;
    fadeColor(newCelsius);
    setNewValue(ui->celsiusValueLabel, ui->celsiusSlider, newCelsius);
    setNewValue(ui->farenheitValueLabel, ui->farenheitSlider, newFarenheit);
}

void MainWindow::celsiusSliderChanged(int newValue)
{
    ui->celsiusValueLabel->setText(QString::number(newValue));
    int newKelvin = newValue + 273;
    int newFarenheit = ((9*newValue) / 5) + 32;
    fadeColor(newValue);
    setNewValue(ui->kelvinValueLabel, ui->kelvinSlider, newKelvin);
    setNewValue(ui->farenheitValueLabel, ui->farenheitSlider, newFarenheit);
}

void MainWindow::farenheitSliderChanged(int newValue)
{
    ui->farenheitValueLabel->setText(QString::number(newValue));
    int newCelsius = ((5*(newValue-32)) / 9);
    int newKelvin = newCelsius + 273;
    fadeColor(newCelsius);
    setNewValue(ui->celsiusValueLabel, ui->celsiusSlider, newCelsius);
    setNewValue(ui->kelvinValueLabel, ui->kelvinSlider, newKelvin);
}
