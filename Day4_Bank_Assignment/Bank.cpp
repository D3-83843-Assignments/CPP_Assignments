#include <iostream>
using namespace std;

class BankAccount
{
private:
    const int accno;
    string name;
    mutable double balance;
    static int generateAccNo;

public:

    BankAccount():accno(generateAccNo++){}
    
    BankAccount(string name, double balance) : accno(generateAccNo++)
    {
        this->name = name;
        this->balance = balance;
    }

    void createAccount()
    {
        cout<<"Enter name and balace: "<<endl;
        cin>>name>>balance;
        cout<<"Account created."<<endl;
    }

    void displayAccount()
    {
        cout<<"Account details: "<<endl;
        cout<<"Acc no: "<<accno<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    // can i make the deposit function const? yes
    void deposit() const
    {
        int depositMoney;
        cout<<"How much money to deposit? "<<endl;
        cin>>depositMoney;
        balance = balance + depositMoney;
    }

    // can i make the deposit function const? yes
    void withdraw() const
    {
        int withdrawMoney;
        cout<<"How much money to withdraw? "<<endl;
        cin>>withdrawMoney;
        balance = balance - withdrawMoney;
    }

    void checkBalance()
    {
        cout<<"Available balance: "<<balance<<endl;
    }
};
int BankAccount::generateAccNo = 1;

int main()
{
    int ch;
    BankAccount *baptr;
    baptr = new BankAccount();
    do
    {
        cout<<".........Menu........."<<endl;
        cout<<"1. Create account"<<endl;
        cout<<"2. Display account details"<<endl;
        cout<<"3. Deposit amount"<<endl;
        cout<<"4. Withdraw amount"<<endl;
        cout<<"5. Check balance"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<"Enter option: "<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
                baptr->createAccount();
                break;

            case 2:
                baptr->displayAccount();
                break;

            case 3:
                baptr->deposit();
                break;

            case 4:
                baptr->withdraw();
                break;

            case 5:
                baptr->checkBalance();
                break;

            case 6:
                cout<<"Thank you.."<<endl;
                break;

            default:
                cout<<"Invalid.."<<endl;
                break;
        }
    } while (ch!=6);
    delete baptr;
    baptr=NULL;
    return 0;
}