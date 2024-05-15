#include "SvgPathItem.h"

SvgPathItem::SvgPathItem(const QPainterPath& path, QGraphicsItem* parent)
	:QGraphicsPathItem(path, parent)
{
	QPen pen = QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	setPen(pen);
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

SvgPathItem* SvgPathItem::copyItem(SvgPathItem* item)
{
	SvgPathItem* pathItem = new SvgPathItem(item->path());
	pathItem->setPos(item->pos());
	pathItem->setFlags(item->flags());
	pathItem->setPen(item->pen());
	pathItem->setBrush(item->brush());
	pathItem->setTransform(item->transform());

	return pathItem;
}

void SvgPathItem::setItemBorderWidth(const double& width)
{
	QPen updatedPen = pen(); // 获取当前的pen并作为副本
	updatedPen.setWidth(width); // 修改副本的宽度
	setPen(updatedPen); // 使用修改后的pen替换当前的pen
	update(); // 请求重绘
}

void SvgPathItem::setItemBorderStyle(const Qt::PenStyle &style)
{
	QPen updatedPen = pen();
	updatedPen.setStyle(style);
	setPen(updatedPen);

}

void SvgPathItem::setItemBorderColor(const QColor &color)
{
	QPen updatedPen = pen();
	updatedPen.setColor(color);
	setPen(updatedPen);
}

double SvgPathItem::getItemBorderWidth() const
{
	return pen().width();
}

Qt::PenStyle SvgPathItem::getItemBorderStyle() const
{
	return pen().style();
}

QColor SvgPathItem::getItemBorderColor() const
{
	return pen().color();
}
