#include <iostream>
#include <string>

using namespace std;
class C {
    private:
        int x;
    public:
        C (int n=0) {x=n;}
        C F (C obj) {C r; r.x=obj.x+x; return x;}
        C G (C obj) const {C r; r.x=obj.x + x; return r;}
        C H (C& obj) {obj.x += x; return obj;}
        C I (const C& obj) {C r; r.x=obj.x+x; return r;}
        C J (const C& obj) const {C r; r.x=obj.x+x; return r;}

};
int main(){
    C x, y(1), z(2);
    const C v(2);
    int a=0, b=1, c=2, d=3, e=4;
    a=(b++, c++, d++, ++e);
    cout << "a= " << a << endl;
    cout << "a= " << a << endl;
}