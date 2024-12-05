/* Write a C++ program to implement a class called Student that has private member variables for name, class, roll number, and marks. 
Include member functions to calculate the grade based on the marks and display the student's information.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Student{
    private:
        string name;
        string classe;
        unsigned int roll;
        vector <unsigned int> marks ={};
    public:
        Student(string _name, string _classe, unsigned int _roll, vector <unsigned int> _marks): name(_name), classe (_classe), roll(_roll), marks(_marks){};
        void StudentInfo() const {
            cout << "Name: " << name << endl <<"Class: " << classe << endl << "Roll Number: " << roll << endl << "Marks: ";
            for (unsigned int mark: marks){
                cout << mark << endl;
            }
            
        }
        double Grade() const {
            
        }
};


int main(){
    
    vector <int> ciao = {1,3,2,4,3,5};
    cout << ciao[5] << endl;
    //cout << ciao [7] << endl ;
    cout << ciao.at(7)<< endl;
    ciao.push_back(9);
    ciao.front()=2;
}