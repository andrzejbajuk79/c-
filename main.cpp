#include <iostream>

using namespace std;

int main()
{
     int x = 2629800; //okres zycia w wieku w niemowlecym w minutach 0-5 lat
    int y = 3681720 ; // dokres zycia w wieku w dzieciecymw minutachziecko w minutach 5-12
    int z = 3155760 ;//okres zycia w wieku w mlodzienczym w minutach 12-16
    int dzien, miesiac, rok;
    int a_dzien=30 , a_miesiac=9, a_rok=2016; // ustalona z gory data dzisiejsza
    string plec;

    cout<<"Podaj date urodzin: "<<endl;
    cout<<"Dzien: ";
    cin>>dzien;
    cout<<"Miesiac: ";
    cin>>miesiac;
    cout<<"Rok: ";
    cin>>rok;
    cout<<"podaj plec :";
    cin>>plec;

        int wynik = 0;

        int tabm[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int tabmp[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

        while(rok<a_rok)
        {
            if((rok%4==0 && !(rok%100==0)) || (rok%400==0))
            {
                wynik+=366;
            }
            else
            {
                wynik+=365;
            }
            rok++;
        }
        if(miesiac<a_miesiac)
        {
           while(miesiac<a_miesiac) //dodajemy miesiace a na koncu dodatkowo nadmiarowe dni
           {
               if((rok%4==0 && !(rok%100==0)) || (rok%400==0))
            {
                wynik+=tabmp[miesiac-1];
            }
            else
            {
                wynik+=tabm[miesiac-1];
            }
              miesiac++;
           }
            wynik+=a_dzien-dzien;
        }
       else if(miesiac==a_miesiac)
        {
            wynik+=a_dzien - dzien;
        }
        else if(miesiac>a_miesiac)
        {
            if((rok%4==0 && !(rok%100==0)) || (rok%400==0))

            {
                while(miesiac<a_miesiac)

                {
                    wynik-=tabmp[miesiac];//dekrementujemy miesiace az sie zrownaja
                    miesiac--;
                }
            }
                else
                {
                    while(a_miesiac<miesiac)
                    {
                        wynik-=tabm[miesiac];
                        miesiac--;
                    }
                }

            wynik+=a_dzien-dzien;

            }

        int wynik_min= wynik*1440; //ilosc dni w przeliczeniu na miute

        cout<<"dotychczas zyles :"<<wynik_min<<" minut"<<endl;
        if(wynik_min<x)
    {
       cout<<"jestes niemowlakiem i twoje serce bilo : "<<wynik_min/130<<" razy do tej pory"<<endl;
    }
        if((wynik_min>x)&&(wynik_min<(x+y)))
    {
       cout<<"jestes dzieckiem i twoje serce bilo : "<<x/130 + (wynik_min-x)/100<<" razy do tej pory"<<endl;
    }
      if((wynik_min>x)&&(wynik_min>(x+y))&&(wynik_min<(x+y+z)))
    {
       cout<<"jestes nastolatkiem i twoje serce bilo : "<<x/130 + y/100 + (wynik_min-(x+y))/85<<" razy do tej pory"<<endl;
    }

    if((wynik_min>x)&&(wynik_min>(x+y))&&(wynik_min>(x+y+z)))
    {
        if( plec=="k"||plec=="K")
        {
             cout<<"jestes kobieta i twoje serce bilo : "<<x/130 + y/100 +z/85 + (wynik_min-(x+y+z))/66<<" razy do tej pory"<<endl;
        }
        else cout<<"jestes facetem i twoje serce bilo : "<<x/130 + y/100 +z/85 + (wynik_min-(x+y+z))/62<<" razy do tej pory"<<endl;

    }

    return 0;
}
