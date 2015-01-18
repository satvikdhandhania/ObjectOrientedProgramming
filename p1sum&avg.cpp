/*
Find the sum and average of n numbers using classes and objects (b)
*/
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
class sumavg
{
      int sum;
      float avg;
      int count;
      public:
      sumavg()
      {
               sum=0;
               count=0;
               avg=0.0;
      }
      void add(int a)
      {
           sum=sum+a;
           count++;
           avg=(float)sum/count;
      }
      void display()
      {
           cout<<"\nSUM OF"<<count<<" NUMBERS IS :"<<sum;
           cout<<"\nAVERAGE OF "<<count<<" NUMBERS IS :"<<avg;
      }};
int main()
{    
     sumavg s;
     int a;
     char ch='y';
     while(ch=='y'||ch=='Y')
     {
     cout<<"\nENTER NUMBER :";
     cin>>a;
     s.add(a);
     cout<<"\nWANT TO CONTINUE ...PRESS Y !!!";
     cin>>ch;
     }
     cout<<"\n\tDISPLAYING RESULTS.......";
     s.display();
     getch();
     return 1;
}
