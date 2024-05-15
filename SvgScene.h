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
	// ����ͼ��
	void drawPenItem(QGraphicsSceneMouseEvent* event);
	void drawLineItem(QGraphicsSceneMouseEvent* event);
	void drawCircleItem(QGraphicsSceneMouseEvent* event);
	void drawRectItem(QGraphicsSceneMouseEvent* event);
	void drawPentagonItem(QGraphicsSceneMouseEvent* event);
	void drawHexagonItem(QGraphicsSceneMouseEvent* event);
	void drawStarItem(QGraphicsSceneMouseEvent* event);
	void drawTextItem(const std::vector<QPointF>& pointVec);

	// ����
	void copyItems(QGraphicsItem* item);
	QGraphicsItem* clonePasteItems(QGraphicsItem* item);

	// ��������ͼԪ�߽��ƫ����
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
	std::vector<QPointF> m_pointVec;	// �������ͼ�εĵ�
	GraphType m_graphType;	// ��ǰ���Ƶ�ͼ������
	std::vector<QGraphicsItem*> m_drawingVec; // �������ڻ��Ƶ�ͼ��
	std::vector<QGraphicsItem*> copiedItems; // �洢���Ƶ�ͼ����
	std::vector<QPointF> m_startPosVec; // �ƶ�ͼ�ε���ʼλ��
	std::vector<QPointF> m_offSetVec; // ͼ��������ƫ����
	QGraphicsRectItem* m_selectRect; // ѡ���
	QPointF m_startSelectPos; // ѡ�����ʼλ��
	bool m_isMoving = false;	// �Ƿ������ƶ�ͼ��
	bool m_isDrawing = false;	// �Ƿ����ڻ���ͼ��
	bool m_isResizing = false;	// �Ƿ����ڵ���ͼ�δ�С
	bool m_isSelecting = false; // �Ƿ�����ѡ��
};
