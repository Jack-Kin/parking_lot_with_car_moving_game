//
// Created by Administrator on 2018/7/30.
//

#include "d.h"

Vehicle::Vehicle(int arr[],int t,int p,int n){
    this->arrival[0]=arr[0];
    this->arrival[1]=arr[1];
    this->arrival[2]=arr[2];
    price=p;
    time=t;
    number=n;

    //get the leave time of the vehicle
    int day=time/1440;
    int hour=(time%1440)/60;
    int min=(time%1440)%60;
    if(min+arrival[2]>=60){
        leave[2]=min+arrival[2]-60;
        hour=hour+1;
    }
    else{
        leave[2]=min+arrival[2];
    }
    if(hour+arrival[1]>=24){
        leave[1]=hour+arrival[1]-24;
        day=day+1;
    }
    else{
        leave[1]=hour+arrival[1];
    }
    leave[0]=day;
}

int Vehicle::gettime(){
    return time;
}

int Vehicle::getprice(){
    return price;
}

int Vehicle::gettotalprice(){
    return (1+time/120)*price;
}

int Vehicle::getnumber(){
    return number;
}

Parkinglot::Parkinglot(){
    vacant=0;
    v=Vehicle();
}

int Parkinglot::getvacant(){return vacant;}

void Parkinglot::inputv(Vehicle vv){
    vacant=1;
    v=vv;
}

int Parkinglot::getvtime(){
    return v.gettime();
}

int Parkinglot::getvprice(){
    return v.getprice();
}

int Parkinglot::getvtotalprice(){
    return v.gettotalprice();
}

int Parkinglot:: getvnumber(){
    return v.getnumber();
}