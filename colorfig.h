//
// Created by jinzh on 2018/7/31.
//

#ifndef PROJECT3_COLORFIG_H
#define PROJECT3_COLORFIG_H
#include "Vector.h"

class Figure {
protected:
    Vec anchor;
public:
    Figure() : anchor(0, 0) {}
    Vec getAnchor() {return anchor;};
    void setAnchor(Vec a) {anchor = a;};
//    virtual void zoom(float k) = 0;
};

class ColoredFig : public Figure{
protected:
    float r, g, b;
public:
//    virtual ColoredFig(){r=0,g=0,b=0;};
    virtual void draw() = 0;
    virtual void move(Vec dir) = 0;
    virtual void rotate(double angle) = 0;
    virtual~ColoredFig() = default;
};

class Rec : public ColoredFig {
public:
    Rec(Vec anchor, Vec pt1, Vec pt2, Vec pt3, Vec pt4, float r, float g, float b);
    void rotate(double angle) ;
    void move(Vec dir) ;
    void draw() override;
private:
    Vec p1, p2, p3, p4;
};

class Circle : public ColoredFig {
public:
    Circle(Vec anchor, Vec pt1, float R, float r, float g, float b);
    void rotate(double angle) ;
    void move(Vec dir) ;
    void draw() override;
private:
    Vec p1;
    float R;
};

class Semicircle : public ColoredFig {
public:
    Semicircle(Vec pt1, float R, float r, float g, float b, float angle);
    void rotate(double angle) ;
    void move(Vec dir) ;
    void draw() override;
private:
    Vec p1;
    float R;
    float alpha;
};

class Triangle : public ColoredFig {
public:
    Triangle(Vec anchor, Vec pt1, Vec pt2, Vec pt3, float r, float g, float b);
    void rotate(double angle) ;
    void move(Vec dir) ;
    void draw()override;
private:
    Vec p1, p2, p3;
};

class Trapezoid : public ColoredFig {   //梯形

public:
    Trapezoid(Vec anchor, Vec pt1, Vec pt2, Vec pt3, Vec pt4, float r, float g, float b);
    void rotate(double angle) ;
    void move(Vec dir) ;
    void draw()override;
private:
    Vec p1, p2, p3, p4;
};


#endif //PROJECT3_COLORFIG_H
