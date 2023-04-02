#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mLabel(nullptr),

      mPos(QPoint(0, 0)), mousePressed(false) {
  ui->setupUi(this);

  mLabel = new QLabel(this);
  mLabel->setText("");
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    mousePressed = true;
    //      mLabel->setText(QApplication::clipboard()->text());
    mLabel->setText("123123");
    mLabel->setGeometry(event->pos().x(), event->pos().y(), 50, 50);
    mPos = event->pos() - mLabel->pos();
  } // end if
}
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
  if (mousePressed) {
    mLabel->move(event->pos() - mPos);
  } // end if
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    mousePressed = false;
    mLabel->setText("");
  } // end if
}

MainWindow::~MainWindow()
{
    delete ui;
}

