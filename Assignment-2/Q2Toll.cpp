#include<iostream>
using namespace std;

class Toll
{
    private:
        unsigned int totalCars;
        unsigned int totalPayCar;
        double moneyCollected;

    public:
        Toll()
        {
            totalCars=0;
            totalPayCar=0;
            moneyCollected=0;
        }

        void payingCar()
        {
            totalCars++;
            totalPayCar = totalPayCar+1;
            moneyCollected = moneyCollected + 0.50;
            cout<<totalPayCar<<" cars payed."<<endl;
        }

        void noPayCar()
        {
            totalCars = totalCars + 1;
            cout<<totalCars-totalPayCar<<" cars not payed."<<endl;
        }

        void printOnConsole()
        {
            cout<<"Total paying cars = "<<totalPayCar<<endl;
            cout<<"Total non paying cars = "<<totalCars-totalPayCar<<endl;
            cout<<"Total money collected = "<<moneyCollected<<endl;
        }
};

int main()
{
    int select;
    Toll t;

    do
    {
        cout<<"\nMenu: "<<endl;
        cout<<"1. Car payed"<<endl;
        cout<<"2. Car not payed"<<endl;
        cout<<"3. Display record"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>select;

        switch(select)
        {
            case 1:
                t.payingCar();
                break;
            
            case 2:
                t.noPayCar();
                break;

            case 3:
                t.printOnConsole();
                break;

            case 4:
                break;

            default:
                cout<<"Invalid! select again.."<<endl;
                break;
        }
    } while (select!=4);
    
    return 0;
}