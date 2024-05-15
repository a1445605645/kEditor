#include "SvgView.h"
#include "SvgScene.h"
#include <QGraphicsView>
#include <QDebug>
#include <QWheelEvent>
#include <QGraphicsScene>

SvgView::SvgView(SvgScene* scene, QWidget* parent)
	: QGraphicsView(scene, parent), m_scaleValue(1.0)
{
	setDragMode(QGraphicsView::NoDrag); 
	setMouseTracking(true);
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	setResizeAnchor(QGraphicsView::AnchorUnderMouse);			
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void SvgView::setGraphType(GraphType graphtype)
{
	QGraphicsScene* scene = this->scene();
	if (scene)
	{	
		SvgScene* svgScene = qobject_cast<SvgScene*>(scene);
		if (svgScene)
		{
			svgScene->setGraphType(graphtype);
		}
	}
}

void SvgView::zoomIn()
{
	scale(1.1, 1.1);
	m_scaleValue *= 1.1;
	update();
}

void SvgView::zoomOut()
{
	scale(0.9, 0.9);
	m_scaleValue *= 0.9;
	update();
}

void SvgView::wheelEvent(QWheelEvent* event)
{
	// 按住Ctrl键，滚动鼠标滚轮，实现放大缩小
	if (event->modifiers() == Qt::CTRL)
	{
		if ((event->delta() > 0) && (m_scaleValue <= 50))
		{
			zoomIn();
		}
		else if ((event->delta() < 0) && (m_scaleValue >= 0.01))
			zoomOut();
	}
	else
	{
		QGraphicsView::wheelEvent(event);
	}
}


