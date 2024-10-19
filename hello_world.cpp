#include <iostream>
#include <string>
using namespace std;

 class orario{

    public:
        orario();
        orario(int, int);
        orario(int, int , int);
        int Ore();
        int Minuti();
        int Secondi();
        friend ostream& operator<<(ostream& os , orario& o);
    private:
        int sec;

};

ostream& operator<<(ostream& os, orario& o){
    return os  << o.Ore() << ':' << o.Minuti() << ':' << o.Secondi();
}

orario::orario(){
    sec=0;
};
orario::orario(int o, int m){
    if (o<0 || o> 23 || m<0 || m>59){
        sec=0;
    }else{
        sec=o*3600+m*60;
    }
}
orario::orario(int o, int m, int s){
    if (o<0 || o> 23 || m<0 || m>59 || s<0 || s>59){
        sec=0;
    }else{       
        sec=0*3600+m*60+s;
    }
}
int  orario::Ore(){
    return sec /3600;
}
int orario::Minuti(){
    return (sec/60) % 60;
}
int orario::Secondi(){
    return sec % 60;
}


int main(){
    orario mattina(9, 20);
    cout<< mattina;
}

