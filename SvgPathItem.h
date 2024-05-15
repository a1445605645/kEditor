#pragma once
#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainterPath>

class SvgPathItem : public QGraphicsPathItem
{
public:
	SvgPathItem(const QPainterPath& path , QGraphicsItem* parent = nullptr);
	~SvgPathItem() = default;

	// ����·���������ظ��Ƶ�·��
	SvgPathItem* copyItem(SvgPathItem* item);

	// ���ñ߿���ʽ
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle& style);
	void setItemBorderColor(const QColor& color);

	// ��ȡ�߿���ʽ
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;

};

