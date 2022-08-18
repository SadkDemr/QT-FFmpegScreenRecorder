import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.1

Window {
    id:windows
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property int count: 0
    Rectangle {
        id: rectangle
        width: parent.width
        height: parent.height
        color: "#ffffff"

        TextField {
            id: textField
            x: 115
            y: 67
           placeholderText: qsTr("File Name")
           onPressed:{
              start.enabled = true
          }
        }

        Button {
            id: button
            x: 347
            y: 67
            text: qsTr("automatic")
            onClicked: {
                console.log(_myrecord.date());
                textField.text =  _myrecord.date();
             }
        }

        Button {
            id: start
            x: 176
            y: 144
            text: qsTr("Start")
            enabled: false
            onClicked:{

                _myrecord.startcmd(textField.text);
                timer.start();
                start.enabled = false;
                stop.enabled = true;
                        }
        }

        Button {
            id: stop
            x: 303
            y: 144
            text: qsTr("Stop")
            enabled: false
                        onClicked: {
                            _myrecord.stop();
                            count = 0
                            timer.stop();
                            start.enabled = true;
                            stop.enabled = false;
                            textField.text = _myrecord.date();
                        }
        }
        Timer {
          id: timer
          interval: 100
          running: false
          repeat: true
          onTriggered: count += 1
        }

        Text {
            id: text1
            x: 243
            y: 278
            width: 160
            height: 109
            text: (count / 10).toFixed(1)
            font.pixelSize: 50
        }
    }

}
