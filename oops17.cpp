/*
Create an abstract class that takes input from the user and has an abstract function to perform sorting of t
he data. Extend the class to perform sorting using bubble and selection sort. Do the sorting by taking the choice
 from the user.(m)
*/
#include<iostream.h>
#include<conio.h>
class base
{     
      public:
      int a[10];
      int i;
             base()
             {    cout<<"\nEnter Array....";    
                  for(i=0;i<10;i++)
                                   cin>>a[i];
             }
             virtual void sort(int)=0;
             virtual void display()=0;
};
class sorting:public base
{     
      public:
             void display()
             {    cout<<"\nDisplaying  Array !! \n";
                  for(i=0;i<10;i++)
                                   cout<<" "<<a[i];
             }
             void sort(int);
};
void sorting::sort(int x)
{ int j,tmp;
  if(x==1)
  {
       for(i=0;i<9;i++)
         for(j=0;j<9-i;j++)
          if(a[j]>a[j+1])
            {            tmp=a[j];
                         a[j]=a[j+1];
                         a[j+1]=tmp;                                   
            }  
           cout<<"\nSorted By Bubble Sort !!!\n";          
  }
 if(x==2)
 {  int pos;
     for(i=0;i<9;i++)
     { pos=i;
      for(j=i+1;j<9;j++)
           if(a[pos]>a[j])         
              pos=j;
        if(pos!=i)
         {
               tmp=a[i];
               a[i]=a[pos];
               a[pos]=tmp;                         
         }  
      }    
      
           cout<<"\nSorted By Selection Sort !!!\n";
 }
}
int main()
{   int ch;
    sorting s;
    cout<<"\n1.Bubble\n2.By Selection Sort :";
    cin>>ch;
    s.sort(ch);
    s.display();
    getch();
    return 1;
}
    

