/*25. Create a class file (filename, author, type of file, no.of words, same_as) and
compare 2 files to find whether they are having exactly the same content. If so, then
update the same as field of the file with the filenames to which this file is similar to.
Allow the searching of files based on type and no. of words in it. Also handle the file
not found exception. (m)*/
#include<iostream>
#include<conio.h>
#include <fstream>
#include <cstring>
using namespace std;
class file
{
      public:
      char filename[20],author[20],type[20],text[50],sameas[10][20];
      int count,n;
      file(){n=0;}
};
int main()
{   
     int n,i,j,k,flag=0;
     char type[20];
     cout<<"enter no. of files to be created\t";cin>>n;
     file ob1[n],ob[n];
     for(i=0;i<n;i++)
     {
      cout<<"enter file name\t";cin>>ob[i].filename;
      fflush(stdin);
      cout<<"enter name of author\t";cin>>ob[i].author;
      cout<<"enter type of file\t";cin>>ob[i].type;
      cout<<"enter number of words\t";cin>>ob[i].count;
      cout<<"enter text in file\t";cin>>ob[i].text;
      }
      // write data
      for(i=0;i<n;i++)
     {
      ofstream outbal(ob[i].filename,ios::out | ios::binary);
      outbal.write((char*)&ob[i],sizeof(file));
      outbal.close();
      }
      for(i=0;i<n;i++)
      {
      ifstream infile(ob[i].filename,ios::in | ios::binary);
      infile.read((char*)&ob1[i],sizeof(file));
      cout<<"\n"<<ob1[i].filename;
      cout<<"\n"<<ob1[i].author;
      cout<<"\n"<<ob1[i].type;
      cout<<"\n"<<ob1[i].count;
      cout<<"\n"<<ob1[i].text;
      cout<<"\n-----------------\n";
      }
  for(j=0;j<n-1;j++)
   for(k=j+1;k<n;k++)
   {
        if((strcmp(ob1[j].author,ob1[k].author)==0)&&(strcmp(ob1[j].type,ob1[k].type)==0)&&(strcmp(ob1[j].text,ob1[k].text)==0)&&(ob1[j].count==ob1[k].count))
        {
              cout<<"\nduplicate file found so update file\n";
                  strcpy(ob1[j].sameas[ob1[j].n],ob1[k].filename);
                  ob1[j].n++;
                  strcpy(ob1[k].sameas[ob1[k].n],ob1[j].filename);
                  ob1[k].n++;        
        }
   }
      for(i=0;i<n;i++)
      {
      cout<<"\n"<<ob1[i].filename;
      cout<<"\n"<<ob1[i].author;
      cout<<"\n"<<ob1[i].type;
      cout<<"\n"<<ob1[i].count;
      cout<<"\n"<<ob1[i].text;
      for(j=0;j<ob1[i].n;j++)
                             cout<<"\nSame As :"<<ob1[i].sameas[j];
      cout<<"\n-----------------\n";
      }        
      cout<<"enter the file type & word count u want to search for ";cin>>type;
      cin>>k;
  try
  {        
      for(i=0;i<n;i++)
      {
      if((strcmp(ob1[i].type,type)==0)&&(ob1[i].count==k))
      {
       flag=1;
       cout<<"file found !!";
       cout<<"\n"<<ob1[i].filename;
       cout<<"\n"<<ob1[i].author;
       cout<<"\n"<<ob1[i].type;
       cout<<"\n"<<ob1[i].count;
       cout<<"\n"<<ob1[i].text;
      for(j=0;j<ob1[i].n;j++)
                             cout<<"\nSame As :"<<ob1[i].sameas[j];
       cout<<"\n-----------------\n";
      }
  }
      if(flag==0)
      { throw "file not found";}
      }
      catch(const char *str)
      {
                  cout<<"\ncaught a string:"<<str;
                  }
      getch();
      return 0;
}
                          
         
