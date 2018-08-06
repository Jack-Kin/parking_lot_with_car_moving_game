//
// Created by jinzh on 2018/7/31.
//

#ifndef PROJECT3_VECTOR_H
#define PROJECT3_VECTOR_H

class Vec {
private:
    float x, y;
public:
    Vec(float _x=0, float _y=0) {
        Vec::x = _x;
        Vec::y = _y;//初始化
    }
    float getX();
    float getY();
//    void setX(float X);
//    void setY(float Y);

    Vec operator+(Vec v);           //相加
    Vec operator-(Vec v);           //相减
    Vec operator*(float k);         //数乘
    float operator*(Vec v);         //点乘
    Vec operator<<(float angle_1);  //顺时针转
    Vec operator>>(float angle_1);  //逆时针转
};

#endif //PROJECT3_VECTOR_H
