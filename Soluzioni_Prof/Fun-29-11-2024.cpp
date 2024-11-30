
/*
Sia B una classe polimorfa e sia C una sottoclasse di B. 
Definire una funzione int Fun(const std::vector<B*>& v) con il seguente comportamento: 
sia v non vuoto e sia T* il tipo dinamico di v[0]; allora Fun(v) ritorna il numero di 
elementi di v che hanno un tipo dinamico T1* tale che T1 e` un sottotipo di C diverso da T; se v e` vuoto deve quindi ritornare 0. Ad esempio, il seguente programma deve compilare e provocare le stampe indicate.
*/

int Fun(const vector<B*>& v) {
  int x=0;
  for(int i=0; i<v.size(); ++i)
    if(dynamic_cast<C*>(v[i]) && typeid(*v[0]) != typeid(*v[i])) ++x;
  return x;
}
