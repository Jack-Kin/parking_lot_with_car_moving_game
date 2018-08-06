//
// Created by jinzh on 2018/8/1.
//

#ifndef PROJECT3_GROUP_H
#define PROJECT3_GROUP_H
#include "Vector.h"
#include "colorfig.h"
#include <ctime>







class Spacecraft : public Figure{
public:
    Spacecraft(Vec pt1, double width, double height,double owidth);
    void draw();
    void zoom(double *width,double *height,double *owidth);
    ~Spacecraft() {
        for (int i = 0; i < 8; ++i) {
            delete sh[i];
        }
    };
private:
    Vec anchor;
    float w, h, o;
    ColoredFig *sh[8];
    void zoomout(double *width,double *height,double *owidth);
    void zoomin(double *width,double *height,double *owidth);
};


class Bling : public Figure{
public:
    Bling(Vec pt1);
    void draw();
    ~Bling() {
        delete sh;
    };
private:
    Vec anchor;
    ColoredFig *sh;
    void paint(float *r, float *g, float *b);
};


class UFO : public  Figure{
public:
    UFO(Vec pt1, float A);
    void draw();
    void rotate(float *A);
    ~UFO(){
        for (int i = 0; i < 3; ++i) {
            delete sh[i];
        }
    };
private:
    Vec anchor;
    float angle;
    ColoredFig *sh[3];
};

class Car : public Figure{
public:
    Car(Vec anchor);
    void CarM(Vec dir);
    void CarR(float angle);
    void CarD();
    Vec getAnchor();
    ~Car();
private:
    Vec anchor;
    ColoredFig *sh[4];
    Vec p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
};

#endif //PROJECT3_GROUP_H
