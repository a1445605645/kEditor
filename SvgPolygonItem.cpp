#include "SvgPolygonItem.h"
#include <QGraphicsScene>
#include <QGraphicsItem>

SvgPolygonItem::SvgPolygonItem(QGraphicsItem* parent)
	: QGraphicsPolygonItem(parent)
{
	QPen pen = QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	setPen(pen);
	QBrush brush = QBrush(Qt::white);
	setBrush(brush);
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

SvgPolygonItem* SvgPolygonItem::copyItem(SvgPolygonItem* item)
{
	SvgPolygonItem* polygonItem = new SvgPolygonItem();
	polygonItem->setPolygon(item->polygon());	//设置多边形
	polygonItem->setPos(item->pos());	//设置位置
	polygonItem->setFlags(item->flags());	//设置标志
	polygonItem->setPen(item->pen());	//设置画笔
	polygonItem->setBrush(item->brush());	//设置画刷
	polygonItem->setTransform(item->transform());	//设置变换

	return polygonItem;
}

void SvgPolygonItem::setItemBorderWidth(const double& width)
{
	QPen updatedPen = pen();
	updatedPen.setWidth(width);
	setPen(updatedPen);
	update();
}

void SvgPolygonItem::setItemBorderStyle(const Qt::PenStyle& style)
{
	QPen updatedPen = pen();
	updatedPen.setStyle(style);
	setPen(updatedPen);

}

void SvgPolygonItem::setItemBorderColor(const QColor& color)
{
	QPen updatedPen = pen();
	updatedPen.setColor(color);
	setPen(updatedPen);

}

void SvgPolygonItem::setItemBrushColor(const QColor& color)
{
	QBrush updatedBrush = brush();
	updatedBrush.setColor(color);
	setBrush(updatedBrush);
}

double SvgPolygonItem::getItemBorderWidth() const
{
	return pen().width();
}

Qt::PenStyle SvgPolygonItem::getItemBorderStyle() const
{
	return pen().style();
}

QColor SvgPolygonItem::getItemBorderColor() const
{
	return pen().color();
}

QColor SvgPolygonItem::getItemBrushColor() const
{
	return brush().color();
}
