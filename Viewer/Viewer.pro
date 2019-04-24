QT += widgets
QT += gui
QT += network
FORMS += \
    viewer.ui

HEADERS += \
    SinaFinanceAPI.h \
    ViewerContent.h \
    viewer.h

SOURCES += \
    SinaFinanceAPI.cpp \
    ViewerContent.cpp \
    main.cpp \
    viewer.cpp

RC_ICONS = res/main_logo.ico
