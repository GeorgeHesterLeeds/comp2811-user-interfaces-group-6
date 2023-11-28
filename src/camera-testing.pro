QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp

HEADERS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

macOS {
    QMAKE_INFO_PLIST = static/macos/Info.plist
}

# Release:DESTDIR = release
# Release:OBJECTS_DIR = release/.obj

# Debug:DESTDIR = debug
# Debug:OBJECTS_DIR = debug/.obj

#DESTDIR = $$PWD/../build/$${BUILD_NAME}/$${BUILD_TYPE}_$${BUILD_PLATFORM}
#OBJECTS_DIR = $${DESTDIR}/.objects
#MOC_DIR = $${DESTDIR}/.moc
#RCC_DIR = $${DESTDIR}/.rcc
#UI_DIR = $${DESTDIR}/.ui
