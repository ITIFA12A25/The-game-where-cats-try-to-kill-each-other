import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "client"

    // Central Content Area
    Rectangle {
        width: parent.width
        height: parent.height

        Column {
            anchors.centerIn: parent
            spacing: 20

            Label {
                text: "<html><head/><body><p><span style='font-size:50pt; font-weight:700;'>The Game Where Cats Try To Kill Each Other</span></p></body></html>"
                wrapMode: Text.Wrap
            }

            Row {
                spacing: 10
                anchors.horizontalCenter: parent.horizontalCenter

                Button {
                    text: "Replay"
                    onClicked: {

                    }
                }

                Button {
                    text: "Play"
                    onClicked: {

                    }
                }

                Button {
                    text: "Info"
                    onClicked: {

                    }
                }
            }
        }
    }
}
