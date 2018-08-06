//
// Created by jinzh on 2018/8/1.
//
#include <iostream>
#include "vector.h"
#include "colorfig.h"
#include "group.h"
#include <cmath>
#include <GL/glut.h>

const float v = 1;

Spacecraft::Spacecraft(Vec pt1, double width, double height, double owidth) {
    this->anchor = pt1;
    this->w = (float) width;
    this->o = (float) owidth;
    this->h = (float) height;
    Vec p0,p1,p2,p3,p4;

    //top triangle
    p0=this->anchor;
    p1={anchor.getX()-w/4,anchor.getY()+h/3};
    p2={anchor.getX()+w/4,anchor.getY()+h/3};
    p3={anchor.getX(),anchor.getY()+h/2};
    sh[0]=new Triangle(p0,p1,p2,p3,0.3,1,0.2);

    //body rectangle
    p0=this->anchor;
    p1={anchor.getX()-w/4,anchor.getY()-h/3};
    p2={anchor.getX()+w/4,anchor.getY()-h/3};
    p3={anchor.getX()+w/4,anchor.getY()+h/3};
    p4={anchor.getX()-w/4,anchor.getY()+h/3};


    sh[1]=new Rec(p0,p1,p2,p3,p4,(float)255.0/255,(float)215.0/255,0.0);

    //left side triangle
    p0=this->anchor;
    p1={anchor.getX()-w/4,anchor.getY()+h/3};
    p2={anchor.getX()-w/4,anchor.getY()-h/3};
    p3={anchor.getX()-w/2,anchor.getY()-h/3};
    sh[2]=new Triangle(p0,p1,p2,p3,(float)255.0/255,(float)165.0/255,0.0);

    //right side triangle
    p0=this->anchor;
    p1={anchor.getX()+w/4,anchor.getY()-h/3};
    p2={anchor.getX()+w/4,anchor.getY()+h/3};
    p3={anchor.getX()+w/2,anchor.getY()-h/3};
    sh[3]=new Triangle(p0,p1,p2,p3,(float)255.0/255,(float)165.0/255,0);

    //eyes
    p0=this->anchor;
    p1={anchor.getX()-w/12-w/12,anchor.getY()+h/6};
    p2={anchor.getX()-w/12,anchor.getY()+h/6};
    p3={anchor.getX()-w/12,anchor.getY()+h/6+h/12};
    p4={anchor.getX()-w/12-w/12,anchor.getY()+h/6+h/12};
    sh[4]=new Rec(p0,p1,p2,p3,p4,(float)240.0/255,(float)128.0/255,(float)128.0/255);

    p0=this->anchor;
    p1={anchor.getX()+w/12,anchor.getY()+h/6};
    p2={anchor.getX()+w/12+w/12,anchor.getY()+h/6};
    p3={anchor.getX()+w/12+w/12,anchor.getY()+h/6+h/12};
    p4={anchor.getX()+w/12,anchor.getY()+h/6+h/12};
    sh[5]=new Rec(p0,p1,p2,p3,p4,(float)240.0/255,(float)128.0/255,(float)128.0/255);

    //mouth
    p0=this->anchor;
    p1={anchor.getX()-w/12,anchor.getY()- h/12};
    p2={anchor.getX()+w/12,anchor.getY()- h/12};
    p3={anchor.getX()+w/12,anchor.getY()+ h/12};
    p4={anchor.getX()-w/12,anchor.getY()+ h/12};
    sh[6]=new Rec(p0,p1,p2,p3,p4,(float)64.0/255,(float)224.0/255,(float)208.0/255);

    //bottom trapezium
    p0=this->anchor;
    p1={anchor.getX()-w/5,anchor.getY()- h/3};
    p2={anchor.getX()-w/4,anchor.getY()- h*3/7};
    p3={anchor.getX()+w/4,anchor.getY()- h*3/7};
    p4={anchor.getX()+w/5,anchor.getY()- h/3};
    sh[7]=new Trapezoid(p0,p1,p2,p3,p4,(float)0,(float)0,(float)0);
}

void Spacecraft::draw() {
    for (int i = 0; i < 8; ++i) {
        sh[i]->draw();
    }
}

void Spacecraft::zoom(double *width, double *height, double *owidth){
    int static j=0;
    if(h>=3 && j==0) zoomout(width, height, owidth);
    else if (h<=25) { j=1; zoomin(width, height, owidth); }
    else j=0;
//    std::cout << " height:" << this->h << " width:" <<this->w << " owidth:" <<this->o << "\n";
}
void Spacecraft::zoomout(double *width, double *height, double *owidth){
    h/=1.01; *height=h; w/=1.01; *width=w; o/=1.01; *owidth=o;
}
void Spacecraft::zoomin(double *width, double *height, double *owidth){
    h*=1.01; *height=h; w*=1.01; *width=w; o*=1.01; *owidth=o;
}



Bling::Bling(Vec pt1) {
    this->anchor = pt1;
    float r,g,b;
    srand((unsigned)time(0));
    paint(&r, &g, &b);
    Vec v0 = this->anchor;
    Vec v1 = {anchor.getX()-13, anchor.getY()-13};
    Vec v2 = {anchor.getX()+13, anchor.getY()-13};
    Vec v3 = {anchor.getX()+13, anchor.getY()+13};
    Vec v4 = {anchor.getX()-13, anchor.getY()+13};
    sh = new Rec(v0,v1,v2,v3,v4, r,g,b);
}

void Bling::draw() {
    sh->draw();
}

void Bling::paint(float *r, float *g, float *b) {
    *r = (float) rand()/RAND_MAX;
    *g = (float) rand()/RAND_MAX;
    *b = (float) rand()/RAND_MAX;
}


UFO::UFO(Vec pt1, float A) {
    this->anchor = pt1;
    this->angle = A;

    Vec p1,p2,p3,p4,p5,p6,p7,p8,p9;
    p1 = {anchor.getX()-10,anchor.getY()-2};
    p2 = {anchor.getX()-2, anchor.getY()-2};
    p3 = {anchor.getX()-3, anchor.getY()-0};
    p4 = {anchor.getX()-9, anchor.getY()-0};

    p5 = {anchor.getX()+2, anchor.getY()-2};
    p6 = {anchor.getX()+10,anchor.getY()-2};
    p7 = {anchor.getX()+9, anchor.getY()-0};
    p8 = {anchor.getX()+3, anchor.getY()-0};

    p9 = {anchor.getX(),anchor.getY()};



    ColoredFig *sh1,*sh2,*sh3;
    sh1 = new Trapezoid(this->anchor,p1,p2,p3,p4,1,0,1);
    sh2 = new Trapezoid(this->anchor,p5,p6,p7,p8,1,0,1);
    sh3 = new Semicircle(p9,12, 5.0/255,158.0/255,160.0/255,A);

    sh1->rotate(A);
    sh2->rotate(A);
//    sh3->rotate(A);

    sh[0] = sh1;
    sh[1] = sh2;
    sh[2] = sh3;

}

void UFO::rotate(float *A) {
    float speed = 0.5;
    UFO::angle = UFO::angle + speed;
    *A = UFO::angle;
}

void UFO::draw() {
    for (int i = 0; i < 3; ++i) {
        sh[i]->draw();
    }
}



Car:: Car(Vec anchor) {
    this->anchor = anchor;
    p0 = {anchor.getX(),anchor.getY()};
    p1 = {this->anchor.getX() - 12,this->anchor.getY() - 4};
    p2 = {this->anchor.getX() + 12,this->anchor.getY() - 4};
    p3 = {this->anchor.getX() + 12,this->anchor.getY() + 4};
    p4 = {this->anchor.getX() - 12,this->anchor.getY() + 4};
    sh[0] = new Rec(p0,p1,p2,p3,p4,0.8,0.9,0.8);

    p5 = {this->anchor.getX() - (float)4.5,this->anchor.getY() - 4};
    sh[1] = new Circle(p0,p5,3,0.9,0.7,0.8);

    p6 = {this->anchor.getX() + (float)4.5,this->anchor.getY() - 4};
    sh[2] = new Circle(p0,p6,3,0.9,0.7,0.8);

    p7 = {this->anchor.getX() - 8,this->anchor.getY() + 4};
    p8 = {this->anchor.getX() + 8,this->anchor.getY() + 4};
    p9 = {this->anchor.getX() + 4,this->anchor.getY() + 9};
    p10 = {this->anchor.getX() - 4,this->anchor.getY() + 9};
    sh[3] = new Trapezoid(p0,p7,p8,p9,p10,0.9,0.7,0.7);

}
void Car::CarD() {
    for (int i = 0; i < 4; ++i) {
        sh[i]->draw();
    }
}

void Car::CarM(Vec dir) {
    this->anchor = dir * v + this->anchor;

    //每个图形move
    for (int i = 0; i < 4; ++i) {
        sh[i]->move(dir);
    }
}

void Car::CarR(float angle) {
    for (int i = 0; i < 4; ++i) {
        sh[i]->rotate(angle);
    }
}

Car::~Car() {
    for (int i = 0; i < 4; ++i) {
      delete sh[i];
    }
}

Vec Car::getAnchor(){
    return this->anchor;
}