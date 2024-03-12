
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
	title: "MQTT File Sender"

    TextField {
        id: hostField
        placeholderText: "Host"
    }

    TextField {
        id: portField
        placeholderText: "Port"
    }

    TextField {
        id: usernameField
        placeholderText: "Username"
    }

    TextField {
        id: passwordField
        placeholderText: "Password"
    }

    TextField {
        id: topicField
        placeholderText: "Topic"
    }

    TextField {
        id: filepathField
        placeholderText: "Filepath"
    }

    Button {
		id: runButton
        text: "RUN"
        onClicked: mqttClient.sendFileToMQTT(hostField.text, parseInt(portField.text), usernameField.text, passwordField.text, topicField.text, filepathField.text)
    }
}