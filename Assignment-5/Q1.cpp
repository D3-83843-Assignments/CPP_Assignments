#include<iostream>
using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;

    public:

        Date():Date(1,1,0){}

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
        }

        void displayDate()
        {
            cout<<day<<"/"<<month<<"/"<<year<<endl;
        }

        ~Date(){}
};

class Person
{
    private:
        string name;
        string addr;
        Date dob;

    public:
        Person():Person("Unknown","India",1,1,2000){}

        Person(string name,string addr,int day,int month,int year):dob(day,month,year)
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
        void set_dob(Date dob)
        {
            this->dob=dob;
        }
        Date get_dob()
        {
            return dob;
        }

        void AcceptPerson()
        {
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter address: ";
            cin>>addr;
            cout<<"Enter date of birth: ";
            dob.acceptDate();
        }

        void displayPerson()
        {
            cout<<"Name: ";
            cin>>name;
            cout<<"Address: ";
            cin>>addr;
            cout<<"Date of birth: ";
            dob.displayDate();
        }

        ~Person(){}
};

class Employee:public Person
{
    private:
        int emp_id;
        float sal;
        string dept;
        Date doj;

    public:
        Employee():Employee(1,10000,"Regular",1,1,2024){}

        Employee(int emp_id,float sal,string dept,int day,int month,int year):doj(day,month,year)
        {
            this->emp_id=emp_id;
            this->sal=sal;
            this->dept=dept;
        }

        void set_emp_id(int emp_id)
        {
            this->emp_id=emp_id;
        }
        int get_emp_id()
        {
            return emp_id;
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
        void set_doj(Date doj)
        {
            this->doj=doj;
        }
        Date get_doj()
        {
            return doj;
        }

        void acceptEmp()
        {
            Person::AcceptPerson();
            cout<<"Enter emp id: ";
            cin>>emp_id;
            cout<<"Enter salary: ";
            cin>>sal;
            cout<<"Enter department: ";
            cin>>dept;
            cout<<"Enter joining date: ";
            doj.acceptDate();
        }

        void displayEmp()
        {
            cout<<"Name: "<<get_name()<<endl;
            cout<<"Emp id: "<<emp_id<<endl;
            cout<<"Salary: "<<sal<<endl;
            cout<<"Department: "<<dept<<endl;
            cout<<"Joining date: ";
            doj.displayDate();
            cout<<"Address: "<<get_addr()<<endl;
            cout<<"Date of birth: ";
            Person::get_dob().displayDate();
        }

        ~Employee(){}
};

int main()
{
    Employee emp;
    emp.acceptEmp();
    emp.displayEmp();

    Person p;
    p.AcceptPerson();
    p.displayPerson();

    Date d;
    d.acceptDate();
    d.displayDate();

}