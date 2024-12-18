#include <QTCore\QCoreApplication>
#include <QTCore\QDebug>

// TODO: Define the Person class (reuse from previous exercises)
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
// - Have a private attribute `university` (QString)
// - Include a constructor to initialize the name, age, and university
// - Have a method `printInfo` that overrides the base class method
//   to display all details (name, age, and university)

class Student: public Person{
private:
    QString universisty;
public:
    Student(const QString& _n, const int& _a, const QString& _u ): universisty(_u){
        setName(_n);
        setAge(_a);
    }
    void printInfo() const override{
        qDebug()<<"Nome: "<<getName()<<", Età: "<<getAge()<<"Frequenta l'università:"<<universisty;
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Create a Student object
    // TODO: Call the printInfo method to display the student's details
    Student Tommaso("Tommaso", 20, "Università degli Studi di Padova");
    Tommaso.printInfo();
    return app.exec();
}