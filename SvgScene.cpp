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
	// 绘画路径
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
	// 没有clone函数，只能复制item中属性，然后新建一个item
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
	// 将准备粘贴的图形复制一份副本
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
	// 计算鼠标和图元边界的偏移量
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
		// 放大效果
		if (m_graphType == GraphType::GLASS_TYPE)
		{
			qreal currentScale = views().first()->transform().m11();
			views().first()->scale(1.2, 1.2);
		}

		m_startPosVec.clear();
		m_offSetVec.clear();
		if (m_graphType == GraphType::CURSOR_TYPE)
		{
			// 选中图形
			QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
			if (item)
			{
				// 按住alt键，缩放图片
				if (event->modifiers() == Qt::AltModifier)
				{
					m_isResizing = true;
				}

				// 如果按住Ctrl键，多选模式。否则单选。
				event->modifiers() == Qt::ControlModifier? item->setSelected(!item->isSelected()): item->setSelected(true);

				// 如果单个图形被选中，则记录鼠标按下的位置和图形与鼠标的偏移量
				if (item->isSelected())
				{
					m_startPosVec.push_back(event->scenePos());
					m_offSetVec.push_back(event->scenePos() - item->pos());
					m_isMoving = true;
				}

				// 如果多个图形被选中，更新鼠标按下的位置和图形与鼠标的偏移量
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
				// 框选
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
			// 如果是其他图形，则记录鼠标按下的位置
			m_isDrawing = true;
			// 检查是否正在画图
			m_pointVec.size() > 0 ? m_pointVec.clear() : m_pointVec;
			m_pointVec.push_back(event->scenePos());
		}
	}
}

void SvgScene::keyPressEvent(QKeyEvent* event)
{
	// ctrl + 一个键出发事件
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
				// 剪切
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
				// 重做
				break;
			}
			default:
				QGraphicsScene::keyPressEvent(event);
		}
	}
	// 删除选中的图形
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
		// 框选
		QRectF selectionRect = QRectF(m_startSelectPos, event->scenePos()).normalized();
		m_selectRect->setRect(selectionRect);

		for (QGraphicsItem* item : items())
		{
			// 用colliding来判断是否在选择框内
			m_selectRect->collidesWithItem(item)? item->setSelected(true) : item->setSelected(false);
		}
	}
	else if (m_isMoving && (m_graphType == CURSOR_TYPE))
	{
		// 移动图形
		QPointF newPos = event->scenePos();
		for (int i = 0; i < selectedItems().size(); ++i)
		{
			QGraphicsItem* item = selectedItems()[i];
			item->setPos(newPos - m_offSetVec[i]);
		}
	}
	else if (m_isResizing && (m_graphType == CURSOR_TYPE) && (event->modifiers() == Qt::AltModifier))
	{
		// 修改图形宽高
		QPointF newPos = event->scenePos();
		for (auto& item : selectedItems())
		{
			qreal offset = calculateOffset(newPos, item);
			qreal scale = 1 + offset / 100;
			item->setScale(scale);

		}
	}
	else if (m_isDrawing)	// 绘制图形
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
	// 右键菜单

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
