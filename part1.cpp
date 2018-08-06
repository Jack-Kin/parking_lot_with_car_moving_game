#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>
#include "d.h"

//check in a single vehicle if there is vacant parkinglot and return whether it successfully checks in
bool checkin(vector<vector<Parkinglot>> *park,Vehicle vv,int arr[],int n){
    vector<vector<Parkinglot>>::iterator ito;//outer iteration
    vector<Parkinglot>::iterator it;//inner iteration
    int i=0;//mark the position of the outer iteration
    for(ito=(*park).begin();ito<(*park).end();ito++){
        i++;
        int ii=0;//mark the position of the inner iteration
        for(it=(*ito).begin();it<(*ito).end();it++){
            ii++;
            //if there is nor vehivle in this parkinglot, add it to the parking lot and print the ticket
            if((*it).getvacant()==0){
                (*it).inputv(vv);//add the vehicle to the parking lot
                ostringstream oss;
                oss<<"./Arrival/"<<"ticket"<<n<<".txt";
                ofstream out(oss.str());
                if(out){
                    if(arr[2]<10){out<<"Arrival: Day"<<arr[0]<<" "<<arr[1]<<":0"<<arr[2]<<endl;}
                    else{out<<"Arrival: Day"<<arr[0]<<" "<<arr[1]<<":"<<arr[2]<<endl;}
                    out<<"Type: ";
                    if(vv.getprice()==3){out<<"car";}
                    else if(vv.getprice()==5){out<<"van";}
                    else if(vv.getprice()==2){out<<"motorbike";}
                    else if(vv.getprice()==1){out<<"bicycle";}
                    out<<endl<<"floor"<<i<<"slot"<<ii<<endl;
                    out.close();
                }
                return true;
            }
        }
    }
    return false;
}

//check out all the vehicles need to leave the parking lot
void checkout(vector<vector<Parkinglot>> *park,int t){
    vector<vector<Parkinglot>>::iterator ito;
    vector<Parkinglot>::iterator it;
    for(ito=(*park).begin();ito<(*park).end();ito++) {
        for (it = (*ito).begin(); it < (*ito).end(); it++) {
            //judge whether there is a vehicle and whether it need to leave
            if((*it).getvacant()==1 && (*it).getvtime()<=t){
                ostringstream oss;
                oss<<"./Departure/"<<"vehicle"<<(*it).getvnumber()<<".txt";
                ofstream out(oss.str());
                if(out){
                    out<<"Time: "<<(*it).getvtime()<<"min"<<endl;
                    out<<"Type: ";
                    if((*it).getvprice()==3){out<<"car"<<endl;}
                    else if((*it).getvprice()==5){out<<"van"<<endl;}
                    else if((*it).getvprice()==2){out<<"motorbike"<<endl;}
                    else if((*it).getvprice()==1){out<<"bicycle"<<endl;}
                    out<<"Price: "<<(*it).getvtotalprice()<<endl;
                    out.close();
                }
                Parkinglot temppark;
                *it=temppark;//renew the parkinglot(vacant=0 and no vehicle)
            }
        }
    }
}

//randomly check in one type of car and randomly decide the time it arrive and the time it will spend
//arr[] is the time it arrive; n is the carnumber
bool randomcheckin(vector<vector<Parkinglot>> *park,int arr[],int n){
    arr[2]=arr[2]+rand()%30;//random decide the exact minutes it arrives
    if(arr[2]>=60){
        arr[2]=arr[2]-60;
        if(arr[1]+1>=24){
            arr[1]=arr[1]-23;
            arr[0]=arr[0]+1;
        }
        else{
            arr[1]=arr[1]+1;
        }
    }
    int spendtime=30+rand()%2850;//the time it will spend is less than two days
    int choosetype=rand()%4;//decide the type of car
    if(choosetype==0){
        car vv(arr,spendtime,n);//generate a car and check in
        if(checkin(park,vv,arr,n)){
            return true;
        }
    }
    else if(choosetype==1){
        van vv(arr,spendtime,n);
        if(checkin(park,vv,arr,n)){
            return true;
        }
    }
    else if(choosetype==2){
        motorbike vv(arr,spendtime,n);
        if(checkin(park,vv,arr,n)){
            return true;
        }
    }
    else if(choosetype==3){
        bicycle vv(arr,spendtime,n);
        if(checkin(park,vv,arr,n)){
            return true;
        }
    }
        return false;
}

int main() {
    srand(time(NULL));
    int t=10+rand()%50;//time of simulation; 1 for half an hour; 60 hours at most for demonstration

    int floor;
    floor=1+rand()%5;//1-6 floors

    vector<vector<Parkinglot>> parking;
    for(int i=0;i<floor;i++){
        int lotnumber=10+rand()%15;//the number of parking lot each floor
        vector<Parkinglot> temppark(lotnumber);
        parking.push_back(temppark);
    }

    int nowtime[3];//time when the simulation begin
    nowtime[0]=1;//Day 1
    nowtime[1]=rand()%24;//hour
    nowtime[2]=rand()%60;//min


    int totalnumberofcar=1;//to generate tickets


    //iterate once means half an hour
    for(int tt=1;tt<=t;tt++){
        int numberofcar=rand()%10;
        for(int vvv=1;vvv<=numberofcar;vvv++){
            if(randomcheckin(&parking,nowtime,totalnumberofcar)){
                totalnumberofcar++;
            }
        }

        checkout(&parking,tt*30);

        //current time
        if(nowtime[2]+30>=60){
            nowtime[2]=nowtime[2]-30;
            if(nowtime[1]+1>=24){
                nowtime[1]=nowtime[1]-23;
                nowtime[0]=nowtime[0]+1;
            }
            else{
                nowtime[1]=nowtime[1]+1;
            }
        }
        else{
            nowtime[2]=nowtime[2]+30;
        }
    }
    return 0;
}