#pragma once
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsItem>

class SvgCircleItem : public QGraphicsEllipseItem
{
public:
	explicit SvgCircleItem(QGraphicsItem* parent = nullptr);
	~SvgCircleItem() = default;

	// 复制圆形，并返回复制的圆形
	SvgCircleItem* copyItem(SvgCircleItem* item);

	// 设置圆形的属性
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle &style);
	void setItemBorderColor(const QColor& color);
	void setItemBrushColor(const QColor& color);

	// 获取圆形的属性
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;
	QColor getItemBrushColor() const;
};

