//-------------------------------------------------------------------------
// “Record.cpp”
//-------------------------------------------------------------------------
/*
 * @Class Name(s): “Record”
 *
 * @Description: “Runs FFmpeg screen recording commands in cmd.exe using QProcess and provides recording of this recording in .avi format.”
 *
 *
 * @Note: “What should we pay attention to?”
 * ->Install FFmpeg library on computer
 *
 *
 * Version 0.0.1: “What are the units added?”
 *                ...
 *                17 AUGUST 2022 Wednesday, 13:15 – “Muhammed Sadık DEMIR”
 *
 *
 * @Author(s): “Muhammed Sadik DEMIR”
 *
 * @Mail(s):   “sadik.demir@dasal.com”
 *
 * Created on 10 AUGUST 2022 Wednesday, 10:20
 *
 * Copyright (C) 2020 DASAL I.C.
 */
//-------------------------------------------------------------------------
#include "record.h"
#include <QDebug>
#include <QDate>
#include <QElapsedTimer>
#include <QTime>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

Record::Record(QObject *parent)
    : QObject{parent}
{

}

void Record::startcmd(QString fileName)
{
    QSize size = qApp->screens()[0]->size();//Learn Computer screen size.
    QString sizeStringWidth = QString("(%1)").arg(size.width());//size to string (width)
    QString sizeStringHeight = QString("(%1)").arg(size.height());//size to string (height)
    sizeStringWidth.remove(0,1);//(1920) -> 1920)
    sizeStringHeight.remove(0,1);//(1080) -> 1080)
    sizeStringWidth.remove(')');//1920) -> 1920
    sizeStringHeight.remove(')');//1080) -> 1080

    QString screenSize = sizeStringWidth + "x" + sizeStringHeight;//Output-> 1920x1080
    qDebug()<<"-----File-Status--------- ";
    qDebug()<<"Screen Size:" <<screenSize;
    qDebug()<<"File Name  :"<<fileName;
    qDebug()<<"------------------------- ";

    qDebug() << "runned....";

    /*
     * Sets the channel mode of the QProcess standard output and standard error channels to the mode specified.
     * This mode will be used the next time start() is called
     * */
    m_Process->setProcessChannelMode(QProcess::MergedChannels);
    QString program = "cmd.exe";//QProcess has run cmd.exe
    QStringList arguments{
                         QStringLiteral("/C"),
                         QString("ffmpeg -f gdigrab -i desktop -framerate 60 -offset_x 0 -offset_y 0 -video_size "+ screenSize +" -pix_fmt yuv420p -vcodec libx264 -crf 18 -threads 1"),
                         QString("C:/Users/msdemir/Desktop/"+ fileName +".avi"),};
    m_Process->start(program,QStringList()<<arguments);
    //ffmpeg -f gdigrab -i desktop -filter:v fps=30 -offset_x 0 -offset_y 0 -video_size 1600x900 -pix_fmt yuv420p -vcodec libx264 -crf 18 -threads 2 C:/Users/msdemir/Desktop/out1.mp4


    qDebug()<<"-----Process-Status(Start)--------- ";
    qDebug()<< m_Process->state();
    qDebug()<< m_Process->atEnd();
    qDebug()<< m_Process->readAllStandardOutput();
    qDebug()<< m_Process->readAllStandardError();
    qDebug()<<"---------------------------- ";

}

void Record::stop()
{
    qDebug()<<"stopped...";
    m_Process->waitForFinished(1000);
    if (m_Process->isOpen())
        {

            m_Process->write("q");
            m_Process->kill();
            qDebug()<<"-----Process-Status(Stop)--------- ";
            qDebug()<< m_Process->state();
            qDebug()<< m_Process->atEnd();
           // qDebug()<< m_Process->readAllStandardOutput();
            qDebug()<< m_Process->readAllStandardError();
            qDebug()<<"---------------------------- ";
        }
}


QString Record::date()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh.mm.ss.z");

    return text;

}
