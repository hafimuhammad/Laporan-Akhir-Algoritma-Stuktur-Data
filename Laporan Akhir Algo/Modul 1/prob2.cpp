#include "circle.h"
#include <iostream>
using namespace std;

int main(){
    Circle c;
    Point p;
    cout << "Masukkan nilai Cx dan Cy: ";
    cin >> c.center.x >> c.center.y;
    cout << "Masukkan nilai radius: ";
    cin >> c.radius;
    cout << "Masukkan nilai Xp dan Yp: ";
    cin >> p.x >> p.y;
    double Jari2 = c.radius * c.radius;
    double jarak = distance(&c,&p);
    string hasil = CheckPointInCircle(jarak, Jari2);
    cout << hasil << endl;
    return 0;

}