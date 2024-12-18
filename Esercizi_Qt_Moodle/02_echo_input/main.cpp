#include <QTCore\QDebug>
#include <QTCore\QTextStream>
#include <QtCore\QCoreApplication>
int main(int argc, char *argv[]) {
    
    QCoreApplication app (argc, argv);
    // Create a QTextStream object for input and output
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    // TODO: Prompt the user to enter a line of text
    cout << "Inserisci una riga di testo:\n" << Qt::flush;
    // TODO: Read the user's input using QTextStream
    QString input = cin.readLine();
    // TODO: Echo the input back to the user
    cout << "La tua stringa: " << input<< "\n" << Qt::flush;

    return app.exec();
}