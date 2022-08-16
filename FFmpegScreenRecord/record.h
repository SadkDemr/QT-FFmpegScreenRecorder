#ifndef RECORD_H
#define RECORD_H

#include <QObject>
#include <QProcess>

class Record : public QObject
{
    Q_OBJECT
public:
    explicit Record(QObject *parent = nullptr);

signals:

public:
  Q_INVOKABLE  void startcmd(QString fileName);
  Q_INVOKABLE  void stop();
  Q_INVOKABLE  QString date();


private:
    QProcess m_Process;


};

#endif // RECORD_H
