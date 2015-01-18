/*
Create a c++ program that maintains an shared array for storing user data using static variable.
Create classes for different category of persons like general public, government official and VVIP.
 Reserve zones in that array such that they are to be used by appropriate category of people. Ensure 
 that the space is available in the array before taking a data (set flag that tells whether memory 
 available or not for each class).  Access the shared memory from all the classes to store and retrieve data. 
*/
#include<iostream.h>
#include<conio.h>
#include<string.h>
class base
{
      public:
             static int a[10];
};
class general:public base
{
      public:
             void insert(int);
};
class gov:public base
{
      public:
             void insert(int);
};
class vvip:public base
{
      public:
             void insert(int);
};
int base::a[10];
void general::insert(int i)
{
     cout<<"\nEnter Id of General :";
     cin>>a[i];
}
void gov::insert(int i)
{
     cout<<"\nEnter Id of Governer :";
     cin>>a[i];
}
void vvip::insert(int i)
{
     cout<<"\nEnter Id of VVIP:";
     cin>>a[i];
}
int main()
{
    general a;
    gov b;
    vvip c;
    int i=5,j=2,k=0;
    int p,flag,sw;
    do
    {
        cout<<"\n1.General \n2.Governor\n3.VVIP";
        cin>>sw;
        switch(sw)
        {
                  case 1 :if(i<=9)
                         {
                                  a.insert(i);
                                  i++;
                         }
                         else 
                         cout<<"NO MORE GENERAL ALLOWED !!!";
                         break;
                  case 2 :if(j<=4)
                         {
                                  b.insert(j);
                                  j++;
                         }
                         else 
                         cout<<"NO MORE GOVERNOR ALLOWED !!!";
                         break;
                  case 3 :if(k<=1)
                         {
                                  c.insert(k);
                                  k++;
                         }
                         else 
                         cout<<"NO MORE VVIP ALLOWED !!!";
                         break;
                  default:cout<<"\nWrong Choice !!";
        } 
        cout<<"\nEnter 1 to continue......";
        cin>>flag;
    }while(flag==1);
    cout<<"Displaying the array !!!";
    for(p=0;p<10;p++)
    {
                     if(p<2&& p<k)
                     
                      cout<<"\nVVIP "<<base::a[p];
                     
                     if(p>=2&& p<j && p<5)
                     
                      cout<<"\nGOVERNOR "<<base::a[p];
                     
                     if(p<i && p>=5)
                     
                      cout<<"\nGENERAL "<<base::a[p];
                      
    }
    getch();
    return 1;
}                  
