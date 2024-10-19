#include <iostream>
#include <string>

using namespace std;
int v[] = {3, 2, 6, 8, 5};
int& setValue(int i){
    return v[i];
}
int main(){
    for (int i=0; i< 5; i++){
        cout<< v[i] << " ";
    }
    cout << endl;
    setValue(1)=9;
    setValue(3)=7;
    for (int i=0; i< 5; i++){
        cout<< v[i] << " ";
    }

    int x=2;
    int& const r=x;
}