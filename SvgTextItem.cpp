#include "SvgTextItem.h"
#include <QFont>

SvgTextItem::SvgTextItem(const std::vector<QPointF>& pointVec, QGraphicsItem* parent)
	:QGraphicsTextItem(parent)
{
	QFont font = QFont("Arial", 20, QFont::Bold);
	setFont(font);
	setPlainText(QString::fromLocal8Bit("请输入文本")); // 中文乱码

	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
	setTextInteractionFlags(Qt::TextEditorInteraction);
	setPos(pointVec[0]);
}

SvgTextItem* SvgTextItem::copyItem(const std::vector<QPointF>& pointVec, SvgTextItem* item)
{
	SvgTextItem* textItem = new SvgTextItem(pointVec);
	textItem->setPlainText(item->toPlainText());
	textItem->setPos(item->pos());
	textItem->setFlags(item->flags());
	textItem->setFont(item->font());
	textItem->setTextInteractionFlags(item->textInteractionFlags());
	textItem->setTransform(item->transform());

	return textItem;
}

void SvgTextItem::setItemFont(const QFont& font)
{
	setFont(font);
	update();
}

