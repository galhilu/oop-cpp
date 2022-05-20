
#include <iostream>
#include "Line.h"
#include <cmath>
using namespace std;


Line::Line(){};
Line::~Line(){};
Line::Line(double x1,double y1, double x2, double y2){
    setLine(x1,y1,x2,y2);
    len=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));         //calculates distance between the points using pitagoras formula

};
void Line::setLine(double xx1,double yy1, double xx2, double yy2){        //set points x and y
    x1=xx1;
    y1=yy1;
    x2=xx2;
    y2=yy2;
};
void Line::printLine(){
    cout<<"("<<x1<<","<<y1<<")"<<" --> "<<"("<<x2<<","<<y2<<")"<<endl;
    cout<<"the length is: "<<len<<endl;
};
double Line::getLen() {
    return len ;
};

