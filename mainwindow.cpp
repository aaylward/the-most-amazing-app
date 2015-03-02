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
    QPalette pal = palette();
    pal.setColor(backgroundRole(), Qt::blue);
    pal.setColor(foregroundRole(), Qt::white);
    setPalette(pal);
    ui->kelvinSlider->setRange(273, 373);
    ui->celsiusSlider->setRange(0, 100);
    ui->farenheitSlider->setRange(32, 212);
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

void MainWindow::kelvinSliderChanged(int newValue)
{
    ui->kelvinValueLabel->setText(QString::number(newValue));
    int newCelsius = newValue - 273;
    int newFarenheit = ((9*newCelsius) / 5) + 32;
    setNewValue(ui->celsiusValueLabel, ui->celsiusSlider, newCelsius);
    setNewValue(ui->farenheitValueLabel, ui->farenheitSlider, newFarenheit);
}

void MainWindow::celsiusSliderChanged(int newValue)
{
    ui->celsiusValueLabel->setText(QString::number(newValue));
    int newKelvin = newValue + 273;
    int newFarenheit = ((9*newValue) / 5) + 32;
    setNewValue(ui->kelvinValueLabel, ui->kelvinSlider, newKelvin);
    setNewValue(ui->farenheitValueLabel, ui->farenheitSlider, newFarenheit);
}

void MainWindow::farenheitSliderChanged(int newValue)
{
    ui->farenheitValueLabel->setText(QString::number(newValue));
    int newCelsius = ((5*(newValue-32)) / 9);
    int newKelvin = newCelsius + 273;
    setNewValue(ui->celsiusValueLabel, ui->celsiusSlider, newCelsius);
    setNewValue(ui->kelvinValueLabel, ui->kelvinSlider, newKelvin);
}
