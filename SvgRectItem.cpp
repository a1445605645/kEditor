#include "SvgRectItem.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>


SvgRectItem::SvgRectItem(QGraphicsItem* parent)
	:QGraphicsRectItem(parent)
{
	QPen pen = QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	setPen(pen);
	QBrush brush = QBrush(Qt::white);
	setBrush(brush);
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

SvgRectItem* SvgRectItem::copyItem(SvgRectItem* item)
{
	SvgRectItem* rectItem = new SvgRectItem();
	rectItem->setRect(item->rect());
	rectItem->setPos(item->pos());
	rectItem->setPen(item->pen());
	rectItem->setBrush(item->brush());
	return rectItem;
}

void SvgRectItem::setItemBorderWidth(const double& width)
{
	QPen updatedPen = pen();
	updatedPen.setWidth(width);
	setPen(updatedPen);
	update();
}

void SvgRectItem::setItemBorderStyle(const Qt::PenStyle& style)
{
	QPen updatedPen = pen();
	updatedPen.setStyle(style);
	setPen(updatedPen);

}

void SvgRectItem::setItemBorderColor(const QColor& color)
{
	QPen updatedPen = pen();
	updatedPen.setColor(color);
	setPen(updatedPen);

}

void SvgRectItem::setItemBrushColor(const QColor& color)
{
	QBrush updatedBrush = brush();
	updatedBrush.setColor(color);
	setBrush(updatedBrush);
}

double SvgRectItem::getItemBorderWidth() const
{
	return pen().width();
}

Qt::PenStyle SvgRectItem::getItemBorderStyle() const
{
	return pen().style();
}

QColor SvgRectItem::getItemBorderColor() const
{
	return pen().color();
}

QColor SvgRectItem::getItemBrushColor() const
{
	return brush().color();
}


