#include <QTCore\QCoreApplication>
#include <QTCore\QFile>
#include <QTCore\QTextStream>
#include <QTCore\QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Open a file for reading
    QFile to_read("qutetext.txt");
    QString text;
    if (!to_read.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<< "Il file to_read non è stato aperto correttamente";
        return 0;
    } 
    // Use QFile and QTextStream to read the contents of the file
    QTextStream in(&to_read);
    while(!in.atEnd()){
        QString line=in.readLine();
        text.append(line);
    }
    to_read.close();
    // TODO: Process the file contents (for example, print them out)
    qDebug()<<text;
    // TODO: Open a new file for writing
    QFile to_write("to_write.txt");
    if (!to_write.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
        qDebug()<<"Il file to_write non è stato aperto correttamente";
        return 0;
    } 
    // Use QFile and QTextStream to write the processed data to the new file
    QTextStream out(&to_write);
    out<<text;
    to_write.close();
    return app.exec();
}