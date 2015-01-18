/*
Create a C++ program that takes employee details like ID, first name, last name, age and address. Perform searching of an employee 
record by taking the first/last name. If two records are with same first/last name, allow the user to search based on other fields. (c)
*/
#include<iostream.h>
#include<conio.h>
#include<string.h>
class employee
{
      int id,age,num;
      char fname[30],lname[30],address[30];
      public:
             employee(){
                        id=age=0;
                        strcpy(fname,"\0");
                        strcpy(lname,"\0");
                        strcpy(address,"\0");
             }
      void add(int);
      void display();
      int search(char[],char[]);
      int search(int);
}t[10],s[5];
void employee::add(int n)
{
     cout<<"\nENTER ID :";
     cin>>id;
     cout<<"\nENTER AGE :";
     cin>>age;
     fflush(stdin);
     cout<<"\nENTER FIRST NAME :";
     gets(fname);
     fflush(stdin);
     cout<<"\nENTER LAST NAME :";
     gets(lname);
     fflush(stdin);
     cout<<"\nENTER ADDRESS :";
     gets(address);
     num=n;
}
void employee::display()
{
     cout<<"\nINDEX POSITION :"<<num;
     cout<<"\nID :"<<id;
     cout<<"\nAGE :"<<age;
     fflush(stdin);
     cout<<"\nFIRST NAME: ";
     puts(fname);
     fflush(stdin);
     cout<<"LAST NAME: ";
     puts(lname);
     fflush(stdin);
     cout<<"ADDRESS : ";
     puts(address);

}
int employee::search(char n1[30],char n2[30])  
{
    if((strcmp(n1,fname)==0)&&(strcmp(n2,lname)==0))
             return 1;
    else 
    return 0;  
}
int employee::search(int a)
{
    if(a==age)
    {
              cout<<"\nRECORD FOUND !!";
              display();
    }
    else
     cout<<"\nNOT FOUND IN RECORDS !!";
}
int main(void)
{
    int i,n,a,c=-1;
    char n1[30],n2[30];
    cout<<"\nENTER NUMBER OF EMPLOYEES :";
    cin>>n;
    for(i=0;i<n;i++)
    {
                    cout<<"\nEnter Details For Employees :";
                    t[i].add(i+1);
    }
    cout<<"\nENTER FIRST NAME FOR SEARCH :";
    gets(n1);
    fflush(stdin);
    cout<<"\nENTER LAST NAME FOR SEARCH :";
    gets(n2);
    for(i=0;i<n;i++)
     if(t[i].search(n1,n2))
            s[++c]=t[i];
    if(c==-1)
             cout<<"\nRECORD NOT FOUND !!!";
    if(c==0)
            cout<<"\n RECORD FOUND !!!";
            s[0].display();
    if(c>0)
    {
           cout<<"\nCLASHING RECORDS ...ENTER AGE :" ;
           cin>>a;
           for(i=0;i<c;i++)
                           s[i].search(a);
    }
getch();
return 1;
}                                        
