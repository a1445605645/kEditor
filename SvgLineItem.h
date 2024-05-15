#pragma once
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsItem>

class SvgLineItem : public QGraphicsLineItem
{
public:
	explicit SvgLineItem(QGraphicsItem* parent = nullptr);
	~SvgLineItem() = default;

	// ����ֱ�ߣ������ظ��Ƶ�ֱ��
	SvgLineItem* copyItem(SvgLineItem* item);

	// ���ñ߿���,�߿���ʽ���߿���ɫ
	void setItemBorderWidth(const double& width);
	void setItemBorderStyle(const Qt::PenStyle& style);
	void setItemBorderColor(const QColor &color);

	// ��ȡ�߿��ȣ��߿���ʽ���߿���ɫ
	double getItemBorderWidth() const;
	Qt::PenStyle getItemBorderStyle() const;
	QColor getItemBorderColor() const;
};

