#ifndef ARROW_H
#define ARROW_H

#include <QColor>
#include <QGraphicsLineItem>
#include <QPainterPath>
#include <QPen>
#include <QRectF>
#include <QString>

class CompositeItem;

class Arrow : public QGraphicsLineItem {
 public:
  enum { Type = UserType + 9 };

  Arrow(CompositeItem *startItem, CompositeItem *endItem,
        QGraphicsItem *parent = nullptr);
  ~Arrow() {
    start_item_ = nullptr;
    end_item_ = nullptr;
  }

  int type() const override { return Type; }
  QRectF boundingRect() const override;
  QPainterPath shape() const override;

  CompositeItem *start_item() const { return start_item_; }
  CompositeItem *end_item() const { return end_item_; }

  void updatePosition();

 protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget = 0) override;

 private:
  static QPointF Intersect(const QPolygonF &polygon, const QPointF &point,
                           const QLineF &line);

  CompositeItem *start_item_;
  CompositeItem *end_item_;
  QPolygonF polygon_;
};

#endif  // ARROW_H