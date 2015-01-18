/*
Write a c++ program that maintains the date in (day/mon/year) format and overload the ++ 
& -- operator to view previous or next date from today's date. Ensure that the day won't 
exceed 30/31 for certain months. 
*/
#include<iostream.h>
#include<conio.h>
class date
{
      int day;
      int month;
      int year;
      bool flag;
      public:
             date()
             {
                   day=29;
                   month=7;
                   year=2020;
             }
             void operator ++()
             {
                  flag=true;
                  if(day==29 && month==2)
                  {
                             month =3;
                             day=1;
                             show();
                  }
                  if(day==28 &&month ==2)
                  {
                             if(year%4==0)
                             {
                                          day++;
                                          show();
                             }
                             else
                              {           month =3;
                                     day=1;
                                     show();
                             }
                  }
                 if(day==30 &&(month==4||month==6||month==9||month==11))
                 { day=1;month++;show();
                 }
                 if(day==31&&month==12)
                 {
                            day=1;
                            year++;
                            month=1;
                            show();
                 }
                 else if(day==31)
                 {    month++;
                      day=1;
                      show();
                 }
                 if(flag)
                 { day++;
                   show();
                 }
             };
     void operator --()
     {
          flag=true;
          if(day==1 && month==3 && year%4==0)                 
          {
                    day=29;
                    month--;
                    show();
          }
          if(day==1 && month ==3)
          {
                    day=28;
                    month--;
                    show();
          }
          if(day==1 &&(month==5||month==7||month==10||month==12))
          {
                    day=30;
                    month--;
                    show();
          }
          if(day==1&&month==1)
          {
                              year--;
                              day=31;
                              month=12;
                              show();
          }
          if(day==1)
          {
                month--;
                day=31;
                show();
          }
          if(flag)
          {
                  day--;
                  show();
          }
     };
   void show()
   {
        flag=false;
        cout<<"DAY :"<<day<<endl<<"MONTH :"<<month<<endl<<"YEAR :"<<year<<endl;
   }
}date;
int main()
{   int ch;
    while(1)
    {
            cout<<"\n1.INCREMENT\n2.DECREMENT\n3.EXIT\nEnter Choice :";
            cin>>ch; 
            switch(ch)
            {
                      case 1:++date;
                             break;
                      case 2:--date;
                             break;
                      case 3:return 0;
                             break;
                      default: cout<<"\nWrong Input !!!";       
            }
    }
}                              
