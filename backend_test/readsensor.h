#ifndef READSENSOR_H
#define READSENSOR_H

#include <QObject>

class ReadSensor : public QObject
{
    Q_OBJECT
public:
    explicit ReadSensor(QObject *parent = nullptr);

signals:
public slots:
    void readSensors();

};

#endif // READSENSOR_H
