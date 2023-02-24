#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;
char symbol;

void DispTime ()
{
    time_t timetoday;
    time(&timetoday);
    system("cls");
    cout << endl << "Calendar date and time as per todays is : " << asctime(localtime(&timetoday));
}
void AddDays ()
{
    int aMenu=0, eD=0, eM=0, eY=0, gD=0, gM=0, gY=0, n=0, leap=0, monthDate=0;
            do
            {
                system("cls");
                cout << "what would you like?"<<endl;
                cout << "1. Adding to EC"<<endl;
                cout << "2. Adding to GC"<<endl;
                cout << "3. Exit"<<endl;
                cout << "Enter menu entry: ";
                cin >> aMenu;

        if (aMenu<0||aMenu>3)
            cerr <<endl<< "Error Invalid Input"<<endl;

            }while(aMenu<0||aMenu>3);

            if(aMenu==3)
                return;

            if (aMenu==1)
            {
                do
                {
                    system("cls");
                    cout << "Enter Ethiopian calendar as follows dd/mm/yyyy: ";
                    cin >> eD >> symbol >> eM >> symbol >> eY;

                    cout << "How many days would you like to add: ";
                    cin >> n;
                }while(eD<0||eD>30||eM<0||eM>13||eY<0||n<0); // verifying the input

                if ((eY-1) % 400 == 0) // checking for leap year
                    leap = 6;
                else if ((eY-1) % 4 == 0)
                    leap = 6;
                else leap = 5;

            for (int i=1; i<=n; ++i) // loop for adding the day
            {
                if (eM >= 13 && eD >= leap) // checks if the year passed
                {
                    eY++;
                    eM=1;
                    eD=0;
                }
                if (eD >= 30) // checks if the month passed
                {
                    eM++;
                    eD=0;
                }

                if (eD<30) // checks if the day is less than 30
                    eD++;

            }

            cout <<setfill('0')<< "The new date is " <<setw(2)<< eD << symbol <<setw(2)<< eM << symbol << eY;

            }else //(aMenu==2)
            {
                do
                {
                    system("cls");
                    cout << "Enter Gregorian calendar as follows dd/mm/yyyy: ";
                    cin >> gD >> symbol >> gM >> symbol >> gY;

                    cout << "How many days would you like to add: ";
                    cin >> n;
                }while(gD<0||gD>31||gM<0||gM>12||gY<0||n<0); // verify s the input

            if (gY % 400 == 0) // checks for leap year and make feburary 29 instead of 28
                leap = 29;
            else if (gY % 4 == 0)
                leap = 29;
            else leap = 28;

            for (int i=1; i<=n; ++i)
            {
                if(gM==1||gM==3||gM==5||gM==7||gM==8||gM==10||gM==12) // checking if the month has 31 days
                {
                    monthDate=31;
                }else if (gM==2) // if it's feburary making the day equal to the day
                    monthDate=leap;
                else
                    monthDate=30; // all the other left month have 30 days



                if (gD>=monthDate)
                {
                    gM++;
                    gD=0;
                }

                if (gM>=12 && gD>=monthDate)
                {
                    gY++;
                    gM=1;
                    gD=0;
                }

                if (gD<monthDate)
                {
                    gD++;
                }
            }

            cout <<setfill('0')<<setw(2)<<"The new Date is "<< gD << symbol <<setw(2)<< gM << symbol << gY;

            }
}

int main()
{
    int sMenu=0;

        cout <<setw(4)<< "1. " << "Show local date and time" << endl;
        cout <<setw(4)<< "2. " << "Convert Date(EC to GC or GC to EC)" << endl;
        cout <<setw(4)<< "3. " << "Add n days to Date(EC  or GC)" << endl;
        cout <<setw(4)<< "4. " << "Date difference between two dates( EC or GC)" << endl;
        cout <<setw(4)<< "5. " << "Show Zemen(Yohannes, Markos, ...) for EC year" << endl;
        cout <<setw(4)<< "6. " << "Is Leap year(EC or GC)" << endl;
        cout <<setw(4)<< "7. " << "The weekday for a given date(EC or GC)" << endl;
        cout <<setw(4)<< "8. " << "Show EC calendar" << endl;
        cout <<setw(4)<< "9. " << "Show GC calendar" << endl;
        cout <<setw(4)<< "10. " << "Exit" << endl;

        cout << "Enter menu entry: ";
        cin >> sMenu;

    switch (sMenu)
    {
        case 1:
            DispTime();
        break;
        case 3:
            AddDays();
        break;
    }

}
