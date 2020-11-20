#include "buswindow.hh"
#include "ui_buswindow.h"

BusWindow::BusWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusWindow)
{
    ui->setupUi(this);
}

BusWindow::~BusWindow()
{
    delete ui;
}
