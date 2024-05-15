#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "GraphType.h"

class SvgScene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit SvgScene(QObject* parent = nullptr);
	~SvgScene() = default;
	void setGraphType(GraphType type);
	// 绘制图形
	void drawPenItem(QGraphicsSceneMouseEvent* event);
	void drawLineItem(QGraphicsSceneMouseEvent* event);
	void drawCircleItem(QGraphicsSceneMouseEvent* event);
	void drawRectItem(QGraphicsSceneMouseEvent* event);
	void drawPentagonItem(QGraphicsSceneMouseEvent* event);
	void drawHexagonItem(QGraphicsSceneMouseEvent* event);
	void drawStarItem(QGraphicsSceneMouseEvent* event);
	void drawTextItem(const std::vector<QPointF>& pointVec);

	// 复制
	void copyItems(QGraphicsItem* item);
	QGraphicsItem* clonePasteItems(QGraphicsItem* item);

	// 计算鼠标和图元边界的偏移量
	qreal calculateOffset(const QPointF& mousePos, QGraphicsItem* item);


public:
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;

signals:
	void drawFinished(const std::vector<QPointF>&, GraphType);

public slots:
	void onDrawFinished(const std::vector<QPointF>& pointVec);

private:
	void clearDrawingPath();

private:
	std::vector<QPointF> m_pointVec;	// 保存绘制图形的点
	GraphType m_graphType;	// 当前绘制的图形类型
	std::vector<QGraphicsItem*> m_drawingVec; // 保存正在绘制的图形
	std::vector<QGraphicsItem*> copiedItems; // 存储复制的图形项
	std::vector<QPointF> m_startPosVec; // 移动图形的起始位置
	std::vector<QPointF> m_offSetVec; // 图形与鼠标的偏移量
	QGraphicsRectItem* m_selectRect; // 选择框
	QPointF m_startSelectPos; // 选择框起始位置
	bool m_isMoving = false;	// 是否正在移动图形
	bool m_isDrawing = false;	// 是否正在绘制图形
	bool m_isResizing = false;	// 是否正在调整图形大小
	bool m_isSelecting = false; // 是否正在选择
};
