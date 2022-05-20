
#include "Clock.h"
#include <iostream>
using namespace std;

Clock::Clock(int h,int min,int sec){        //stores given or default parameters in time array
    time[0]=h;
    time[1]=min;
    time[2]=sec;
    if (time[0]>24||time[0]<0)              //if input is out of range calls timezero to set time to 00:00:00
        timezero();
    for(int i=1;i<2;i++)
        if (time[0]>60||time[0]<0)
            timezero();
}
Clock::~Clock(){}
void Clock::printtime(){                //prints time
    for(int i=0;i<2;i++) {                  //cheks if a zero is needed to add to display properly
        if (time[i] <= 9)
            cout << "0" << time[i] << ":";
        else
            cout << time[i] << ":";
    }
    if (time[2] <= 9)                        //the secs are out of loop because we don't want to print ":" after them

        cout << "0" << time[2]<<endl;
    else
        cout << time[2]<<endl;
}
int Clock::geth() {         //return hour
    return time[0];
}
int Clock::getmin() {         //return minuet
    return time[1];
}
int Clock::getsec() {         //return second
    return time[2];
}
void Clock::seth(int h){
    time[0]=h;
};
void Clock::setmin(int min){
    time[1]=min;
};
void Clock::setsec(int sec){
    time[2]=sec;
};
void Clock::timezero(){         //set time to 00:00:00
    for(int i=0;i<3;i++)
        time[i]=0;
}
bool Clock::isMorning(){
    if (time[0]<12)
        return true;
    else
        return false;
}
bool Clock::isAfternoon() {
    if (time[0] <= 12 && time[0]>18)
        return true;
    else
        return false;
}
bool Clock::isEvning() {
    if (time[0] >=18)
        return true;
    else
        return false;
}
void Clock::tick() {
    addtime(0,0,1);
}
void Clock::addh(int num){
    time[0]= (time[0]+num)%24;
}
void Clock::addmin(int num){
    time[1] = time[1] + num;
    if (time[1] >= 60) {
        time[1] = time[1] - 60;
        addh(1);
    }
}
void Clock::addsec(int num) {
    time[2] = time[2] + num;
    if (time[2] >= 60) {
        time[2] = time[2] - 60;
        addmin(1);
    }
}
void Clock::addtime(int h,int min,int sec){
    addh(h);
    addmin(min);
    addsec(sec);
    printtime();


}
