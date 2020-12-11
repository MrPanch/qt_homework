#include <QMouseEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    connect(&representer_, &Representer::Updated, this, &MainWindow::UpdateHandler);
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::UpdateHandler() {
    repaint();
}

void MainWindow::paintEvent(QPaintEvent* paint_event) {
    representer_.Repaint(this);
    QMainWindow::paintEvent(paint_event);
}

void MainWindow::mousePressEvent(QMouseEvent* mouse_event) {
    if (mouse_event->button() == Qt::LeftButton) {
        representer_.AddRandomFigure(mouse_event->pos());
    } else if (mouse_event->button() == Qt::RightButton) {
        representer_.DeleteFigure(mouse_event->pos());
    }

    QMainWindow::mousePressEvent(mouse_event);
}
