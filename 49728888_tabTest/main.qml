import QtQuick 2.9
import QtQuick.Controls 1.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TabView {
        id: tabView

        function setTab2Text(txt) {
            tab2.tab2Text = txt
        }

        Tab
        {
            id: tab1
            title:'tab1'
            property string tab1Text: 'Test123'
            Text {
                id:test
                text: tab1.tab1Text
            }
        }
        Tab
        {
            id: tab2
            title:'tab2'
            property string tab2Text
            Text {
                id:test2
                text: tab2.tab2Text
            }
        }
        Component.onCompleted: setTab2Text('Test456')
    }
}
