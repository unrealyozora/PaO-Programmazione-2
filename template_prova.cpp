#include <iostream>
using namespace std;
template <class T>
T min_1(T a, T b){
    return a<b ? a: b;
}

int main(){
    int i, j, k;
    i=1;
    j=2;
    k=3;

    double a, b, c;
    a=1.1;
    b=2.2;
    c=3.3;

    double res1=min_1(b, c);
    cout<<res1;
}