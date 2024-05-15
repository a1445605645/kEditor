#pragma once
#include <QGraphicsSvgItem>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>

class SvgPolygonItem : public QGraphicsPolygonItem
{
public:
	SvgPolygonItem(QGraphicsItem* parent = nullptr);
	~SvgPolygonItem() = default;

	// 复制多边形，并返回复制的多边形
	SvgPolygonItem* copyItem(SvgPolygonItem* item);

	// 设置多边形的属性
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle& style);
	void setItemBorderColor(const QColor& color);
	void setItemBrushColor(const QColor& color);

	// 获取多边形的属性
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;
	QColor getItemBrushColor() const;
};

