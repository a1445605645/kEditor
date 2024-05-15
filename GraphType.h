#pragma once
#include <QMap>

enum GraphType{
	NONE_TYPE,
	CURSOR_TYPE,
	PEN_TYPE,
	LINE_TYPE,
	CIRCLE_TYPE,
	RECTANGLE_TYPE,
	PENTAGON_TYPE,
	HEXAGON_TYPE,
	STAR_TYPE,
	TEXT_TYPE,
	GLASS_TYPE
};

// ����һ��ӳ������ַ���ӳ�䵽Qt::PenStyleö��ֵ
static QMap<QString, Qt::PenStyle> styleMap = {
		{"SolidLine", Qt::SolidLine},
		{"DashLine", Qt::DashLine},
		{"DotLine", Qt::DotLine},
		{"DashDotLine", Qt::DashDotLine},
		{"DashDotDotLine", Qt::DashDotDotLine}
};
