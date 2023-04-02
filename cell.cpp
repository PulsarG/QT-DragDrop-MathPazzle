#include "cell.h"

Cell::Cell(QWidget *parent)
    : QLabel(parent),

      mLabel(nullptr),

      mPos(QPoint(0, 0)), mousePressed(false){
  if (this->text() != "") {
    this->setStyleSheet("border: 3px solid red; text-align: center");
  } else {
    this->setStyleSheet("border: 3px solid blue; text-align: center");
  }

//  mLabel = new QLabel(this->window());
  mLabel = new QLabel(this);
  mLabel->setStyleSheet(
      "border: 1px solid red; font: 500 50pt 'Segoe UI'; text-align: center");
  mLabel->hide();
}

void Cell::mousePressEvent(QMouseEvent *event) {

  if (event->button() == Qt::LeftButton && !this->text().isEmpty()) { // if
    this->now_label = this;
    QApplication::clipboard()->setText(this->text());
    this->setText("");
    mousePressed = true;


        mLabel->move(QCursor::pos());
    mLabel->setText(QApplication::clipboard()->text());
    mLabel->setGeometry(event->pos().x() - 75, event->pos().y() - 75, 140, 140);
    mPos = event->pos() - mLabel->pos();

    mLabel->show();

    this->setStyleSheet("border: none");
  } else if (event->button() == Qt::LeftButton && this->text().isEmpty()) {

    QApplication::clipboard()->clear();
    this->setText(QApplication::clipboard()->text());
  } // end if
}

void Cell::mouseMoveEvent(QMouseEvent *event) {
  if (mousePressed) {
    mLabel->move(event->pos() - mPos);
  } // end if
}

//

void Cell::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
    mLabel->hide();
    QPoint cursor_Pos = event->globalPosition().toPoint();
    QWidget* widget = qApp->widgetAt(cursor_Pos);
    QLabel* label = qobject_cast<QLabel*>(widget);

    //
    if (event->button() == Qt::LeftButton && label) { // * if

        if (label->text() == "") { // ** if
          label->setText(QApplication::clipboard()->text());
          QApplication::clipboard()->clear();
          label->setStyleSheet("border: 3px solid red");
          this->setStyleSheet("border: 1px solid blue");
        } else {
            this->now_label->setText(QApplication::clipboard()->text());
            QApplication::clipboard()->clear();
            this->setStyleSheet("border: 3px solid red");
            label->setStyleSheet("border: 3px solid blue");
        } // * end if

      } else {
        this->now_label->setText(QApplication::clipboard()->text());
        QApplication::clipboard()->clear();
        this->setStyleSheet("border: 3px solid red");

      } // * end if
}
