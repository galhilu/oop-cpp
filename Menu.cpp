
#include <iostream>
#include "Menu.h"


using namespace std;
Menu::Menu(){}
Menu::~Menu(){}
void Menu::mainMenu(){                  //the Main menu input loop
    int choice;
    while (1){
        printMainmenu();
        cin>>choice;
        switch (choice) {               // a case for each of the menu choices by order
            case 1:
                LineMenu();             //go to line menu
                break;
            case 2:
                fractionMenu();         //go to fraction menu
                break;
            case 3:
                clockMenu();            //go to clock menu
                break;
            case 4:
                cout<<"Goodbye!"<<endl;     //ends program
                return;
            default:
                cout<<"illegal choice"<<endl;
        }
    }


};
void Menu::printMainmenu(){                     //prints the Main menu
    cout<<"(1) - line menu"<<endl;
    cout<<"(2) - fraction menu"<<endl;
    cout<<"(3) - clock menu"<<endl;
    cout<<"(4) - exit"<<endl;
    return;
};
void Menu::printlinemenu(){                     //prints the line menu
    cout<<"<1> To view first Line coordinates and length."<<endl;
    cout<<"<2> To view second Line coordinates and length."<<endl;
    cout<<"<3> To view third Line coordinates and length."<<endl;
    cout<<"<4> To print line order by length"<<endl;
    cout<<"<5> To exit"<<endl;
};
void Menu::printfrationmenu(){                      //prints the fraction menu
    cout<<"<1> calculate sum of f1 and f2."<<endl;
    cout<<"<2> is equal?."<<endl;
    cout<<"<3> print first fraction."<<endl;
    cout<<"<4> print second fraction."<<endl;
    cout<<"<5> exit."<<endl;
};
void Menu::printclockmenu(){                    //prints the clock menu
    cout<<"<1> what is the time"<<endl;
    cout<<"<2> add second"<<endl;
    cout<<"<3> add 10 seconds"<<endl;
    cout<<"<4> add 02:30:15"<<endl;
    cout<<"<5> exit"<<endl;
};
void Menu::LineMenu(){                          // creates 3 lines from user input and goes to line menu
    Line linearr[3];                            //here we will store the 3 lines the user will create
    for(int i=1;i<=3;i++){                      //loop for creating and storing the 3 lines
        linearr[i-1]=pointsinupt(i);
    };
    int choice;
    while (1){
        printlinemenu();
        cin>>choice;
        switch(choice){
            case 1 :                   //print a line according to the users choice
                cout<<"the coordinate of line 1:"<<endl;
                linearr[0].printLine();
                break;
            case 2 :                   //print a line according to the users choice
                cout<<"the coordinate of line 2:"<<endl;
                linearr[1].printLine();
                break;
            case 3 :                   //print a line according to the users choice
                cout<<"the coordinate of line 3:"<<endl;
                linearr[2].printLine();
                break;
            case 4:                         //prints the lines in length order
                printlinesbylen(linearr[0],linearr[1],linearr[2]);
                break;
            case 5:                         //back to main menu
                return;
            default:
                cout<<"illegal choice"<<endl;
        }
    }
};
Fraction Menu::fraccreat(){                 //asks the user for two numbers to create a fraction
    int n,d;
    cout<<"Numerator:";
    cin>>n;
    cout<<"Denominator:";
    cin>>d;
    return Fraction(n,d);
}
void Menu::fractionMenu(){                      // creates 2 fractions from user input and goes to fractions menu
    cout<<"Set the first fraction:"<<endl;
    Fraction f1=fraccreat();
    cout<<"Set the second fraction:"<<endl;
    Fraction f2=fraccreat();
    int choice;
    while (1){
        printfrationmenu();
        cin>>choice;
        switch(choice){
            case 1:                             //calculate the sum of the two fractions
                f1.add(f2);
                break;
            case 2:
                if(f1.isEqual(f2))              //checks if the fractions are the same
                    cout<<"equal"<<endl;
                else
                    cout<<"not equal"<<endl;
                break;
            case 3:                             //prints f1
                f1.printval();
                break;
            case 4:                             //prints f2
                f2.printval();
                break;
            case 5:                             //return to main menu
                return;
            default:
                cout<<"illegal choice"<<endl;
        }
    }
};
void Menu::clockMenu(){                         // creates a clock from user input and goes to clock menu
    int h,min,sec;
    cout<<"Enter hours:"<<endl;                 //gets input
    cin>>h;
    cout<<"Enter minutes:"<<endl;
    cin>>min;
    cout<<"Enter seconds:"<<endl;
    cin>>sec;
    Clock clock1=Clock(h,min,sec);          //create the clock
    int choice;
    while (1){                              //menu loop
        printclockmenu();
        cin>>choice;
        switch(choice){
            case 1:
                clock1.printtime();         //display the time
                break;
            case 2:
                clock1.tick();              // add 1 second
                break;
            case 3:
                for(int i=0;i<10;i++)       //add 10 second
                    clock1.tick();
                break;
            case 4:
                clock1.addtime(2,30,15);        //add 2 hours 30 minutes and 15 seconds
                break;
            case 5:                         // return to main menu
                return;
            default:
                cout<<"illegal choice"<<endl;
        }
    }

};
Line Menu::pointsinupt(int i){              //asks for input to make a Line object
    double x1,x2,y1,y2;
    cout<<"Enter the first point of Line "<<i<<":"<<endl;
    cin>>x1;
    cin>>y1;
    cout<<"Enter the second point of Line "<<i<<":"<<endl;
    cin>>x2;
    cin>>y2;
    Line l=Line(x1,y1,x2,y2);
    return l;
};
void Menu::printlinesbylen(Line l1,Line l2,Line l3) {                       //prints the 3 lines by length
    cout<<"the coordinate ordered from high to low(by length):"<<endl;
    if (l1.getLen() >= l2.getLen() && l1.getLen() >= l3.getLen()) {           //the case when l1 is the longest
        cout<<"cord:";
        l1.printLine();
        if (l2.getLen() >= l3.getLen()) {
            cout<<"cord:";
            l2.printLine();
            cout<<"cord:";
            l3.printLine();
            return;
        } else{
            cout<<"cord:";
            l3.printLine();
            cout<<"cord:";
            l2.printLine();
            return;
        }
    }
    if (l2.getLen() >= l3.getLen() ) {                                   //the case when l2 is the longest
        cout<<"cord:";
        l2.printLine();
        if (l3.getLen() >= l1.getLen()) {
            cout<<"cord:";
            l3.printLine();
            cout<<"cord:";
            l1.printLine();
            return;
        } else{
            cout<<"cord:";
            l1.printLine();
            cout<<"cord:";
            l3.printLine();
            return;
        }
    } else {                                                            //the case when l3 is the longest
        cout<<"cord:";
        l3.printLine();
        if (l2.getLen() > l1.getLen()) {
            cout<<"cord:";
            l2.printLine();
            cout<<"cord:";
            l1.printLine();
            return;
        } else{
            cout<<"cord:";
            l1.printLine();
            cout<<"cord:";
            l2.printLine();
            return;
        }
    }
}