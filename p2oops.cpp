/*
Generate factorial and Fibonacci by taking inputs from the user. Use separate functions inside the class.(b)
*/
#include<iostream.h>
#include<conio.h>
class fibfac{
      int a,b,c,fact,i;
      public:
       void gen(int x)
       {    a=0;b=1;
            if(x<=0){
             cout<<"NO FIBONACCI SERIES !!! ";
            }
            else if(x==1)
            {  cout<< a;
            }
            else                 
             { cout<<"FIBONACCI SERIES ....:\n";
               cout<<a<<"\t"<<b<<"\t"; 
               for(i=0;i<x-2;i++)
                {  
                    c=a+b;
                    a=b;
                    b=c;
                    cout<<c<<"\t";
                }     
            }          
            }
       void fibfac::fac(int x)
       {
            if(x==0)
            {
                cout<<"\nFACTORIAL =1";
            }
            else 
            {   fact=1;
                 while(x>0)
                 {
                  fact*=x;
                  x--;
                 }
                 cout<<"\nFACTORIAL IS :"<<fact;
            }
       }
};      
int main()
{   fibfac g;
    int a,b;
    cout<<"ENTER NO OF TERMS IN FIBONACCI SEQUENCE :";
    cin>>a;
    g.gen(a);
    cout<<"ENTER NO. FOR FACTORIAL :";
    cin>>b;
    g.fac(b);
    getch();
    return 1;
} 
      
