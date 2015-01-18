/*
Create a class that takes the details in ur ID card for 2 students and allow the student to update, delete and display records.(
*/
#include<iostream.h>
#include<conio.h>
#include<string.h>
class ID
{     bool flag;
      int reg,year;
      char name[30],branch[30];
      public:
       ID()
       {   flag=true;
           year=reg=0;
           strcpy(name,"\0");
           strcpy(branch,"\0");
       }
       void add();
       void display();
       void update();
       void del();
}t[2];
void ID::add()
{
     cout<<"\n ENTER REGISTRATION NUMBER :";
     cin>>reg;
     cout<<"\n ENTER YEAR :";
     cin>>year;
     fflush(stdin);
     cout<<"\n ENTER NAME :";
     gets(name);
     fflush(stdin);
     cout<<"\n ENTER BRANCH :";
     gets(branch);
}
void ID::display()
{    if(flag)
     {
      cout<<"\n REGISTRATION NUMBER :"<<reg;
      cout<<"\nYEAR :"<<year;
      fflush(stdin);
      cout<<"\n NAME :";
      puts(name);
      cout<<"BRANCH :";
      puts(branch);
     }
    else 
    cout<<"\nELEMENT DELETED !!!";
}    
void ID::del()
{
     display();
     cout<<"\n DELETING THE ABOVE DATA !! ";
     flag=false;
     reg=year=0;
     strcpy(branch,"\0");
     strcpy(name,"\0");   
}
void ID::update()
{    
     char ch;
     cout<<"\nDO YOU WANT TO CHANGE REGISTRATION NUMBER (PRESS Y) :";
     cin>>ch;
     if(ch=='y'||ch=='Y')
     {
                         cout<<"\nENTER REGISTRATION NUMBER :";
                         cin>>reg;
     }
     cout<<"\nDO YOU WANT TO CHANGE YEAR (PRESS Y) :";
     cin>>ch;
     if(ch=='y'||ch=='Y')
     {
                         cout<<"\nENTER YEAR :";
                         cin>>year;
     }
     cout<<"\nDO YOU WANT TO CHANGE NAME (PRESS Y) :";
     cin>>ch;
     if(ch=='y'||ch=='Y')
     {                   fflush(stdin);
                         cout<<"\nENTER NAME :";
                         gets(name);
     }
     cout<<"\nDO YOU WANT TO CHANGE BRANCH (PRESS Y) :";
     cin>>ch;
     if(ch=='y'||ch=='Y')
     {                   fflush(stdin);
                         cout<<"\nENTER BRANCH :";
                         gets(branch);
     }
}
int main(void)
{   int i,n;
    char c='y';
    cout<<"\n ENTER DETAILS FOR STUDENT 1 :";
    t[0].add();
    cout<<"\n ENTER DETAILS FOR STUDENT 2 :";
    t[1].add();
    while(c=='y'||c=='Y')       
    {     cout<<"\nENTER STUDENT NO. TO PERFORM ACTION UPON(1/2) :";
          cin>>n;
          n--;                
          cout<<"\nENTER YOUR CHOICE \n1.UPDATE\n2.DELETE\n3.DISPLAY ";
          cin>>i;
          switch(i)
          {
                   case 1:cout<<"\nUPDATING !!";
                          t[n].update();
                                      break;
                   case 2:cout<<"\nDELETING !!";
                          t[n].del();
                                      break;
                   case 3:cout<<"\nDISPLAYING !!";
                          t[n].display();
                                         break;
                   default:cout<<"\nERROR !!";
                            break;
          }
          cout<<"\nWANT TO CONTINUE PRESS Y :";
          cin>>c;
    }
getch();
return 1;
}
                        
          
