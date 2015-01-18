/*
Create a c++ program that has separate classes for shoes (prod_id, brand, quantity, price, size), belt and caps. 
List out the products available to the user and allow the user to select the products and the quantity. Overload 
* operator for multiplying quantity with objects and overload + operator to add all the product costs together. 
Finally display the total amount, quantity of each product with their brands, price etc.,. 
*/
#include<iostream.h>
#include<conio.h>
#include<string.h>
class object
{
      int q,size;
      char brand[20];
      float price,tprice;
      public:
             int prod_id;
             object()
             {
                     q=prod_id=size=0;
                     strcpy(brand,"\0");
                     price=tprice=0.0;
             }
             void operator *(int n)
             {
                  q=n;
                  tprice=price*n;
             }
             float operator +(float gr)
             {
                   gr=gr+tprice;
                   return gr;
             }
             void acc();
             void disp();
}*p[3];
void object::acc()
{
     cout<<"\nEnter Product_Id :";
     cin>>prod_id;
     cout<<"\nEnter Brand :";
     fflush(stdin);
     gets(brand);
     cout<<"Enter SiZe ";
     cin>>size;
     cout<<"\nEnter Price :";
     cin>>price;
}
void object::disp()
{
     cout<<"\nProduct Id: "<<prod_id<<"Brand :"<<brand<<" Size :"<<size<<"  Price :"<<price;
     if(q!=0)
      cout<<"QUANTITY :"<<q;
}
class shoes:public object
{
      public:
             shoes()
             {
                    cout<<"\nEnter Details For Shoe :";
                    acc();
             }
             int returnid()
             { return prod_id;}
             void display()
             {
                  cout<<"\nDISPLAYING SHOE DETAILS :";
                  disp();
             }
};
class belts:public object
{
      public:
           belts()
             {
                    cout<<"\nEnter Details For belt :";
                    acc();
             }
             int returnid()
             { return prod_id;}
             void display()
             {
                  cout<<"\nDISPLAYING belt DETAILS :";
                  disp();
             }
};
class caps:public object
{
      public:
             caps()
             {
                    cout<<"\nEnter Details For cap :";
                    acc();
             }
             int returnid()
             { return prod_id;}
             void display()
             {
                  cout<<"\nDISPLAYING cap DETAILS :";
                  disp();
             }
};
 int main()
 {
     int i,id,n;
     float gr=0.0;
     shoes s[1];
     belts b[1];
     caps c[1];
     system("cls");
     cout<<"\nOptions For Buy ";
     cout<<"\n\t\tSHOES !!";
     for(i=0;i<1;i++)
                     s[i].display();
     cout<<"\n\t\tBELTS !!";
     for(i=0;i<1;i++)
                     b[i].display();
     cout<<"\n\t\tCAPS !!";
     for(i=0;i<1;i++)
                     c[i].display();
     cout<<"\nSelect by putting id and quantity for shoes :";
     cin>>id>>n;
     for(i=0;i<1;i++)
           if(s[i].returnid()==id)
           {
            p[0]=&s[i];
            *p[0]*n;
            break;
            }
            else
            {
                p[0]=&s[0];
                *p[0]*0;
            }
     cout<<"\nSelect by putting id and quantity for belts:";
     cin>>id>>n;
     for(i=0;i<1;i++)
           if(b[i].returnid()==id)
           {
            p[1]=&b[i];
            *p[1]*n;
            break;
            }
            else
            {
                p[1]=&b[0];
                *p[1]*0;
            }
     cout<<"\nSelect by putting id and quantity for caps :";
     cin>>id>>n;
     for(i=0;i<1;i++)
           if(c[i].returnid()==id)
           {
            p[2]=&c[i];
            *p[2]*n;
            break;
            }
            else
            {
                p[2]=&c[0];
                *p[2]*0;
            }
     for(i=0;i<3;i++)
     {
                     p[i]->disp();
                     gr=*p[i]+gr;
     }
     cout<<"\n\n\tGRAND TOTAL :"<<gr;
     getch();
     return 1;
}
