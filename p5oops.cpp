/*
Create a class that holds the details of the students like name, age, phone no. etc.,. Use a function of that class to
 check whether the mobile number is a prime and set the flag field of the class as true. Finally display the objects that 
 has their mobile number as prime. (b)
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class student 
{
      int age;
      char name[20];
      long long int mob;
      bool flag;
      public:
      student()
      {
               age=0;
               mob=0;
               flag=true;
      }
      void checkprime();
      void accept();
      void display();
      bool returnflag()
      {
           return flag;
      }
};
void student::accept()
{          
           fflush(stdin);
           cout<<"\nENTER THE NAME OF THE STUDENT :";
           gets(name);           
           cout<<"\nENTER THE AGE :";
           cin>>age;
           cout<<"\nENTER THE MOBILE NUMBER :";
           cin>>mob;
           checkprime();
}
void student::display()
{          
           fflush(stdin);
           cout<<"\nNAME OF THE STUDENT :";
           puts(name);           
           cout<<"AGE :";
           cout<<age;
           cout<<"\nMOBILE NUMBER :";
           cout<<mob;
}
void student::checkprime()
{         
          int i;
          for(i=2;i<mob/2;i++)
          {
              if(mob%i==0)
                 {
                          flag=false;         
                          break;
                 }
          }
}            

int main(void)
{   int i,n;
    student s[10];
     cout<<"\nENTER NUMBER OF STUDENTS :";
     cin>>n;
     cout<<"\n\t\tENTER DETAILS OF STUDENTS :";
     for(i=0;i<n;i++)
         s[i].accept();
     cout<<"\nDETAILS OF STUDENTS WITH PRIME MOBILE NUMBERS :";
     for(i=0;i<n;i++)
        {            if(s[i].returnflag())
                                          s[i].display();
        }
      getch();
      return 1;
}       
                               
