#include <QTCore\QCoreApplication>
#include <QTCore\QDebug>

// TODO: Define the Person class
// The class should have:
// - A private attribute `name` (QString)
// - A private attribute `age` (int)
// - A public method `setName` to set the name
// - A public method `setAge` to set the age
// - A public method `printInfo` to display the person's details using qDebug()


class Person{
private:
    QString name;
    int age;
public:
    void setName(const QString& n){
        name=n;
    }
    void setAge(int a){
        age=a;
    }
    void printInfo(){
        qDebug()<<"Nome: "<<name<<", Età: "<<age;
    }

};
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Create a Person object
    // TODO: Set the person's name and age using the class methods
    // TODO: Call the `printInfo` method to display the details
    Person Tommaso;
    Tommaso.setName("Tommaso");
    Tommaso.setAge(20);
    Tommaso.printInfo();
    return app.exec();
}