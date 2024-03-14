#include<iostream>
using namespace std;

class Insufficient_funds
{
    int accid;
    double current_balance;
    double withdraw_amount;

    public:
        Insufficient_funds(int accid,double current_balance, double withdraw_amount)
        {
            this->accid=accid;
            this->current_balance=current_balance;
            this->withdraw_amount=withdraw_amount;
        }

        void display()
        {
            cout<<"Insufficient funds in account."<<endl;
            cout<<"Account id: "<<accid<<endl;
            cout<<"Current balance: "<<current_balance<<endl;
            cout<<"Withdraw amount: "<<withdraw_amount<<endl;
        }
};

enum account_type
{
    SAVING=1,CURRENT,DMAT
};

class Account
{
    int id;
    account_type type;
    double balance;

    public:
        Account()
        {
            id=1;
            type=SAVING;
            balance=0;
        }

        Account(int id, account_type type,double balance)
        {
            this->id=id;
            this->type=type;
            this->balance=balance;
        }

        void set_id(int id)
        {
            this->id=id;
        }
        int get_id()
        {
            return id;
        }
        void set_type(account_type type)
        {
            this->type=type;
        }
        account_type get_type()
        {
            return type;
        }
        void set_balance(double balance)
        {
            this->balance=balance;
        }
        double get_balance()
        {
            return balance;
        }

        void accept()
        {
            int n;
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter account type: ";
            cout<<"1:Saving 2:current 3:DMAT"<<endl;
            cin>>n;
            if(n==1)
            {
                set_type(SAVING);
            }
            else if(n==2)
            {
                set_type(CURRENT);
            }
            else if(n==3)
            {
                set_type(DMAT);
            }
            else
            {
                throw 4;
            }
            cout<<"Enter balance: ";
            cin>>balance;
        }

        void display()
        {
            cout<<"id: "<<id<<endl;
            cout<<"type of account: "<<type<<endl;
            cout<<"balance: "<<balance<<endl;
        }

        void deposit(double amount)
        {
            balance += amount;
        }

        void withdraw(double amount)
        {
            if(amount>balance)
            {
                throw Insufficient_funds(id,balance,amount);
            }
            balance -= amount;
        }
};

int main()
{
    int ch,i=0;
    int accid,deposit,withdraw;
    Account *a[5];

    do
    {
        cout<<"\n......MENU........."<<endl;
        cout<<"1: Create account "<<endl;
        cout<<"2: Display Account "<<endl;
        cout<<"3: Deposit amount "<<endl;
        cout<<"4: Withdraw amount "<<endl;
        cout<<"5: Display all accounts"<<endl;
        cout<<"0: EXIT"<<endl;
        cout<<"\n Enter your choice: "<<endl;
        cin>>ch;

        switch (ch)
        {
        case 1:
            a[i] = new Account();
            try
            {
                a[i]->accept();
            }
            catch(int e)
            {
                cout<<"Account type not found."<<endl;
            }
            cout<<endl;
            a[i]->display();
            i++;
            break;

        case 2:
            cout<<"Which account to display: ";
            cin>>accid;
            for(int j=0;j<i;j++)
            {
                if(a[j]->get_id()==accid)
                {
                    a[j]->display();
                }
            }
            break;

        case 3:
            cout<<"Enter account to deposit: ";
            cin>>accid;
            cout<<"Enter amount to deposit: ";
            cin>>deposit;
            for(int j=0;j<i;j++)
            {
                if(a[j]->get_id()==accid)
                {
                    a[j]->deposit(deposit);
                    a[j]->display();
                }
            }
            break;

        case 4:
            cout<<"Enter account to withdraw: ";
            cin>>accid;
            cout<<"Enter amount to withdraw: ";
            cin>>withdraw;
            for(int j=0;j<i;j++)
            {
                if(a[j]->get_id()==accid)
                {
                    try{
                        a[j]->withdraw(withdraw);
                        a[j]->display();

                    }catch(Insufficient_funds &insuff_funds)
                    {
                            insuff_funds.display();
                            break;
                    }
                }
            }
            break;

        case 5:
            for(int j=0;j<i;j++)
            {
                a[j]->display();
                cout<<endl;
            }
            break;

        case 0:
            cout<<"Thank you.."<<endl;
            break;
        
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    } while (ch!=0);
    
    for(int j=0;j<i;j++)
    {
        delete a[j];
    }
}