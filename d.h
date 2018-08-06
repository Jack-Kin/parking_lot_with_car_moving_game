//
// Created by Administrator on 2018/7/30.
//

#ifndef P13_D_H
#define P13_D_H

#include <iostream>
using namespace std;

class Vehicle{
public:
    Vehicle()=default;
    Vehicle(int arr[],int t,int p,int n);//arr[]: arrival time; t: the time it spends; p: the price per unit time; n: number of car
    int gettime();//return this->time
    int getprice();//return this->price
    int gettotalprice();//return the total price
    int getnumber();//return the number of car
protected:
    int arrival[3];//day(1-n), hour, min
    int leave[3];//the time it leave
    int time;//total time it spend in the parkinglot in mins
    int price;//the price per unit time for different types of cars; judge the type of vehicle by price: 3 for car; 5 for van; 2 for motorbike; 1 for bicycle
    int number;//the number of car to name the file of ticket
};

class car:public Vehicle{
public:
    car(int arr[],int t,int n):Vehicle(arr,t,3,n){};//set the price as 3
};

class van:public Vehicle{
public:
    van(int arr[],int t,int n):Vehicle(arr,t,5,n){};
};

class motorbike:public Vehicle{
public:
    motorbike(int arr[],int t,int n):Vehicle(arr,t,2,n){};
};

class bicycle:public Vehicle{
public:
    bicycle(int arr[],int t,int n):Vehicle(arr,t,1,n){};
};

class Parkinglot{
public:
    Parkinglot();
    void inputv(Vehicle vv);//add a new vehicle to the empty parkinglot
    int getvacant();//to see whether it is vacant
    // get the information of the vehicle in the parkinglot
    int getvtime();
    int getvprice();
    int getvtotalprice();
    int getvnumber();
protected:
    int vacant;//0 for vacant
    Vehicle v;
};

#endif //P13_D_H
