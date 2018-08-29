import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    readonly property int count: dataProvider ? dataProvider.countFindedWords : 0
//    Binding {
//        target: dataProvider
//        property: "startUrl"
//        value: startUrl.text
//    }

//    Binding {
//        target: dataProvider
//        property: "countOfThreads"
//        value: countOfThreads.text
//    }

//    Binding {
//        target: dataProvider
//        property: "searchText"
//        value: searchText.text
//    }

//    Binding {
//        target: dataProvider
//        property: "maxCountScanningURL"
//        value: maxCountScanningURL.text
//    }

    ColumnLayout {

        anchors.centerIn: parent

        Label {
            id: findedWords

            Layout.fillWidth: true
            horizontalAlignment: Qt.AlignHCenter

            text: count

        }

        Label {
            id: startUrlLabel

            Layout.fillWidth: true
            horizontalAlignment: Qt.AlignHCenter

            text: qsTr("Start URL")
        }

        TextField {
            id: startUrlField

            Layout.fillWidth: true
        }

        Label {
            id: countOfThreadsLabel

            Layout.fillWidth: true
            horizontalAlignment: Qt.AlignHCenter

            text: qsTr("Count of threads")
        }

        TextField {
            id: countOfThreadsField

            Layout.fillWidth: true
        }

        Label {
            id: searchTextLabel

            Layout.fillWidth: true
            horizontalAlignment: Qt.AlignHCenter

            text: qsTr("Search text")
        }

        TextField {
            id: searchTextField

            Layout.fillWidth: true
        }

        Label {
            id: maxCountScanningUrlLabel

            Layout.fillWidth: true
            horizontalAlignment: Qt.AlignHCenter

            text: qsTr("Maximum count scanning URL")
        }

        TextField {
            id: maxCountScanningUrlField

            Layout.fillWidth: true
        }

        Label {
            id: controlButtonsLabel

            Layout.fillWidth: true
            horizontalAlignment: Qt.AlignHCenter

            text: qsTr("Controls")
        }

        RowLayout {
            id: controlButtons

            Button {
                text: qsTr("Start")

                onClicked: {
                    dataProvider.startURl = startUrlField.text;
                    dataProvider.countOfThreads = parseInt(countOfThreadsField.text);
                    dataProvider.searchText = searchTextField.text;
                    dataProvider.maxCountScanningURL = parseInt(maxCountScanningUrlField.text);

                    searchEngine.start();
                }
            }

            Button {
                text: qsTr("Stop")
            }

            Button {
                text: qsTr("Pause")

                onClicked: {
                    text = text === qsTr("Pause") ? qsTr("Resume") : qsTr("Pause");
                }
            }
        }
    }

}
