/*
Create a savings_account class that maintains the details of customers like name, phone number, accno, balance. Ensure 
that the variables are protected with proper specifiers such that only the user's personal details can be modified directly.
 Perform deposit, withdrawal, statement print, and pin change operations by checking for minimum balance and other conditions. 
*/
#include<iostream.h>
#include<conio.h>
class savings
{     
      int accno,pin;
      long long double balance;
      public:
             char name[30];
             long long double phone;
             savings()
             {
                      accno=pin=phone=balance=0;
                      strcpy(name,"\0");
             }
      void newaccount();
      void deposit(double);
      void withdraw(double);
      void print();
      int returnpin()
      {   return pin;
      }
      int returnaccno()
      {
          return accno;
      }
      void pinchange();
}a[10];
void savings::pinchange()
{
     int n,a;
     cout<<"\nEnter Current Pin :";
     cin>>n;
     if(n==pin)
     {
             lb1:
                 cout<<"\nEnter new pin :";
                 cin>>a;
                 cout<<"\nEnter new pin Again:";
                 cin>>n;
                 if(a==n)
                         pin=a ;
                 else 
                      {
                               cout<<"\nPin Does Not MATCh try again :";
                               goto lb1;
                      }
     }
     else 
     cout<<"\nWRONG PIN !!!";
}
void savings::newaccount()
{
     cout<<"\nEnter ACCOUNT No. :";
     cin>>accno;
     cout<<"\nEnter Balance in account :";
     cin>>balance;
     fflush(stdin);
     cout<<"\nEnter Name of account holder :";
     gets(name);
     cout<<"\nEnter Pin :";
     cin>>pin;
     cout<<"\nEnter Phone No:";
     cin>>phone;
}
void savings::deposit(double n)
{
     balance+=n;
     cout<<"\nAFTER ADDING RS"<<n<<"BALANCE IS :"<<balance;
}
void savings::withdraw(double n)
{
     if(n>balance)
                  cout<<"\n NOT ENOUGH CASH IN ACCOUNT !!";
     else if(balance-n<1000)
          cout<<"\nMINIMUM BALANCE REQUIRED IS RS 1000";
     else 
     {    balance-=n;
               cout<<"\nAFTER WITHDRAWING RS"<<n<<"BALANCE IS :"<<balance;
     }
}
void savings::print()
{
     cout<<"\nACCOUNT NO :"<<accno;
     cout<<"\nBalnce in ACCOUNT :"<<balance;
     fflush(stdin);
     cout<<"\nNAme of account holder :";
     puts(name);
     cout<<"\nPIN :"<<pin;
     cout<<"\nPHONE  :"<<phone;
     
}
int main()
{
    int n,i,z,no,p;
    double amt;
    char c='y';
    cout<<"\nEnter no of accounts :";
    cin>>n;
    for(i=0;i<n;i++)
    {
                    cout<<"\nEnter Details for account "<<i+1<<" :";
                    a[i].newaccount();
     }
    while(c=='y'||c=='Y')
    {
          lb:
          cout<<"\nEnter account no to perform transaction :";
          cin>>no;    
    for(i=0;i<n;i++)
    {
                    if(no==a[i].returnaccno())
                    break;
     }
     if(i>=n)
     {
             cout<<"\nAccount Does Not Exist !!!";
             goto lb;
     }
     cout<<"\nEnter Pin :";
     cin>>p;
     if(p!=a[i].returnpin())
     {            
                 cout<<"\nWRONG PIN  !!!";
                 goto lb;
     }
      cout<<"\nWHAT DO YOU WANT TO DO ??\n1.DEPOSIT\n2.WITHDRAW\n3.PRINT \n4.PIN CHANGE\n";
          cin>>z;
          switch(z)
          {
                   case 1:cout<<"\nENTER AMOUNT TO DEPOSIT :";
                                         cin>>amt;
                           a[i].deposit(amt);
                           break;
                   case 2:cout<<"\nENTER AMOUNT TO WITHDRAW :";
                                         cin>>amt;
                           a[i].withdraw(amt);
                           break;
                   case 3:cout<<"\nDETAILS OF PREVIOUS TRANSACTIONS :";
                             a[i].print();
                           break;
                   
                   case 4:cout<<"\nPIN CHANGE  :";
                             a[i].pinchange();
                           break;
                   default :cout<<"\n WRONG INPUT !!";
                           break;
          }
          cout<<"\n WANT TO CONTINUE PRESS Y :";
          cin>>c;
     }
    getch();
   return 1;
}                             
     
                     
