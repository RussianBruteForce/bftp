#-------------------------------------------------
#
# Project created by QtCreator 2013-01-02T19:45:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bftpmaker
TEMPLATE = app


SOURCES += main.cpp\
        BftpMaker.cpp \
    IOFiles.cpp \
    Test.cpp \
    Question.cpp \
    Answer.cpp \
    AnswerEdit.cpp \
    TextEditor.cpp

HEADERS  += BftpMaker.h \
    IOFiles.h \
    Test.h \
    Question.h \
    Answer.h \
    AnswerEdit.h \
    TextEditor.h

FORMS    += BftpMaker.ui \
    AnswerEdit.ui

OTHER_FILES += \
    images/save.png \
    images/paste.png \
    images/open.png \
    images/new.png \
    images/cut.png \
    images/copy.png

RESOURCES += \
    textedit.qrc
