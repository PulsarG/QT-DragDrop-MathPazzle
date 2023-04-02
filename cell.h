#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QMouseEvent>
#include <QClipboard>
#include <QApplication>
#include <QPointF>

class Cell : public QLabel {
public:
  Cell(QWidget *parent = nullptr);

  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

  //
  void mouseMoveEvent(QMouseEvent *event) override;

private:
  QLabel* now_label;


  //
  QLabel *mLabel;
  QPoint mPos;
  bool mousePressed;

};

#endif // CELL_H
