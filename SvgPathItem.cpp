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
	QPen updatedPen = pen(); // ��ȡ��ǰ��pen����Ϊ����
	updatedPen.setWidth(width); // �޸ĸ����Ŀ��
	setPen(updatedPen); // ʹ���޸ĺ��pen�滻��ǰ��pen
	update(); // �����ػ�
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
