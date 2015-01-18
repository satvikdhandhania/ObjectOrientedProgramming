/*
Create a class joint_aacount (account_no, balance, date of opening, acc.holders and their access 
right (use a structure that has customer ID and access type)). Create customers (customer ID,
 name, address, phone, account_no) and allow them to perform the operations like deposit, 
 withdrawal and statement print based on the access rights supported. If the access right 
 is (DWS - then they can do deposit, withdrawal and statement print). 
*/
#include<iostream>
#include<conio.h>
using namespace std;
int n=0;
class joint_account
{     
      public:
      int account_no;
      float balance;
      char doo[10],holders[10][30];
             joint_account()
             {
                      account_no=1;
                      balance=0.0;
                      strcpy(doo,"29/09/2012");
             }
      struct accessright
      {
             int id;
             char typ[3];
      }ar[10];
}a;
class customers
{
      int account_no;
      char name[30],address[50];
      long long int phone;
      public:
       int id;
       void accept()
       {
            cout<<"\nEnter Details For Customer "<<n+1<<":\n";
            cout<<"\nEnter customer id :";
            cin>>id;
            a.account_no=account_no;
            cout<<"\nEnter Name :";
            fflush(stdin);
            gets(name);
            cout<<"\nEnter Address  :";
            fflush(stdin);
            gets(address);
            cout<<"\nEnter Phone ";
            cin>>phone;
            a.ar[n].id=id;
            strcpy(a.holders[n],name);
            cout<<"\nEnter Access Right (DWS):";
            fflush(stdin);
            gets(a.ar[n].typ);
            n++;
       }
       void deposit();
       void withdraw();
       void print();
       void display()
       {
            cout<<"\nCustomer id :"<<id;
            cout<<"\nAccount No :"<<account_no;
            cout<<"\nName :"<<name;
            cout<<"\nPhone :"<<phone;
            cout<<"\nAddress :"<<address;
       }
};
void customers::deposit()
{
     int i,z;
     for(z=0;z<n;z++)
     {
                     if(a.ar[z].id==id)
                     {
                       if(strstr(a.ar[z].typ,"d"))
                       {
                          cout<<"\nEnter Amount To add :";
                          cin>>i;
                          a.balance+=i;
                          cout<<"\nBAlance Added !!!";
                       }
                       else 
                            cout<<"\nUser Cannot Deposit Money !!";
                       break;
                     }
     }
}
void customers::withdraw()
{
     int i,z;
     for(z=0;z<n;z++)
     {
                     if(a.ar[z].id==id)
                     {
                       if(strstr(a.ar[z].typ,"w"))
                       {
                          cout<<"\nEnter Amount To Withdraw :";
                          cin>>i;
                          if(a.balance-i>1000)
                            {                  a.balance-=i;
                                               cout<<"\nMoney Withdrawn !!!";
                            }
                          else 
                               cout<<"\nNot Enough Cash !!";
                       }
                       else 
                            cout<<"\nUser Cannot Withdraw Money !!";
                       break;
                     }
     }
}
void customers::print()
{
     int i,z;
     for(z=0;z<n;z++)
     {
                     if(a.ar[z].id==id)
                     {
                       if(strstr(a.ar[z].typ,"s"))
                       {
                          cout<<"\nBalance is : "<<a.balance;
                          cout<<"\nAccount NO : "<<a.account_no;
                          cout<<"\nDate of opening : "<<a.doo;
                          cout<<"\nAccount holders  : ";
                          for(i=0;i<z;i++)
                             cout<<"\n"<<a.holders[i];
                       }
                       else 
                            cout<<"\nUser Cannot See Statements !!";
                       break;
                     }
     }
}
int main()
{
    int z,i,y;
    bool flag;
    customers c[10];
    cout<<"\nEnter No of account holders :";
    cin>>z;
     for(i=0;i<z;i++)
                     c[i].accept();
     while(1)
     {
             flag=false;
             cout<<"n1.Deposit\n2.Withdraw\n3.Print\n4.Exit\nEnter Your Choice :";
             cin>>i;
             switch(i)
             {
                      case 1:cout<<"\nDeposit !!\nEnter Customer ID :";
                           cin>>z;
                            for(y=0;y<n;y++)
                               if(c[y].id==z)
                                { flag=true;
                                  c[y].deposit();
                                }
                               if(!flag)
                                        cout<<"\nNoSuch Customer Exists !!";
                               break;
                      case 2:cout<<"\nWithdraw !!\nEnter Customer ID :";
                           cin>>z;
                            for(y=0;y<n;y++)
                               if(c[y].id==z)
                                { flag=true;
                                  c[y].withdraw();
                                }
                               if(!flag)
                                        cout<<"\nNoSuch Customer Exists !!";
                               break;
                        case 3:cout<<"\nPrint  !!\nEnter Customer ID :";
                             cin>>z;
                             for(y=0;y<n;y++)
                               if(c[y].id==z)
                                { flag=true;
                                  c[y].display();
                                  c[y].print();
                                }
                               if(!flag)
                                        cout<<"\nNoSuch Customer Exists !!";
                               break;   
                       case 4:exit(0);
                      default:cout<<"\nWrong Input !!!";
             }
     }
    getch();
    return 1;
}     
