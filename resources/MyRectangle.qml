import QtQuick 2.8
import QtQuick.Window 2.2
import QtLocation 5.3
import QtPositioning 5.2

Rectangle{
        color: "red"
        width: 240
        height: 240

        MouseArea{
            anchors.fill: parent
            drag.target: parent
        }
}


