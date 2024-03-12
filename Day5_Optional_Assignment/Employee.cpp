#include<iostream>
using namespace std;

enum Eemp
{
    ACCEPT=1,
    DISPLAY,
    FIND,
    EXIT
};

class Employee
{
    int const eId;
    string eName;
    double eSal;
    static int generateEmpId;

    public:
        Employee():eId(generateEmpId++){}

        Employee(string eName, double eSal):eId(generateEmpId++)
        {
            this->eName=eName;
            this->eSal=eSal;
        }

        int getEid()
        {
            return eId;
        }

        void acceptEmp()
        {
            cout<<"Enter employee details: name , salary"<<endl;
            cin>>eName>>eSal;
            cout<<"Employee added."<<endl<<endl;
        }

        void displayEmp()
        {
            cout<<" Employee details: "<<endl;
            cout<<"Employee id: "<<eId<<endl;
            cout<<"Employee name: "<<eName<<endl;
            cout<<"Employee salary: "<<eSal<<endl;
            cout<<endl;
        }
};
int Employee::generateEmpId=1000;

int main()
{
    int n;
    cout<<"Enter number of employees: "<<endl;
    cin>>n;

    Employee *eptr[n];
    int i=0,eid,ch;
    do
    {
        eptr[i] = new Employee;
    
        cout<<"...MENU...."<<endl;
        cout<<"1.Add employee"<<endl;
        cout<<"2.Show all employees"<<endl;
        cout<<"3.Find employee"<<endl;
        cout<<"4.EXIT"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        switch (Eemp(ch))
        {
        case ACCEPT:
            eptr[i]->acceptEmp();
            i++;
            break;
        
        case DISPLAY:
            for(int j=0;j<i;j++)
            {
                eptr[j]->displayEmp();
            }
            break;

        case FIND:
            cout<<"Enter employee id: "<<endl;
            cin>>eid;
            for(int j=0;j<i;j++)
            {
                if(eid==eptr[j]->getEid())
                {
                    eptr[j]->displayEmp();
                }
            }

        case EXIT:
            cout<<"Thank you.."<<endl;
            break;

        default:
            cout<<"Invalid.."<<endl;
            break;
        }
    } while(Eemp(ch)!=EXIT);
    
}