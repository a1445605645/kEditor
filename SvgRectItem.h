#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>

class SvgRectItem : public QGraphicsRectItem
{
public:
	explicit SvgRectItem(QGraphicsItem* parent = nullptr);
	~SvgRectItem() = default;

	// ���ƾ��Σ��������µľ���
	SvgRectItem* copyItem(SvgRectItem* item);

	// ���þ��ε�����
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle& style);
	void setItemBorderColor(const QColor& color);
	void setItemBrushColor(const QColor& color);

	// ��ȡ���ε�����
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;
	QColor getItemBrushColor() const;
};

