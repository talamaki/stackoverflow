import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function initializeProviders(anObject) {
        for (var prop in anObject) {
            console.log("Object item:", prop, "=", anObject[prop])
        }
    }

    Text {
        id: textLabel
        anchors.centerIn: parent
        text: qsTr("text")
    }
}
