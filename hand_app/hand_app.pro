QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core470 \
    -lopencv_highgui470 \
    -lopencv_imgproc470 \
    -lopencv_imgcodecs470 \
    -lopencv_videoio470 \
    -lopencv_features2d470 \
    -lopencv_calib3d470 \
    -lopencv_dnn470
