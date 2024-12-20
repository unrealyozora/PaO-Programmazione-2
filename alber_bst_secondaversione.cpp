#include <iostream>
using namespace std;
template <class T> class AlbBinRic;
template <class T> class Nodo;


template <class T>
class Nodo{
    friend class AlbBinRic<T>;
    friend ostream& operator<<(ostream& os, Nodo<T>* p){
        if (!p){
        os<< '@';
    }else{
        os << "(" << p->info << "," << p->sinistro << "," << p->destro << ")";
    }
    return os;
    }
    private:
        T info;
        Nodo* sinistro;
        Nodo* destro;
        Nodo * padre;
        Nodo (const T& v, Nodo* p=0, Nodo* s=0, Nodo* d=0): info(v), padre(p), sinistro(s), destro(d){}; 
};


template <class T>
class AlbBinRic{
    friend ostream& operator<<  (ostream& os, const AlbBinRic<T>& a){
        os<<a.radice<<endl;
    return os;
    }
    public:
        AlbBinRic(): radice(0) {};
        Nodo<T>* Find(T) const;
        Nodo<T>* Minimo () const;
        Nodo <T>* Massimo () const;
        Nodo <T>* Succ (Nodo <T>*) const;
        Nodo <T>* Prec (Nodo <T>*) const;
        void Insert(T);
        static T Valore(Nodo<T>* p){return p->info;}
    private:
        Nodo <T>* radice;
        static Nodo<T>* FindRic (Nodo<T>*, T);   
        static Nodo<T>* MinimoRic(Nodo<T>*);    
        static Nodo<T>* MassimoRic(Nodo<T>*);
        static void InsertRic (Nodo<T>*, T);
};


template <class T>
Nodo<T>* AlbBinRic<T>:: Find(T v) const {
    return FindRic(radice, v);
}

template <class T>
Nodo <T>* AlbBinRic<T>::FindRic(Nodo <T>* x, T v){
    if (!x){
        return x;
    }else if (v==x->info){
        return x;
    }else if (v<x->info){
        return FindRic(x->sinistro, v);
    }else if (v>x.info){
        return FindRic(x->destro, v);
    }
}

template <class T>
Nodo <T>* AlbBinRic<T>::Minimo() const{
    if (!radice){
        return 0;
    }else{
        return MinimoRic(radice);
    }
}

template <class T>
Nodo<T>* AlbBinRic<T>::MinimoRic(Nodo<T>* x){
    if (!(x->sinistro)){
        return x;
    }else{
        return MinimoRic(x->sinistro);
    }
}

template <class T>
Nodo <T>* AlbBinRic<T>::Massimo() const{
    if (!radice){
        return 0;
    }else{
        return MassimoRic(radice);
    }
}

template <class T>
Nodo<T>* AlbBinRic<T>::MassimoRic(Nodo<T>* x){
    if (!(x->destro)){
        return x;
    }else{
        return MassimoRic(x->destro);
    }
}

template <class T>
Nodo<T>* AlbBinRic<T>:: Succ (Nodo <T>* x) const{
    if (!x){
        return 0;
    }
    if (x->destro){
        return MinimoRic(x->destro);
    }
    while(x->padre && x->padre->sinistro==x){
        x=x->padre;
    }
    return x->padre;
}

template <class T>
Nodo<T>* AlbBinRic<T>:: Prec (Nodo <T>* x) const{
    if (!x){
        return 0;
    }
    if (x->sinistro){
        return MinimoRic(x->sinistro);
    }
    while(x->padre && x->padre->destro==x){
        x=x->padre;
    }
    return x->padre;
}

template <class T>
void AlbBinRic<T>:: Insert(T v){
    if (!radice){
        radice= new Nodo<T>(v);
    }else{
        InsertRic(radice, v);
    }
}

template <class T>
void AlbBinRic<T>:: InsertRic(Nodo<T>* x, T v){
    if (v<x->info){
        if (x->sinistro==0){
            x->sinistro= new Nodo<T>(v,x);
        }else{
            InsertRic(x->sinistro, v);
        }
    }else{
        if (x->destro==0){
            x->destro= new Nodo<T>(v,x);
        }else{
            InsertRic(x->destro, v);
        }
    }
}



int main(){
    AlbBinRic<int> a;
    a.Insert(3);
    a.Insert(2);
    a.Insert(3);
    a.Insert(1);
    a.Insert(6);
    a.Insert(5);

    cout<<"L'albero è:" << a << endl;

    cout<< "Massimo: " << AlbBinRic<int>::Valore(a.Massimo()) << endl;
}
