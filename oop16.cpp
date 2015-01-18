/*
Create an class that stores details about the computer (Assembled/branded, RAM, HDD, processor speed, price etc.,). 
Use constructors to initialize the object and a destructor that deducts the count of object each time the object is 
passed to destroy function. Also use copy constructor to create a system with the configuration same as that's of an
 existing system. 
*/
#include<iostream.h>
#include<conio.h>
class computer 
{     public:
      int hdd,speed;
      float price,ram;
      char type[30];
        static int count;
             computer()
             {
               count++;
               cout<<"Count Is :"<<count;
               accept();
             }
           ~computer()
           { 
               count--;
               cout<<"Count Is :"<<count;
           }     
           void accept();
           computer operator =(computer c2)
           { 
             hdd=c2.hdd;
             ram=c2.ram;
             speed=c2.speed;
             price= c2.price;
             strcpy(type,c2.type);
           }
           void display();        
};

int computer::count=0;
void computer::accept()
{
     cout<<"\nEnter Hard Drive Space :";
     cin>>hdd;
     cout<<"\nEnter Processor Speed :";
     cin>>speed;
     cout<<"\nEnter RAM :";
     cin>>ram;
     cout<<"\nEnter Type :";
     fflush(stdin);
     gets(type);
     cout<<"\nEnter Price :";
     cin>>price;
}
void computer::display()
{
     cout<<"\nHard Drive Space :"<<hdd;
     cout<<"\nProcessor Speed :"<<speed;
     cout<<"\nRAM :"<<ram;
     cout<<"\nType :";
     fflush(stdin);
     puts(type);
     cout<<"\nPrice :"<<price;
}
int main()
{
    computer x1,x2;
    cout<<"\nBefore Copy Constructor !!!\n\n\n";
    x1.display();
    x2.display();
    x1=x2;
    cout<<"\nAfter Copy Constructor !!!\n\n\n";
    x1.display();
    x2.display();
    getch();
    return 1;
}
    
    
         


           
