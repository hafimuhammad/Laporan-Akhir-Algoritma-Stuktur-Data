#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "point.h"
#include <string>

struct Circle {
    Point center;
    double radius;
};

double distance(const Circle * c,const Point * p){
    return std::pow(p->x - c->center.x, 2) + std::pow(p->y - c->center.y, 2);
}
std::string CheckPointInCircle(double distance, double r2){
    double epsilon = 1e-6;
    if(distance < r2){
        return "Inside";
    }
    else if(std::abs(distance - r2) < epsilon){
        return "On Circle";
    }
    else{
        return "Outside";
    }
}

#endif