//
// Created by jinzh on 2018/8/6.
//
#include <iostream>
#include "vector.h"
#include "colorfig.h"
#include "group.h"
#include "GL/glut.h"
#include <ctime>
#include "random.h"


Vec randomPool(int i){
    Vec v1;
    switch (i) {
        case 0:v1 = {-60,-65};break;
        case 1:v1 = {-30,-65};break;
        case 2:v1 = {0,-65};break;
        case 3:v1 = {30,-65};break;
        case 4:v1 = {60,-65};break;
        case 5:v1 = {-60,65};break;
        case 6:v1 = {-30,65};break;
        case 7:v1 = {0,65};break;
        case 8:v1 = {30,65};break;
        case 9:v1 = {60,65};break;
    }
    return v1;
}

void drawBling(Vec v){
    Bling bling(v);
    bling.draw();
}

void drawSpace(Vec v){
    double static width = 10, height = 20, owidth= 10;
    Spacecraft spacecraft1(v,width,height,owidth);
    spacecraft1.zoom(&width,&height,&owidth);
    spacecraft1.draw();
}

void drawUFO(Vec v){
    float static A = 50;
    UFO ufo1(v,A);
    ufo1.rotate(&A);
    ufo1.draw();
}