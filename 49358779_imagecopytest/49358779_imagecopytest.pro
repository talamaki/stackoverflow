QT       += core gui widgets

TARGET = 49358779_imagecopytest
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp

HEADERS +=

win32 {
copydata.commands = $(COPY_DIR) $$shell_path($$PWD/test.png) $$shell_path($$OUT_PWD)
} else {
copydata.commands = $(COPY_DIR) $$PWD/settings.ini $$OUT_PWD
}
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
