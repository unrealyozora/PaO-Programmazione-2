#include <iostream>
using namespace std;

template<class T>
class QueueItem{
    public:
        QueueItem(const T& val) : info(val), next(0) {};
        T info;
        QueueItem* next;
};

template<class T>
class Queue{
    public:
        Queue() : primo(0), ultimo(0) {};
        ~Queue(){
            while (!is_empty()){
                remove();
            }
        }
        bool is_empty() const {return (primo==0);};
        void add (const T& val) {
            QueueItem<T>* p = new QueueItem<T>(val);
            if (is_empty()){
                primo = ultimo = p;
            }else{
                ultimo->next=p;
                ultimo=p;
            }
        };
        T remove(){
            if (is_empty()){
                cerr << "remove() su stringa vuota"<< endl;
                exit(1);
            }
            QueueItem<T>* p = primo;
            primo=primo->next;
            T aux= p->info;
            delete p;
            return aux;
        };
    private:
    QueueItem<T>* primo;
    QueueItem<T>* ultimo;
};

int main(){
    Queue<int>* pi = new Queue<int>;

    int i;
    for (i=0; i<10; i++){
        pi->add(i);
        cout << pi->remove();
    }
}
