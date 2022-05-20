
#ifndef UNTITLED3_LINE_H
#define UNTITLED3_LINE_H


class Line {
        private:
        double x1,y1;               // defines the first point
        double x2,y2;               // defines the second point
        double len;                 // the distance between the points
        public:
        Line();
        ~Line();
        Line(double x1,double y1, double x2, double y2);
        void setLine(double x1,double y1, double x2, double y2);
        double getLen();
        void printLine();
};


#endif //UNTITLED3_LINE_H
