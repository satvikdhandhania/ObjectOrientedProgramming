/*
Create a class account that maintains acc_no, name, and balance. Perform deposit, withdrawal and statement print operations.
(statement print must print all the transactions that has taken place so for - use structures inside the class to maintain the
details about transactions)(b)
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
struct details 
{
       char tr;
       double amount,balance;
};
class account
{
      int i,acc_no;
      double balance;
      char name[20];
      details d[20];
      public:
             account()
             {
                      i=0;
                      acc_no=0;
                      balance=0;
             }
      void newaccount()
      {
           cout<<"\nENTER THE ACCOUNT NUMBER :";
           cin>>acc_no;
           cout<<"\nENTER THE BALANCE IN ACCOUNT :";
           cin>>balance;
           fflush(stdin);
           cout<<"\nENTER THE NAME OF THE ACCOUNT HOLDER :";
           gets(name);
           d[i].tr='c';
           d[i].amount=balance;
           d[i].balance=balance;
      }
      void deposit(double);
      void withdraw(double);
      void print();
};
void account::deposit(double n)
{
     balance+=n;
     cout<<"\nAFTER ADDING RS"<<n<<"BALANCE IS :"<<balance;
     i++;
           d[i].tr='d';
           d[i].amount=n;
           d[i].balance=balance;
}
void account::withdraw(double n)
{
     if(n>balance)
                  cout<<"\n NOT ENOUGH CASH IN ACCOUNT !!";
     else if(balance-n<1000)
          cout<<"\nMINIMUM BALANCE REQUIRED IS RS 1000";
     else 
     {    balance-=n;
               cout<<"\nAFTER WITHDRAWING RS"<<n<<"BALANCE IS :"<<balance;
     i++;
           d[i].tr='w';
           d[i].amount=n;
           d[i].balance=balance;
     }
}     
 void account::print()
 {
      int a;
      for(a=0;a<=i;a++)
      {
                      cout<<"\nTRANSACTION "<<a+1<<" :";
                      if(d[a].tr=='c')
                        {  cout<<"\nACCOUNT CREATED !!";
                           cout<<"\n AMOUNT DEPOSITED :"<<d[a].amount;
                        }
                      if(d[a].tr=='d')
                        {  cout<<"\nMONEY DEPOSIT !!";
                           cout<<"\n AMOUNT DEPOSITED :"<<d[a].amount;
                        }
                       if(d[a].tr=='w')
                        {  cout<<"\nMONEY WITHDRAWN !!";
                           cout<<"\n AMOUNT DEPOSITED :"<<d[a].amount;
                        }             
                       cout<<"\nBALANCE :"<<d[a].balance;
      }
}
 int main(void)
{
     int i;
     double amt;
     char c='y';
     account a;
     a.newaccount();
     while(c=='y'||c=='Y')
     {                    
          cout<<"\nWHAT DO YOU WANT TO DO ??\n1.DEPOSIT\n2.WITHDRAW\n3.DISPLAY TRANSACTIONS\n";
          cin>>i;
          switch(i)
          {
                   case 1:cout<<"\nENTER AMOUNT TO DEPOSIT :";
                                         cin>>amt;
                           a.deposit(amt);
                           break;
                   case 2:cout<<"\nENTER AMOUNT TO WITHDRAW :";
                                         cin>>amt;
                           a.withdraw(amt);
                           break;
                   case 3:cout<<"\nDETAILS OF PREVIOUS TRANSACTIONS :";
                             a.print();
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
          
                          
