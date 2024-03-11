#include<iostream>
using namespace std;

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


int main()
{
    struct Student s;
    int ch;
    
    do
    {
        cout<<"1.Initialize student"<<endl;
        cout<<"2.Accept student"<<endl;
        cout<<"3.Print student"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
                s.initStudent();
                break;

            case 2:
                s.acceptStudentOnConsole();
                break;

            case 3:
                s.printStudentOnConsole();
                break;

            case 4:
                cout<<"Thank you!"<<endl;

            default:
                cout<<"Invalid choice."<<endl;
                break;

        }
    } while (ch!=4);
    
}