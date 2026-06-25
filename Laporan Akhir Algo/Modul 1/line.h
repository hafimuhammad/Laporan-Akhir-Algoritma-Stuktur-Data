#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <string>

struct Line {
    double a, b, c;
}; 

double Equality(const Line *l, const Point *p){
    double hasil = (l->a * p->x) + (l->b * p->y) + l->c;
    return hasil;
}
std::string CheckPointPosition(double hasil){
    if(hasil < 0){
        return "right";
    }
    else if(hasil == 0){
        return "On Line";
    }
    else{
        return "left";
    }
}
#endif