/*
Synthesize a C++ program that has two classes (one for employee and one for student), have a separate class for 
address (with door no, street name, city, state) and reuse address both for employee and student. Perform insert, delete
 and display operations by taking choice of person (employee or student) from the user. Allow user to have more than one 
 address also
*/
#include<iostream.h>
#include<conio.h>
class address
{     
      int doorno;
      char street[30],city[30],state[30];
      public:
             address(){
                       doorno=0;
                       strcpy(street,"\0");
                       strcpy(city,"\0");
                       strcpy(state,"\0");
             }
             void accept();
             void disp();
             void d();
};
void address::accept()
{
     cout<<"\nENTER DOOR NO :";
     cin>>doorno;
     fflush(stdin);
     cout<<"Enter Street :";
     gets(street);
     fflush(stdin);
     cout<<"Enter City :";
     gets(city);
     fflush(stdin);
     cout<<"Enter State :";
     gets(state);
}

void address::d()
{    doorno=0;
     strcpy(street,"\0");
     strcpy(city,"\0");
     strcpy(state,"\0");
}

void address::disp()
{
     cout<<"\nDOOR NO :"<<doorno;
     fflush(stdin);
     cout<<"\nStreet :";
     puts(street);
     fflush(stdin);
     cout<<"City :";
     puts(city);
     fflush(stdin);
     cout<<"State :";
     puts(state);
}

class student
{     bool f;
      int reg,n,c;
      char name[30];
      address a[5];
      public:
             void del();
             void add();
             void display();
}s;
void student::add()
{    n=0;
     f=true;
     char c='y';
     cout<<"\nEnter Registration No. :";
     cin>>reg;
     fflush(stdin);
     cout<<"\nEnter Name :";
     gets(name);
     while(c=='y'||c=='Y')
          {
               a[n].accept();
               n++;
               cout<<"\nWANT TO ADD MORE ADDRESSES (PRESS Y) :";
               cin>>c;
          }
}    

void student::del()
{    reg=0;
     f=false;
     strcpy(name,"\0");
     int i;
     for(i=0;i<n;i++)
          {    
             a[i].d();
          }
}    
void student::display()
{    if(f)
     {
          cout<<"\nRegistration No. :"<<reg;
          fflush(stdin);
          cout<<"\nName :";
          puts(name);
          int i;
          for(i=0;i<n;i++)
          {    
               cout<<"\nAddress "<<i+1<<" :";
               a[i].disp();
          }
     }
     else 
     cout<<"\nSTUDENT DELETED BEFORE!!!";
}    
class employee
{     bool f;
      int id,n;
      address a[5];
      char name[30];
      public:
             void add();
             void del();
             void display();
}emp;

void employee::add()
{    n=0;
     f=true;
     char c='y';
     cout<<"\nEnter ID :";
     cin>>id;
     fflush(stdin);
     cout<<"\nEnter Name :";
     gets(name);
     while(c=='y'||c=='Y')
          {    cout<<"\nEnter Address "<<n+1<<" :";           
               a[n].accept();
               n++;
               cout<<"\nWANT TO ADD MORE ADDRESSES (PRESS Y) :";
               cin>>c;
          }
}    

void employee::display()
{    if(f)
     {    cout<<"\nID :"<<id;
          fflush(stdin);
          cout<<"\nName :";
          puts(name);
          int i;
          for(i=0;i<n;i++)
          {    
               cout<<"\nAddress "<<i+1<<" :";
               a[i].disp();
          }
     }
     else
      cout<<"\nEMPLOYEE DELETED BEFORE!!!";
}    

void employee::del()
{    id=0;
     f=false;
     strcpy(name,"\0");
     int i;
     for(i=0;i<n;i++)
          {    
               a[i].d();
          }      
}          
            
int main()
{
     int i,c;
     char ch='y';
     while(ch=='y'||ch=='Y')
     {        lb:              
              cout<<"\n PREFORM ACTION ON : \n1.STUDENT \n2.EMPLOYEE :";
                cin>>i;
                if(!(i==1||i==2))
                    {          
                        cout<<"\nWRONG INPUT....TRY AGAIN !!!!";
                        goto lb; 
                    }          
                 cout<<"\nWhat Action Do You Want to Perform :\n1.INSERT\n2.DELETE\n3.DISPLAY:";
                               cin>>c;
                                switch(c)
                                {
                                  case 1:cout<<"\nINSERTING !!";
                                                 if(i==1)
                                                     s.add();
                                                 if(i==2)
                                                     emp.add();
                                               break;
                                  case 2:cout<<"\nDELETING !!";
                                             if(i==1)
                                                  s.del();
                                             if(i==2)
                                                  emp.del();
                                               break;                                                                
                                 case 3:cout<<"\nDISPLAYING !!";
                                                 if(i==1)
                                                     s.display();
                                                 if(i==2)
                                                     emp.display();
                                               break;  
                                 default :cout<<"\nWRONG INPUT !!!!";
                                }
                 cout<<"\nDo You Want To Continue ...Press Y  :";
                 cin>>ch;
     }

getch();
return 1;
}
