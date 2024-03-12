***************************************** © MERKULOV E.V. 2024********************************************

Для начала необходимо установить Qt и библиотеку для работы с MQTT. 
Установите также библиотеку Eclipse Paho MQTT C, следуя инструкциям на официальном сайте.
Для этого выполним следующие команды в терминале окна Linux:
sudo apt-get update
sudo apt-get install qt5-default qtdeclarative5-dev qml-module-qtquick-controls qml-module-qtquick-layouts qml-module-qtquick-dialogs libmosquitto-dev
sudo apt-get install libmosquitto-dev

Инструкция по сборке и запуску программы:

1. Установите Qt Framework на вашу операционную систему
2. Создайте новый проект Qt с помощью Qt Creator
3. Добавьте файлы main.cpp, mqttclient.h, mqttclient.cpp и main.qml в проект
4. Соберите проект с помощью qmake и make
5. Запустите исполняемый файл
6. Подключите ваше устройство к брокеру MQTT
7. Запустите приложение и введите необходимые данные в поля формы
8. Нажмите кнопку "RUN" для отправки данных из файла построчно в брокер MQTT
9. После выполнения программы будет выведена статистика о количестве отправленных сообщений
10. Логи работы программы будут выведены в окне консоли в Qt Creator

Выполним следующие команды для сборки и запуска приложения в терминале Linux:

mkdir build
cd build
cmake ..
make
./MQTT_Sender

После запуска программы на экране отобразится окно с полями для ввода данных. Введите необходимые данные и нажмите кнопку "RUN". 
Программа отправит содержимое текстового файла построчно в указанный топик брокера MQTT и выведет статистику о количестве отправленных строк. 
Логирование работы программы можно настроить с помощью стандартных средств Qt или использовать сторонние библиотеки для логирования.

Для сборки в докер контейнере под архитектуру linux arm64 можно использовать Dockerfile:
FROM arm64v8/ubuntu
RUN apt-get update && \
    apt-get install -y qt5-default qml-module-qtquick-controls2 qml-module-qtmqtt && \
    apt-get clean
COPY . /app
WORKDIR /app
RUN qmake && make
CMD ["./MQTTFileSender"]

Или так:
FROM arm64v8/ubuntu:latest
RUN apt-get update && apt-get install -y \
    qt5-default \
    qttools5-dev-tools \
    libssl-dev \
    libpaho-mqtt-dev
WORKDIR /app
COPY . /app
RUN qmake && make
CMD ["./MQTTFileSender"]


Этот Dockerfile устанавливает необходимые зависимости, копирует проект внутрь контейнера, собирает программу и запускает её.
После создания Dockerfile, выполните команды для сборки образа и запуска контейнера:
 
docker build -t mqttfilesender.
docker run -it mqttfilesender

Таким образом, программа с графическим интерфейсом на QML для отправки содержимого текстового файла в брокер MQTT с 
использованием фреймворка Qt может быть реализована на C++ с использованием указанных компонентов.
