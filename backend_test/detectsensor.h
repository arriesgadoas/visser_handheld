#ifndef DETECTSENSOR_H
#define DETECTSENSOR_H

#include <QObject>

using namespace std;

class DetectSensor : public QObject
{
    Q_OBJECT
public:
    explicit DetectSensor(QObject *parent = nullptr);

signals:

public slots:
    void detectSensors();

};

#endif // DETECTSENSOR_H
