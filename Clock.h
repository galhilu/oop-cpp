/*Assignment c++:1
 Author:Gal Hilu, ID:315477802
*/
#ifndef UNTITLED3_CLOCK_H
#define UNTITLED3_CLOCK_H


class Clock {
        private:
        int time[3];
        void timezero();
        void addh(int);
        void addmin(int);
        void addsec(int);
        public:
        Clock(int=0,int=0,int=0);
        ~Clock();
        int geth();
        int getmin();
        int getsec();
        void seth(int);
        void setmin(int);
        void setsec(int);
        void printtime();
        bool isMorning();
        bool isAfternoon();
        bool isEvning();
        void tick();
        void addtime(int,int,int);
};


#endif //UNTITLED3_CLOCK_H
