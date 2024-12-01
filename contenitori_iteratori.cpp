#include <iostream>
using namespace std;

class contenitore{
    friend class iteratore;
    private:
        class nodo{
            public:
                int info;
                nodo* next;
                nodo(int x, nodo* p): info(x), next(p){};
        };
    nodo* first;
    public:
        class iteratore{
            friend class contenitore;
            private:
                contenitore::nodo* punt;
            public:
                bool operator==(iteratore i) const{
                    return punt==i.punt;
                }
                bool operator!=(iteratore i) const{
                    return !(punt==i.punt);
                }
                iteratore& operator++(){
                    if (punt){
                        punt= punt->next;
                    }
                }
        };
        
        contenitore(): first(0){};
        void aggiungi_in_testa(int x){
            first= new nodo(x, first);
        }

        iteratore begin() const;
        iteratore end() const;
        int& operator[] (iteratore) const;
};

contenitore::iteratore contenitore::begin() const{
    iteratore aux;
    aux.punt= first;
    return aux;
}

contenitore::iteratore contenitore:: end() const{
    iteratore aux;
    aux.punt=0;
    return aux;
}

int& contenitore::operator[](contenitore::iteratore it) const{
    return it.punt->info;
}

int main(){
    contenitore prova;
    prova.aggiungi_in_testa(2);
    prova.aggiungi_in_testa(3);
    prova.aggiungi_in_testa(4);
    prova.aggiungi_in_testa(5);
    prova.aggiungi_in_testa(6);

    for (contenitore::iteratore x=prova.begin(); x!=prova.end(); ++x){
        cout<<prova[x];
    }
}

