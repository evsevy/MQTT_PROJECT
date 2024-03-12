
#include "mqttclient.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <mqtt/client.h> // #include <MQTTClient.h> пример библиотеки для работы с MQTT

MQTTClient::MQTTClient(QObject *parent) : QObject(parent)
{
    mqttClient = new QMqttClient(this);
}

void MQTTClient::sendFileToMQTT(QString host, int port, QString username, QString password, QString topic, QString filepath)
{
    mqttClient->setHostname(host);
    mqttClient->setPort(port);
    mqttClient->setUsername(username);
    mqttClient->setPassword(password);
//Проверка подключения через ветвление
    if (!mqttClient->connectToHost()) {
        qDebug() << "Failed to connect to MQTT broker";
        return;
    }

    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        mqttClient->publish(QMqttTopicName(topic), line.toUtf8());
    }

    file.close();

    mqttClient->disconnectFromHost();

    qDebug() << "File sent to MQTT broker successfully";
}
// Подключение к MQTT брокеру с использованием переданных параметров
// Открытие файла по filepath и отправка содержимого построчно в топик topic
// Отправка сигнала с количеством отправленных сообщений