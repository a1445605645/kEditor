#pragma once
#include <QGraphicsTextItem>


class SvgTextItem : public QGraphicsTextItem
{
public:
	SvgTextItem(const std::vector<QPointF>& pointVec, QGraphicsItem* parent = nullptr);
	~SvgTextItem() = default;

	// �����ı���
	SvgTextItem* copyItem(const std::vector<QPointF>& pointVec, SvgTextItem* item);

	// �����ı��������
	void setItemFont(const QFont& font);

};

