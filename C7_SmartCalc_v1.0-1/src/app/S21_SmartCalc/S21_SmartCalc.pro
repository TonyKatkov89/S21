QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculation.c \
    creditpayments.cpp \
    graph.cpp \
    main.cpp \
    mortgage.cpp \
    parcing.c \
    qcustomplot.cpp \
    s21_smartcalc.cpp \
    scale.cpp \
    structs.c

HEADERS += \
    calculation.h \
    creditpayments.h \
    graph.h \
    mortgage.h \
    parcing.h \
    qcustomplot.h \
    s21_smartcalc.h \
    scale.h \
    structs.h

FORMS += \
    creditpayments.ui \
    graph.ui \
    mortgage.ui \
    s21_smartcalc.ui \
    scale.ui

# Default rules for deployment.
qnx: target.path = ../build/$${TARGET}/bin
else: unix:!android: target.path = ../build/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
