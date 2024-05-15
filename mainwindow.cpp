#include "mainwindow.h"
#include "SvgScene.h"
#include "SvgView.h"
#include "SvgPathItem.h"
#include "SvgLineItem.h"
#include "SvgCircleItem.h"
#include "SvgRectItem.h"
#include "SvgPolygonItem.h"
#include "SvgTextItem.h"

#include <QGraphicsSvgItem>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QSvgGenerator>
#include <QSvgRenderer>
#include <QtWidgets>
#include <QtSvg>

mainwindow::mainwindow(QWidget *parent)
	: QMainWindow(parent)
{
    ui.setupUi(this);

	initSvgView();

	// ��������
	connect(ui.widthLineEdit, &QLineEdit::textChanged, this, &mainwindow::onWidthChanged);
	connect(ui.heightLineEdit, &QLineEdit::textChanged, this, &mainwindow::onHeightChanged);
	connect(ui.scaleLineEdit, &QLineEdit::textChanged, this, &mainwindow::onScaleChanged);
	connect(ui.colorButton, &QPushButton::clicked, this, &mainwindow::onColorChanged);

	// �˵���
	connect(ui.newAction, &QAction::triggered, this, &mainwindow::onNewCanvasTriggered);
	connect(ui.openAction, &QAction::triggered, this, &mainwindow::onOpenFileTriggered);
	connect(ui.saveAction, &QAction::triggered, this, &mainwindow::onSaveFileTriggered);
	connect(ui.saveAsPngAction, &QAction::triggered, this, &mainwindow::onSaveAsPngFileTriggered);
	// ��ͼ������
	connect(ui.cursorAction, &QAction::toggled, this, &mainwindow::onCursorToggled);
	connect(ui.penAction, &QAction::toggled, this, &mainwindow::onPenToggled);
	connect(ui.lineAction, &QAction::toggled, this, &mainwindow::onLineToggled);
	connect(ui.rectAction, &QAction::toggled, this, &mainwindow::onRectToggled);
	connect(ui.circleAction, &QAction::toggled, this, &mainwindow::onCircleToggled);
	connect(ui.pentagonAction, &QAction::toggled, this, &mainwindow::onPentagonToggled);
	connect(ui.hexagonAction, &QAction::toggled, this, &mainwindow::onHexagonToggled);
	connect(ui.starAction, &QAction::toggled, this, &mainwindow::onStarToggled);
	connect(ui.textAction, &QAction::toggled, this, &mainwindow::onTextToggled);
	connect(ui.glassAction, &QAction::toggled, this, &mainwindow::onGlassToggled);
	// ͼԪ����
	connect(ui.itemWidthLineEdit, &QLineEdit::textChanged, this, &mainwindow::onItemBorderWidthChanged);
	connect(ui.itemBorderStyleComboBox, QOverload<const QString&>::of(&QComboBox::currentIndexChanged), this, &mainwindow::onItemBorderStyleChanged);
	connect(ui.itemBorderColorButton, &QPushButton::clicked, this, &mainwindow::onItemBorderColorChanged);
	connect(ui.itemBrushButton, &QPushButton::clicked, this, &mainwindow::onItemBrushColorChanged);
	// ѡ��ͼԪ
	connect(m_svgView->scene(), &SvgScene::selectionChanged, this, &mainwindow::onItemSelected);
}

void mainwindow::initSvgView()
{
	// ����һ��SvgView����
	m_svgView = new SvgView(new SvgScene(), ui.canvasWidget);
	m_svgView->setStyleSheet("background-color: white");
	m_svgView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_svgView->setMinimumSize(1600, 1000);
	ui.canvasLayout->addWidget(m_svgView, 0, Qt::AlignCenter);

	// ��ʼ����������
	ui.widthLineEdit->setText("1600");
	ui.heightLineEdit->setText("1000");
	ui.scaleLineEdit->setText("100");
	ui.colorButton->setStyleSheet("background-color: white");
	// ����SvgItem����
	ui.itemWidthGroup->setVisible(false);
	ui.itemBorderStyleGroup->setVisible(false);
	ui.itemBorderColorGroup->setVisible(false);
	ui.itemBrushGroup->setVisible(false);
}

void mainwindow::createSvgView()
{
	// ɾ��ԭ�е�SvgView����
	if (m_svgView)
	{
		ui.canvasLayout->removeWidget(m_svgView);
		delete m_svgView;
	}
	// ����һ���µ�SvgView����
	initSvgView();
}

void mainwindow::showSvgFile(const QString& fileName)
{
	m_svgItem = new QGraphicsSvgItem(fileName);
	m_svgItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
	
	// m_svgViewû��scene,������Ҫ����scene
	m_svgView->setScene(new QGraphicsScene(this));
	m_svgView->scene()->addItem(m_svgItem);
	m_svgView->fitInView(m_svgItem, Qt::KeepAspectRatio);
	m_svgView->update();

	// ���û�������
	ui.widthLineEdit->setText(QString::number(m_svgItem->boundingRect().width()));
	ui.heightLineEdit->setText(QString::number(m_svgItem->boundingRect().height()));
	ui.scaleLineEdit->setText("100");
}

void mainwindow::onWidthChanged(const QString& width)
{
	if (m_svgView && !width.isEmpty())
	{
		m_svgView->setFixedWidth(width.toInt());
	}
}

void mainwindow::onHeightChanged(const QString& height)
{
	if (m_svgView && !height.isEmpty())
	{
		m_svgView->setFixedHeight(height.toInt());
	}
}

void mainwindow::onScaleChanged(const QString& scale)
{
	if (m_svgView && !scale.isEmpty())
	{
		m_svgView->setTransform(QTransform::fromScale(scale.toDouble() / 100, scale.toDouble() / 100));
	}
}

void mainwindow::onColorChanged()
{
	qDebug() << "onColorChanged";
	QColor color = QColorDialog::getColor(m_svgColor, this, tr("ѡ�񻭲���ɫ"));
	if (color.isValid())
	{
		m_svgColor = color;
		ui.colorButton->setStyleSheet(QString("background-color: %1").arg(m_svgColor.name()));
		m_svgView->setStyleSheet(QString("background-color: %1").arg(m_svgColor.name()));
	}
}

void mainwindow::onItemSelected()
{
	// ��ȡ��ǰѡ�е�����ͼԪ
	QList<QGraphicsItem*> selectedItems = m_svgView->scene()->selectedItems();

	if (selectedItems.isEmpty()|| selectedItems.size()>1) {
		// ���û���κ�ͼԪ��ѡ�У����������Ա༭�ؼ�
		ui.itemWidthGroup->setVisible(false);
		ui.itemBorderStyleGroup->setVisible(false);
		ui.itemBorderColorGroup->setVisible(false);
		ui.itemBrushGroup->setVisible(false);
	}
	else {
		// �����ͼԪ��ѡ�У�����ʾ���Ա༭�ؼ�
		ui.itemWidthGroup->setVisible(true);
		ui.itemBorderStyleGroup->setVisible(true);
		ui.itemBorderColorGroup->setVisible(true);
		ui.itemBrushGroup->setVisible(true);

		QGraphicsItem* selectedItem = selectedItems.first();
		// ����ͼԪ������ñ߿���
		switch (selectedItem->type())
		{
		case SvgPathItem::Type:
			ui.itemWidthLineEdit->setText(QString::number(qgraphicsitem_cast<SvgPathItem*>(selectedItem)->getItemBorderWidth()));
			ui.itemBorderStyleComboBox->setCurrentIndex(ui.itemBorderStyleComboBox->findText(styleMap.key(qgraphicsitem_cast<SvgPathItem*>(selectedItem)->getItemBorderStyle())));
			ui.itemBorderColorButton->setStyleSheet(QString("background-color: %1").arg(qgraphicsitem_cast<SvgPathItem*>(selectedItem)->getItemBorderColor().name()));
			break;
		case SvgLineItem::Type:
			ui.itemWidthLineEdit->setText(QString::number(qgraphicsitem_cast<SvgLineItem*>(selectedItem)->getItemBorderWidth()));
			ui.itemBorderStyleComboBox->setCurrentIndex(ui.itemBorderStyleComboBox->findText(styleMap.key(qgraphicsitem_cast<SvgLineItem*>(selectedItem)->getItemBorderStyle())));
			ui.itemBorderColorButton->setStyleSheet(QString("background-color: %1").arg(qgraphicsitem_cast<SvgLineItem*>(selectedItem)->getItemBorderColor().name()));
			break;
		case SvgCircleItem::Type:
			ui.itemWidthLineEdit->setText(QString::number(qgraphicsitem_cast<SvgCircleItem*>(selectedItem)->getItemBorderWidth()));
			ui.itemBorderStyleComboBox->setCurrentIndex(ui.itemBorderStyleComboBox->findText(styleMap.key(qgraphicsitem_cast<SvgCircleItem*>(selectedItem)->getItemBorderStyle())));
			ui.itemBorderColorButton->setStyleSheet(QString("background-color: %1").arg(qgraphicsitem_cast<SvgCircleItem*>(selectedItem)->getItemBorderColor().name()));
			ui.itemBrushButton->setStyleSheet(QString("background-color: %1").arg(qgraphicsitem_cast<SvgCircleItem*>(selectedItem)->getItemBrushColor().name()));
			break;
		case SvgRectItem::Type:
			ui.itemWidthLineEdit->setText(QString::number(qgraphicsitem_cast<SvgRectItem*>(selectedItem)->getItemBorderWidth()));
			ui.itemBorderStyleComboBox->setCurrentIndex(ui.itemBorderStyleComboBox->findText(styleMap.key(qgraphicsitem_cast<SvgRectItem*>(selectedItem)->getItemBorderStyle())));
			ui.itemBorderColorButton->setStyleSheet(QString("background-color: %1").arg(qgraphicsitem_cast<SvgRectItem*>(selectedItem)->getItemBorderColor().name()));
			ui.itemBrushButton->setStyleSheet(QString("background-color: %1").arg(qgraphicsitem_cast<SvgRectItem*>(selectedItem)->getItemBrushColor().name()));
			break;
		case SvgPolygonItem::Type:
			ui.itemWidthLineEdit->setText(QString::number(qgraphicsitem_cast<SvgPolygonItem*>(selectedItem)->getItemBorderWidth()));
			ui.itemBorderStyleComboBox->setCurrentIndex(ui.itemBorderStyleComboBox->findText(styleMap.key(qgraphicsitem_cast<SvgPolygonItem*>(selectedItem)->getItemBorderStyle())));
			ui.itemBorderColorButton->setStyleSheet(QString("background-color: %1").arg(qgraphicsitem_cast<SvgPolygonItem*>(selectedItem)->getItemBorderColor().name()));
			ui.itemBrushButton->setStyleSheet(QString("background-color: %1").arg(qgraphicsitem_cast<SvgPolygonItem*>(selectedItem)->getItemBrushColor().name()));
			break;
		}
	}
}

void mainwindow::onItemBorderWidthChanged(const QString& width)
{
	if (m_svgView && !width.isEmpty())
	{
		QGraphicsItem* selectedItem = m_svgView->scene()->selectedItems().first();
		qDebug() << selectedItem->type();
		qDebug() << SvgLineItem::Type;
		// ����ͼԪ������ñ߿���
		switch (selectedItem->type())
		{
			case SvgPathItem::Type:
				qgraphicsitem_cast<SvgPathItem*>(selectedItem)->setItemBorderWidth(width.toDouble());
				break;
			case SvgLineItem::Type:
				qgraphicsitem_cast<SvgLineItem*>(selectedItem)->setItemBorderWidth(width.toDouble());
				break;
			case SvgCircleItem::Type:
				qgraphicsitem_cast<SvgCircleItem*>(selectedItem)->setItemBorderWidth(width.toDouble());
				break;
			case SvgRectItem::Type:
				qgraphicsitem_cast<SvgRectItem*>(selectedItem)->setItemBorderWidth(width.toDouble());
				break;
			case SvgPolygonItem::Type:
				qgraphicsitem_cast<SvgPolygonItem*>(selectedItem)->setItemBorderWidth(width.toDouble());
				break;
			default:
				break;
		}
		m_svgView->scene()->update();
	}

}

void mainwindow::onItemBorderStyleChanged(const QString& style)
{
	// style: "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine"
	// ʹ��ӳ�������ȡ��Ӧ��Qt::PenStyleö��ֵ
	Qt::PenStyle penStyle = styleMap[style];
	if (m_svgView && !style.isEmpty())
	{
		QGraphicsItem* selectedItem = m_svgView->scene()->selectedItems().first();
		// ����ͼԪ������ñ߿���ʽ
		switch (selectedItem->type())
		{
		case SvgPathItem::Type:
			qgraphicsitem_cast<SvgPathItem*>(selectedItem)->setItemBorderStyle(penStyle);
			break;
		case SvgLineItem::Type:
			qgraphicsitem_cast<SvgLineItem*>(selectedItem)->setItemBorderStyle(penStyle);
			break;
		case SvgCircleItem::Type:
			qgraphicsitem_cast<SvgCircleItem*>(selectedItem)->setItemBorderStyle(penStyle);
			break;
		case SvgRectItem::Type:
			qgraphicsitem_cast<SvgRectItem*>(selectedItem)->setItemBorderStyle(penStyle);
			break;
		case SvgPolygonItem::Type:
			qgraphicsitem_cast<SvgPolygonItem*>(selectedItem)->setItemBorderStyle(penStyle);
			break;
		default:
			break;
		}
		m_svgView->scene()->update();
	}
}

void mainwindow::onItemBorderColorChanged()
{
	QColor color = QColorDialog::getColor(Qt::black, this, tr("ѡ��߿���ɫ"));
	if (color.isValid())
	{
		QGraphicsItem* selectedItem = m_svgView->scene()->selectedItems().first();
		// ����ͼԪ������ñ߿���ɫ
		switch (selectedItem->type())
		{
			case SvgPathItem::Type:
				qgraphicsitem_cast<SvgPathItem*>(selectedItem)->setItemBorderColor(color);
				break;
			case SvgLineItem::Type:
				qgraphicsitem_cast<SvgLineItem*>(selectedItem)->setItemBorderColor(color);
				break;
			case SvgCircleItem::Type:
				qgraphicsitem_cast<SvgCircleItem*>(selectedItem)->setItemBorderColor(color);
				break;
			case SvgRectItem::Type:
				qgraphicsitem_cast<SvgRectItem*>(selectedItem)->setItemBorderColor(color);
				break;
			case SvgPolygonItem::Type:
				qgraphicsitem_cast<SvgPolygonItem*>(selectedItem)->setItemBorderColor(color);
				break;
			default:
				break;
		}
		m_svgView->scene()->update();
	}
}

void mainwindow::onItemBrushColorChanged()
{
	QColor color = QColorDialog::getColor(Qt::black, this, tr("ѡ�������ɫ"));
	if (color.isValid())
	{
		QGraphicsItem* selectedItem = m_svgView->scene()->selectedItems().first();
		// ����ͼԪ������������ɫ
		switch (selectedItem->type())
		{
			case SvgCircleItem::Type:
				qgraphicsitem_cast<SvgCircleItem*>(selectedItem)->setItemBrushColor(color);
				break;
			case SvgRectItem::Type:
				qgraphicsitem_cast<SvgRectItem*>(selectedItem)->setItemBrushColor(color);
				break;
			case SvgPolygonItem::Type:
				qgraphicsitem_cast<SvgPolygonItem*>(selectedItem)->setItemBrushColor(color);
				break;
			default:
				break;
		}
		m_svgView->scene()->update();
	}
}

void mainwindow::onNewCanvasTriggered()
{
	QMessageBox::information(this, tr("��ʾ"), tr("�½������ɹ�"));
	createSvgView();
}

void mainwindow::onOpenFileTriggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("�½��ļ�"), ".", tr("SVG�ļ�(*.svg)"));
	if (!fileName.isEmpty())
	{
		createSvgView();
		showSvgFile(fileName);
	}
}

void mainwindow::onSaveFileTriggered()
{
	// ��svgView����Ϊsvg�ļ�
	QString fileName = QFileDialog::getSaveFileName(this, tr("�����ļ�"), ".", tr("SVG�ļ�(*.svg)"));
	if (!fileName.isEmpty())
	{
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly))
		{
			QMessageBox::warning(this, tr("����"), tr("�޷������ļ�: %1").arg(file.errorString()));
		}
		else
		{
			QSvgGenerator generator;
			generator.setFileName(fileName);
			QPainter painter;
			painter.begin(&generator);
			m_svgView->render(&painter);
			painter.end();
		}
	}
}

void mainwindow::onSaveAsPngFileTriggered()
{
	// ��svgView����Ϊpng�ļ�
	QString fileName = QFileDialog::getSaveFileName(this, tr("�����ļ�"), ".", tr("PNG�ļ�(*.png)"));
	if (!fileName.isEmpty())
	{
		QImage image(m_svgView->size(), QImage::Format_ARGB32);
		QPainter painter(&image);
		m_svgView->render(&painter);
		image.save(fileName);
	}
}

void mainwindow::onCursorToggled()
{
	// �任���ͼ��
	ui.cursorAction->isChecked() ? ui.cursorAction->setIcon(QIcon(":/mainwindow/icons_cursor_click.png")) : ui.cursorAction->setIcon(QIcon(":/mainwindow/icons_cursor.png"));

	// �������ʽ����Ϊpng
	QCursor cursor;
	cursor = QCursor(Qt::ArrowCursor);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::CURSOR_TYPE);
	}
}

void mainwindow::onPenToggled()
{
	ui.penAction->isChecked() ? ui.penAction->setIcon(QIcon(":/mainwindow/icons_pen_click.png")) : ui.penAction->setIcon(QIcon(":/mainwindow/icons_pen.png"));

	// �������ʽ����Ϊpng
	QCursor cursor;
	cursor = QCursor(QPixmap(":/mainwindow/icons_pen.png"), 0, 0);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::PEN_TYPE);
	}
}

void mainwindow::onLineToggled()
{
	ui.lineAction->isChecked() ? ui.lineAction->setIcon(QIcon(":/mainwindow/icons_line_click.png")) : ui.lineAction->setIcon(QIcon(":/mainwindow/icons_line.png"));

	QCursor cursor;
	cursor = QCursor(Qt::CrossCursor);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::LINE_TYPE);
	}

}

void mainwindow::onRectToggled()
{
	ui.rectAction->isChecked() ? ui.rectAction->setIcon(QIcon(":/mainwindow/icons_rectangle_click.png")) : ui.rectAction->setIcon(QIcon(":/mainwindow/icons_rectangle.png"));

	QCursor cursor;
	cursor = QCursor(Qt::CrossCursor);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::RECTANGLE_TYPE);
	}
}

void mainwindow::onCircleToggled()
{
	ui.circleAction->isChecked() ? ui.circleAction->setIcon(QIcon(":/mainwindow/icons_circle_click.png")) : ui.circleAction->setIcon(QIcon(":/mainwindow/icons_circle.png"));

	QCursor cursor;
	cursor = QCursor(Qt::CrossCursor);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::CIRCLE_TYPE);
	}
}

void mainwindow::onPentagonToggled()
{
	ui.pentagonAction->isChecked() ? ui.pentagonAction->setIcon(QIcon(":/mainwindow/icons_pentagon_click.png")) : ui.pentagonAction->setIcon(QIcon(":/mainwindow/icons_pentagon.png"));

	QCursor cursor;
	cursor = QCursor(Qt::CrossCursor);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::PENTAGON_TYPE);
	}
}

void mainwindow::onHexagonToggled()
{
	ui.hexagonAction->isChecked() ? ui.hexagonAction->setIcon(QIcon(":/mainwindow/icons_hexagon_click.png")) : ui.hexagonAction->setIcon(QIcon(":/mainwindow/icons_hexagon.png"));

	QCursor cursor;
	cursor = QCursor(Qt::CrossCursor);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::HEXAGON_TYPE);
	}
}

void mainwindow::onStarToggled()
{
	ui.starAction->isChecked() ? ui.starAction->setIcon(QIcon(":/mainwindow/icons_star_click.png")) : ui.starAction->setIcon(QIcon(":/mainwindow/icons_star.png"));

	QCursor cursor;
	cursor = QCursor(Qt::CrossCursor);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::STAR_TYPE);
	}
}

void mainwindow::onTextToggled()
{
	ui.textAction->isChecked() ? ui.textAction->setIcon(QIcon(":/mainwindow/icons_T_click.png")) : ui.textAction->setIcon(QIcon(":/mainwindow/icons_T.png"));

	QCursor cursor;
	cursor = QCursor(QPixmap(":/mainwindow/icons_T.png"), 0, 0);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::TEXT_TYPE);
	}
}

void mainwindow::onGlassToggled()
{
	ui.glassAction->isChecked() ? ui.glassAction->setIcon(QIcon(":/mainwindow/icons_glass_click.png")) : ui.glassAction->setIcon(QIcon(":/mainwindow/icons_glass.png"));

	QCursor cursor;
	cursor = QCursor(QPixmap(":/mainwindow/icons_glass.png"), 0, 0);
	m_svgView->setCursor(cursor);

	if (m_svgView)
	{
		m_svgView->setGraphType(GraphType::GLASS_TYPE);
	}
}
