#include "SvgCircleItem.h"

SvgCircleItem::SvgCircleItem(QGraphicsItem* parent)
	:QGraphicsEllipseItem(parent)
{
	QPen pen = QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);//设置画笔-黑色、粗细5、实线、圆形端点、圆角连接
	setPen(pen);
	QBrush brush = QBrush(Qt::white);
	setBrush(brush);
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

SvgCircleItem* SvgCircleItem::copyItem(SvgCircleItem* item)
{
	SvgCircleItem* circleItem = new SvgCircleItem();
	circleItem->setRect(item->rect());	// 设置矩形
	circleItem->setPos(item->pos());	// 设置位置
	circleItem->setFlags(item->flags());	// 设置标志
	circleItem->setPen(item->pen());	// 设置画笔
	circleItem->setBrush(item->brush());	// 设置画刷
	circleItem->setTransform(item->transform());	// 设置变换

	return circleItem;
}

void SvgCircleItem::setItemBorderWidth(const double& width)
{
	QPen updatedPen = pen();
	updatedPen.setWidth(width);
	setPen(updatedPen);
	update();
}

void SvgCircleItem::setItemBorderStyle(const Qt::PenStyle & style)
{
	QPen updatedPen = pen();
	updatedPen.setStyle(style);
	setPen(updatedPen);

}

void SvgCircleItem::setItemBorderColor(const QColor& color)
{
	QPen updatedPen = pen();
	updatedPen.setColor(color);
	setPen(updatedPen);

}

void SvgCircleItem::setItemBrushColor(const QColor& color)
{
	QBrush updatedBrush = brush();
	updatedBrush.setColor(color);
	setBrush(updatedBrush);
}

double SvgCircleItem::getItemBorderWidth() const
{
	return pen().width();
}

Qt::PenStyle SvgCircleItem::getItemBorderStyle() const
{
	return pen().style();
}

QColor SvgCircleItem::getItemBorderColor() const
{
	return pen().color();
}

QColor SvgCircleItem::getItemBrushColor() const
{
	return brush().color();
}

