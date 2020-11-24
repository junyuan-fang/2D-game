#include "buswindow.hh"
#include "ui_buswindow.h"

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
    });

    connect(ui->leftButton, &QPushButton::clicked, [this](){
        this->close();
        emit selectedBus(ui->leftButton->text());
    });
    connect(ui->endButton, &QPushButton::clicked, this, &QWidget::close);
}

BusWindow::~BusWindow()
{
    delete ui;
}

