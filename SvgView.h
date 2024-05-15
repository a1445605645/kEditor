#ifndef SVGVIEW_H
#define SVGVIEW_H
#pragma execution_character_set("utf-8")
#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QColor>
#include "SvgScene.h"

class SvgView : public QGraphicsView
{
	Q_OBJECT
public:
	explicit SvgView(SvgScene* scene = nullptr, QWidget* parent = nullptr);
	~SvgView() = default;
	void setGraphType(GraphType graphtype);
	void zoomIn();	// �Ŵ�
	void zoomOut();	// ��С
	void wheelEvent(QWheelEvent* event) override;	// �Ŵ���С

private:
	double m_scaleValue;
};

#endif // SVGVIEW_H