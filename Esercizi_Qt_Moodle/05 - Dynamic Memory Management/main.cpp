#include <QTCore\QCoreApplication>
#include <QTCore\QDebug>

// Reuse the Person class from the previous exercise

class Person{
private:
    QString name;
    int age;
public:
    Person(const QString& _n, const int& _a): name(_n), age(_a){};

    QString getName(){
        return this->name;
    }
    int getAge(){
        return this->age;
    }

    void printInfo(){
        qDebug()<<"Nome: "<<getName()<<", Età: "<<getAge();
    }
    
};


int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Dynamically create a Person object
    Person* Tommaso= new Person("Tommaso", 20);
    // Use the constructor to initialize the object

    // TODO: Call the printInfo method to display the person's details
    Tommaso->printInfo();
    // TODO: Deallocate the memory used by the Person object
    delete Tommaso;
    return app.exec();
}