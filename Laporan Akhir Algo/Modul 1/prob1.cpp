#include "line.h"
#include <iostream>
using namespace std;

int main(){
    Line l;
    Point p;

    cout << "Masukkan nilai a, b, dan c: ";
    cin >> l.a >> l.b >> l.c;

    cout << "Masukkan nilai xp dan yp: ";
    cin >> p.x >> p.y;

    double hitungan = Equality(&l, &p);
    string hasil = CheckPointPosition(hitungan);
    cout << hasil << endl;
    return 0;
}