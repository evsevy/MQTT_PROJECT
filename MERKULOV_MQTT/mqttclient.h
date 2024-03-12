//***************************************** © MERKULOV E.V. 2024********************************************//

#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QObject>
#include <QMqttClient>

class MQTTClient : public QObject
{
    Q_OBJECT
public:
    explicit MQTTClient(QObject *parent = nullptr);

public slots:
    void sendFileToMQTT(QString host, int port, QString username, QString password, QString topic, QString filepath);

private:
    QMqttClient *mqttClient;
};

#endif // MQTTCLIENT_H