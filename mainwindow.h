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
	// �޸�SvgView������-��ȡ��߶ȡ����ű�����������ɫ
	void onWidthChanged(const QString& width); //��textchanged�ź����ӣ�ͨ������setText()������
	void onHeightChanged(const QString& height);
	void onScaleChanged(const QString& scale);
	void onColorChanged();

	// ����SvgView��ѡ�е�ͼԪ��������-�߿��ȡ��߿���ʽ���߿���ɫ�������ɫ
	void onItemSelected();

	// �޸�SvgView��ѡ�е�ͼԪ������-�߿��ȡ��߿���ʽ���߿���ɫ�������ɫ
	void onItemBorderWidthChanged(const QString& width);
	void onItemBorderStyleChanged(const QString& style);
	void onItemBorderColorChanged();
	void onItemBrushColorChanged();

	// �˵���
	void onNewCanvasTriggered(); //ͨ��QAction��triggered�ź�����
	void onOpenFileTriggered();
	void onSaveFileTriggered();
	void onSaveAsPngFileTriggered();

	// ��ͼ
	void onCursorToggled(); // ���ѡ��
	void onPenToggled(); // ����
	void onLineToggled(); // ֱ��
	void onRectToggled(); // ����
	void onCircleToggled(); // Բ��
	void onPentagonToggled(); //�����
	void onHexagonToggled(); //������
	void onStarToggled(); //����
	void onTextToggled(); // �ı�
	void onGlassToggled(); // �Ŵ�

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
