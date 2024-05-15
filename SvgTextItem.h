#pragma once
#include <QGraphicsTextItem>


class SvgTextItem : public QGraphicsTextItem
{
public:
	SvgTextItem(const std::vector<QPointF>& pointVec, QGraphicsItem* parent = nullptr);
	~SvgTextItem() = default;

	// 复制文本项
	SvgTextItem* copyItem(const std::vector<QPointF>& pointVec, SvgTextItem* item);

	// 设置文本项的属性
	void setItemFont(const QFont& font);

};

