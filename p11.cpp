/*
Create a c++ program that has separate classes for shoes (prod_id, brand, quantity, price, size), belt and caps. 
List out the products available to the user and allow the user to select the products and the quantity. Overload * 
operator for multiplying quantity with objects and overload + operator to add all the product costs together. Finally 
display the total amount, quantity of each product with their brands, price etc.,. 
*/
#include<iostream>
#include<conio.h>
using namespace std;

class shoes
{
     public: int prod_id[2];
      char brand[5][10];
      int quantity[3];
      int price[3];
      int size[2];
       int sprice;
       int flag;
             shoes()
             {  prod_id[0]=123;
                strcpy(brand[0],"REEBOK");
                price[0]=300;
                size[0]=8;
                quantity[0]=0;
                prod_id[1]=129;
                strcpy(brand[1],"PUMA");
                price[1]=200;
                size[1]=9;
                quantity[1]=0;
             }
             ~shoes()
             {
                     cout<<"\nShoes\n1."<<brand[0]<<"\nProd_id - "<<prod_id[0]<<"\n2.Price - "<<price[0]<<"\n3.Quantity - "<<quantity[0]<<"\n4.Size - "<<size[0];
                     cout<<"\n1."<<brand[1]<<"\nProd_id - "<<prod_id[1]<<"\n2.Price - "<<price[1]<<"\n3.Quantity - "<<quantity[1]<<"\n4.Size - "<<size[1];
                     getch();
             }       
             int operator*(int);
             int operator+(int);
                    
      
}s;
int shoes::operator*(int n)
{   if(flag==1)
    sprice+=price[0]*n;
    else
    sprice+=price[1]*n;
    return sprice;
}
int shoes::operator+(int n)
{   int total;
    total=sprice+n;
    return total;
}
class belt
{    public: int prod_id[2];
      char brand[5][10];
      int quantity[3];
      int price[3];
      int size[2];
      int bprice;
      int flag;
             belt()
             {  prod_id[0]=145;
                strcpy(brand[0],"ARMANI");
                price[0]=5000;
                size[0]=28;
                quantity[0]=0;
                prod_id[1]=150;
                strcpy(brand[1],"CHARLIE");
                price[1]=2000;
                size[1]=32;
                quantity[1]=0;
             }
              ~belt()
             {
                     cout<<"\nBelt\n1."<<brand[0]<<"\nProd_id - "<<prod_id[0]<<"\n2.Price - "<<price[0]<<"\n3.Quantity - "<<quantity[0]<<"\n4.Size - "<<size[0];
                     cout<<"\n1."<<brand[1]<<"\nProd_id - "<<prod_id[1]<<"\n2.Price - "<<price[1]<<"\n3.Quantity - "<<quantity[1]<<"\n4.Size - "<<size[1];
             }       
             
             int operator*(int);
             int operator+(int);
      
             
}b;
int belt::operator*(int n)
{    
   if(flag==1)
    bprice+=price[0]*n;
    else
    bprice+=price[1]*n;
    return bprice;
}
int belt::operator+(int n)
{   int total;
    total=bprice+n;
    return total;
}
    

class cap
{      public:int prod_id[2];
      char brand[5][10];
      int quantity[3];
      int price[3];
      int size[2];
      int cprice;
       int flag;
             cap()
             {  prod_id[0]=191;
                strcpy(brand[0],"NIKE");
                price[0]=500;
                size[0]=5;
                quantity[0]=0;
                prod_id[1]=199;
                strcpy(brand[1],"TH");
                price[1]=1000;
                size[1]=6;
                quantity[1]=0;
             }
              ~cap()
             {
                     cout<<"\nCap\n1."<<brand[0]<<"\nProd_id - "<<prod_id[0]<<"\n2.Price - "<<price[0]<<"\n3.Quantity - "<<quantity[0]<<"\n4.Size - "<<size[0];
                     cout<<"\n1."<<brand[1]<<"\nProd_id - "<<prod_id[1]<<"\n2.Price - "<<price[1]<<"\n3.Quantity - "<<quantity[1]<<"\n4.Size - "<<size[1];
                     
             }       
      int operator*(int);
      int operator+(int);
      
}c;
int cap::operator*(int n)
{   if(flag==1)
    cprice+=price[0]*n;
    else
    cprice+=price[1]*n;
    return cprice;
}
int cap::operator+(int n)
{   int total;
    total=cprice+n;
    return total;
}


int main()
{   int ch,ch1,sprice,bprice,cprice,m,total;char ch2;
    s.flag=0;b.flag=0;c.flag=0;
    s.sprice=0;b.bprice=0;c.cprice=0;
do
{
cout<<"Want To buy :\n1.Shoes\n2.Belt\n3.Cap";
cout<<"\nEnter your choice";
cin>>ch;

switch(ch)
{
          case 1: cout<<"Brands Available are :\n1."<<s.brand[0]<<"\n2."<<s.brand[1];
                  cout<<"\nEnter your choice :";
                  cin>>ch1;
                  if(ch1==1)
                  s.flag=1;
                  cout<<"Enter the quantity ";
                  cin>>s.quantity[ch1-1];
                  m=s.quantity[ch1-1];
                  sprice=s*m;
                  s.flag=0;
                  break;
          case 2: cout<<"Brands Available are :\n1."<<b.brand[0]<<"\n2."<<b.brand[1];
                  cout<<"\nEnter your choice :";
                  cin>>ch1;
                  if(ch1==1)
                  b.flag=1;
                  cout<<"Enter the quantity ";
                  cin>>b.quantity[ch1-1];
                  m=b.quantity[ch1-1];
                  bprice=b*m;
                  b.flag=0;
                  break;
          case 3: cout<<"Brands Available are :\n1."<<c.brand[0]<<"\n2."<<c.brand[1];
                  cout<<"\nEnter your choice :";
                  cin>>ch1;
                  if(ch1==1)
                  c.flag=1;
                  cout<<"Enter the quantity ";
                  cin>>c.quantity[ch1-1];
                  m=c.quantity[ch1-1];
                  cprice=c*m;
                  c.flag=0;
                  break;
          default:cout<<"Invalid choice";
                  break;
}cout<<"Want to continue(Y/N)";
cin>>ch2;
}while(ch2=='Y'||ch2=='y');

total=s+0;
total=b+total;
total=c+total;

cout<<"\nTotal="<<total;
getch();
return 0;
}


                                 
                  
                  
                  
