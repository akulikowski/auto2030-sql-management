QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fahrzeugdetail.cpp \
    fahrzeugeinzel.cpp \
    fahrzeugliste.cpp \
    fahrzeugneu.cpp \
    kundedetail.cpp \
    kundeeinzel.cpp \
    kundeliste.cpp \
    kundeneu.cpp \
    main.cpp \
    mainwindow.cpp \
    reservierung.cpp \
    rueckgabe.cpp \
    vertrag.cpp

HEADERS += \
    fahrzeugdetail.h \
    fahrzeugeinzel.h \
    fahrzeugliste.h \
    fahrzeugneu.h \
    kundedetail.h \
    kundeeinzel.h \
    kundeliste.h \
    kundeneu.h \
    mainwindow.h \
    reservierung.h \
    rueckgabe.h \
    vertrag.h

FORMS += \
    fahrzeugdetail.ui \
    fahrzeugeinzel.ui \
    fahrzeugneu.ui \
    kundedetail.ui \
    kundeeinzel.ui \
    kundeneu.ui \
    mainwindow.ui \
    reservierung.ui \
    rueckgabe.ui \
    vertrag.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    symbole.qrc
