#include <iostream>
#include <string>
using namespace std;

class automobile{
    public:
        int targa;
        int anno;
        automobile(int, int);
    friend ostream&  operator<<(ostream& os, automobile& a);
};

ostream&  operator<<(ostream& os, automobile& a){
    return os << "la targa è: " << a.targa << " e l'anno è " << a.anno;
}

automobile::automobile(int a, int b){
    this->targa=a;
    this->anno=b;
}
int main(){
    automobile bmw(4254, 2004);
    cout<<bmw;
}

