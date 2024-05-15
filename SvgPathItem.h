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

	// 复制路径，并返回复制的路径
	SvgPathItem* copyItem(SvgPathItem* item);

	// 设置边框样式
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle& style);
	void setItemBorderColor(const QColor& color);

	// 获取边框样式
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;

};

