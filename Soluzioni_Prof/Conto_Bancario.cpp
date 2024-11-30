/*
ESERCIZIO. Definire una superclasse ContoBancario e due sue sottoclassi ContoCorrente e ContoDiRisparmio che soddisfano le seguenti specifiche:

1) Ogni ContoBancario è caratterizzato da un saldo e rende disponibili due funzionalità di deposito e prelievo: double deposita(double) e double preleva(double) che ritornano il saldo aggiornato dopo l’operazione di deposito/prelievo.
2) Ogni ContoCorrente è caratterizzato anche da una spesa fissa uguale per ogni ContoCorrente che deve essere detratta dal saldo ad ogni operazione di deposito e prelievo.
3) Ogni ContoDiRisparmio deve avere un saldo non negativo e pertanto non tutti i prelievi sono permessi; d’altra parte, le operazioni di deposito e prelievo non comportano costi aggiuntivi e restituiscono il saldo aggiornato.
4) Si definisca inoltre una classe ContoArancio derivata da ContoDiRisparmio. La classe ContoArancio deve avere un ContoCorrente di appoggio: quando si deposita una somma S su un ContoArancio, S viene prelevata dal ContoCorrente di appoggio; d’altra parte, i prelievi di una somma S da un ContoArancio vengono depositati nel ContoCorrente di appoggio.
*/

class ContoBancario {
private:
  double saldo;
public:
  ContoBancario(double di =0.0): saldo(di > 0 ? di : 0) {}
  double deposita(double d) {
    if(d>0) {
      saldo += d;
    }
    return saldo;
  }

  double preleva(double p) {
    if(p>0) {
      saldo -= p;
    }
    return saldo;  
  }

  double getSaldo() const {return saldo;}
};

class ContoCorrente: public ContoBancario {
private:
  static double spesaFissa;
public:
  ContoCorrente(double di = 0.0): ContoBancario(di) {}
  // ridefinizione per specializzazione
  double deposita(double d) {
    return ContoBancario::deposita(d-spesaFissa);
  }
  double preleva(double p) {
    if(p>=spesaFissa){
      return ContoBancario::preleva(p+spesaFissa);
    }
    return getSaldo();
  }
};

double ContoCorrente::spesaFissa = 1.0;

class ContoDiRisparmio: public ContoBancario {
  // INVL saldo >=0
public:
  ContoDiRisparmio(double di = 0.0): ContoBancario(di) {}
  // ContoBancario::deposita viene ereditato senza ridefinizione
  
  double preleva(double p) {
    if(p<=getSaldo()) {
      ContoBancario::preleva(p);
    }
    return getSaldo();  
  }
};

class ContoArancio: public ContoDiRisparmio {
private:
  ContoCorrente& appoggio;
public:
  ContoArancio(ContoCorrente& ca, double di = 0.0): ContoDiRisparmio(di), appoggio(ca) {}

  double deposita(double d) {
    appoggio.preleva(d);
    return ContoDiRisparmio::deposita(d); 
  }
  double preleva(double p) {
    if(p<=getSaldo()) {
      appoggio.deposita(p);
    }
    return ContoDiRisparmio::preleva(p);
  }
};

#include<iostream>

int main() {
  ContoCorrente cc(2000);
  ContoArancio ca(cc,1500);
  ca.deposita(350); ca.preleva(400); cc.preleva(150); 
  std::cout << cc.getSaldo() << std::endl; // stampa: 1897
  std::cout << ca.getSaldo() << std::endl; // stampa: 1450
}




































