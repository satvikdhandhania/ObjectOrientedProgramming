/*
Create a C++ program that finds sum of all the digits of a number or a string up to a single digit by overloading functions. 
For strings the ASCII equivalents must be added together up to single digit and the corresponding digit's character must be 
displayed as output 
*/
#include<iostream.h>
#include<conio.h>
#include<string.h>
class strnum
{
      public:
             int sum(int);
             int sum(char[]);
}z;
int strnum::sum(int n)
{    if(n==0)
             return 0;
     else 
     return ((n%10) + sum(n/10));
}
int strnum::sum(char st[100])
{    int i,l,d=0;
     l=strlen(st); 
     for(i=0;i<l;i++)       
            d=d+(int)st[i];
     return sum(d);
}
int main()
{   char st[100];
    int c,a;
    cout<<"\nWHAT DO YOU WANT TO ENTER \n1.STRING \n2.NUMBER :";
    cin>>c;
    if(c==1)
    {       fflush(stdin);
            cout<<"\nENTER STRING :";
            gets(st);
            a=z.sum(st);
            lb:
               a=z.sum(a);                             
            if(a>=10)
                     goto lb;
            else
                cout<<"\nSUM OF STRING :"<<a<<" CHARACTER :"<<(char)a;
    }
    else if(c==2)
    {
                 cout<<"\nENTER NUMBER :";
            cin>>a;
            lb1:
            a=z.sum(a);
            if(a>=10)
                     goto lb1;
            else
                cout<<"\nSUM OF NUMBER :"<<a;            
    }         
    else
        cout<<"\nERROR IN CHOICE ....PROGRAM TERMINATING !!!";
getch();
return 1;
}
                    
