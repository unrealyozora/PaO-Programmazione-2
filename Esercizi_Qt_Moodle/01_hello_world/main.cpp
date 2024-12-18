#include <QtCore\QCoreApplication>
#include <QtCore\QDebug>

int main(int argc, char *argv[]) {
    // Create a QCoreApplication object
    QCoreApplication app(argc, argv);
    // TODO: Add the code to print "Hello, World!" using QDebug
    qDebug()<<"Hello World";
    return app.exec();
}