#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
    int sMenu=0,lMenu=0,aMenu=0,bMenu=0,cMenu=0,dMenu=0;
    int eD=1,eM=1,eY=1,gD=1,gM=1,gY=1;
    char symbol;
    //Conversion
    int nY=1, nM=1, nD=1;
    //GC calendar
    int year, firstDM;
    int numDays;
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	string month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	//EC calendar
    int yearE, firstDME;
    int numDaysE;
    int daysE[] = {30,30,30,30,30,30,30,30,30,30,30,30,5};

    //EC adding n
    int n, leap;
    //GC adding n
    int monthDate;
    //Zemen calculating
    int amAlem, zemenR;
    int const bcYear = 5500;
    string zemen[4] = { "Yohannes", "Mathewos", "Markos", "Lukas"};
    //Diiference between dates
    char ans;
    bool error;
    int k=0, h=0, kP=0, hP=0, T=0, Tp=0, p=0, pP=0, tD=0;
    int ta[12] = {10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
    int tb[12] = {6, 7, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5};
    //WeekDay
    string weekDay[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string ecDay[7] = {"Ehud", "Segno", "Maksegno", "Erob", "Hamus", "Arb", "Kidame"};
    int monthCode[12] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int temp, yNum, lNum=0, day;

	string monthE[] = { "Meskerem", "Tikimt", "Hidar", "Tahsas", "Tir", "Yakatit", "Meggabit", "Miyazya", "Ginbot", "Sene", "Hamle", "Nehase", "Pagume"};

    do
    {
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

        if (sMenu<0||sMenu>10)
            cerr <<endl<< "Error Invalid Input"<<endl;

    }while(sMenu<0||sMenu>10);

    switch(sMenu)
    {
        case 1:
            time_t timetoday;
            time(&timetoday);
            cout << endl << "Calendar date and time as per todays is : " << asctime(localtime(&timetoday));
        break;
        case 2:
            do
            {
                cout << "what would you like?"<<endl;
                cout << "1. EC to GC"<<endl;
                cout << "2. GC to EC"<<endl;
                cout << "3. Exit"<<endl;
                cout << "Enter menu entry: ";
                cin >> lMenu;

        if (lMenu<0||lMenu>3)
            cerr <<endl<< "Error Invalid Input"<<endl;

            }while(lMenu<0||lMenu>3);
            if (lMenu==3)
                break;

            if (lMenu==1)
            {
                do
                {
                    cout << "Enter Ethiopian calendar as follows dd/mm/yyyy: ";
                    cin >> eD >> symbol >> eM >> symbol >> eY;
                }while(eD<0||eD>30||eM<0||eM>13||eY<0);

        if(eM==5||eM==8||eM==9)
        {
            nY = eY + 8;
            nM = eM - 4;
            if (nM<1)
            nM += 12;
            nD = eD + 8;
            if (nD>days[nM-1])
            {
                nD -= days[nM-1];
                ++nM;
            }
            if (nM>12)
                nM -= 12;
        }else if (eM==6||eM==10||eM==11)
        {
            nY = eY + 8;
            nM = eM - 4;
            if (nM<1)
            nM += 12;
            nD = eD + 7;
            if (nD>days[nM-1])
            {
                nD -= days[nM-1];
                ++nM;
            }
            if (nM>12)
                nM -= 12;
        }else if(eM==12)
        {
            nY = eY + 8;
            nM = eM - 4;
            if (nM<1)
            nM += 12;
            nD = eD + 6;
            if (nD>days[nM-1])
            {
                nD -= days[nM-1];
                ++nM;
            }
            if (nM>12)
                nM -= 12;
        }else if (eM==13)
        {
            nY = eY + 8;
            nM = eM - 4;
            if (nM<1)
            nM += 12;
            nD = eD + 5;
            if (nD>days[nM-1])
            {
                nD -= days[nM-1];
                ++nM;
            }
            if (nM>12)
                nM -= 12;
        }else if (eM<=2)
        {
            nY = eY + 7;
            nM = eM - 4;
            if (nM<1)
            nM += 12;
            nD = eD + 10;
            if (nD>days[nM-1])
            {
                nD -= days[nM-1];
                ++nM;
            }
            if (nM>12)
                nM -= 12;
        }else
        {
            nY = eY + 8;
            nM = eM - 4;
            if (nM<1)
            nM += 12;
            nD = eD + 9;
            if (nD>days[nM-1])
            {
                nD -= days[nM-1];
                ++nM;
            }
            if (nM>12)
                nM -= 12;
        }

        cout <<setfill('0')<<setw(2)<< nD << symbol <<setw(2)<< nM << symbol << nY;
            }else
            {
                do
                {
                    cout << "Enter Gregorian calendar as follows dd/mm/yyyy: ";
                    cin >> gD >> symbol >> gM >> symbol >> gY;
                }while(gD<0||gD>31||gM<0||gM>12||gY<0);

                if (gM==1||gM==4||gM==5)
                {
                    nY = gY - 8;
                    if (gY % 400 == 0 || gY % 4 == 0)
                        daysE[12] = 6;
                    nM = gM + 4;
                    nD = gD - 8;
                    if (nD<=0)
                    {
                        nD += daysE[nM-1];
                        --nM;
                    }

                }else if(gM==2||gM==6||gM==7)
                {
                    nY = gY - 8;
                    if (gY % 400 == 0 || gY % 4 == 0)
                        daysE[12] = 6;
                    nM = gM + 4;
                    nD = gD - 7;
                    if (nD<=0)
                    {
                        nD += daysE[nM-1];
                        --nM;
                    }
                }else if (gM==3)
                {
                    nY = gY - 8;
                    if (gY % 400 == 0 || gY % 4 == 0)
                        daysE[12] = 6;
                    nM = gM + 4;
                    nD = gD - 9;
                    if (nD<=0)
                    {
                        nD += daysE[nM-1];
                        --nM;
                    }
                }else if (gM==8)
                {
                    nY = gY - 8;
                    if (gY % 400 == 0 || gY % 4 == 0)
                        daysE[12] = 6;
                    nM = gM + 4;
                    nD = gD - 6;
                    if (nD<=0)
                    {
                        nD += daysE[nM-1];
                        --nM;
                    }
                }else if (gM==9)
                {
                    nY = gY - 8;
                    if (gY % 400 == 0 || gY % 4 == 0)
                        daysE[12] = 6;
                    nM = gM + 4;
                    nD = gD - 5;
                    if (nD<=0)
                    {
                        --nM;
                        nD += daysE[nM-1];
                    }if (nD > daysE[nM-1])
                    {
                        nD -= daysE[nM-1];
                        ++nY;
                        nM = 1;
                    }
                }else if (gM==10)
                {
                    nY = gY - 7;
                    if (gY % 400 == 0 || gY % 4 == 0)
                        daysE[12] = 6;
                    nM = gM + 4;
                    if(nM>13)
                        nM -= 12;
                    nD = gD - 10;
                    if (nD<=0)
                    {
                        --nM;
                        nD += daysE[nM-1];
                    }
                }else if (gM==11||gM==12)
                {
                    nY = gY - 7;
                    if (gY % 400 == 0 || gY % 4 == 0)
                        daysE[12] = 6;
                    nM = gM + 4;
                    if(nM>13)
                        nM -= 12;
                    nD = gD - 9;
                    if (nD<=0)
                    {
                        --nM;
                        nD += daysE[nM-1];
                    }
                }


                cout <<setfill('0')<<setw(2)<< nD << symbol <<setw(2)<< nM << symbol << nY;
            }

        break;
        case 3:
            do
            {
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
                break;

            if (aMenu==1)
            {
                do
                {
                    cout << "Enter Ethiopian calendar as follows dd/mm/yyyy: ";
                    cin >> eD >> symbol >> eM >> symbol >> eY;

                    cout << "How many days would you like to add: ";
                    cin >> n;
                }while(eD<0||eD>30||eM<0||eM>13||eY<0||n<0);

                if (eY % 400 == 0)
                    leap = 6;
                else if (eY % 4 == 0)
                    leap = 6;
                else leap = 5;

            for (int i=1; i<=n; ++i)
            {
                if (eM >= 13 && eD >= leap)
                {
                    eY++;
                    eM=1;
                    eD=0;
                }
                if (eD >= 30)
                {
                    eM++;
                    eD=0;
                }

                if (eD<30)
                    eD++;

            }

            cout <<setfill('0')<<setw(2)<< "The new date is " << eD << symbol <<setw(2)<< eM << symbol << eY;

            }else //(aMenu==2)
            {
                do
                {
                    cout << "Enter Gregorian calendar as follows dd/mm/yyyy: ";
                    cin >> gD >> symbol >> gM >> symbol >> gY;

                    cout << "How many days would you like to add: ";
                    cin >> n;
                }while(gD<0||gD>31||gM<0||gM>12||gY<0||n<0);

            if (gY % 400 == 0)
                leap = 29;
            else if (gY % 4 == 0)
                leap = 29;
            else leap = 28;

            for (int i=1; i<=n; ++i)
            {
                if(gM==1||gM==3||gM==5||gM==7||gM==8||gM==10||gM==12)
                {
                    monthDate=31;
                }else if (gM==2)
                    monthDate=leap;
                else
                    monthDate=30;



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

        break;
        case 4:
            do
            {
                cout << "what would you like?"<<endl;
                cout << "1. Difference for EC Dates"<<endl;
                cout << "2. Difference for GC Dates"<<endl;
                cout << "3. Exit"<<endl;
                cout << "Enter menu entry: ";
                cin >> bMenu;

        if (bMenu<0||bMenu>3)
            cerr <<endl<< "Error Invalid Input"<<endl;

            }while(bMenu<0||bMenu>3);

            if(bMenu==3)
                break;

            if(bMenu==1)
            {
                do
                {
                    cout << "Enter the first date as follows dd/mm/yyyy: ";
                    cin >> eD >> symbol >> eM >> symbol >> eY;
                }while(eD<0||eD>30||eM<0||eM>13||eY<0);

                do
                {
                    cout << "Enter the second date as follows dd/mm/yyyy: ";
                    cin >> gD >> symbol >> gM >> symbol >> gY;
                }while(gD<0||gD>30||gM<0||gM>13||gY<0);

                cout <<setfill('0')<<setw(2)<< eD << symbol <<setw(2)<< eM << symbol << eY<<endl;
                cout <<setfill('0')<<setw(2)<< gD << symbol <<setw(2)<< gM << symbol << gY;

            }else
            {
                 do
                {
                    do
                    {
                        cout << "Enter the first date as follows dd/mm/yyyy: ";
                        cin >> eD >> symbol >> eM >> symbol >> eY;

                        if (eD<0||eD>30||eM<0||eM>13||eY<0)
                            cerr <<endl<< "Error Invalid Input"<<endl;
                    }while(eD<0||eD>30||eM<0||eM>13||eY<0);

                    do
                    {
                        cout << "Enter the second date as follows dd/mm/yyyy: ";
                        cin >> gD >> symbol >> gM >> symbol >> gY;

                        if (gD<0||gD>30||gM<0||gM>13||gY<0)
                            cerr <<endl<< "Error Invalid Input"<<endl;
                    }while(gD<0||gD>30||gM<0||gM>13||gY<0);

                        if(gY==eY & gM==eM & gD<eD)
                            cout << "The second date can't be lower than the first"<<endl;
                        if(gY==eY & gM<eM)
                            cout << "The second date can't be lower than the first"<<endl;
                        if (gY<eY)
                        {
                            cout << "The second date can't be lower than the first"<<endl;
                        }

                }while(gY<eY|(gY==eY&gM<eM)||(gY==eY&gM==eM&gD<eD));

                do
                {
                    error = true;
                    cout << "Would you like to add the end date(y/n): ";
                    cin >> ans;

                    if (ans=='y'||ans=='n'||ans=='Y'||ans=='N')
                        error = false;
                }while(error);

                if (eM<= 2)
                    eY -= 1;
                if (gM <= 2)
                    gY -= 1;

                k = eY/100;
                kP = gY/100;
                h = eY-(100*k);
                hP = gY-(100*kP);

                T = (24*k) + (k/4) + (h/4);
                Tp = (24*kP) + (kP/4) + (hP/4);
                p = (30 * ta[eM-1]) + tb[eM-1];
                pP = (30 * ta[gM-1]) + tb[gM-1];

                T += p + eD;
                Tp += pP + gD;

                tD = 365*(gY-eY) + Tp - T;

                if (ans=='Y'||ans=='y')
                    cout <<endl<< "The difference between the dates in days is: " << tD+1 << " Days";
                else
                    cout <<endl<< "The difference between the dates in days is: " << tD << " Days";

            }

        break;
        case 5:
            do
            {
                cout << "Enter the year: ";
                cin >> eY;
            }while(eY<0);

        amAlem = bcYear + eY;
        zemenR = amAlem%4;

        cout << zemen[zemenR];

        break;
        case 6:
            do
            {
                cout << "what would you like?"<<endl;
                cout << "1. Leap year for EC Dates"<<endl;
                cout << "2. Leap year for GC Dates"<<endl;
                cout << "3. Exit"<<endl;
                cout << "Enter menu entry: ";
                cin >> cMenu;

        if (cMenu<0||cMenu>3)
            cerr <<endl<< "Error Invalid Input"<<endl;

            }while(cMenu<0||cMenu>3);

            if(cMenu==3)
                break;

            if(cMenu==1)
            {
                do
                {
                    cout << "Enter the year: ";
                    cin >> eY;
                }while(eY<0);
            }else
            {
                do
                {
                    cout << "Enter the year: ";
                    cin >> eY;
                }while(eY<0);
            }

            if (eY % 400 == 0)
                cout << eY << " is a leap year";
            else if (eY % 100 == 0)
                cout << eY << " is not a leap year";
            else if (eY % 4 == 0)
                cout << eY << " is a leap year";
            else
                cout << eY << " is not a leap year";

        break;
        case 7:
            do
            {
                cout << "what would you like?"<<endl;
                cout << "1. Weekday for EC Dates"<<endl;
                cout << "2. Weekday for GC Dates"<<endl;
                cout << "3. Exit"<<endl;
                cout << "Enter menu entry: ";
                cin >> dMenu;

                if (dMenu<0||dMenu>3)
                    cerr <<endl<< "Error Invalid Input"<<endl;

            }while(dMenu<0||dMenu>3);

            if(dMenu==3)
                break;

            if(dMenu==1)
            {
                do
                {
                    cout << "Enter Ethiopian calendar as follows dd/mm/yyyy: ";
                    cin >> eD >> symbol >> eM >> symbol >> eY;
                }while(eD<0||eD>30||eM<0||eM>13||eY<0);

                if(eM==5||eM==8||eM==9)
                {
                    nY = eY + 8;
                    nM = eM - 4;
                    if (nM<1)
                    nM += 12;
                    nD = eD + 8;
                    if (nD>days[nM-1])
                    {
                        nD -= days[nM-1];
                        ++nM;
                    }
                    if (nM>12)
                        nM -= 12;
                }else if (eM==6||eM==10||eM==11)
                {
                    nY = eY + 8;
                    nM = eM - 4;
                    if (nM<1)
                    nM += 12;
                    nD = eD + 7;
                    if (nD>days[nM-1])
                    {
                        nD -= days[nM-1];
                        ++nM;
                    }
                    if (nM>12)
                        nM -= 12;
                }else if(eM==12)
                {
                    nY = eY + 8;
                    nM = eM - 4;
                    if (nM<1)
                    nM += 12;
                    nD = eD + 6;
                    if (nD>days[nM-1])
                    {
                        nD -= days[nM-1];
                        ++nM;
                    }
                    if (nM>12)
                        nM -= 12;
                }else if (eM==13)
                {
                    nY = eY + 8;
                    nM = eM - 4;
                    if (nM<1)
                    nM += 12;
                    nD = eD + 5;
                    if (nD>days[nM-1])
                    {
                        nD -= days[nM-1];
                        ++nM;
                    }
                    if (nM>12)
                        nM -= 12;
                }else if (eM<=2)
                {
                    nY = eY + 7;
                    nM = eM - 4;
                    if (nM<1)
                    nM += 12;
                    nD = eD + 10;
                    if (nD>days[nM-1])
                    {
                        nD -= days[nM-1];
                        ++nM;
                    }
                    if (nM>12)
                        nM -= 12;
                }else
                {
                    nY = eY + 8;
                    nM = eM - 4;
                    if (nM<1)
                    nM += 12;
                    nD = eD + 9;
                    if (nD>days[nM-1])
                    {
                        nD -= days[nM-1];
                        ++nM;
                    }
                    if (nM>12)
                        nM -= 12;
                }

                if (nY % 400 == 0 || nY % 4 == 0 & (nM==1||nM==2))
                    lNum = 1;
                else
                    lNum = 0;

                yNum=nY%100;

            temp = (yNum+yNum/4)+(nD-lNum) + monthCode[nM-1];
            day = temp%7;

            cout << setfill('0') << "The date " <<setw(2)<< eD << symbol <<setw(2)<< eM << symbol << eY << " is on "<< ecDay[day];

            }else
            {
                do
                {
                    cout << "Enter Gregorian calendar as follows dd/mm/yyyy: ";
                    cin >> gD >> symbol >> gM >> symbol >> gY;
                }while(gD<0||gD>31||gM<0||gM>12||gY<0);

                if (gY % 400 == 0 || gY % 4 == 0 & (gM==1||gM==2))
                    lNum = 1;
                else
                    lNum = 0;

                    yNum=gY%100;

                temp = (yNum+yNum/4)+(gD-lNum) + monthCode[gM-1];
                day = temp%7;

                cout << setfill('0') << "The date " <<setw(2)<< gD << symbol <<setw(2)<< gM << symbol << gY << " is on "<< weekDay[day];
            }

        break;
        case 8:

            cout << "What Ethiopian calendar year would you like to see: ";
            cin >> yearE;

            if (yearE % 400 == 0)
                daysE[12]=6;
            else if (yearE % 4 == 0)
                daysE[12]=6;

            cout << endl;

            int e1, e2, e3;
            e1 = (yearE - 1)/4;
            e2 = (yearE - 1)/100;
            e3 = (yearE - 1)/400;

            firstDME = (yearE + e1 - e2 + e3)%7;
            firstDME -= 4;

            if (firstDME<0)
                firstDME *= -1;

            cout << yearE <<endl;

            for (int k=0; k<13; ++k)
            {
                cout <<left<< setw(10) <<  monthE[k] << '\t' << yearE << endl;
                numDaysE = daysE[k];

                cout <<right<< " S  M  T  W  T  F  S" << endl;
                cout <<"--------------------" << endl;

                int dayE = 1;
                int iE = firstDME;
                while (iE>0)
                {
                    cout << "   ";
                    --iE;
                }

                while (dayE <= numDaysE)
                {
                    cout << setw(2) << dayE << " ";
                    if(firstDME == 6)
                    {
                        cout << endl;
                    firstDME = 0;
                    }else
                    {
                        ++firstDME;
                    }

                    dayE++;
                }

                cout << endl << endl << endl;
            }
        break;
        case 9:

            cout << "What Gregorian calendar year would you like to see: ";
            cin >> year;

                if (year % 400 == 0)
                    days[1]=29;
                else if (year % 4 == 0)
                    days[1]=29;

            cout << endl;

            int x1, x2, x3;
            x1 = (year - 1)/4;
            x2 = (year - 1)/100;
            x3 = (year - 1)/400;

            firstDM = (year + x1 - x2 +x3)%7;

            cout << year << endl << endl;

            for (int k=0; k<12; ++k)
            {
                cout <<left<< setw(10) <<  month[k] << '\t' << year << endl;
                numDays = days[k];

                cout <<right<< " S  M  T  W  T  F  S" << endl;
                cout <<"--------------------" << endl;

                int day = 1;
                int i = firstDM;
                while (i>0)
                {
                    cout << "   ";
                    --i;
                }

                while (day <= numDays)
                {
                    cout << setw(2) << day << " ";
                    if(firstDM == 6)
                    {
                        cout << endl;
                    firstDM = 0;
                    }else
                    {
                        ++firstDM;
                    }

                    day++;
                }

                cout << endl << endl << endl;
            }
        break;
    }

    return 0;
}

/*#include <iostream>
#include <ctime>
using namespace std;

int main()
{
   // current date and time on the current system
   time_t now = time(0);

   // convert now to string form
   char* date_time = ctime(&now);

   cout << "The current date and time is: " << date_time << endl;
}*/
