/*
Create a class which maintains information like username, password, age, mailid, phone number, accepted friends 
list, etc.,. Declare a friend function inside the class.  Create 3 users such that the first user is friend with
 2 and 3 (update friend llist of 1 with user names of 2 and 3). If the user1 logs in, he should see the personal 
 information of 2 and 3, likewise 2 and 3 should see personal info of 1. However, 2 can't see the personal information
  of 3 and vise versa. 
*/
#include<iostream.h>
#include<conio.h>
class  base
{
       public:
              char user[30],pass[30],mail[30];
              int age;
              long long int ph;
              void accept();   
};
void base::accept()
{
    cout<<"\nEnter Username :";
     fflush(stdin);
     gets(user);
    cout<<"\nEnter Password :";
     fflush(stdin);
     gets(pass);
    cout<<"\nEnter Email :";
     fflush(stdin);
     gets(mail);
    cout<<"\nEnter Age :";
     cin>>age;
    cout<<"\nEnter Phone Number :";
     cin>>ph;
}
class person2;
class person3;
class person1:public base
{
      public:
             person1()
             {
                      accept();
             }
      friend void acc(person2 a,person3 b);
};
 
class person2:public base
{
      public:
             person2()
             {
                      accept();
             }
      friend void acc(person1 c);
};
 
class person3:public base
{
      public:
             person3()
             {
                      accept();
             }
      friend void acc(person1 c);
};
void acc(person1 c)
{    cout<<"\nFRIENDS !!!";
     cout<<"\nUsername :"<<c.user;
     cout<<"\nEmail ID :"<<c.mail;
     cout<<"\nAge :"<<c.age;
     cout<<"\nPhone Number :"<<c.ph; 
}
void acc(person2 a,person3 b)
{    cout<<"\nFRIENDS !!!";
     cout<<"\nUsername :"<<a.user;
     cout<<"\nEmail ID :"<<a.mail;
     cout<<"\nAge :"<<a.age;
     cout<<"\nPhone Number :"<<a.ph; 
     cout<<"\n\n\nUsername :"<<b.user;
     cout<<"\nEmail ID :"<<b.mail;
     cout<<"\nAge :"<<b.age;
     cout<<"\nPhone Number :"<<b.ph; 
}
int main()
{
    person1 p;
    person2 q;
    person3 r;
    char name[30],pass[30];
    int flag;
    do
    {
        cout<<"\nEnter Username and Password :";
        fflush(stdin);
        gets(name);
        fflush(stdin);
        gets(pass);
        if((strcmp(name,p.user)==0)&&(strcmp(pass,p.pass)==0))
             acc(q,r);
        else if((strcmp(name,q.user)==0)&&(strcmp(pass,q.pass)==0))
             acc(p);
        else if((strcmp(name,r.user)==0)&&(strcmp(pass,r.pass)==0))
             acc(p);
        else 
            cout<<"\nWrong Username And Password !!!";
             cout<<"\nDo You Want to enter again(1=yes,2=no)";
             cin>>flag;
    }while(flag==1);
        getch();
        return 1;
}
