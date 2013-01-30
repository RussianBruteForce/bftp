#-------------------------------------------------
#
# Project created by QtCreator 2013-01-02T19:43:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bftp
TEMPLATE = app


SOURCES += main.cpp\
        Bftp.cpp \
        ../bftpmaker/IOFiles.cpp \
        ../bftpmaker/Answer.cpp \
        ../bftpmaker/Question.cpp \
        ../bftpmaker/Test.cpp \
        AnswerWidget.cpp \
    ResultWidget.cpp

HEADERS  += Bftp.h \
        ../bftpmaker/IOFiles.h \
        ../bftpmaker/Answer.h \
        ../bftpmaker/Question.h \
        ../bftpmaker/Test.h \
        AnswerWidget.h \
    ResultWidget.h

FORMS    += Bftp.ui \
            AnswerWidget.ui \
    ResultWidget.ui
