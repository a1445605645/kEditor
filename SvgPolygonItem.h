#pragma once
#include <QGraphicsSvgItem>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>

class SvgPolygonItem : public QGraphicsPolygonItem
{
public:
	SvgPolygonItem(QGraphicsItem* parent = nullptr);
	~SvgPolygonItem() = default;

	// ���ƶ���Σ������ظ��ƵĶ����
	SvgPolygonItem* copyItem(SvgPolygonItem* item);

	// ���ö���ε�����
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle& style);
	void setItemBorderColor(const QColor& color);
	void setItemBrushColor(const QColor& color);

	// ��ȡ����ε�����
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;
	QColor getItemBrushColor() const;
};

