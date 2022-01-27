#include "readsensor.h"
#include <linux/i2c-dev.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <QDebug>

#define ADDRESS 0x48

ReadSensor::ReadSensor(QObject *parent) : QObject(parent)
{

}

void ReadSensor::readSensors()
{
    //refer to https://xgoat.com/wp/2007/11/11/using-i2c-from-userspace-in-linux/
    int fd;
    uint16_t analogReadings[4] = {0};
    fd = open("/dev/i2c-1",O_RDWR);
    if(ioctl(fd, I2C_SLAVE,ADDRESS)<0){
        qDebug()<<"FAILED";
    }

    //use table 8  of ADS1115 datasheet for reference
    char config[3] = {0};
    config[0] = 0b00000001;
    config[1] = 0b01010010;
    config[2] = 0b10000011;
    char reg[1]={0x00};
    uint16_t raw_adc;
    uint8_t data[2] = {0};

    for(int i=0;i<5;i++){
        write(fd, config,3);
        write(fd,reg,1);
        read(fd,data,2);
        raw_adc=((data[0]<<8)+data[1]);

        if(raw_adc > 60000){       //fix for floating pins
            raw_adc=0;
        }

         //skip first read of conversion register
        if(i!=0){
            sleep(1);

            analogReadings[i-1]=raw_adc;
            qDebug()<<"Port "<<i<<":";
            qDebug()<<analogReadings[i-1];
            config[1]=config[1]+0b10000;
        }
    }
}
