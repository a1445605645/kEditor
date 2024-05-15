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
	void zoomIn();	// 放大
	void zoomOut();	// 缩小
	void wheelEvent(QWheelEvent* event) override;	// 放大缩小

private:
	double m_scaleValue;
};

#endif // SVGVIEW_H