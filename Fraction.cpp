
#include "Fraction.h"
#include <iostream>
using namespace std;
Fraction::~Fraction(){}
Fraction::Fraction(int n, int d) {          //call constructor
    setNumerator(n);
    setDenominator(d);
    reduce();
}
void Fraction::reduce(){                //reduces to the smallest numerator and denominator possible
    int min;
    if (Denominator<Numerator)          // determine which is smaller
        min=Denominator;
    else
        min=Numerator;
    if (min<0)
        min=(-1)*min;
    for(int i=min;i>=2;i--){            //checks all numbers from min value to zero and if both are dividable by it, divides them both
        if (Denominator%i==0&&Numerator%i==0){
            Denominator=Denominator/i;
            Numerator=Numerator/i;
        }
    }
}
void Fraction::setNumerator(int n){                 //sets the numerator to a different value
    Numerator=n;
}
void Fraction::setDenominator(int d){               //sets the denominator to a different value
    Denominator=d;
}
void Fraction::add(Fraction frac){                  //calculates the sum of two fractions
    Fraction result;
    result.Numerator=Numerator*frac.Denominator+frac.Numerator*Denominator;                 //calculations ard done like this:
    result.Denominator=Denominator*frac.Denominator;                                        //(n1*d2)+(n2*d1)
    result.reduce();                                                                        //--------------        (n=numerator   d=denominator)
    result.printval();                                                                      //      d1*d2
}
void Fraction::printval(){                      // prints the value of the fraction
    cout<<"The value is:"<<Numerator<<"/"<<Denominator<<endl;
}
bool Fraction::isEqual(Fraction frac){          //checks if two fractions are the same
    if (frac.Numerator==Numerator&&frac.Denominator==Denominator)
        return true;
    else
        return false;
}