import QtQuick 2.8
import QtQuick.Window 2.2
import QtLocation 5.3
import QtPositioning 5.2
//import ExampleModule 1.0

//import "qrc:/components"
//import "qrc:/"
import "qrc:/"
//import "resources"
//import MyRectangle

Window {
    visible: true
    width: Screen.width
    height: Screen.height
    title: qsTr("Hello World")


    MyRectangle{
        id:myrect
    }

}
