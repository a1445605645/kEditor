/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H
#pragma execution_character_set("utf-8")
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QColorDialog>
#include <QPushButton>
#include <QPalette>
#include <QtWidgets/QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>


QT_BEGIN_NAMESPACE

class Ui_mainwindowClass
{
public:
    QAction* undoAction;
    QAction* redoAction;
    QAction* cutAction;
    QAction* copyAction;
    QAction* pasteAction;
    QAction* deleteAction;
    QAction* newAction;
    QAction* openAction;
    QAction* saveAction;
    QAction* saveAsPngAction;
    QAction* cursorAction;
    QAction* penAction;
    QAction* lineAction;
    QAction* circleAction;
    QAction* rectAction;
    QAction* pentagonAction;
    QAction* hexagonAction;
    QAction* starAction;
    QAction* textAction;
    QAction* glassAction;

	// 画布属性
    QWidget* centralwidget;
    QHBoxLayout* horizontalLayout;
    QWidget* canvasWidget;
	QHBoxLayout* canvasLayout;
    QWidget* statusWidget;
    QLabel* label;
    QWidget* layoutWidget;
    QGridLayout* statusGridLayout;
    QGroupBox* heightGroup;
    QLabel* heightLabel;
    QLineEdit* heightLineEdit;
    QGroupBox* colorGroup;
    QLabel* colorLabel;
    QPushButton* colorButton;
    QGroupBox* scaleGroup;
    QLabel* scaleLabel;
    QLineEdit* scaleLineEdit;
    QGroupBox* widthGroup;
    QLabel* widthLabel;
    QLineEdit* widthLineEdit;
    QMenuBar* menubar;
    QMenu* docMenu;
    QToolBar* toolBar;
	QActionGroup* toolActionGroup;

	// SvgItem属性
	QGroupBox* itemWidthGroup;
	QLabel* itemWidthLabel;
	QLineEdit* itemWidthLineEdit;

	QGroupBox* itemBorderStyleGroup;
    QLabel* itemBorderStyleLabel;
	QComboBox* itemBorderStyleComboBox;

    QGroupBox* itemBorderColorGroup;
	QLabel* itemBorderColorLabel;
	QPushButton* itemBorderColorButton;

	QGroupBox* itemBrushGroup;
	QLabel* itemBrushLabel;
	QPushButton* itemBrushButton;

    // 文本属性框
    QGroupBox* textFontGroup;
    QLabel* textFontLabel;
    QComboBox* textFontBox;


    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName(QStringLiteral("mainwindowClass"));
        mainwindowClass->resize(1600, 1000);
        mainwindowClass->setMinimumSize(QSize(800, 600));
        undoAction = new QAction(mainwindowClass);
        undoAction->setObjectName(QStringLiteral("undoAction"));
        redoAction = new QAction(mainwindowClass);
        redoAction->setObjectName(QStringLiteral("redoAction"));
        cutAction = new QAction(mainwindowClass);
        cutAction->setObjectName(QStringLiteral("cutAction"));
        copyAction = new QAction(mainwindowClass);
        copyAction->setObjectName(QStringLiteral("copyAction"));
        pasteAction = new QAction(mainwindowClass);
        pasteAction->setObjectName(QStringLiteral("pasteAction"));
        deleteAction = new QAction(mainwindowClass);
        deleteAction->setObjectName(QStringLiteral("deleteAction"));
        newAction = new QAction(mainwindowClass);
        newAction->setObjectName(QStringLiteral("newAction"));
        openAction = new QAction(mainwindowClass);
        openAction->setObjectName(QStringLiteral("openAction"));
        saveAction = new QAction(mainwindowClass);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        saveAsPngAction = new QAction(mainwindowClass);
        saveAsPngAction->setObjectName(QStringLiteral("saveAsPngAction"));
        cursorAction = new QAction(mainwindowClass);
        cursorAction->setObjectName(QStringLiteral("cursorAction"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/mainwindow/icons_cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        cursorAction->setIcon(icon);
        cursorAction->setMenuRole(QAction::NoRole);
        penAction = new QAction(mainwindowClass);
        penAction->setObjectName(QStringLiteral("penAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/mainwindow/icons_pen.png"), QSize(), QIcon::Normal, QIcon::Off);
        penAction->setIcon(icon1);
        penAction->setMenuRole(QAction::NoRole);
        lineAction = new QAction(mainwindowClass);
        lineAction->setObjectName(QStringLiteral("lineAction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/mainwindow/icons_line.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineAction->setIcon(icon2);
        lineAction->setMenuRole(QAction::NoRole);
        circleAction = new QAction(mainwindowClass);
        circleAction->setObjectName(QStringLiteral("circleAction"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/mainwindow/icons_circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        circleAction->setIcon(icon3);
        circleAction->setMenuRole(QAction::NoRole);
        rectAction = new QAction(mainwindowClass);
        rectAction->setObjectName(QStringLiteral("rectAction"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/mainwindow/icons_rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectAction->setIcon(icon4);
        rectAction->setMenuRole(QAction::NoRole);
        pentagonAction = new QAction(mainwindowClass);
        pentagonAction->setObjectName(QStringLiteral("pentagonAction"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/mainwindow/icons_pentagon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pentagonAction->setIcon(icon5);
        pentagonAction->setMenuRole(QAction::NoRole);
        hexagonAction = new QAction(mainwindowClass);
        hexagonAction->setObjectName(QStringLiteral("hexagonAction"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/mainwindow/icons_hexagon.png"), QSize(), QIcon::Normal, QIcon::Off);
        hexagonAction->setIcon(icon6);
        hexagonAction->setMenuRole(QAction::NoRole);
        starAction = new QAction(mainwindowClass);
        starAction->setObjectName(QStringLiteral("starAction"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/mainwindow/icons_star.png"), QSize(), QIcon::Normal, QIcon::Off);
        starAction->setIcon(icon7);
        starAction->setMenuRole(QAction::NoRole);
        textAction = new QAction(mainwindowClass);
        textAction->setObjectName(QStringLiteral("textAction"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/mainwindow/icons_T.png"), QSize(), QIcon::Normal, QIcon::Off);
        textAction->setIcon(icon8);
        textAction->setMenuRole(QAction::NoRole);
        glassAction = new QAction(mainwindowClass);
        glassAction->setObjectName(QStringLiteral("glassAction"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/mainwindow/icons_glass.png"), QSize(), QIcon::Normal, QIcon::Off);
        glassAction->setIcon(icon9);
        glassAction->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(mainwindowClass);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        canvasWidget = new QWidget(centralwidget);
        canvasWidget->setObjectName(QStringLiteral("canvasWidget"));
        canvasWidget->setMinimumSize(QSize(400, 300));
        canvasWidget->setStyleSheet(QStringLiteral("background-color: rgb(117, 117, 117);"));
		canvasLayout = new QHBoxLayout(canvasWidget);
		canvasLayout->setObjectName(QStringLiteral("canvasLayout"));



        horizontalLayout->addWidget(canvasWidget);

        statusWidget = new QWidget(centralwidget);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        statusWidget->setEnabled(true);
        statusWidget->setMinimumSize(QSize(168, 200));
        statusWidget->setMaximumSize(QSize(500, 999999));
		QColor color(Qt::white);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        statusWidget->setFont(font);
        statusWidget->setStyleSheet(QStringLiteral("background-color: rgb(117, 117, 117);"));
        label = new QLabel(statusWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 291, 31));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        label->setFont(font1);
        layoutWidget = new QWidget(statusWidget);   
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
		layoutWidget->setGeometry(QRect(40, 40, 414, 1600));// 
        
        statusGridLayout = new QGridLayout(layoutWidget);
        statusGridLayout->setObjectName(QStringLiteral("statusGridLayout"));
		statusGridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        statusGridLayout->setContentsMargins(5, 5, 5, 5);

		// 画布属性
        heightGroup = new QGroupBox(layoutWidget);
        heightGroup->setObjectName(QStringLiteral("heightGroup"));
        heightGroup->setMinimumSize(QSize(70, 70));
        heightGroup->setMaximumSize(QSize(200, 200));
        QFont font2;
        font2.setBold(true);
        heightGroup->setFont(font2);
        heightGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
        heightLabel = new QLabel(heightGroup);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));
        heightLabel->setGeometry(QRect(40, 20, 120, 40));
        heightLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        heightLabel->setFont(font3);
        heightLabel->setAlignment(Qt::AlignCenter);
        heightLineEdit = new QLineEdit(heightGroup);
        heightLineEdit->setObjectName(QStringLiteral("heightLineEdit"));
        heightLineEdit->setGeometry(QRect(25, 120, 151, 51));
        heightLineEdit->setFont(font3);
        heightLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        heightLineEdit->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);

        statusGridLayout->addWidget(heightGroup, 0, 1, 1, 1);

        colorGroup = new QGroupBox(layoutWidget);
        colorGroup->setObjectName(QStringLiteral("colorGroup"));
        colorGroup->setMinimumSize(QSize(70, 70));
        colorGroup->setMaximumSize(QSize(200, 200));
        colorGroup->setFont(font2);
        colorGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
        colorLabel = new QLabel(colorGroup);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));
        colorLabel->setGeometry(QRect(40, 20, 120, 40));
        colorLabel->setFont(font3);
        colorLabel->setAlignment(Qt::AlignCenter);
        colorLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        colorButton = new QPushButton(colorGroup);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        colorButton->setGeometry(QRect(25, 120, 151, 51));
        QFont font4;
        font4.setPointSize(16);
        colorButton->setFont(font4);

        statusGridLayout->addWidget(colorGroup, 1, 1, 1, 1);

        scaleGroup = new QGroupBox(layoutWidget);
        scaleGroup->setObjectName(QStringLiteral("scaleGroup"));
        scaleGroup->setMinimumSize(QSize(70, 70));
        scaleGroup->setMaximumSize(QSize(200, 200));
        scaleGroup->setFont(font2);
        scaleGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
        scaleLabel = new QLabel(scaleGroup);
        scaleLabel->setObjectName(QStringLiteral("scaleLabel"));
        scaleLabel->setGeometry(QRect(40, 20, 120, 40));
        scaleLabel->setFont(font3);
        scaleLabel->setAlignment(Qt::AlignCenter);
        scaleLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        scaleLineEdit = new QLineEdit(scaleGroup);
        scaleLineEdit->setObjectName(QStringLiteral("scaleLineEdit"));
        scaleLineEdit->setGeometry(QRect(25, 120, 151, 51));
        QFont font5;
        font5.setPointSize(15);
        font5.setBold(true);
        scaleLineEdit->setFont(font5);
		scaleLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        scaleLineEdit->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);

        statusGridLayout->addWidget(scaleGroup, 1, 0, 1, 1);

        widthGroup = new QGroupBox(layoutWidget);
        widthGroup->setObjectName(QStringLiteral("widthGroup"));
        widthGroup->setMinimumSize(QSize(70, 70));
        widthGroup->setMaximumSize(QSize(200, 200));
        widthGroup->setFont(font2);
        widthGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
        widthLabel = new QLabel(widthGroup);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));
        widthLabel->setGeometry(QRect(40, 20, 120, 40));
        widthLabel->setFont(font3);
        widthLabel->setAlignment(Qt::AlignCenter);
        widthLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        widthLineEdit = new QLineEdit(widthGroup);
        widthLineEdit->setObjectName(QStringLiteral("widthLineEdit"));
        widthLineEdit->setGeometry(QRect(25, 120, 151, 51));
        widthLineEdit->setFont(font3);
        widthLineEdit->setCursor(QCursor(Qt::IBeamCursor));
		widthLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        widthLineEdit->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);

        statusGridLayout->addWidget(widthGroup, 0, 0, 1, 1);

		// SvgItem属性
		itemWidthGroup = new QGroupBox(layoutWidget);
		itemWidthGroup->setObjectName(QStringLiteral("itemWidthGroup"));
		itemWidthGroup->setMinimumSize(QSize(70, 70));
		itemWidthGroup->setMaximumSize(QSize(200, 200));
		itemWidthGroup->setFont(font2);
		itemWidthGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
		itemWidthLabel = new QLabel(itemWidthGroup);
		itemWidthLabel->setObjectName(QStringLiteral("itemWidthLabel"));
		itemWidthLabel->setGeometry(QRect(40, 20, 120, 40));
		itemWidthLabel->setFont(font3);
		itemWidthLabel->setAlignment(Qt::AlignCenter);
		itemWidthLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
		itemWidthLineEdit = new QLineEdit(itemWidthGroup);
		itemWidthLineEdit->setObjectName(QStringLiteral("itemWidthLineEdit"));
		itemWidthLineEdit->setGeometry(QRect(25, 120, 151, 51));
		itemWidthLineEdit->setFont(font3);
		itemWidthLineEdit->setCursor(QCursor(Qt::IBeamCursor));
		itemWidthLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
		itemWidthLineEdit->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);

		statusGridLayout->addWidget(itemWidthGroup, 2, 0, 1, 1);

		itemBorderStyleGroup = new QGroupBox(layoutWidget);
		itemBorderStyleGroup->setObjectName(QStringLiteral("itemBorderStyleGroup"));
		itemBorderStyleGroup->setMinimumSize(QSize(70, 70));
		itemBorderStyleGroup->setMaximumSize(QSize(200, 200));
		itemBorderStyleGroup->setFont(font2);
		itemBorderStyleGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
		itemBorderStyleLabel = new QLabel(itemBorderStyleGroup);
		itemBorderStyleLabel->setObjectName(QStringLiteral("itemBorderStyleLabel"));
		itemBorderStyleLabel->setGeometry(QRect(40, 20, 120, 40));
		itemBorderStyleLabel->setFont(font3);
		itemBorderStyleLabel->setAlignment(Qt::AlignCenter);
		itemBorderStyleLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
		itemBorderStyleComboBox = new QComboBox(itemBorderStyleGroup);
		itemBorderStyleComboBox->setObjectName(QStringLiteral("itemBorderStyleComboBox"));
		itemBorderStyleComboBox->setGeometry(QRect(25, 120, 151, 51));
		itemBorderStyleComboBox->setFont(font2);
		itemBorderStyleComboBox->setCursor(QCursor(Qt::IBeamCursor));
		itemBorderStyleComboBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

		statusGridLayout->addWidget(itemBorderStyleGroup, 2, 1, 1, 1);

		itemBorderColorGroup = new QGroupBox(layoutWidget);
		itemBorderColorGroup->setObjectName(QStringLiteral("itemBorderColorGroup"));
		itemBorderColorGroup->setMinimumSize(QSize(70, 70));
		itemBorderColorGroup->setMaximumSize(QSize(200, 200));
		itemBorderColorGroup->setFont(font2);
		itemBorderColorGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
		itemBorderColorLabel = new QLabel(itemBorderColorGroup);
		itemBorderColorLabel->setObjectName(QStringLiteral("itemBorderColorLabel"));
		itemBorderColorLabel->setGeometry(QRect(40, 20, 120, 40));
		itemBorderColorLabel->setFont(font3);
		itemBorderColorLabel->setAlignment(Qt::AlignCenter);
		itemBorderColorLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
		itemBorderColorButton = new QPushButton(itemBorderColorGroup);
		itemBorderColorButton->setObjectName(QStringLiteral("itemBorderColorButton"));
		itemBorderColorButton->setGeometry(QRect(25, 120, 151, 51));
		itemBorderColorButton->setFont(font4);

		statusGridLayout->addWidget(itemBorderColorGroup, 3, 0, 1, 1);

		itemBrushGroup = new QGroupBox(layoutWidget);
		itemBrushGroup->setObjectName(QStringLiteral("itemBrushGroup"));
		itemBrushGroup->setMinimumSize(QSize(70, 70));
		itemBrushGroup->setMaximumSize(QSize(200, 200));
		itemBrushGroup->setFont(font2);
		itemBrushGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
		itemBrushLabel = new QLabel(itemBrushGroup);
		itemBrushLabel->setObjectName(QStringLiteral("itemBrushLabel"));
		itemBrushLabel->setGeometry(QRect(40, 20, 120, 40));
		itemBrushLabel->setFont(font3);
		itemBrushLabel->setAlignment(Qt::AlignCenter);
		itemBrushLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
		itemBrushButton = new QPushButton(itemBrushGroup);
		itemBrushButton->setObjectName(QStringLiteral("itemBrushButton"));
		itemBrushButton->setGeometry(QRect(25, 120, 151, 51));
		itemBrushButton->setFont(font4);

		statusGridLayout->addWidget(itemBrushGroup, 3, 1, 1, 1);

		textFontGroup = new QGroupBox(layoutWidget);
		textFontGroup->setObjectName(QStringLiteral("textFontGroup"));
		textFontGroup->setMinimumSize(QSize(70, 70));
		textFontGroup->setMaximumSize(QSize(200, 200));
		textFontGroup->setFont(font2);
		textFontGroup->setStyleSheet(QStringLiteral("background-color: rgb(59, 58, 58);"));
		textFontLabel = new QLabel(textFontGroup);
		textFontLabel->setObjectName(QStringLiteral("textFontLabel"));
		textFontLabel->setGeometry(QRect(40, 20, 120, 40));
		textFontLabel->setFont(font3);
		textFontLabel->setAlignment(Qt::AlignCenter);
		textFontLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
		textFontBox = new QComboBox(textFontGroup);
		textFontBox->setObjectName(QStringLiteral("textFontBox"));
		textFontBox->setGeometry(QRect(25, 120, 151, 51));
		textFontBox->setFont(font2);
		textFontBox->setCursor(QCursor(Qt::IBeamCursor));
		textFontBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

		statusGridLayout->addWidget(textFontGroup, 4, 0, 1, 1);

		// 添加弹簧
		statusGridLayout->setRowStretch(0, 2);
		statusGridLayout->setRowStretch(1, 2);
		statusGridLayout->setRowStretch(2, 2);
		statusGridLayout->setRowStretch(3, 2);
		statusGridLayout->setRowStretch(4, 2);
		statusGridLayout->setColumnStretch(0, 1);

        horizontalLayout->addWidget(statusWidget);
        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 4);
        mainwindowClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindowClass);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        docMenu = new QMenu(menubar);
        docMenu->setObjectName(QStringLiteral("docMenu"));
        mainwindowClass->setMenuBar(menubar);
        toolBar = new QToolBar(mainwindowClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        mainwindowClass->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(docMenu->menuAction());
        docMenu->addAction(newAction);
        docMenu->addAction(openAction);
        docMenu->addAction(saveAction);
        docMenu->addAction(saveAsPngAction);
        toolBar->addAction(cursorAction);
        toolBar->addAction(penAction);
        toolBar->addAction(lineAction);
        toolBar->addAction(circleAction);
        toolBar->addAction(rectAction);
        toolBar->addAction(pentagonAction);
        toolBar->addAction(hexagonAction);
        toolBar->addAction(starAction);
        toolBar->addAction(textAction);
        toolBar->addAction(glassAction);

        toolActionGroup = new QActionGroup(toolBar);
        toolActionGroup->setObjectName(QStringLiteral("toolActionGroup"));

		toolActionGroup->addAction(cursorAction);
		toolActionGroup->addAction(penAction);
		toolActionGroup->addAction(lineAction);
		toolActionGroup->addAction(circleAction);
		toolActionGroup->addAction(rectAction);
		toolActionGroup->addAction(pentagonAction);
		toolActionGroup->addAction(hexagonAction);
		toolActionGroup->addAction(starAction);
		toolActionGroup->addAction(textAction);
		toolActionGroup->addAction(glassAction);

        retranslateUi(mainwindowClass);

        QMetaObject::connectSlotsByName(mainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowClass)
    {
        mainwindowClass->setWindowTitle(QApplication::translate("mainwindowClass", "mainwindow", Q_NULLPTR));
        undoAction->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
        redoAction->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232", Q_NULLPTR));
        cutAction->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", Q_NULLPTR));
        copyAction->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
        pasteAction->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
        deleteAction->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        newAction->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", Q_NULLPTR));
        openAction->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200SVG", Q_NULLPTR));
        saveAction->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        saveAsPngAction->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272PNG", Q_NULLPTR));
        cursorAction->setText(QApplication::translate("MainWindow", "\345\205\211\346\240\207", Q_NULLPTR));
        penAction->setText(QApplication::translate("MainWindow", "\347\254\224", Q_NULLPTR));
        lineAction->setText(QApplication::translate("MainWindow", "\347\272\277\346\235\241", Q_NULLPTR));
        circleAction->setText(QApplication::translate("MainWindow", "\345\234\206", Q_NULLPTR));
        rectAction->setText(QApplication::translate("MainWindow", "\347\237\251\345\275\242", Q_NULLPTR));
        pentagonAction->setText(QApplication::translate("MainWindow", "\344\272\224\350\276\271\345\275\242", Q_NULLPTR));
        hexagonAction->setText(QApplication::translate("MainWindow", "\345\205\255\350\276\271\345\275\242", Q_NULLPTR));
        starAction->setText(QApplication::translate("MainWindow", "\346\230\237\346\230\237", Q_NULLPTR));
        textAction->setText(QApplication::translate("MainWindow", "\346\226\207\346\234\254", Q_NULLPTR));
        glassAction->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247\351\225\234", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        heightGroup->setTitle(QString());
        heightLabel->setText(QApplication::translate("MainWindow", "\347\224\273\345\270\203\351\253\230\345\272\246", Q_NULLPTR));
        colorGroup->setTitle(QString());
        colorLabel->setText(QApplication::translate("MainWindow", "\347\224\273\345\270\203\351\242\234\350\211\262", Q_NULLPTR));
        colorButton->setText(QString());
        scaleGroup->setTitle(QString());
        scaleLabel->setText(QApplication::translate("MainWindow", "\347\274\251\346\224\276\346\257\224\344\276\213", Q_NULLPTR));
        widthGroup->setTitle(QString());
        widthLabel->setText(QApplication::translate("MainWindow", "\347\224\273\345\270\203\345\256\275\345\272\246", Q_NULLPTR));
		itemWidthGroup->setTitle(QString());
		itemWidthLabel->setText(QApplication::translate("MainWindow", "边框宽度", Q_NULLPTR));
		itemBorderStyleGroup->setTitle(QString());
		itemBorderStyleLabel->setText(QApplication::translate("MainWindow", "边框样式", Q_NULLPTR));
		itemBorderColorGroup->setTitle(QString());
		itemBorderColorLabel->setText(QApplication::translate("MainWindow", "边框颜色", Q_NULLPTR));
		itemBrushGroup->setTitle(QString());
		itemBrushLabel->setText(QApplication::translate("MainWindow", "填充颜色", Q_NULLPTR));

		itemWidthLineEdit->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
		itemBorderColorButton->setText(QString());
		itemBrushButton->setText(QString());

        itemBorderStyleComboBox->addItem(QApplication::translate("MainWindow", "SolidLine", Q_NULLPTR));
        itemBorderStyleComboBox->addItem(QApplication::translate("MainWindow", "DashLine", Q_NULLPTR));
        itemBorderStyleComboBox->addItem(QApplication::translate("MainWindow", "DotLine", Q_NULLPTR));
        itemBorderStyleComboBox->addItem(QApplication::translate("MainWindow", "DashDotLine", Q_NULLPTR));
        itemBorderStyleComboBox->addItem(QApplication::translate("MainWindow", "DashDotDotLine", Q_NULLPTR));

		itemBorderStyleComboBox->setCurrentIndex(0);
		itemBorderStyleComboBox->setStyleSheet("background-color: white");
        itemBorderColorButton->setStyleSheet("background-color: black");
        itemBrushButton->setStyleSheet("background-color: white");

        docMenu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        toolBar->setMovable(false);
        toolBar->setContextMenuPolicy(Qt::PreventContextMenu);// 工具栏禁用右键菜单
        toolBar->setStyleSheet("QToolBar { spacing: 20px; }");// 设置工具栏按钮间隔
        toolBar->setIconSize(QSize(50, 50));// 设置工具栏按钮大小
        menubar->setContextMenuPolicy(Qt::PreventContextMenu);
        	
		cursorAction->setCheckable(true);
		penAction->setCheckable(true);
		lineAction->setCheckable(true);
		circleAction->setCheckable(true);
		rectAction->setCheckable(true);
		pentagonAction->setCheckable(true);
		hexagonAction->setCheckable(true);
		starAction->setCheckable(true);
		textAction->setCheckable(true);
		glassAction->setCheckable(true);

    } // retranslateUi

};

namespace Ui {
    class mainwindowClass: public Ui_mainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
