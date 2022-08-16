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
    QSize size = qApp->screens()[0]->size();
    QString sizeStringWidth = QString("(%1)").arg(size.width());
    QString sizeStringHeight = QString("(%1)").arg(size.height());
    sizeStringWidth.remove(0,1);
    sizeStringHeight.remove(0,1);
    sizeStringWidth.remove(')');
    sizeStringHeight.remove(')');

    QString screenSize = sizeStringWidth + "x" + sizeStringHeight;
    qDebug()<<"-----File-Status--------- ";
    qDebug()<<"Screen Size:" <<screenSize;
    qDebug()<<"File Name  :"<<fileName;
    qDebug()<<"------------------------- ";

    qDebug() << "runned....";

    /*
     * Sets the channel mode of the QProcess standard output and standard error channels to the mode specified.
     * This mode will be used the next time start() is called
     * */
    m_Process.setProcessChannelMode(QProcess::MergedChannels);
    QString cmd = "ffmpeg -f gdigrab -i desktop -framerate 60 -offset_x 0 -offset_y 0 -video_size "+ screenSize +" -pix_fmt yuv420p -vcodec libx264 -crf 18 -threads 1 C:/Users/msdemir/Desktop/"+ fileName +".avi";
    m_Process.start(cmd);
    //ffmpeg -f gdigrab -i desktop -filter:v fps=30 -offset_x 0 -offset_y 0 -video_size 1600x900 -pix_fmt yuv420p -vcodec libx264 -crf 18 -threads 2 C:/Users/msdemir/Desktop/out1.mp4


    qDebug()<<"-----Process-Status(Start)--------- ";
    qDebug()<< m_Process.state();
    qDebug()<< m_Process.atEnd();
    qDebug()<< m_Process.readAllStandardOutput();
    qDebug()<< m_Process.readAllStandardError();
    qDebug()<<"---------------------------- ";

}

void Record::stop()
{
    qDebug()<<"stopped...";
    m_Process.write("");
    m_Process.waitForFinished(5000);
    if (m_Process.state() != QProcess::NotRunning)
    {
        m_Process.close();
        m_Process.kill();

        qDebug()<<"stopped";
        qDebug()<<"-----Process-Status(Stop)--------- ";
        qDebug()<< m_Process.state();
        qDebug()<< m_Process.atEnd();
        qDebug()<<m_Process.readAllStandardOutput();
        qDebug()<< m_Process.readAllStandardError();
        qDebug()<<"---------------------------- ";
    }

}


QString Record::date()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh.mm.ss.z");

    return text;

}
