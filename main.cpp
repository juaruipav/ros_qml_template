#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <ros_qml_template/foo.h>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    ros_qml_template::foo fooMsg;
    fooMsg.a = 10;
    qDebug() << "Example of a foo msg " << fooMsg.a;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
