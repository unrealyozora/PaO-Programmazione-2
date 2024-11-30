/* ESERCIZIO:
Definire una classe vettore i cui oggetti rappresentano array di interi.
vettore deve includere un costruttore di default (e auspicabilmente
un costruttore "opportuno"), una operazione di
concatenazione che restituisce un nuovo vettore v1+v2, una operazione di
append v1.append(v2), l'overloading dell'uguaglianza, dell'operatore di
output e dell'operatore di indicizzazione.  
Deve inoltre includere il costruttore di copia profonda, l'assegnazione profonda e la distruzione profonda.
*/

#include<iostream>

class Vettore {
  friend Vettore operator+(const Vettore&, const Vettore&);
    friend bool operator==(const Vettore&, const Vettore&);
  friend std::ostream& operator<<(std::ostream&, const Vettore&);
private:
  int* a;
  unsigned int size;
  // Vettore vuoto IFF size==0 && a==nullptr
  int* copia() const {
    if(size == 0) return nullptr;
    int* aux = new int[size];
    for(unsigned int k=0; k<size; ++k) aux[k]=a[k];
    return aux;
  }
public:
  Vettore(unsigned int s =0, int v =0): a(s>0 ? new int[s] : nullptr), size(s)
  {
    for(unsigned int k=0; k<size; ++k) a[k]=v;
  }
  Vettore(const Vettore& v): a(v.copia()), size(v.size) {}

  Vettore& operator=(const Vettore& v) {
    if(this != &v) {
      delete[] a;
      a=v.copia();
      size = v.size;
    }
    return *this;
  }
  ~Vettore() {delete[] a;}

  void append(const Vettore& v) {
    *this = *this + v;
  }

  int& operator[](unsigned int k) const {
    return a[k]; 
  }
};

Vettore operator+(const Vettore& v1, const Vettore& v2) {
  Vettore v(v1.size+v2.size);
  for(unsigned int k=0; k<v.size; ++k)
    if(k<v1.size) v.a[k] = v1.a[k];
    else v.a[k] = v2.a[k-v1.size];
  return v;
}

bool operator==(const Vettore& v1, const Vettore& v2) {
  if (v1.size != v2.size) return false;
  // v1.size == v2.size
  for(unsigned int k=0; k<v1.size; ++k)
    if(v1.a[k] != v2.a[k]) return false;
  return true;
}

std::ostream& operator<<(std::ostream& os, const Vettore& v) {
  for(unsigned int k=0; k<v.size; ++k)
    os << v.a[k] << ",";
  return os;
}


int main() {
  Vettore v1(4), v2(3,2), v3(5,3), v4;
  v1 = v2+v3;
  v2.append(v2);
  v3.append(v1);
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;

}

