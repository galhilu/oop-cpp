/*Assignment c++:1
 Author:Gal Hilu, ID:315477802
*/
#ifndef UNTITLED3_MENU_H
#define UNTITLED3_MENU_H
#include "Line.h"
#include "Clock.h"
#include "Fraction.h"

class Menu {
        public:
        Menu();
        ~Menu();
        void mainMenu();
        private:
        Line pointsinupt(int);
        void LineMenu();
        void fractionMenu();
        void clockMenu();
        void printMainmenu();
        void printlinemenu();
        void printfrationmenu();
        Fraction fraccreat();
        void printclockmenu();
        void printlinesbylen(Line,Line,Line);
};


#endif //UNTITLED3_MENU_H
