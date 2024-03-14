#include <iostream>
using namespace std;

class Employee
{
    private:
        int id;
        float sal;

    public:
        Employee():Employee(0,1000){}

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

        virtual void display()
        {
            cout<<"Id: "<<id<<endl;
            cout<<"Salary: "<<sal<<endl;
        }

        virtual ~Employee()
        {}
};

class Manager:virtual public Employee
{
    private: 
        float bonus;

    protected:
        void accept_Manager()
        {
            cout<<"Enter bonus: ";
            cin>>bonus;
        }


        void display_Manager()
        {
            cout<<"Bonus: "<<bonus<<endl;
        }

    public:
        Manager(){
            bonus=10;
        }

        Manager(int id,float sal,float bonus)
        {
            this->bonus=bonus;
            this->set_id(id);
            this->set_sal(sal);
        }

        void set_bonus(float bonus)
        { this->bonus=bonus; }

        float get_bonus()
        { return bonus; }

        
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

        virtual ~Manager(){}
};

class Salesman:virtual public Employee
{
    private:
        float comm;

    protected:
        void accept_Salesman()
        {
            cout<<"Enter comm: ";
            cin>>comm;
        }

        void display_salesman()
        {
            cout<<"Commission: "<<comm<<endl;
        }

    public:
        Salesman(){}

        Salesman(int id,float sal,float comm)
        {
            this->set_id(id);
            this->set_sal(sal);
            this->comm=comm;
        }

        void set_comm(float comm)
        { this->comm=comm; }

        float get_comm()
        { return comm; }

        
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

        virtual ~Salesman(){}
};

class Sales_Manager:public Manager,public Salesman
{
    public:
        Sales_Manager():Sales_Manager(0,1000,0,0){}

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
            Manager::accept_Manager();
            Salesman::accept_Salesman();
        }

        void display()
        {
            Employee::display();
            Manager::display_Manager();
            Salesman::display_salesman();
        }

        ~Sales_Manager(){}
};

int menu()
{
    int choice;
    cout<<"\n...Menu...."<<endl;
    cout<<"1: Accept employee"<<endl;
    cout<<"2: Display employee"<<endl;
    cout<<"3: Accept manager"<<endl;
    cout<<"4: Display manager"<<endl;
    cout<<"5: Accept salesman"<<endl;
    cout<<"6: Display salesman"<<endl;
    cout<<"7: Accept sales manager"<<endl;
    cout<<"8: Display sales manager"<<endl;
    cout<<"9: Display all"<<endl;
    cout<<"10: Exit"<<endl;
    cout<<"Enter choice : ";
    cin>>choice;
    return choice;

}

int main()
{
    int num,ch,i=0;
    cout<<"How many employees to enter? ";
    cin>>num;
    Employee *earr[num];
    while((ch=menu())!=10)
    {
        switch(ch)
        {
            case 1:
                if(i<num)
                {
                    earr[i]=new Employee();
                    earr[i]->accept();
                    i++; 
                    break;
                }
                else
                {
                    cout<<"No more employees."<<endl;
                    break;
                }
                
            case 2:
                cout<<"\nEmployees: "<<endl;
                for(int j=0;j<i;j++)
                {
                    if(typeid(*earr[j])==typeid(Employee))
                    {
                        earr[j]->display();
                    }
                }
                break;

            case 3:
                if(i<num)
                {
                    earr[i]=new Manager();
                    earr[i]->accept();
                    i++; 
                    break;
                }
                else
                {
                    cout<<"No more employees."<<endl;
                    break;
                }

            case 4:
                cout<<"\nManagers: "<<endl;
                for(int j=0;j<i;j++)
                {
                    if(typeid(*earr[j])==typeid(Manager))
                    {
                        earr[j]->display();
                    }
                }
                break;

            case 5:
                if(i<num)
                {
                    earr[i]=new Salesman();
                    earr[i]->accept();
                    i++; 
                    break;
                }
                else
                {
                    cout<<"No more employees."<<endl;
                    break;
                }

            case 6:
                cout<<"\nSalesmans: "<<endl;
                for(int j=0;j<i;j++)
                {
                    if(typeid(*earr[j])==typeid(Salesman))
                    {
                        earr[j]->display();
                    }
                }
                break;

            case 7:
                if(i<num)
                {
                    earr[i]=new Sales_Manager();
                    earr[i]->accept();
                    i++; 
                    break;
                }
                else
                {
                    cout<<"No more employees."<<endl;
                    break;
                }

            case 8:
                cout<<"\nSalesmanagers: "<<endl;
                for(int j=0;j<i;j++)
                {
                    if(typeid(*earr[j])==typeid(Sales_Manager))
                    {
                        earr[j]->display();
                    }
                }
                break;

            case 9:
                cout<<"\nAll Workers:"<<endl;
                for(int j=0;j<i;j++)
                {
                    earr[j]->display();
                }
                break;
            
            case 10:
                cout<<"Invalid.."<<endl;
                break;
        }  
      
    }
    for(int j=0;j<i;j++)
    {
        delete earr[j];
    }
    return 0;
}