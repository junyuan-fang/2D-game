#include "buswindow.hh"
#include "ui_buswindow.h"
#include <QDebug>

BusWindow::BusWindow(QString mapName, QWidget *parent) :
    QWidget(parent),
    MapOfBusStop(mapName),
    ui(new Ui::BusWindow)
{
    ui->setupUi(this);
    initWindow();
    connect(ui->rightButton, &QPushButton::clicked, [this](){
        this->close();
        emit selectedBus(ui->rightButton->text());
        button_pressed_=true;//for testing
    });

    connect(ui->leftButton, &QPushButton::clicked, [this](){
        this->close();
        emit selectedBus(ui->leftButton->text());
        button_pressed_=true;//for testing
    });
    connect(ui->endButton, &QPushButton::clicked, this, &QWidget::close);
}

BusWindow::~BusWindow()
{
    delete ui;
}

QPushButton *BusWindow::getEndButton()
{
    return ui->endButton;
}

QPushButton *BusWindow::getLeftButton()
{
    return ui->leftButton;
}

QPushButton *BusWindow::getRightButton()
{
    return ui->rightButton;
}

bool BusWindow::get_pressed()
{
    return  button_pressed_;
}

void BusWindow::initWindow()
{
    ui->textDisplay->setText("Which bus would you like to take?");
    if(MapOfBusStop.toLower() == "airport"){
        ui->rightButton->setVisible(true);
        ui->leftButton->setVisible(true);
        ui->rightButton->setText("6B");
        ui->leftButton->setText("1A");
        return;
    }
    ui->rightButton->setVisible(false);
    ui->leftButton->setVisible(true);
    ui->leftButton->setText("6B");
}
