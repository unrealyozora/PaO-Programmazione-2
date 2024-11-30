/*
Si consideri il seguente modello di realtà concernente i file audio memorizzati in un riproduttore audio digitale iZod.

(A) Definire la seguente gerarchia di classi.

1. Definire una classe base polimorfa astratta FileAudio i cui oggetti rappresentano un file audio memorizzabile in un iZod. Ogni FileAudio  e' caratterizzato dal titolo (una stringa) e dalla propria dimensione in MB. La classe è astratta in quanto prevede i seguenti metodi virtuali puri:

• un metodo di “clonazione”; 

• un metodo bool qualita() con il seguente contratto: f->qualita() ritorna true se il file audio *f è considerato di
qualità, altrimenti ritorna false.

2. Definire una classe concreta Mp3 derivata da FileAudio i cui oggetti rappresentano un file audio in formato mp3. Ogni oggetto Mp3 è caratterizzato dal proprio bitrate espresso in Kbit/s. La classe Mp3 implementa i metodi virtuali puri di FileAudio come segue:

• implementazione canonica del metodo di clonazione; 

• per ogni puntatore p a Mp3, p->qualita() ritorna true se il bitrate di *p è ≥ 192 Kbit/s, altrimenti ritorna false.

3. Definire una classe concreta WAV derivata da FileAudio i cui oggetti rappresentano un file audio in formato WAV. Ogni oggetto WAV è caratterizzato dalla propria frequenza di campionamento espressa in kHz e dall’essere lossless oppure no (cioè con compressione senza perdita oppure con perdita). La classe WAV implementa i metodi virtuali puri di FileAudio come segue:

• implementazione canonica del metodo di clonazione; 

• per ogni puntatore p a WAV, p->qualita() ritorna true se la frequenza di campionamento di *p è ≥ 96 kHz, altrimenti
ritorna false.

(B) Definire una classe iZod i cui oggetti rappresentano i brani memorizzati in un iZod. La classe iZod deve soddisfare le seguenti specifiche:
`
1. E definita una classe annidata Brano i cui oggetti rappresentano un brano memorizzato nell’iZod. Ogni oggetto Brano è
rappresentato da un puntatore (super)polimorfo ad un FileAudio.

• La classe Brano deve essere dotata di un opportuno costruttore Brano(FileAudio*) con il seguente comportamento:
Brano(p) costruisce un oggetto Brano il cui puntatore polimorfo punta ad una copia dell’oggetto *p.

• La classe Brano ridefinisce costruttore di copia profonda, assegnazione profonda e distruttore profondo.

2. Un oggetto di iZod è quindi caratterizzato da un vector di oggetti di tipo Brano che contiene tutti i brani memorizzati nell’iZod.

3. La classe iZod rende disponibili i seguenti metodi:

• Un metodo vector<Mp3> mp3(double, int) con il seguente comportamento: una invocazione iz.mp3(dim,br) ritorna un vector di oggetti Mp3 contenente tutti e soli i file audio in formato mp3 memorizzati nell’iZod iz che: (i) hanno una dimensione ≥ dim e (ii) hanno un bitrate ≥ br.

• Un metodo vector<FileAudio*> braniQual() con il seguente comportamento: una invocazione iz.braniQual() ritorna il vector dei puntatori ai FileAudio memorizzati nell’iZod iz che: (i) sono considerati di qualità e (ii) se sono dei file audio WAV allora devono essere lossless.

• Un metodo void insert(Mp3*) con il seguente comportamento: una invocazione iz.insert(p) inserisce il nuovo oggetto Brano(p) nel vector dei brani memorizzati nell’iZod iz se il file audio mp3 *p non è già memorizzato in iz, mentre se il file audio *p risulta già memorizzato non provoca alcun effetto.

*/

#include<string>

class FileAudio {
private:
  std::string titolo;
  double MB;
public:
  virtual FileAudio* clone() const =0;
  virtual bool qualita() const =0;
  virtual ~FileAudio() = default;
  double getSize() const {return MB;}
  virtual bool operator==(const FileAudio& fa) const {
    return typeid(*this)==typeid(fa) && titolo==fa.titolo && MB==fa.MB; 
  }
};

class Mp3: public FileAudio {
private:
  unsigned int bitrate;
  static unsigned int br_threshold;
public:
  Mp3* clone() const override {return new Mp3(*this);}
  bool qualita() const override {return bitrate >= br_threshold;}
  unsigned int getBitrate() const {return bitrate;}
  bool operator==(const FileAudio& fa) const override {
    return this->FileAudio::operator==(fa) &&  bitrate==static_cast<const Mp3&>(fa).bitrate; 
  }
};
unsigned int Mp3::br_threshold = 192;

class WAV: public FileAudio {
private:
  unsigned int frequency;
  bool lossLess;
  static unsigned int fr_threshold;
public:
  WAV* clone() const override {return new WAV(*this);}
  bool qualita() const override {return frequency >= fr_threshold;}
  bool isLossLess() const {return lossLess;}
    bool operator==(const FileAudio& fa) const override {
    return this->FileAudio::operator==(fa) &&  frequency==static_cast<const WAV&>(fa).frequency
      && lossLess==static_cast<const WAV&>(fa).lossLess; 
  }
};
unsigned int WAV::fr_threshold = 96;

#include<vector>

class iZod {
private:
  class Brano {
  public:
    FileAudio* ptr; // puntatore (super)polimorfo
    Brano(FileAudio* p): ptr(p->clone()) {} // convertitore FileAudio* => Brano
    ~Brano() {delete ptr;} // distruzione polimorfa
    Brano(const Brano& b): ptr((b.ptr)->clone()) {}
    Brano& operator=(const Brano& b) {
      if(this != &b) {
	delete ptr;
	ptr = (b.ptr)->clone();
      }
      return *this;
    }
  };
  
  std::vector<Brano> v;

public:
  
  std::vector<Mp3> mp3(double dim, int br) const {
    std::vector<Mp3> w;    
    for(std::vector<Brano>::const_iterator cit = v.begin(); cit != v.end(); ++cit)
      if(dynamic_cast<Mp3*>(cit->ptr) && (cit->ptr)->getSize()>=dim
	 && (static_cast<Mp3*>(cit->ptr))->getBitrate() >= br)
	w.push_back(*(static_cast<Mp3*>(cit->ptr)));
    return w;
  }
  
  std::vector<FileAudio*> braniQual() const {
    std::vector<FileAudio*> w;    
    for(std::vector<Brano>::const_iterator cit = v.begin(); cit != v.end(); ++cit) {
      WAV* p = dynamic_cast<WAV*>(cit->ptr);
      if(cit->ptr && (cit->ptr)->qualita() && (!p || p->isLossLess()))
	w.push_back(p);
    }
    return w;
  }
  
  void insert(Mp3* p) {
    if(p) {
      bool found = false;
      for(unsigned int i=0; !found && i<v.size(); ++i) 
	if(v[i].ptr && *(v[i].ptr) == *p) found = true;
      if(!found) v.push_back(p);
    }
  }
};

int main() {}
