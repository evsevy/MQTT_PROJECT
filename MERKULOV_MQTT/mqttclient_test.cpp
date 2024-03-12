//***************************************** © MERKULOV E.V. 2024********************************************//

#include <QtTest>
#include "mqttclient.h"

class MqttClientTest : public QObject
{
    Q_OBJECT

private slots:
    void testSendMessages_data();
    void testSendMessages();
};

void MqttClientTest::testSendMessages_data()
{
    QTest::addColumn<QString>("filepath");
    QTest::addColumn<QString>("host");
    QTest::addColumn<int>("port");
    QTest::addColumn<QString>("username");
    QTest::addColumn<QString>("password");
    QTest::addColumn<QString>("topic");

    QTest::newRow("test1") << "test.txt" << "test.mosquitto.org" << 1884 << "rw" << "readwrite" << "piklema/test";
}

void MqttClientTest::testSendMessages()
{
    QFETCH(QString, filepath);
    QFETCH(QString, host);
    QFETCH(int, port);
    QFETCH(QString, username);
    QFETCH(QString, password);
    QFETCH(QString, topic);

    MqttClient mqttClient;
    QVERIFY(mqttClient.sendMessages(filepath, host, port, username, password, topic));
}

QTEST_APPLESS_MAIN(MqttClientTest)


