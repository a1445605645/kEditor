#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "SvgView.h"
#include <QGraphicsSvgItem>

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() = default;

public slots:
	// 修改SvgView的属性-宽度、高度、缩放比例、背景颜色
	void onWidthChanged(const QString& width); //用textchanged信号连接，通过调用setText()来触发
	void onHeightChanged(const QString& height);
	void onScaleChanged(const QString& scale);
	void onColorChanged();

	// 根据SvgView中选中的图元更新属性-边框宽度、边框样式、边框颜色、填充颜色
	void onItemSelected();

	// 修改SvgView中选中的图元的属性-边框宽度、边框样式、边框颜色、填充颜色
	void onItemBorderWidthChanged(const QString& width);
	void onItemBorderStyleChanged(const QString& style);
	void onItemBorderColorChanged();
	void onItemBrushColorChanged();

	// 菜单栏
	void onNewCanvasTriggered(); //通过QAction的triggered信号连接
	void onOpenFileTriggered();
	void onSaveFileTriggered();
	void onSaveAsPngFileTriggered();

	// 画图
	void onCursorToggled(); // 光标选择
	void onPenToggled(); // 画笔
	void onLineToggled(); // 直线
	void onRectToggled(); // 矩形
	void onCircleToggled(); // 圆形
	void onPentagonToggled(); //五边形
	void onHexagonToggled(); //六边形
	void onStarToggled(); //星星
	void onTextToggled(); // 文本
	void onGlassToggled(); // 放大镜

private:
	void initSvgView();
	void createSvgView(); 
	void showSvgFile(const QString& fileName);

private:
    Ui::mainwindowClass ui;
    SvgView* m_svgView;
	QGraphicsSvgItem* m_svgItem;
	QColor m_svgColor;
};
