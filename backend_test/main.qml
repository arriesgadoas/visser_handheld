import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import sensors_detect 1.0
import sensors_read 1.0

Window {
   width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    DetectSensor{
        id: detectClass
     }

    ReadSensor{
        id: readClass
    }

    Button {
        id: scanButton
        anchors.centerIn:  parent
        text: "Scan for sensors"
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: -87
        onClicked: detectClass.detectSensors()
       }

    Button {
        id: readButton
        anchors.centerIn:  parent
        text: "Read sensors"
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 66
        onClicked: readClass.readSensors()
    }
}
