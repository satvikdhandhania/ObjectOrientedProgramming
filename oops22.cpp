/*
22. Create a class telephone_directory (name, occupation, phone, address) and an virtual function search (), that searches the
object contents in a linear fashion. Extend the class in a specific class called doctor (qualification, clinic, visiting time)
and override the virtual function such that it searches using binary search. Also create another class lawyer (qualification, 
civil/criminal, cases attended, contact_no, office_address) that extends the telephone_directory such that it wont override the
virtual function. Search for a doctor and a lawyer by taking the option from the user. (m) 
*/
#include<conio.h>
#include<iostream>
using namespace std;
int dn,ln;
class telephone_directory
{     public:
      char name[30],occ[10],add[50];
      long long double phone;
      virtual void search()=0;   
};
class doctor:public telephone_directory
{
      public:
      char quali[10],clinic[30],visit[20];
      void accept()
      {
           cout<<"\nEnter Name :";
           fflush(stdin);
           gets(name);
           cout<<"Enter Occupation :";
           fflush(stdin);
           gets(occ);
           cout<<"Enter Phone No :";
           cin>>phone;
           cout<<"\nEnter Address :";
           fflush(stdin);
           gets(add);
           cout<<"Enter Qualification :";
           fflush(stdin);
           gets(quali);
           cout<<"Enter Clinic :";
           fflush(stdin);
           gets(clinic);
           cout<<"nEnter Visiting Hours :";
           fflush(stdin);
           gets(visit);
      }
      void display()
      {
           cout<<"\nName :"<<name;
           cout<<"\nOccupation :"<<occ;
           cout<<"\nPhone No :"<<phone;
           cout<<"\nAddress :"<<add;
           cout<<"\nQualification:"<<quali;
           cout<<"\nClinic :"<<clinic;
           cout<<"\nVisiting Hours :"<<visit;
      }
      void search();
}d[50];
void doctor::search()
      {    int i;
           char n[30];
           cout<<"\nEnter Name Of Doctor To Be Searched :";
           fflush(stdin);
           gets(n);
           for(i=0;i<dn;i++)
                            if(strcmp(d[i].name,n)==0)
                              {   cout<<"\nFound !!";
                                  d[i].display();
                                  break;
                              }
           if(i==dn)
                    cout<<"\nNot Found !!!";
      }
class lawyer:public telephone_directory
{
      public:          
      char quali[15],typ[10],offadd[50];
      int casatten; 
      long long double contac;
      void accept()
      {    
           cout<<"\nEnter Name :";
           fflush(stdin);
           gets(name);
           cout<<"Enter Occupation :";
           fflush(stdin);
           gets(occ);
           cout<<"Enter Phone No :";
           cin>>phone;
           cout<<"\nEnter Address :";
           fflush(stdin);
           gets(add);
           cout<<"Enter Qualification :";
           fflush(stdin);
           gets(quali);
           cout<<"Enter Type(civil/criminal) :";
           fflush(stdin);
           gets(typ);
           cout<<"\nEnter Cases attended :";
           cin>>casatten;
           cout<<"\nEnter Contact no :";
           cin>>contac;
           cout<<"\nEnter Office Address :";
           fflush(stdin);
           gets(offadd);
      }
      void display()
      {
           cout<<"\nName :"<<name;
           cout<<"\nOccupation :"<<occ;
           cout<<"\nPhone No :"<<phone;
           cout<<"\nAddress :"<<add;
           cout<<"\nQualification :"<<quali;
           cout<<"\nType :"<<typ;
           cout<<"\nCases attended :"<<casatten;
           cout<<"\nContact no :"<<contac;
           cout<<"\nOffice Address :"<<offadd;
      }
      void search();
}l[50],temp;
void lawyer::search()
      {    bool flag=false;
           int mid,low,high;
           char n[30];
           cout<<"\nEnter Name Of lawyer To Be Searched :";
           fflush(stdin);
           gets(n);
           for(low=0;low<ln;low++)
               for(mid=0;mid<ln-low-1;mid++)
                  if(strcmp(l[mid].name,l[mid+1].name)>0)
                       { 
                         temp=l[mid];
                         l[mid]=l[mid+1];
                         l[mid+1]=temp;                                                   
                       }
           low=0;
           high=ln;
           while(low<high)
           {
                mid=(low+high)/2;
                           if(strcmp(l[mid].name,n)==0)
                              {   cout<<"\nFound !!";
                                  l[mid].display();
                                  flag=true;
                                  break;
                              }
                            else if(strcmp(l[mid].name,n)>0)
                              {    
                                   high=mid-1;
                              }
                            else if(strcmp(l[mid].name,n)<0)
                              {    
                                   low=mid+1;
                              }      
            }
            if(!flag)
                     cout<<"\nNot Found !!!";
}
int main()
{     int i;
      cout<<"\nEnter No Of Doctors :";
      cin>>dn;
      for(i=0;i<dn;i++)
         {             cout<<"\nEnter Details For Doctor "<<i+1<<" :";
                       d[i].accept();
         } 
      cout<<"\nEnter No Of Lawyers :";
      cin>>ln;
      for(i=0;i<ln;i++)
         {             cout<<"\nEnter Details For Lawyer "<<i+1<<" :";
                       l[i].accept();
         } 
      cout<<"\nWhat Do You Want To Search For 1.Doctor 2.Lawyer :\nEnter Your Choice :";
      cin>>i;
      if(i==1)
            d[0].search();
      else if(i==2)
           l[0].search();
      getch();
      system("cls");
      for(i=0;i<ln;i++)
         {             cout<<"\nDetails For Lawyer "<<i+1<<" :";
                       l[i].display();
         } 
      getch();
      system("cls");
      for(i=0;i<dn;i++)
         {             cout<<"\nDetails For Doctor "<<i+1<<" :";
                       d[i].display();
         } 
      getch();
      return 1;
}
