import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 1920
    height: 1080
    title: "Form"

    Rectangle {
        width: parent.width
        height: parent.height
        color: "white"

        Column {
            anchors.centerIn: parent
            spacing: 20

            Label {
                text: "The Game Where Cats Try To Kill Each Other"
                font.pointSize: 30
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
            }

            Row {
                spacing: 30
                anchors.horizontalCenter: parent.horizontalCenter

                Button {
                    text: "Back"
                    width: 71
                    height: 71
                    onClicked: {
                        // Insert action for Back button
                    }
                }

                Button {
                    text: "Info"
                    width: 71
                    height: 71
                    onClicked: {
                        // Insert action for Info button
                    }
                }

                Button {
                    width: 361
                    height: 501
                    icon.source: "resources/catest.jpeg"
                    icon.width: 100
                    icon.height: 100
                    flat: true
                    onClicked: {
                        // Insert action for this button
                    }
                }
            }
        }
    }
}
