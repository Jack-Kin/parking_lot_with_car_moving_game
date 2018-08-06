//
// Created by jinzh on 2018/7/31.
//

#include "vector.h"
#include "cmath"
#define PI 3.1415926

float Vec::getX() {return x;}
float Vec::getY() {return y;}

//void Vec::setX(float X) { this->x = X ;}
//void Vec::setY(float Y) { this->y = Y ;}


Vec Vec::operator+(Vec v){
    return Vec(x+v.getX(),y+v.getY());
}
Vec Vec::operator-(Vec v) {
    return Vec(x-v.getX(),y-v.getY());
}
Vec Vec::operator*(float k) {
    return Vec(x*k,y*k);
}
float Vec::operator*(Vec v) {
    return x*v.getX()+y*v.getY();
}
Vec Vec::operator<<(float angle_1) {
    float angle=PI*angle_1/180;
    return Vec(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
}
Vec Vec::operator>>(float angle_1) {
    float angle=-PI*angle_1/180;
    return Vec(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
}