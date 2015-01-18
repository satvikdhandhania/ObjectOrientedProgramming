/*
Create a class employee that maintains the details like empid, years of exp, address, phone). 
Create separate class for type of skills the employee possesses  like carpentry (what type of 
wood, years, type of creations, tools used),masonry ( type of constructions, years), 
Driving(license no, years of exp, types of vehicles). Make the employee class to inherit the
three classes and have the details that are relevant for the employee. Have constructors to
initialize all the classes and maintain the status in employee according to the skills
(111- means have all skills).If a skill status is 0, then have the default values 
initialized with constructor
*/
#include<iostream.h>
#include<conio.h>
class carpentry
{
      public:
      char typewood[30],typecreations[30],tools[30];
      int years,p;
      carpentry(int i)
      {   if(i==1)
           {
              cout<<"\n\tCarpentry ::";
              cout<<"\nEnter Type of wood :";     
              fflush(stdin);
              gets(typewood);
              cout<<"\nEnter Type of Creation :";     
              fflush(stdin);
              gets(typecreations);
              cout<<"\nEnter Tools Used :";     
              fflush(stdin);
              gets(tools);
              cout<<"\nEnter Years Of Experience In Carpentry  :";     
              cin>>years;
           }
           p=i;
      }
      void display1()
      {
        if(p==1)
        { cout<<"\n\nCarpentry ::";
          cout<<"\nType of wood :"<<typewood;
          cout<<"\nType of Creation :"<<typecreations;
          cout<<"\nTools Used :"<<tools;
          cout<<"\nYears Of Experience In Carpentry :"<<years;           
        }     
        else 
         cout<<"\nNo Carpentry Skills !!!";
      }
};
class masonary
{
      public:
      char typecontructions[30];
      int years,p;
      masonary(int i)
      {   if(i==1)
          {
              cout<<"\n\tMasonary ::";
              cout<<"\nEnter Type of Constructors :";     
              fflush(stdin);
              gets(typecontructions);
              cout<<"\nEnter Year:";     
              cin>>years;
          }
              p=i;
          
      }
      void display2()
      {
        if(p==1)
        { cout<<"\n\tMasonary ::";
          cout<<"\nType of Constructors :"<<typecontructions;
          cout<<"\nYear:"<<years;        
        }     
        else 
         cout<<"\nNo Masonary Skills !!!";
      }
};
class driving
{
      public:
      char typvehicle[30];
      int yopd,p;
      driving(int i)
      {   if(i==1)
          {
              cout<<"\n\tDRIVING ::";
              cout<<"\nEnter Type of Vehicle :";     
              fflush(stdin);
              gets(typvehicle);
              cout<<"\nEnter Years Of Experience :";     
              cin>>yopd;
          }
           p=i;
      }
        void display3()
      {
        if(p==1)
        { cout<<"\n\tDRIVING ::";
          cout<<"\nType of Vehicle :"<<typvehicle;
          cout<<"\nYears Of Experience Driving:"<<yopd;      
        }     
        else 
         cout<<"\nNo Driving Skills !!!";
      }
};
class employee:public carpentry,public driving,public masonary
{
      public:
      int empid,yop;
      long long int phone;
      char name[30],address[30];
      employee(char a[30],int x,int y,int z):carpentry(x),masonary(y),driving(z)
      {         strcpy(name,a);    
                cout<<"\nEner Employee Id :";
                cin>>empid;
                cout<<"\nEner Years of experience  :";
                cin>>yop;
                cout<<"\nEner Phone No.  :";
                cin>>phone;
                cout<<"\nEner Address :";
                fflush(stdin);
                gets(address);
      }
      void display()
      {             cout<<"\n\tEMPLOYEE DETAILS ::";
                cout<<"\nNAME :"<<name;    
                cout<<"\nmployee Id :"<<empid;
                cout<<"\nYears of experience  :"<<yop;
                cout<<"\nPhone No.  :"<<phone;
                cout<<"\nAddress :";
                puts(address);
                display1();
                display2();
                display3();
      }           
};
int main()
{   
    employee e("Satvik",0,1,0);
    e.display();
    getch();
    return 1;
}
