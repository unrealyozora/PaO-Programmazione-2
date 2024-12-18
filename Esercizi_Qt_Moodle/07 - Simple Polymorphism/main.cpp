#include <QTCore\QCoreApplication>
#include <QTCore\QDebug>
 
//!!Cosa cambia dall'esercizio precedente?//
// TODO: Define the Person class
// The class should:
// - Include a virtual `printInfo` method

class Person{
private:
    QString name;
    int age;
public:
    
    Person(const QString& _n="", const int& _a=1): name(_n), age(_a){};

    QString getName() const{
        return this->name;
    }
    int getAge() const{
        return this->age;
    }

    void setName(const QString& n){
        name=n;
    }
    void setAge(int a){
        age=a;
    }

    virtual void printInfo() const{
        qDebug()<<"Nome: "<<getName()<<", Età: "<<getAge();
    }
    
};

// TODO: Define the Student class
// The class should:
// - Inherit from Person
// - Override the `printInfo` method to include university details
class Student: public Person{
private:
    QString universisty;
public:
    Student(const QString& _n, const int& _a, const QString& _u ):universisty(_u){
        setName(_n);
        setAge(_a);
    }
    void printInfo() const override{
        qDebug()<<"Nome: "<<getName()<<", Età: "<<getAge()<<"Frequenta l'università:"<<universisty<< "\n";
    }
};


void displayInfo(Person *person) {
    // TODO: Call the printInfo method on the passed object
    person->printInfo();
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Create a Person object
    Person Marco("Marco", 25);
    // TODO: Create a Student object
    Student Tommaso("Tommaso", 20, "Università degli Studi di Padova");
    // TODO: Call displayInfo for each object
    displayInfo(&Marco);
    displayInfo(&Tommaso);
    return app.exec();
}