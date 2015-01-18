
/*
  Create 2 classes one holding the personal details of the student (like regno, school, branch, address and phone no) 
  and another holding the students academic performance (regno, semester, backlogs, CGPA, remarks). Inherit the classes personal 
  and academic performance in a new class communication (communication ID, date, and sent by). Display the communication object 
  to the parent with all the information. (Note : Use necessary constructors) (m)
*/
#include<conio.h>
#include<iostream.h>
class student
{
      public:
             int regno;
             char name[30],branch[10],school[10],address[50];
             long long int phone;
             student()
             {
                      cout<<"\nEnter Registration Number :";
                      cin>>regno;
                      cout<<"\nEnter Name :";
                      fflush(stdin);
                      gets(name);
                      cout<<"\nEnter Branch :";
                      fflush(stdin);
                      gets(branch);
                      cout<<"\nEnter School :";
                      fflush(stdin);
                      gets(school);
                      cout<<"\nEnter Address :";
                      fflush(stdin);
                      gets(address);
                      cout<<"\nEnter Phone Number :";
                      cin>>phone;
             }
};
class academic
{
      public:
             int semester,backlogs;
             char remarks[30];
             float cgpa;
             academic()
             {
                      cout<<"\nEnter Semesterr :";
                      cin>>semester;
                      cout<<"\nEnter Backlogs :";
                      cin>>backlogs;
                      cout<<"\nEnter CGPA :";
                      cin>>cgpa;
                      cout<<"\nEnter Remarks :";
                      fflush(stdin);
                      gets(remarks);
             }
};
class communicate:public student,public academic
{
      public:
             int id;
             char date[30],sentby[30];
             communicate()
             {
                          cout<<"\nEnter Communication ID :";
                          cin>>id;
                          cout<<"\nEnter Date :";
                          fflush(stdin);
                          gets(date);
                          cout<<"Enter Sent BY :";
                          fflush(stdin);
                          gets(sentby);
             }
             ~communicate()
             {        cout<<"\n\tDISPLAYING OBJECT DETAILS !!!";
                      cout<<"\nRegistration Number :"<<regno;
                      cout<<"\nName :";
                      puts(name);
                      cout<<"Branch :";
                      puts(branch);
                      cout<<"\nSchool :";
                      puts(school);
                      cout<<"Address :";
                      puts(address);
                      cout<<"\nPhone Number :"<<phone;
                      cout<<"\nSemesterr :"<<semester;
                      cout<<"\nBacklogs :"<<backlogs;
                      cout<<"\nCGPA :"<<cgpa;
                      cout<<"\nRemarks :";
                      puts(remarks);
                      cout<<"\nCommunication ID :"<<id;
                      cout<<"\nDate :";
                      puts(date);
                      cout<<"Sent BY :";
                      puts(sentby);
                      getch();
             }
};
int main()
{
    communicate ob;
    return 1;
}
