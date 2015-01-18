/*
23. Create a class powered device (type(electronic/mechanical), power range(10W-20W), self_powered/adapter) and inherit it in two
classes scanner (no.of pages per second, resolution, size, cost, brand) and printer (brand, dpi, color/b/w, pages per second, 
laser/inkjet). Create another class named copier that inherits the features of printer and scanner along with additional features 
(storage capacity, stored copy printing speed). Ensure that the duplicate copies of powered_device object don't exist in copier. (m)
*/
#include<iostream>
#include<conio.h>
using namespace std;
class powerdev
{     
       char type[15],range[10],typepow[20];
       public:
       bool flag1,flag2;
       powerdev(){flag1=false;flag2=false;}
       void acc()
       {    if(!flag1)
             {  cout<<"\n\nEnter DEtails of power device "; 
                cout<<"\nEnter Type(electronic/mechanical) :";
                fflush(stdin);
                gets(type);
                cout<<"Enter power range(15w-20w) :";
                fflush(stdin);
                gets(range);
                cout<<"Enter Power Type(self-powered/adapter) :";
                fflush(stdin);
                gets(typepow);
                flag1=true;
             }
       }
       void dis()
       {   if(!flag2)
            {   cout<<"\n\nDEtails of power device "; 
                cout<<"\nType : "<<type;
                cout<<"\nPower range(15w-20w) : "<<range;
                cout<<"\nPower Type(self-powered/adapter):"<<typepow;
                flag2=true;
            }
       }
};
class scanner:public virtual powerdev
{     int nop,resol1,resol2,size,cost;
      char brand[20];
      public:
      void accept1()
      {
           acc();
           cout<<"\n\nEnter DEtails of Scanner "; 
            cout<<"\nEnter No Of Pages/second : ";
            cin>>nop;
            cout<<"\nEnter Resolution 1 : ";
            cin>>resol1;
            cout<<"\nEnter Resolution 2 : ";
            cin>>resol2;
            cout<<"\nEnter Size :";
            cin>>size;
            cout<<"\nEnter Brand :";
            fflush(stdin);
            gets(brand);
      }
      void disp1()
      {
           dis();
           cout<<"\n\nDEtails of Scanner "; 
           cout<<"\nNo Of Pages/second : "<<nop;
           cout<<"\nResolution: "<<resol1<<"x"<<resol2;
           cout<<"\nSize :"<<size;
           cout<<"\nBrand :"<<brand;
      }
};
class printer:public virtual powerdev
{     int nop,dpi;
      char brand[20],color[10],type[10];
      public:                                                             
      void accept2()
      {
           acc();
           cout<<"\n\nEnter DEtails of Printer "; 
            cout<<"\nEnter No Of Pages/second : ";
            cin>>nop;
            cout<<"\nEnter DPI : ";
            cin>>dpi;
            cout<<"\nEnter Brand :";
            fflush(stdin);
            gets(brand);
            cout<<"Enter Color(coloured/black-white) :";
            fflush(stdin);
            gets(color);
            cout<<"Enter Type(laser/inkjet) :";
            fflush(stdin);
            gets(type);
      }
      void disp2()
      {
           dis();
           cout<<"\n\nDEtails of Printer "; 
            cout<<"\nNo Of Pages/second : "<<nop;
            cout<<"\nDPI : "<<dpi;
            cout<<"\nColor :"<<color;
            cout<<"\nType :"<<type;
           cout<<"\nBrand :"<<brand;
      }
};
class copier:public scanner,public printer
{
      int store,speed;
      public:
      void enter()
      {     cout<<"\nEnter Copier Details ";
            accept1();
            accept2();
            cout<<"\nEnter Speed/second : ";
            cin>>speed;
            cout<<"\nEnter Storage Capacity : ";
            cin>>store;
      }
      void display()
      {     cout<<"\nCopier Details :"; 
            disp1();
            disp2();
            cout<<"\nSpeed/per second : "<<speed;
            cout<<"\nStorage Capacity : "<<store;
      }
}c;
int main()
{
    c.enter();
    c.display();
    getch();
    return 1;
}         
