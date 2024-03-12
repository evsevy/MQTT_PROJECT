//***************************************** © MERKULOV E.V. 2024********************************************//

#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mqttclient.h" // #include <MQTTClient.h>
#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QtMqtt/QMqttTopicName>
#include <QFile>
#include <QTextStream>
#include <QDebug> // Если подключить проверку в код

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MQTTClient mqttClient;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mqttClient", &mqttClient);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}