/*26. Create a class that maintains the details like, given_no, a temporary array, and
factorial_of the given no. Use a function that finds the factorial of the given number
without using recursion by making use of the temporary array. Handle the array
overflow exception when all the locations of the array were used and display the
message “internal memory is not sufficient to carryout this operation”.*/

#include<iostream>
#include<conio.h>
using namespace std;
class factorial
{
     public: int given_no,temp[5],fact;
     factorial()
     { int i;
       for(i=0;i<5;i++)
       temp[i]=1;
     }         
     void facto();
};
void factorial::facto()
{
 int fact=1,b,i=0;
 b=given_no;
 try
 {
  while(b!=1)
  {
    temp[i]=b;
     ++i;
     --b;         
     if(i>=5)
     throw i; 
  }
    i=0;
   while(temp[i]!=1)
   {
     fact=fact*temp[i++];
   }
    cout<<"factorial of number is:"<<fact;
   }
   catch(int j)
   {
     cout<<"\nCaugth exception array index out of bounds cz of array limit:\t"<<j;
     cout<<"\ninternal memory is not sufficient to carryout this operation";
     cout<<"\n-------------------------------------------------------------\n";
    }
 }
int main()
{
    factorial obj;
    cout<<"factorial is to be calculated for:";cin>>obj.given_no;
    obj.facto();
    getch();
    return 0;
}                   
