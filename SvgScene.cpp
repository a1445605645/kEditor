#include "SvgScene.h"
#include "SvgRectItem.h"
#include "SvgCircleItem.h"
#include "SvgLineItem.h"
#include "SvgPolygonItem.h"
#include "SvgPathItem.h"
#include "SvgTextItem.h"
#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>
#include <QGraphicsItem>
#include <QDebug>
#include <QtSvg>

SvgScene::SvgScene(QObject* parent)
	:QGraphicsScene(parent),
	m_isMoving(false),
	m_isDrawing(false),
	m_isSelecting(false),
	m_selectRect(nullptr),
	m_graphType(GraphType::CURSOR_TYPE)
{}

void SvgScene::setGraphType(GraphType type)
{
	m_graphType = type;
}

void SvgScene::drawPenItem(QGraphicsSceneMouseEvent* event)
{
	// �滭·��
	QLineF line(m_pointVec.back(), event->scenePos());
	QPen pen = QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	m_drawingVec.emplace_back(addLine(line, pen));
	m_pointVec.emplace_back(event->scenePos());
}

void SvgScene::drawLineItem(QGraphicsSceneMouseEvent* event)
{
	clearDrawingPath();
	QLineF line(m_pointVec.back(), event->scenePos());
	SvgLineItem* lineItem = new SvgLineItem();
	lineItem->setLine(line);
	addItem(lineItem);
	m_drawingVec.push_back(lineItem);
}

void SvgScene::drawCircleItem(QGraphicsSceneMouseEvent* event)
{
	clearDrawingPath();
	QPointF center = m_pointVec[0];
	qreal radius = QLineF(center, event->scenePos()).length();
	SvgCircleItem* circleItem = new SvgCircleItem();
	circleItem->setRect(center.x() - radius, center.y() - radius, 2 * radius, 2 * radius);
	circleItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
	addItem(circleItem);
	m_drawingVec.push_back(circleItem);
}

void SvgScene::drawRectItem(QGraphicsSceneMouseEvent* event)
{
	clearDrawingPath();
	QRectF rect(m_pointVec[0], event->scenePos());
	SvgRectItem* rectItem = new SvgRectItem();
	rectItem->setRect(rect);
	rectItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
	addItem(rectItem);	
	m_drawingVec.push_back(rectItem);	
}

void SvgScene::drawPentagonItem(QGraphicsSceneMouseEvent* event)
{
	clearDrawingPath();
	QPointF center = m_pointVec[0];
	qreal radius = QLineF(center, event->scenePos()).length();
	QPolygonF polygon;
	for (int i = 0; i < 5; ++i)
	{
		qreal angle = 2 * 3.1415926 / 5 * i;
		qreal x = center.x() + radius * qCos(angle);
		qreal y = center.y() + radius * qSin(angle);
		polygon << QPointF(x, y);
	}
	SvgPolygonItem* pentagonItem = new SvgPolygonItem();
	pentagonItem->setPolygon(polygon);
	addItem(pentagonItem);
	pentagonItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
	m_drawingVec.push_back(pentagonItem);
}

void SvgScene::drawHexagonItem(QGraphicsSceneMouseEvent* event)
{
	clearDrawingPath();
	QPointF center = m_pointVec[0];
	qreal radius = QLineF(center, event->scenePos()).length();
	QPolygonF polygon;
	for (int i = 0; i < 6; ++i)
	{
		qreal angle = 2 * 3.1415926 / 6 * i;
		qreal x = center.x() + radius * qCos(angle);
		qreal y = center.y() + radius * qSin(angle);
		polygon << QPointF(x, y);
	}
	SvgPolygonItem* hexagonItem = new SvgPolygonItem();
	hexagonItem->setPolygon(polygon);
	addItem(hexagonItem);
	hexagonItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
	m_drawingVec.push_back(hexagonItem);
}

void SvgScene::drawStarItem(QGraphicsSceneMouseEvent* event)
{
	clearDrawingPath();
	QPointF center = m_pointVec[0];
	qreal radius = QLineF(center, event->scenePos()).length();
	QPolygonF polygon;
	for (int i = 0; i < 5; ++i)
	{
		qreal angle = 2 * 3.1415926 / 5 * i;
		qreal x = center.x() + radius * qCos(angle);
		qreal y = center.y() + radius * qSin(angle);
		polygon << QPointF(x, y);
		angle = 2 * 3.1415926 / 5 * i + 3.1415926 / 5;
		x = center.x() + radius / 2 * qCos(angle);
		y = center.y() + radius / 2 * qSin(angle);
		polygon << QPointF(x, y);
	}
	SvgPolygonItem* starItem = new SvgPolygonItem();
	starItem->setPolygon(polygon);
	addItem(starItem);
	m_drawingVec.push_back(starItem);
}

void SvgScene::drawTextItem(const std::vector<QPointF>& pointVec)
{
	SvgTextItem* textItem = new SvgTextItem(pointVec);
	addItem(textItem);
}

void SvgScene::copyItems(QGraphicsItem* item)
{
	// û��clone������ֻ�ܸ���item�����ԣ�Ȼ���½�һ��item
	QGraphicsItem* copyItem = nullptr;
	switch (item->type())
	{
		case SvgPathItem::Type:
		{
			copyItem = new SvgPathItem(static_cast<SvgPathItem*>(item)->path());
			break;
		}
		case SvgLineItem::Type:
		{
			copyItem = new SvgLineItem();
			static_cast<SvgLineItem*>(copyItem)->setLine(static_cast<SvgLineItem*>(item)->line());
			break;
		}
		case SvgRectItem::Type:
		{
			copyItem = new SvgRectItem();
			static_cast<SvgRectItem*>(copyItem)->setRect(static_cast<SvgRectItem*>(item)->rect());
			break;
		}
		case SvgCircleItem::Type:
		{
			copyItem = new SvgCircleItem();
			static_cast<SvgCircleItem*>(copyItem)->setRect(static_cast<SvgCircleItem*>(item)->rect());
			break;
		}
		case SvgPolygonItem::Type:
		{
			copyItem = new SvgPolygonItem();
			static_cast<SvgPolygonItem*>(copyItem)->setPolygon(static_cast<SvgPolygonItem*>(item)->polygon());
			break;
		}
		case SvgTextItem::Type:
		{
			copyItem = new SvgTextItem(m_pointVec);
			static_cast<SvgTextItem*>(copyItem)->setPlainText(static_cast<SvgTextItem*>(item)->toPlainText());
			break;
		}
	}
	copiedItems.push_back(copyItem);
}

QGraphicsItem* SvgScene::clonePasteItems(QGraphicsItem* item)
{
	// ��׼��ճ����ͼ�θ���һ�ݸ���
	QGraphicsItem* copyItem = nullptr;
		switch (item->type())
		{
		case SvgPathItem::Type:
		{
			copyItem = new SvgPathItem(static_cast<SvgPathItem*>(item)->path());
			break;
		}
		case SvgLineItem::Type:
		{
			copyItem = new SvgLineItem();
			static_cast<SvgLineItem*>(copyItem)->setLine(static_cast<SvgLineItem*>(item)->line());
			break;
		}
		case SvgRectItem::Type:
		{
			copyItem = new SvgRectItem();
			static_cast<SvgRectItem*>(copyItem)->setRect(static_cast<SvgRectItem*>(item)->rect());
			break;
		}
		case SvgCircleItem::Type:
		{
			copyItem = new SvgCircleItem();
			static_cast<SvgCircleItem*>(copyItem)->setRect(static_cast<SvgCircleItem*>(item)->rect());
			break;
		}
		case SvgPolygonItem::Type:
		{
			copyItem = new SvgPolygonItem();
			static_cast<SvgPolygonItem*>(copyItem)->setPolygon(static_cast<SvgPolygonItem*>(item)->polygon());
			break;
		}
		case SvgTextItem::Type:
		{
			copyItem = new SvgTextItem(m_pointVec);
			static_cast<SvgTextItem*>(copyItem)->setPlainText(static_cast<SvgTextItem*>(item)->toPlainText());
			break;
		}
	}
	return copyItem;
}

qreal SvgScene::calculateOffset(const QPointF& mousePos, QGraphicsItem* item)
{
	// ��������ͼԪ�߽��ƫ����
	QRectF itemRect = item->boundingRect();
	QPointF itemPos = item->scenePos();
	itemRect.moveTo(itemPos);

	qreal leftDist = qAbs(mousePos.x() - itemRect.left());
	qreal rightDist = qAbs(mousePos.x() - itemRect.right());
	qreal topDist = qAbs(mousePos.y() - itemRect.top());
	qreal bottomDist = qAbs(mousePos.y() - itemRect.bottom());

	qreal minDist = qMin(qMin(leftDist, rightDist), qMin(topDist, bottomDist));
	return minDist;
}

void SvgScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		// �Ŵ�Ч��
		if (m_graphType == GraphType::GLASS_TYPE)
		{
			qreal currentScale = views().first()->transform().m11();
			views().first()->scale(1.2, 1.2);
		}

		m_startPosVec.clear();
		m_offSetVec.clear();
		if (m_graphType == GraphType::CURSOR_TYPE)
		{
			// ѡ��ͼ��
			QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
			if (item)
			{
				// ��סalt��������ͼƬ
				if (event->modifiers() == Qt::AltModifier)
				{
					m_isResizing = true;
				}

				// �����סCtrl������ѡģʽ������ѡ��
				event->modifiers() == Qt::ControlModifier? item->setSelected(!item->isSelected()): item->setSelected(true);

				// �������ͼ�α�ѡ�У����¼��갴�µ�λ�ú�ͼ��������ƫ����
				if (item->isSelected())
				{
					m_startPosVec.push_back(event->scenePos());
					m_offSetVec.push_back(event->scenePos() - item->pos());
					m_isMoving = true;
				}

				// ������ͼ�α�ѡ�У�������갴�µ�λ�ú�ͼ��������ƫ����
				m_offSetVec.clear();
				for (auto& selectedItem : selectedItems())
				{
					if (selectedItem->isSelected())
					{
						m_startPosVec.push_back(event->scenePos());
						m_offSetVec.push_back(event->scenePos() - selectedItem->pos());
					}
				}
				m_isMoving = !m_offSetVec.empty();
			}
			else
			{
				// ��ѡ
				m_startSelectPos = event->scenePos();
				m_selectRect = new QGraphicsRectItem(QRectF(m_startSelectPos, QSizeF(0, 0)));
				m_selectRect->setPen(QPen(Qt::blue, 5, Qt::DashLine));
				m_selectRect->setBrush(QBrush(QColor(128, 128, 255, 64)));
				addItem(m_selectRect);
				m_isSelecting = true;
			}
		}
		else
		{
			// ���������ͼ�Σ����¼��갴�µ�λ��
			m_isDrawing = true;
			// ����Ƿ����ڻ�ͼ
			m_pointVec.size() > 0 ? m_pointVec.clear() : m_pointVec;
			m_pointVec.push_back(event->scenePos());
		}
	}
}

void SvgScene::keyPressEvent(QKeyEvent* event)
{
	// ctrl + һ���������¼�
	if (event->modifiers() == Qt::ControlModifier)
	{
		switch (event->key())
		{
			case Qt::Key_A:
			{
				for (auto& item : items())
				{
					item->setSelected(true);
				}
				break;
			}
			case Qt::Key_C:
			{
				copiedItems.clear();
				for (auto& item : selectedItems())
				{
					copyItems(item);
				}
				break;
			}
			case Qt::Key_V:
			{
				std::vector<QGraphicsItem*> newPastedItems;
				for (auto& item : copiedItems)
				{
					QGraphicsItem* newItem = clonePasteItems(item);
					if (newItem)
					{
						newItem->setPos(item->pos() + QPointF(20, 20));
						addItem(newItem);
						newPastedItems.push_back(newItem);
					}
				}
				copiedItems.swap(newPastedItems);
				break;
			}
			case Qt::Key_X:
			{
				// ����
				copiedItems.clear();
				for (auto& item : selectedItems())
				{
					copyItems(item);
					removeItem(item);
				}
				break;
			}
			case Qt::Key_Y:
			{
				// ����
				break;
			}
			default:
				QGraphicsScene::keyPressEvent(event);
		}
	}
	// ɾ��ѡ�е�ͼ��
	else if ((event->key() == Qt::Key_Backspace) && m_graphType == GraphType::CURSOR_TYPE)
	{
		for (auto& item : selectedItems())
		{
			removeItem(item);
		}
	}
	else
	{
		QGraphicsScene::keyPressEvent(event);
	}
}

void SvgScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if ((event->button() == Qt::LeftButton) && (m_graphType == CURSOR_TYPE))
	{
		if (m_isMoving)
		{
			m_isMoving = false;
		}
		else if (m_isSelecting)
		{
			m_isSelecting = false;
			m_startSelectPos = QPointF();
			if (m_selectRect)
			{
				removeItem(m_selectRect);
				//delete m_selectRect;
			}
		}
		else if (m_isResizing)
		{
			m_isResizing = false;
		}
	}
	else if ((event->button() == Qt::LeftButton) && m_isDrawing)
	{
		m_isDrawing = false;
		m_pointVec.emplace_back(event->scenePos());
		onDrawFinished(m_pointVec);
	}
}

void SvgScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	if ((m_isSelecting) && (m_graphType == CURSOR_TYPE))
	{
		// ��ѡ
		QRectF selectionRect = QRectF(m_startSelectPos, event->scenePos()).normalized();
		m_selectRect->setRect(selectionRect);

		for (QGraphicsItem* item : items())
		{
			// ��colliding���ж��Ƿ���ѡ�����
			m_selectRect->collidesWithItem(item)? item->setSelected(true) : item->setSelected(false);
		}
	}
	else if (m_isMoving && (m_graphType == CURSOR_TYPE))
	{
		// �ƶ�ͼ��
		QPointF newPos = event->scenePos();
		for (int i = 0; i < selectedItems().size(); ++i)
		{
			QGraphicsItem* item = selectedItems()[i];
			item->setPos(newPos - m_offSetVec[i]);
		}
	}
	else if (m_isResizing && (m_graphType == CURSOR_TYPE) && (event->modifiers() == Qt::AltModifier))
	{
		// �޸�ͼ�ο��
		QPointF newPos = event->scenePos();
		for (auto& item : selectedItems())
		{
			qreal offset = calculateOffset(newPos, item);
			qreal scale = 1 + offset / 100;
			item->setScale(scale);

		}
	}
	else if (m_isDrawing)	// ����ͼ��
	{
		switch (m_graphType)
		{
			case GraphType::PEN_TYPE:
			{
				drawPenItem(event);
				break;
			}
			case GraphType::LINE_TYPE:
			{
				drawLineItem(event);
				break;
			}
			case GraphType::CIRCLE_TYPE:
			{
				drawCircleItem(event);
				break;
			}
			case GraphType::RECTANGLE_TYPE:
			{
				drawRectItem(event);
				break;
			}
			case GraphType::PENTAGON_TYPE:
			{
				drawPentagonItem(event);
				break;
			}
			case GraphType::HEXAGON_TYPE:
			{
				drawHexagonItem(event);
				break;
			}
			case GraphType::STAR_TYPE:
			{
				drawStarItem(event);
				break;
			}
		}
	}
}

void SvgScene::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)
{
	// �Ҽ��˵�

}

void SvgScene::onDrawFinished(const std::vector<QPointF>& pointVec)
{
	switch (m_graphType)
	{
	case GraphType::CURSOR_TYPE:
		break;
	case GraphType::PEN_TYPE:
	{
		clearDrawingPath();	
		QPainterPath path;
		path.moveTo(m_pointVec[0]);
		for (const auto& point : m_pointVec)
		{
			path.lineTo(point.x(), point.y());
		}
		SvgPathItem* penItem = new SvgPathItem(path);
		addItem(penItem);
		break;
	}
	case GraphType::LINE_TYPE:
	{
		m_drawingVec.clear();
		break;
	}
	case GraphType::CIRCLE_TYPE:
	{
		m_drawingVec.clear();
		break;
	}
	case GraphType::RECTANGLE_TYPE:
	{
		m_drawingVec.clear();
		break;
	}
	case GraphType::PENTAGON_TYPE:
	{
		m_drawingVec.clear();
		break;
	}
	case GraphType::HEXAGON_TYPE:
	{
		m_drawingVec.clear();
		break;
	}
	case GraphType::STAR_TYPE:
	{
		m_drawingVec.clear();
		break;
	}
	case GraphType::TEXT_TYPE:
	{
		drawTextItem(pointVec);
		break;
	}
	default:
		break;
	}
}

void SvgScene::clearDrawingPath()
{
	for (auto& item : m_drawingVec)
		removeItem(item);
	m_drawingVec.clear();
}
