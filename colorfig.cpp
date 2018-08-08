//
// Created by jinzh on 2018/7/31.
//
#include "vector.h"
#include "colorfig.h"
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159
#define N 100
const float v = 1;
Rec::Rec(Vec anchor, Vec pt1, Vec pt2, Vec pt3, Vec pt4, float r, float g, float b): p1((float)-1.0,(float)-0.5),p2((float)1.0,(float)0.5){
    this->anchor = anchor; p1 = pt1; p2 = pt2; p3 = pt3; p4 = pt4; this->r = r; this->g = g; this->b = b;
}
void Rec::draw() {
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(p1.getX(),p1.getY());
    glVertex2f(p2.getX(),p2.getY());
    glVertex2f(p3.getX(),p3.getY());
    glVertex2f(p4.getX(),p4.getY());
    glEnd();
}

void Rec::move(Vec dir) {
    Vec vector = (dir * v) + this->anchor;
    setAnchor(vector);
    p1 = (dir *v) + p1;
    p2 = (dir *v) + p2;
    p3 = (dir *v) + p3;
    p4 = (dir *v) + p4;
}

void Rec::rotate(double angle) {
    p1 = ((p1 - anchor) << angle )+ anchor;
    p2 = ((p2 - anchor) << angle )+ anchor;
    p3 = ((p3 - anchor) << angle )+ anchor;
    p4 = ((p4 - anchor) << angle )+ anchor;
}


Circle::Circle(Vec anchor, Vec pt1, float R, float r, float g, float b):p1((float)0,(float)0),R((float)2) {
    this->anchor = anchor; this->p1 = pt1; this->R = R; this->r = r; this->g = g; this->b = b;
}
void Circle::draw() {
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < N; ++i) {
        glVertex2f((float) (p1.getX() + R * cos(2 * PI*i/N)),(float) (p1.getY() + R * (sin(2 * PI*i/N))));
    }
    glEnd();
}

void Circle::move(Vec dir) {
    Vec vector = (dir * v) + this->anchor;
    setAnchor(vector);
    p1 = (dir *v) + p1;
}
void Circle::rotate(double angle) {
    p1 = ((p1 - anchor) << angle )+ anchor;
}


Semicircle::Semicircle(Vec pt1, float R, float r, float g, float b, float angle):p1(0,0),R(2) {
    this->p1 = pt1; this->R = R; this->r = r; this->g = g; this->b = b, this->alpha = angle;
}

void Semicircle::draw() {
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < (N+1); ++i) {
        glVertex2f((float) (p1.getX() + R * cos( PI*i/N + PI/180*this->alpha)),(float) (p1.getY() + R * (sin(PI*i/N + PI/180*this->alpha ))));
    }
    glEnd();

//    this->alpha = this->alpha + (float)0.5;
}

void Semicircle::rotate( double angle) {
    p1 = ((p1 - anchor) << angle )+ anchor;
}

void Semicircle::move(Vec dir) {
    Vec vector = (dir * v) + this->anchor;
    setAnchor(vector);
    p1 = (dir *v) + p1;
}


Triangle::Triangle(Vec anchor, Vec pt1, Vec pt2, Vec pt3, float r, float g, float b): p1((float)-1.0,0.0),p2(1.0,0.0),p3(0.0,1.0) {
    this->anchor = anchor; this->p1 = pt1; this->p2 = pt2; this->p3 = pt3, this->r = r, this->g = g; this->b = b;
}
void Triangle::draw() {
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLES);
    glVertex2f(p1.getX(), p1.getY());
    glVertex2f(p2.getX(), p2.getY());
    glVertex2f(p3.getX(), p3.getY());
    glEnd();
}


void Triangle::move(Vec dir) {
    Vec vector = (dir * v) + this->anchor;
    setAnchor(vector);
    p1 = (dir *v) + p1;
    p2 = (dir *v) + p2;
    p3 = (dir *v) + p3;
}

void Triangle::rotate(double angle) {
    p1 = ((p1 - anchor) << angle )+ anchor;
    p2 = ((p2 - anchor) << angle )+ anchor;
    p3 = ((p3 - anchor) << angle )+ anchor;
}

Trapezoid::Trapezoid(Vec anchor, Vec pt1, Vec pt2, Vec pt3, Vec pt4, float r, float g, float b) : p1((float)-2.0,0.0),p2(2.0,0.0),p3(1.0,1.0),p4((float)-1.0,1.0) {
    this->anchor = anchor, this->p1 = pt1; this->p2 = pt2; this->p3 = pt3, this->p4 = pt4, this->r = r, this->g = g; this->b = b;
}
void Trapezoid::draw() {
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(p1.getX(), p1.getY());
    glVertex2f(p2.getX(), p2.getY());
    glVertex2f(p3.getX(), p3.getY());
    glVertex2f(p4.getX(), p4.getY());
    glEnd();
}

void Trapezoid::move(Vec dir) {
    Vec vector = (dir * v) + this->anchor;
    setAnchor(vector);
    p1 = (dir *v) + p1;
    p2 = (dir *v) + p2;
    p3 = (dir *v) + p3;
    p4 = (dir *v) + p4;
}

void Trapezoid::rotate(double angle) {
    p1 = ((p1 - this->anchor) << angle) + this->anchor;
    p2 = ((p2 - this->anchor) << angle) + this->anchor;
    p3 = ((p3 - this->anchor) << angle) + this->anchor;
    p4 = ((p4 - this->anchor) << angle) + this->anchor;
}
