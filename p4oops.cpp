/*
Create a class that registers ur details by taking reg.no, name, age and mail id. Create a function that prevents 
duplicate entries of objects based on reg.no.(b)
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class student 
{
      int reg_no,age;
      char email[30],name[50];
      public:
             student()
             {
                      reg_no=age=0;
             }
             void add(int);
             void display();
             int returnreg()
             {
                 return reg_no;
             }
}t[10];
void student::add(int reg)
{
     reg_no=reg;
     cout<<"\nENTER AGE :";
     cin>>age;
     fflush(stdin);
     cout<<"\nENTER NAME :";
     gets(name);
     fflush(stdin);
     cout<<"\n ENTER EMAIL :";
     gets(email);
}
void student::display()
{
     cout<<"\n DISPLAYING !! ";
     cout<<"\n REGISTRATION NUMBER :"<<reg_no;
     cout<<"\nAGE :"<<age;
     fflush(stdin);
     cout<<"\nNAME :";
     puts(name);
     fflush(stdin);
     cout<<"\nEMAIL :";
     puts(email);
}
int check(int n,int z)
{
    int i;
    for(i=0;i<z;i++)
       if(n==t[i].returnreg())
         {
                    cout<<"\nSTUDENT ALREADY EXISTS....TRY AGAIN ";
                    return 1;
         }
       return 0;
}
int main(void)
{ int i,n,reg;
  cout<<"\n ENTER STUDENT COUNT :";
  cin>>n;
  for(i=0;i<n;i++)
  {
                  lb:
                    cout<<"\nENTER REGISTRATION NUMBER :";
                    cin>>reg;
                    if(check(reg,i)==1)
                          goto lb;
                    else t[i].add(reg);
  }
 for(i=0;i<n;i++)
  t[i].display();
  getch();
 return 1;
}         
     
