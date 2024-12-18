#include <QTCore\QCoreApplication>
#include <QTCore\QList>
#include <QTCore\QDebug>

// Reuse the Person class from previous exercises
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

    // TODO: Create a QList to store Person objects
    QList<Person> PersonList;
    // TODO: Add a few Person objects to the list
    Person Tommaso("Tommaso", 20);
    Person Marco("Marco", 25);
    Person Giovanni("Giovanni", 32);
    Person Dennis("Dennis", 20);
    PersonList.append(Tommaso);
    PersonList.append(Marco);
    PersonList.append(Giovanni);
    PersonList.append(Dennis);
    // TODO: Display all Person objects in the list using qDebug
    QList<Person>::const_iterator it;
    qDebug()<<"Lista prima: \n";
    for (it=PersonList.begin(); it!= PersonList.end(); it++){
        qDebug()<<(*it).getName()<<"\n";
    }

    // TODO: Remove a Person object from the list
    PersonList.removeOne(Giovanni);
    // TODO: Display the updated list
    qDebug()<<"Lista dopo: \n";
    for (it=PersonList.begin(); it!= PersonList.end(); it++){
        qDebug()<<(*it).getName()<<"\n";
    }
    return app.exec();
}