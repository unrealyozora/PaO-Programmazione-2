#include <QTCore\QCoreApplication>
#include <QTCore\QDebug>

// TODO: Define the Person class
// The class should:
// - Overload the `==` operator to compare two Person objects based on their attributes
// - Overload the `+` operator to return the sum of the ages of two Person objects

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
    friend bool operator==(const Person& p1, const Person& p2){
        return (p1.getAge()==p2.getAge() && p1.getName()==p1.getName());
    }
    friend int operator+(const Person& p1, const Person& p2){
        return p1.getAge()+p2.getAge();
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Create two Person objects
    Person Tommaso("Tommaso", 20);
    Person Marco("Marco", 25);
    // TODO: Use the `==` operator to compare the two objects
    bool compar=(Tommaso==Marco);
    qDebug()<< "Persone uguali: " << compar << "\n";
    // TODO: Use the `+` operator to calculate the combined age of the two objects
    int sum_of_Ages=Tommaso+Marco;
    qDebug()<<"Somma età: "<< sum_of_Ages;
    return app.exec();
}