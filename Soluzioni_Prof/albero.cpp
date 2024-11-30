/* 
Definire un template di classe albero<T> i cui oggetti rappresentano 
un albero 3-ario ove i nodi memorizzano dei valori di tipo T ed hanno 
3 figli (invece dei 2 figli di un usuale albero binario). Il template 
albero<T> deve soddisfare i seguenti vincoli:
1. Deve essere disponibile un costruttore di default che costruisce l’albero vuoto. 
2. Gestione della memoria senza condivisione.
3. Metodo void insert(const T&): a.insert(t) inserisce nell'albero a una nuova radice che memorizza il valore t ed avente come figli 3 copie di a 
4. Metodo bool search(const T&): a.search(t) ritorna true se t occorre nell'albero a, altrimenti ritorna false.
5. Overloading dell'operatore di uguaglianza.
6. Overloading dell'operatore di output.

*/

#include<iostream>

// forward declaration del template di classe albero<T>
template <class T>
class albero;

// dichiarazione del template di funzione operator<<
template <class T>
std::ostream& operator<<(std::ostream&,const albero<T>&);


template <class T>
class albero {

  friend std::ostream& operator<< <T> (std::ostream&,const albero&);
  
private:
  class nodo {
  public:
    T info;
    nodo *sx, *cx, *dx;
    nodo(const T& t,nodo* s, nodo* c, nodo* d):
      info(t), sx(s), cx(c), dx(d) {}
  };

  nodo* root;

  static albero::nodo* copia(typename albero::nodo* r) {
    if(!r) return nullptr;
    // r != nullptr (l'albero puntato da r non e' vuoto)
    return new albero::nodo(r->info,copia(r->sx),copia(r->cx),copia(r->dx)); 
  }

  static void distruggi(typename albero::nodo* r) {
    if(r) {
      distruggi(r->sx);
      distruggi(r->cx);
      distruggi(r->dx);
      delete r;
    }
  }

  static bool rec_search(nodo* r, const T& t) {
    if(!r) return false;
    // albero puntato da r non e' vuoto
    return r->info == t || rec_search(r->sx,t) ||
      rec_search(r->cx,t) ||rec_search(r->dx,t);
  }

  static bool rec_eq(nodo* r1, nodo* r2) {
    if(!r1 && !r2) return true;
    // r1 | r2
    if(!r1 || !r2) return false;
    // r1 & r2
    return r1->info == r2->info &&
      rec_eq(r1->sx,r2->sx) &&
      rec_eq(r1->cx,r2->cx) &&
      rec_eq(r1->dx,r2->dx);
  }

  static void rec_print(std::ostream& os, nodo* r) {
    if(r) {
      os << r->info << ' ';
      rec_print(os,r->sx);
      os << ' ';
      rec_print(os,r->cx);
      os << ' ';
      rec_print(os,r->dx);
    }
  }
public:
  albero(): root(nullptr) {}

  albero(const albero& a): root(copia(a.root)) {}
  
  albero& operator=(const albero& a) {
    if(this != &a) {
      distruggi(root);
      root = copia(a.root);
    }
    return *this;
  }

  ~albero() {if(root) distruggi(root);}

  void insert(const T& t) {
    root = new albero::nodo (t,root,copia(root),copia(root));
  }

  bool search(const T& t) const {
    return rec_search(root,t);
  }

  bool operator==(const albero& a) const {
    return rec_eq(root,a.root);
  }
};

template <class T>
std::ostream& operator<<(std::ostream& os,const albero<T>& a) {
  albero<T>::rec_print(os,a.root); return os;
}

int main() {
  albero<char> t1, t2, t3;
  t1.insert('b');
  t1.insert('a');
  t2.insert('a');
  t3 = t1;
  t3.insert('c');
  std::cout << (t1==t2) << std::endl;
  std::cout << t3.search('c') << std::endl;
  std::cout << "t1 = " << t1 << std::endl;
  std::cout << "t2 = " << t2 << std::endl;
  std::cout << "t3 = " << t3 << std::endl;
}

