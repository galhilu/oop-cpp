
#ifndef UNTITLED3_FRACTION_H
#define UNTITLED3_FRACTION_H


class Fraction {
        private:
        int Numerator,Denominator;
        void reduce();
        public:
        Fraction(int=0,int=1);
        ~Fraction();
        void setNumerator(int);
        void setDenominator(int);
        void add(Fraction);
        bool isEqual(Fraction);
        void printval();
};


#endif //UNTITLED3_FRACTION_H
