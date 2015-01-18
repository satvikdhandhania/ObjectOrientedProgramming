/*
24. Create a class file (filename, author, program no, prog. name, cyclesheet 1/2/3, verified/not, name of the file to which the 
current file is copied). List out all the files and allow creation of a new file, show the contents and copy one file to another. (m)
*/
#include<iostream>
#include<conio.h>
using namespace std;
class file
{
      char author[30],progname[30],verify[3];
      int pno,cyclesheet;
      public:
             char filename[30],copy[20][30];
             int n;
      file()
      {   n=0; }
      void accept()
      {
           cout<<"\nEnter Details Of File \n\nEnter Filename :";
           fflush(stdin);
           gets(filename);
           cout<<"\nEnter Author :";
           fflush(stdin);
           gets(author);
           cout<<"\nEnter Program No :";
           cin>>pno;
           cout<<"\nEnter Cyclesheet No (1/2/3):";
           cin>>cyclesheet;
           cout<<"\nEnter Program Name :";
           fflush(stdin);
           gets(progname);
           cout<<"\nEnter Verify(yes/no) :";
           fflush(stdin);
           gets(verify);
      }
      void display()
      {    int i;
           cout<<"\n\n\nDetails Of File\nFilename :"<<filename;
           cout<<"\nAuthor :"<<author;
           cout<<"\nProgram No :"<<pno;
           cout<<"\nCyclesheet No (1/2/3):"<<cyclesheet;
           cout<<"\nProgram Name :"<<progname;
           cout<<"\nVerified :"<<verify;
           if(n>0)
           {      cout<<"\nCopied To :";
                  for(i=0;i<n;i++)
                        cout<<"\n"<<copy[i];
           }
           else 
           cout<<"\nFile Not Yet Copied !!!";
      }
}f[20];
int main()
{   int i,n,j,k;
    char name[30];
    cout<<"\nEnter No Of Files :";
    cin>>n;
    for(i=0;i<n;i++)
    {               
                    cout<<"\nEnter Details For File "<<i+1<<" :";
                    f[i].accept();
    }
    while(1)
    {
        cout<<"\n\n\tMENU\n1.Copy\n2.Display\n3.List\n4.Exit\n5.Add File\nEnter Your Choice :";    
        cin>>j;
        switch(j)
        {         
             case 1: cout<<"\nLIST ";
                     for(i=0;i<n;i++) 
                       cout<<"\n"<<i+1<<" :"<<f[i].filename;
                     cout<<"\nEnter Position to copy from and position to store :";
                     cin>>i>>k;
                     i--;k--;
                     if(i<n&&k<n)
                     {
                     strcpy(name,f[k].filename);
                     f[k]=f[i];
                     strcpy(f[i].copy[f[i].n],name);
                     f[i].n++;
                     }
                     else 
                     cout<<"\nOut Of Range !!";
                     break;
             case 2:cout<<"\nDisplay ";
                     for(i=0;i<n;i++) 
                        f[i].display();
                     break;
             case 3:cout<<"\nLIST ";
                     for(i=0;i<n;i++) 
                       cout<<"\n"<<f[i].filename;
                     break;
             case 4:exit(0);
             case 5:cout<<"\nCreating New  File !!!";
                       f[n].accept();
                       n++;
                       break;
             default:cout<<"\nWrong Input ....Try AGain !!" ;
        }
    } 
    getch();
    return 1;
}
