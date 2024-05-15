#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>

class SvgRectItem : public QGraphicsRectItem
{
public:
	explicit SvgRectItem(QGraphicsItem* parent = nullptr);
	~SvgRectItem() = default;

	// 复制矩形，并返回新的矩形
	SvgRectItem* copyItem(SvgRectItem* item);

	// 设置矩形的属性
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle& style);
	void setItemBorderColor(const QColor& color);
	void setItemBrushColor(const QColor& color);

	// 获取矩形的属性
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;
	QColor getItemBrushColor() const;
};

