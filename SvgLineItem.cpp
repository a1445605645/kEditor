#include "SvgLineItem.h"
#include <QPen>
#include <QDebug>

SvgLineItem::SvgLineItem(QGraphicsItem* parent)
	: QGraphicsLineItem(parent)
{
	QPen pen = QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	setPen(pen);
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

SvgLineItem* SvgLineItem::copyItem(SvgLineItem* item)
{
	SvgLineItem* lineItem = new SvgLineItem();
	lineItem->setLine(item->line());
	lineItem->setPen(item->pen());
	lineItem->setFlags(item->flags());
	lineItem->setPos(item->pos());

	return lineItem;
}

void SvgLineItem::setItemBorderWidth(const double& width)
{
	QPen updatedPen = pen(); 
	updatedPen.setWidth(width); 
	setPen(updatedPen); 
	update(); 
}

void SvgLineItem::setItemBorderStyle(const Qt::PenStyle &style)
{
	QPen updatedPen = pen();
	updatedPen.setStyle(style);
	setPen(updatedPen);
}

void SvgLineItem::setItemBorderColor(const QColor& color)
{
	QPen updatedPen = pen();
	updatedPen.setColor(color);
	setPen(updatedPen);
}


double SvgLineItem::getItemBorderWidth() const
{
	return pen().width();
}

Qt::PenStyle SvgLineItem::getItemBorderStyle() const
{
	return pen().style();
}

QColor SvgLineItem::getItemBorderColor() const
{
	return pen().color();
}

