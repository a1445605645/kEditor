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

// 创建一个映射表，将字符串映射到Qt::PenStyle枚举值
static QMap<QString, Qt::PenStyle> styleMap = {
		{"SolidLine", Qt::SolidLine},
		{"DashLine", Qt::DashLine},
		{"DotLine", Qt::DotLine},
		{"DashDotLine", Qt::DashDotLine},
		{"DashDotDotLine", Qt::DashDotDotLine}
};
