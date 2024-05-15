#pragma once
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsItem>

class SvgLineItem : public QGraphicsLineItem
{
public:
	explicit SvgLineItem(QGraphicsItem* parent = nullptr);
	~SvgLineItem() = default;

	// 复制直线，并返回复制的直线
	SvgLineItem* copyItem(SvgLineItem* item);

	// 设置边框宽度,边框样式，边框颜色
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle& style);
	void setItemBorderColor(const QColor &color);

	// 获取边框宽度，边框样式，边框颜色
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;
};

