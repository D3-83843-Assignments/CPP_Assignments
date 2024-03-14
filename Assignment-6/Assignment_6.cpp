#include <iostream>
using namespace std;

class Employee
{
    private:
        int id;
        float sal;

    public:
        Employee():Employee(0,1000){
            cout<<"employee constructor."<<endl;
        }

        Employee(int id, float sal)
        {
            this->id=id;
            this->sal=sal;
        }

        void set_id(int id){ this->id=id; }
        int get_id(){ return id; }
        void set_sal(float sal){ this->sal=sal; }
        int get_sal(){ return sal; }

        virtual void accept()
        {
            cout<<"Enter id:";
            cin>>id;
            cout<<"Enter salary: ";
            cin>>sal;
        }

        void display()
        {
            cout<<"Id: "<<id<<endl;
            cout<<"Salary: "<<sal<<endl;
        }
};

class Manager:virtual public Employee
{
    protected: 
        float bonus;

    public:
        Manager():Manager(0){
            cout<<"manager constructor."<<endl;
        }

        Manager(float bonus)
        {
            this->bonus=bonus;
        }

        void set_bonus(float bonus){ this->bonus=bonus; }
        float get_bonus(){ return bonus; }

        void accept()
        {
            Employee::accept();
            cout<<"Enter bonus: ";
            cin>>bonus;
        }

        void display()
        {
            Employee::display();
            cout<<"Bonus: "<<bonus<<endl;
        }
};

class Salesman:virtual public Employee
{
    protected:
        float comm;

    public:
        Salesman():Salesman(100){
            cout<<"Salesman constructor."<<endl;
        }

        Salesman(float comm)
        {
            this->comm=comm;
        }

        void set_comm(float comm){ this->comm=comm; }
        float get_comm(){ return comm; }

        void accept()
        {
            Employee::accept();
            cout<<"Enter comm: ";
            cin>>comm;
        }

        void display()
        {
            Employee::display();
            cout<<"Commision: "<<comm<<endl;
        }
};

class Sales_Manager:public Manager,public Salesman
{
    public:
        Sales_Manager():Sales_Manager(0,1000,0,0){
            cout<<"Sales manager constructor."<<endl;
        }

        Sales_Manager(int id,float sal,float bonus, float comm)
        {
            set_id(id);
            set_sal(sal);
            set_bonus(bonus);
            set_comm(comm);
        }

        void accept()
        {
            Employee::accept();
            cout<<"Enter bonus: ";
            cin>>bonus;
            cout<<"Enter commission: ";
            cin>>comm;
        }

        void display()
        {
            Employee::display();
            cout<<"Bonus: "<<bonus;
            cout<<"Commision: "<<comm;
        }
};

int main()
{
    Employee *e=new Employee();
    e->accept();

    e=new Manager(); //upcasting
    Manager *m=dynamic_cast<Manager *>(e);
    m->accept();

    Employee *e1=new Employee();
    Sales_Manager *sm=dynamic_cast<Sales_Manager *>(e1);  
    //Sales_Manager *sm=dynamic_cast<Manager *>(m); //no polymorphic class
    sm->accept();

}