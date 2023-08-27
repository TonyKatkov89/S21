/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <oglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_as_Picture;
    QAction *actionExport_to_GIF;
    QAction *actionSave_Settings;
    QAction *actionLoad_Settings;
    QAction *actionReset_Settings;
    QAction *action_4;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *LFileName;
    QLabel *LNumberV;
    QLabel *LNumberE;
    QGroupBox *scalingGB;
    QDoubleSpinBox *scaleSB;
    QGroupBox *movingGB;
    QLabel *label;
    QDoubleSpinBox *moveX;
    QLabel *label_2;
    QDoubleSpinBox *moveY;
    QLabel *label_3;
    QDoubleSpinBox *moveZ;
    QGroupBox *rotatingGB;
    QLabel *label_4;
    QDoubleSpinBox *rotateX;
    QLabel *label_5;
    QDoubleSpinBox *rotateY;
    QLabel *label_6;
    QDoubleSpinBox *rotateZ;
    QGroupBox *projectionGB;
    QRadioButton *pParallel;
    QRadioButton *pCentral;
    QGroupBox *edgesGB;
    QPushButton *BBackgroundE;
    QRadioButton *eDashed;
    QRadioButton *eSolid;
    QLabel *label_7;
    QDoubleSpinBox *eWidth;
    QGroupBox *verticesGB;
    QPushButton *BBackgroundV;
    QRadioButton *vSquare;
    QRadioButton *vCircle;
    QLabel *label_8;
    QDoubleSpinBox *vSize;
    QRadioButton *vNone;
    QGroupBox *groupBox_8;
    QPushButton *BBackground;
    QFrame *line;
    QFrame *line_2;
    OGLWidget *openGLWidget;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QMenuBar *menubar;
    QMenu *menuOpen;
    QMenu *menuEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1310, 864);
        MainWindow->setMinimumSize(QSize(1310, 864));
        MainWindow->setMaximumSize(QSize(1310, 864));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_as_Picture = new QAction(MainWindow);
        actionSave_as_Picture->setObjectName(QString::fromUtf8("actionSave_as_Picture"));
        actionExport_to_GIF = new QAction(MainWindow);
        actionExport_to_GIF->setObjectName(QString::fromUtf8("actionExport_to_GIF"));
        actionSave_Settings = new QAction(MainWindow);
        actionSave_Settings->setObjectName(QString::fromUtf8("actionSave_Settings"));
        actionLoad_Settings = new QAction(MainWindow);
        actionLoad_Settings->setObjectName(QString::fromUtf8("actionLoad_Settings"));
        actionReset_Settings = new QAction(MainWindow);
        actionReset_Settings->setObjectName(QString::fromUtf8("actionReset_Settings"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_4->setVisible(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(840, 20, 451, 801));
        LFileName = new QLabel(groupBox);
        LFileName->setObjectName(QString::fromUtf8("LFileName"));
        LFileName->setGeometry(QRect(10, 10, 431, 41));
        LFileName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        LFileName->setWordWrap(true);
        LNumberV = new QLabel(groupBox);
        LNumberV->setObjectName(QString::fromUtf8("LNumberV"));
        LNumberV->setGeometry(QRect(10, 70, 431, 16));
        LNumberE = new QLabel(groupBox);
        LNumberE->setObjectName(QString::fromUtf8("LNumberE"));
        LNumberE->setGeometry(QRect(10, 90, 431, 16));
        scalingGB = new QGroupBox(groupBox);
        scalingGB->setObjectName(QString::fromUtf8("scalingGB"));
        scalingGB->setGeometry(QRect(10, 120, 131, 81));
        scaleSB = new QDoubleSpinBox(scalingGB);
        scaleSB->setObjectName(QString::fromUtf8("scaleSB"));
        scaleSB->setGeometry(QRect(10, 40, 111, 26));
        scaleSB->setDecimals(1);
        scaleSB->setMinimum(1.000000000000000);
        scaleSB->setSingleStep(0.100000000000000);
        movingGB = new QGroupBox(groupBox);
        movingGB->setObjectName(QString::fromUtf8("movingGB"));
        movingGB->setGeometry(QRect(10, 210, 431, 91));
        label = new QLabel(movingGB);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 67, 17));
        moveX = new QDoubleSpinBox(movingGB);
        moveX->setObjectName(QString::fromUtf8("moveX"));
        moveX->setGeometry(QRect(10, 50, 111, 26));
        moveX->setDecimals(1);
        moveX->setMinimum(-100.000000000000000);
        moveX->setSingleStep(0.100000000000000);
        label_2 = new QLabel(movingGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 30, 67, 17));
        moveY = new QDoubleSpinBox(movingGB);
        moveY->setObjectName(QString::fromUtf8("moveY"));
        moveY->setGeometry(QRect(140, 50, 111, 26));
        moveY->setDecimals(1);
        moveY->setMinimum(-100.000000000000000);
        moveY->setSingleStep(0.100000000000000);
        label_3 = new QLabel(movingGB);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 30, 67, 17));
        moveZ = new QDoubleSpinBox(movingGB);
        moveZ->setObjectName(QString::fromUtf8("moveZ"));
        moveZ->setGeometry(QRect(270, 50, 111, 26));
        moveZ->setDecimals(1);
        moveZ->setMinimum(-100.000000000000000);
        moveZ->setSingleStep(0.100000000000000);
        rotatingGB = new QGroupBox(groupBox);
        rotatingGB->setObjectName(QString::fromUtf8("rotatingGB"));
        rotatingGB->setGeometry(QRect(10, 310, 431, 91));
        label_4 = new QLabel(rotatingGB);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 67, 17));
        rotateX = new QDoubleSpinBox(rotatingGB);
        rotateX->setObjectName(QString::fromUtf8("rotateX"));
        rotateX->setGeometry(QRect(10, 50, 111, 26));
        rotateX->setDecimals(1);
        rotateX->setMinimum(-100.000000000000000);
        rotateX->setSingleStep(0.100000000000000);
        label_5 = new QLabel(rotatingGB);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 30, 67, 17));
        rotateY = new QDoubleSpinBox(rotatingGB);
        rotateY->setObjectName(QString::fromUtf8("rotateY"));
        rotateY->setGeometry(QRect(140, 50, 111, 26));
        rotateY->setDecimals(1);
        rotateY->setMinimum(-100.000000000000000);
        rotateY->setSingleStep(0.100000000000000);
        label_6 = new QLabel(rotatingGB);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 30, 67, 17));
        rotateZ = new QDoubleSpinBox(rotatingGB);
        rotateZ->setObjectName(QString::fromUtf8("rotateZ"));
        rotateZ->setGeometry(QRect(270, 50, 111, 26));
        rotateZ->setDecimals(1);
        rotateZ->setMinimum(-100.000000000000000);
        rotateZ->setSingleStep(0.100000000000000);
        projectionGB = new QGroupBox(groupBox);
        projectionGB->setObjectName(QString::fromUtf8("projectionGB"));
        projectionGB->setGeometry(QRect(160, 120, 131, 81));
        pParallel = new QRadioButton(projectionGB);
        pParallel->setObjectName(QString::fromUtf8("pParallel"));
        pParallel->setGeometry(QRect(10, 20, 112, 23));
        pParallel->setChecked(true);
        pCentral = new QRadioButton(projectionGB);
        pCentral->setObjectName(QString::fromUtf8("pCentral"));
        pCentral->setGeometry(QRect(10, 50, 112, 23));
        edgesGB = new QGroupBox(groupBox);
        edgesGB->setObjectName(QString::fromUtf8("edgesGB"));
        edgesGB->setGeometry(QRect(10, 410, 431, 91));
        BBackgroundE = new QPushButton(edgesGB);
        BBackgroundE->setObjectName(QString::fromUtf8("BBackgroundE"));
        BBackgroundE->setGeometry(QRect(10, 40, 111, 32));
        eDashed = new QRadioButton(edgesGB);
        eDashed->setObjectName(QString::fromUtf8("eDashed"));
        eDashed->setGeometry(QRect(140, 60, 112, 23));
        eSolid = new QRadioButton(edgesGB);
        eSolid->setObjectName(QString::fromUtf8("eSolid"));
        eSolid->setGeometry(QRect(140, 30, 112, 23));
        eSolid->setChecked(true);
        label_7 = new QLabel(edgesGB);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 30, 81, 17));
        eWidth = new QDoubleSpinBox(edgesGB);
        eWidth->setObjectName(QString::fromUtf8("eWidth"));
        eWidth->setGeometry(QRect(270, 50, 111, 26));
        eWidth->setDecimals(0);
        eWidth->setMinimum(1.000000000000000);
        eWidth->setSingleStep(1.000000000000000);
        verticesGB = new QGroupBox(groupBox);
        verticesGB->setObjectName(QString::fromUtf8("verticesGB"));
        verticesGB->setGeometry(QRect(10, 510, 431, 91));
        BBackgroundV = new QPushButton(verticesGB);
        BBackgroundV->setObjectName(QString::fromUtf8("BBackgroundV"));
        BBackgroundV->setGeometry(QRect(10, 40, 111, 32));
        vSquare = new QRadioButton(verticesGB);
        vSquare->setObjectName(QString::fromUtf8("vSquare"));
        vSquare->setGeometry(QRect(140, 60, 112, 23));
        vCircle = new QRadioButton(verticesGB);
        vCircle->setObjectName(QString::fromUtf8("vCircle"));
        vCircle->setGeometry(QRect(140, 40, 112, 23));
        label_8 = new QLabel(verticesGB);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(270, 30, 67, 17));
        vSize = new QDoubleSpinBox(verticesGB);
        vSize->setObjectName(QString::fromUtf8("vSize"));
        vSize->setGeometry(QRect(270, 50, 111, 26));
        vSize->setDecimals(1);
        vSize->setMinimum(1.000000000000000);
        vSize->setSingleStep(0.100000000000000);
        vNone = new QRadioButton(verticesGB);
        vNone->setObjectName(QString::fromUtf8("vNone"));
        vNone->setGeometry(QRect(140, 20, 112, 23));
        vNone->setChecked(true);
        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(310, 120, 131, 81));
        BBackground = new QPushButton(groupBox_8);
        BBackground->setObjectName(QString::fromUtf8("BBackground"));
        BBackground->setGeometry(QRect(10, 40, 111, 32));
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 50, 431, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 110, 431, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        openGLWidget = new OGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(20, 20, 801, 801));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 10, 801, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(20, 820, 801, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 20, 16, 801));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(820, 20, 16, 801));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1310, 24));
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuOpen->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuOpen->addAction(actionOpen);
        menuOpen->addSeparator();
        menuOpen->addAction(actionSave_as_Picture);
        menuOpen->addSeparator();
        menuOpen->addAction(actionExport_to_GIF);
        menuEdit->addAction(actionSave_Settings);
        menuEdit->addSeparator();
        menuEdit->addAction(actionLoad_Settings);
        menuEdit->addAction(action_4);
        menuEdit->addSeparator();
        menuEdit->addAction(actionReset_Settings);
        menuEdit->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3DViewer 1.0", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as_Picture->setText(QCoreApplication::translate("MainWindow", "Save as Picture", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as_Picture->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExport_to_GIF->setText(QCoreApplication::translate("MainWindow", "Export to GIF", nullptr));
#if QT_CONFIG(shortcut)
        actionExport_to_GIF->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_Settings->setText(QCoreApplication::translate("MainWindow", "Save Settings", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_Settings->setShortcut(QCoreApplication::translate("MainWindow", "Meta+Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad_Settings->setText(QCoreApplication::translate("MainWindow", "Load Settings", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad_Settings->setShortcut(QCoreApplication::translate("MainWindow", "Meta+Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReset_Settings->setText(QCoreApplication::translate("MainWindow", "Reset Settings", nullptr));
#if QT_CONFIG(shortcut)
        actionReset_Settings->setShortcut(QCoreApplication::translate("MainWindow", "Meta+Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        action_4->setText(QCoreApplication::translate("MainWindow", "Apply Settings", nullptr));
#if QT_CONFIG(shortcut)
        action_4->setShortcut(QCoreApplication::translate("MainWindow", "Meta+Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QString());
        LFileName->setText(QCoreApplication::translate("MainWindow", "File Name: ", nullptr));
        LNumberV->setText(QCoreApplication::translate("MainWindow", "Number of Vertices: ", nullptr));
        LNumberE->setText(QCoreApplication::translate("MainWindow", "Number of Edges: ", nullptr));
        scalingGB->setTitle(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        movingGB->setTitle(QCoreApplication::translate("MainWindow", "Moving", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
        rotatingGB->setTitle(QCoreApplication::translate("MainWindow", "Rotating", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
        projectionGB->setTitle(QCoreApplication::translate("MainWindow", "Projection", nullptr));
        pParallel->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        pCentral->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        edgesGB->setTitle(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        BBackgroundE->setText(QCoreApplication::translate("MainWindow", "Change Color", nullptr));
        eDashed->setText(QCoreApplication::translate("MainWindow", "Dashed", nullptr));
        eSolid->setText(QCoreApplication::translate("MainWindow", "Solid", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Thickness", nullptr));
        verticesGB->setTitle(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        BBackgroundV->setText(QCoreApplication::translate("MainWindow", "Change Color", nullptr));
        vSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        vCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        vNone->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Background", nullptr));
        BBackground->setText(QCoreApplication::translate("MainWindow", "Change Color", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
