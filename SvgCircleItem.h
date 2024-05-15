#pragma once
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsItem>

class SvgCircleItem : public QGraphicsEllipseItem
{
public:
	explicit SvgCircleItem(QGraphicsItem* parent = nullptr);
	~SvgCircleItem() = default;

	// ����Բ�Σ������ظ��Ƶ�Բ��
	SvgCircleItem* copyItem(SvgCircleItem* item);

	// ����Բ�ε�����
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle &style);
	void setItemBorderColor(const QColor& color);
	void setItemBrushColor(const QColor& color);

	// ��ȡԲ�ε�����
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;
	QColor getItemBrushColor() const;
};

