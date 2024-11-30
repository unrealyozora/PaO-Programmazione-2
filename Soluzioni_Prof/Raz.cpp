/*
Definire, separando interfaccia ed implementazione, una classe Raz i cui oggetti rappresentano un numero razionale num/den (naturalmente, i numeri razionali hanno sempre un denominatore diverso da 0). La classe
deve includere:
1. opportuni costruttori;

2. un metodo Raz inverso() con il seguente comportamento: se l’oggetto
di invocazione rappresenta n/m allora inverso() ritorna un oggetto che
rappresenta m/n;
3. un operatore esplicito di conversione al tipo primitivo double;
4. l’overloading degli operatori di somma e moltiplicazione;
5. l’overloading dell’operatore di incremento postfisso/prefisso, che,
   naturalmente, dovra` incrementare di 1 il razionale di invocazione;
6. l'overloading dell'operatore di uguaglianza;
7. l’overloading dell’operatore di output;
8. un metodo Raz unTerzo() che ritorna il razionale 1/3.
*/

class Raz {
private:
int num, den; // INV: den !=0

public:
// agisce da convertitore int => Raz, n convertito in n/1
Raz(int n = 0, int d = 1);
  
Raz inverso() const;

  operator double() const;

  Raz operator+(const Raz&) const;
  Raz operator*(const Raz&) const;
  
  Raz& operator++(); // ++ prefisso
  
  Raz operator++(int); // ++ postfisso

  bool operator==(const Raz&) const;

  static Raz unTerzo();
};

Raz::Raz(int n, int d) : num(n), den(d != 0 ? d : 1) {}

// su 0 ritorna un intero non prevedibile
Raz Raz::inverso() const {
  return Raz(den,num);
}

Raz::operator double() const {
  return (1.0*num)/(1.0*den);
}

//Il prof qui lasciava return Raz(0) e non so perchè, ho provato a modificare con questa versione
Raz Raz::operator+(const Raz& g) const {
  return Raz(this->num*g.den + g.num*this->den, this->den*g.den); // ...; n1/d1 + n2/d2 = (n1*d2 + n2*d1)/d1*d2
}

Raz Raz::operator*(const Raz&) const {
  return Raz(1); // ...; n1/d1 * n2/d2 = n1*n2/d1*d2
}


// n/d + d/d = (n*d + d*d)/d*d

Raz& Raz::operator++() {
  return *this = *this + Raz(1); // assegnazione standard Raz& operator=(const Raz&);
}

Raz Raz::operator++(int) {
  Raz aux(*this);
  *this = *this + Raz(1);
  return aux;
}

bool Raz::operator==(const Raz& r) const {
  return num*r.den == den*r.num;
}

#include<iostream>


std::ostream& operator<<(std::ostream& os, const Raz& r) {
  return os << "L'output del razionale convertito a double e' " << r.operator double(); 
}

Raz Raz::unTerzo() {
  return Raz(1,3);
}


// main.cpp
int main() {
  Raz x(2,3), y(2), z, u(1,8), v(3,2), w(8,4);

  Raz(2,3)*y; 
y*Raz(2,3);

  /*std::cout << x+y+v*u << std::endl; // 2.85417
  std::cout << u.inverso() << std::endl; // 8
  std::cout << (y == w) << std::endl; // true
  std::cout << y++ << " " << ++w << std::endl; // 2 3
  std::cout << (++y + Raz::unTerzo()) << std::endl; // 4.33333
  std::cout << 2 + Raz(1,2) << std::endl; // 2.5*/

  std::cout << x+y<< std::endl;
}
