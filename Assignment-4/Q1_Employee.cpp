#include<iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

    public:
        Date():Date(1,1,2000){}

        Date(int day,int month,int year)
        {
            this->day=day;
            this->month=month;
            this->year=year;
        }

        void set_day(int day)
        {
            this->day=day;
        }
        int get_day()
        {
            return day;
        }
        void set_month(int month)
        {
            this->month=month;
        }
        int get_month()
        {
            return month;
        }
        void set_year(int year)
        {
            this->year=year;
        }
        int get_year()
        {
            return year;
        }

        void acceptDate()
        {
            cout<<"Enter day: ";
            cin>>day;
            cout<<"Enter month: ";
            cin>>month;
            cout<<"Enter year: ";
            cin>>year;
            cout<<endl;
        }

        void displayDate()
        {
            cout<<"Date: "<<day<<"/"<<month<<"/"<<year<<endl;
        }

        ~Date(){}
};

class Person
{
    string name;
    string addr;
    Date dob;

    public:
        Person():Person("unknown","India",1,1,2000){}

        Person(string name, string addr)
        {
            this->name=name;
            this->addr=addr;
        }

        Person(string name, string addr,int day,int month,int year):dob(day,month,year)
        {
            this->name=name;
            this->addr=addr;
        }

        void set_name(string name)
        {
            this->name=name;
        }
        string get_name()
        {
            return name;
        }
        void set_addr(string addr)
        {
            this->addr=addr;
        }
        string get_addr()
        {
            return addr;
        }

        void set_birth_date(Date d)
        {
            Date dob(d);
        }
        Date get_birth_date()
        {
            return dob;
        }

        void accept()
        {
            cout<<"Enter name of person:";
            cin>>name;
            cout<<"Enter address: ";
            cin>>addr;
            cout<<"Enter date of birth: ";
            dob.acceptDate();
        }

        void display()
        {
            cout<<"Name of person: "<<name<<endl;
            cout<<"Address: "<<addr<<endl;
            dob.displayDate();
            cout<<endl;
        }

        ~Person(){}
};

class Employee
{
    int id;
    float sal;
    string dept;
    Date doj;

    public:
        Employee():Employee(1,100,"regular",15,3,2021){}

        Employee(int id, float sal, string dept)
        {
            this->id=id;
            this->sal=sal;
            this->dept=dept;
        }

        Employee(int id,float sal,string dept,int day,int month,int year):doj(day,month,year)
        {
            this->id=id;
            this->sal=sal;
            this->dept=dept;
        }

        void set_id(int id)
        {
            this->id=id;
        }
        int get_is()
        {
            return id;
        }
        void set_sal(float sal)
        {
            this->sal=sal;
        }
        float get_sal()
        {
            return sal;
        }
        void set_dept(string dept)
        {
            this->dept=dept;
        }
        string get_dept()
        {
            return dept;
        }

        void set_joining_date(Date d)
        {
            Date doj(d);
        }
        Date get_joining_date()
        {
            return doj;
        }

        void accept()
        {
            cout<<"Enter emp id: ";
            cin>>id;
            cout<<"Enter emp salary: ";
            cin>>sal;
            cout<<"Enter emp department: ";
            cin>>dept;
            cout<<"Enter joining date: ";
            doj.acceptDate();
        }

        void display()
        {
            cout<<"Emp id: "<<id<<endl;
            cout<<"Emp salary: "<<sal<<endl;
            cout<<"Emp dept: "<<dept<<endl;
            doj.displayDate();
        }

        ~Employee(){}
};

int main()
{
    //Using default employee, person
    Employee e;
    e.accept();
    e.display();

    Person p;
    p.accept();
    p.display();

    //Employees
    Employee e1(1,20000,"Development",1,2,2000);
    e1.display();

    Employee e2(2,10000,"IT");
    e2.display();

    Employee e3;
    e3.display();

    //Person
    Person p;
    p.display();

    Person p1;
    p1.accept();
    p1.display();

    Person p2("XYZ","Mumbai",19,3,1975);
    p2.display();

    Person p3("Ayu","Nagpur");
    p3.display();


    return 0;
}
