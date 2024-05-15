#include "SvgCircleItem.h"

SvgCircleItem::SvgCircleItem(QGraphicsItem* parent)
	:QGraphicsEllipseItem(parent)
{
	QPen pen = QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);//���û���-��ɫ����ϸ5��ʵ�ߡ�Բ�ζ˵㡢Բ������
	setPen(pen);
	QBrush brush = QBrush(Qt::white);
	setBrush(brush);
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

SvgCircleItem* SvgCircleItem::copyItem(SvgCircleItem* item)
{
	SvgCircleItem* circleItem = new SvgCircleItem();
	circleItem->setRect(item->rect());	// ���þ���
	circleItem->setPos(item->pos());	// ����λ��
	circleItem->setFlags(item->flags());	// ���ñ�־
	circleItem->setPen(item->pen());	// ���û���
	circleItem->setBrush(item->brush());	// ���û�ˢ
	circleItem->setTransform(item->transform());	// ���ñ任

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

