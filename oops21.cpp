/*
21. Create a class for house (house no, street, city, state, pincode) and a subclass vehicles (vehicle no, type(2/4 wheeler),
 fuel(petrol/diesel)), 2 wheeler(gear type(with/without gear), start type(kick/button), brand), 4 wheeler (A/c, music system,
  brand, ABS, airbag). Take the vehicle number from the user and retrieve the information on a specific parameter. Also list 
  out the vehicles in a specific area by pincode. (m)
*/
#include<iostream.h>
#include<conio.h>

class wheel2 
{     public:
      bool flag;
      int vno;
      char fuel[10],geartyp[15],starttyp[10],brand[30];
      wheel2()
      {
              flag=false;
      }
      void accept()
      {
           if(flag)
              {    cout<<"\nEnter Details For Two Wheeler \n\n";
                   cout<<"\nEnter Vehicle No :";
                   cin>>vno;
                   cout<<"\nEnter Fuel(petrol/diesel)  :";
                   fflush(stdin);
                   gets(fuel);
                   cout<<"Enter GearType(with/without gear):";          
                   fflush(stdin);
                   gets(geartyp);
                   cout<<"Enter StartType(kick/button):";          
                   fflush(stdin);
                   gets(starttyp);
                   cout<<"Enter Brand:";          
                   fflush(stdin);
                   gets(brand);
              }     
      }        
      void display()
      {
           if(flag)
              {
                   cout<<"\nTWO WHEELER\n\n";          
                   cout<<"Vehicle No :"<<vno;
                   cout<<"\nFuel(petrol/diesel):"<<fuel; 
                   cout<<"\nGear Type :"<<geartyp;
                   cout<<"\nStartType(kick/button):"<<starttyp;
                   cout<<"\nBrand:"<<brand;
                   
              }     
      }            
};
class wheel4
{     public:
      bool flag;
      char ac[3],music[3],brand[10],abs[3],air[3];
      int vno;
      char fuel[10];
      wheel4()
      {
       flag=false;
      }
      void accept()
      {
           if(flag)
              {    cout<<"\nEnter Details For Four Wheeler \n\n";
                   cout<<"\nEnter Vehicle No :";
                   cin>>vno;
                   cout<<"\nEnter Fuel(petrol/diesel)  :";
                   fflush(stdin);
                   gets(fuel);
                   cout<<"Enter Ac(yes/no):";          
                   fflush(stdin);
                   gets(ac);
                   cout<<"Enter Music System(yes/no):";          
                   fflush(stdin);
                   gets(music);
                   cout<<"Enter ABS(yes/no):";          
                   fflush(stdin);
                   gets(abs);
                   cout<<"Enter Airbag(yes/no):";          
                   fflush(stdin);
                   gets(air);
                   cout<<"Enter Brand:";          
                   fflush(stdin);
                   gets(brand);
              }     
      }        
      void display()
      {
           if(flag)
              {
                   cout<<"\nFOUR WHEEL\n\n";
                   cout<<"Vehicle No :"<<vno;
                   cout<<"\nFuel(petrol/diesel)  :"<<fuel; 
                   cout<<"\nAC:"<<ac;
                   cout<<"\nMusic System:"<<music;
                   cout<<"\nABS:"<<abs;
                   cout<<"\nAirbag:"<<air;
                   cout<<"\nBrand:"<<brand;
              }     
      }            
};
class vehicles
{     public:
      wheel2 type2;
      wheel4 type4;
};     
class house:public vehicles
{     public:
      int hno;
      double pin;
      char street[30],city[30],state[30];
      void accept()
      {    cout<<"\nEnter Details For House \n\n";
           char j ;
           cout<<"\nEnter House No :";
           cin>>hno;
           cout<<"\nEnter Street:";          
           fflush(stdin);
           gets(street);
           cout<<"Enter City:";          
           fflush(stdin);
           gets(city);
           cout<<"Enter State:";          
           fflush(stdin);
           gets(state);
           cout<<"\nEnter Pincode :";
           cin>>pin;
           cout<<"\nEnter Whether Two Wheeler (y/n) :";
           cin>>j;
           if(j=='y'||j=='Y')
                   type2.flag=true;
           type2.accept();
           cout<<"\nEnter Whether Four Wheeler (y/n) :";
           cin>>j;
           if(j=='y'||j=='Y')
                   type4.flag=true;
           type4.accept();
      }
      void display()
      {    
           cout<<"\nHouse No :"<<hno;
           cout<<"\nStreet:"<<street;
           cout<<"\nCity:"<<city;
           cout<<"\nState:"<<state;
           cout<<"\nPincode :"<<pin;
           type2.display();
           type4.display();
      }
}h[50];
main()
{     bool flag=false;    
      int i,n,vno;
      double pin;
      cout<<"\nEnter No Of Houses You want to enter :";
      cin>>n;
      for(i=0;i<n;i++) 
                       h[i].accept();
      getch();
      system("cls");
      cout<<"\nEnter Vehicle No. To Be Searched For :";
      cin>>vno;
      for(i=0;i<n;i++) 
      {
          if(h[i].type2.flag)
             if(h[i].type2.vno==vno)
             {   flag=true;
                 h[i].type2.display();                              
             }
          if(h[i].type4.flag)
             if(h[i].type4.vno==vno)
               {  flag=true;
                  h[i].type4.display();             
               }
      }
      if(!flag)
      cout<<"\nNot FOund !!! ";
      flag=false;
      getch();
      system("cls");
      cout<<"\nEnter Pincode of the area to display wheelers :";
      cin>>pin;
      for(i=0;i<n;i++) 
      {
          if(h[i].pin==pin)
          {
                  h[i].type2.display();             
                  h[i].type4.display();             
                  flag=true;
          }
      }
      if(!flag)
      cout<<"\nNot FOund !!! ";
       getch();
       system("cls");
       cout<<"\nAll Houses Details :";
       for(i=0;i<n;i++) 
                       h[i].display();
       getch();
       return 1;
}      

