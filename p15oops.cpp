/*
Create a class that stores the details about a room in a hotel (private: room no, type, cost, tv, intercom, refridgerator, 
status). Create a class that maintains the customer details (name, age, address, phoneno).  Allow booking of the room by 
the customer after checking the status of its availability. Have the status as a static variable so that only one copy of 
status exists for all the customers.
*/
#include<iostream.h>
#include<conio.h>
class room 
{
      private:
              int rno,cost,intercom;
              char type[30],tv,ref;
      public:
              static bool status;
                     room()
                     {     accept();
                     }
                     void accept();
                     void display();
                     bool returnstatus(){return status;}
                     static void changestatus()
                     { status=status?false:true;}
};
bool room::status=false;
void room::accept()
{
     cout<<"\nEnter Room No. :";
     cin>>rno;
     cout<<"\nEnter Type Of Room. :";
     fflush(stdin);
     gets(type);
     cout<<"\nEnter Cost :";
     cin>>cost;
     cout<<"\nEnter tv Available(Y) or Not(N) :";
     cin>>tv;
     cout<<"\nEnter Refrigerator Available(Y) or Not(N) :";
     cin>>ref;
     cout<<"\nEnter Intercom No. :";
     cin>>intercom;
}
void room::display()
{
     cout<<"\nRoom No. :"<<rno;
     cout<<"\nType Of Room. :";
     fflush(stdin);
     puts(type);
     cout<<"Cost :"<<cost;
     cout<<"\nTv Available(Y) or Not(N) :"<<tv;
     cout<<"\nRefrigerator Available(Y) or Not(N) :"<<ref;
     cout<<"\nIntercom No.:"<<intercom;
}
class customer 
{      private:
       char name[30],add[50];
       long long int phone;
       int age;
       public :
              customer()
              { accept(); }
             void accept();
             void display();
};
void customer::accept()
{
     cout<<"\nEnter Name :";
     fflush(stdin);
     gets(name);
     cout<<"Enter Address :";
     fflush(stdin);
     gets(add);
     cout<<"Enter Age :";
     cin>>age;
     cout<<"\nEnter Phone Number :";
     cin>>phone;
}           
void customer::display()
{
     cout<<"\nName :";
     fflush(stdin);
     puts(name);
     cout<<"Address :";
     fflush(stdin);
     puts(add);
     cout<<"Age :"<<age;
     cout<<"\nPhone Number :"<<phone;
}              
int main()
{
    customer c;
    room r;
    int i;
    char ch;
    do
    {
         cout<<"\n1.Book \n2.Checkout\nExit :";
         cin>>i;
         switch(i)
         {
                  case 1: r.display();
                            if(r.returnstatus()==false)
                             {
                                 r.changestatus();
                                 cout<<"\nRoom Booked !! \n\n";
                             }
                             else 
                             {    cout<<"\nRoom Already Booked by ";
                                            c.display();
                             }
                             break;
                  case 2:if(r.returnstatus()==true)
                          {
                                               cout<<"\nRemoving Reservation !!!\n\n";
                                               r.changestatus();
                                               r.display();
                                               c.display();
                          }
                          else 
                               cout<<"\nRoom Not Booked Yet !!! ";
                               break;
                  case 3:exit(0);
                  default :cout<<"\nWrong Input !!!";
         }
         cout<<"\nPress Y to continue ....";
         cin>>ch;
    }while(ch=='y'||ch=='Y');
    getch();
    return 1;
} 
                              
