#include<iostream>
using namespace std;

namespace NStudent 
{
    struct Student
    {
        int rollNo;
        string name;
        int marks;

        void initStudent()
        {
            rollNo=0;
            name="unknown";
            marks=0;

        }

        void acceptStudentOnConsole()
        {
            cout<<"Enter student roll no, name and marks: "<<endl;
            cin>>rollNo>>name>>marks;
        }

        void printStudentOnConsole()
        {
            cout<<"Student Roll no: "<<rollNo<<endl;
            cout<<"Student name: "<<name<<endl;
            cout<<"STudent marks: "<<marks<<endl;
            cout<<endl;
        }
    };
}

int main()
{
    struct NStudent::Student s;
    s.initStudent();
    s.acceptStudentOnConsole();
    s.printStudentOnConsole();

    // using namespace NStudent;
    // struct Student s;
    // s.initStudent();
    // s.acceptStudentOnConsole();
    // s.printStudentOnConsole();
}