#include<iostream>
using namespace std;

namespace ns
{
    struct Date
    {
        int date;
        int month;
        int year;

        void initDate()
        {
            date=1;
            month=1;
            year=2000;
        }

        void acceptDateOnConsole()
        {
            cout<<" Enter date, month, year: ";
            cin>>date>>month>>year;
        }

        void printDateOnConsole()
        {
            cout<<"\nDate: "<<date<<" / " <<month<<" / "<<year<<endl;
        }

        bool isLeapYear()
            {
                if(year%4==0)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
    };
}

namespace nc
{
    class Date
    {
        private:
            int date;
            int month;
            int year;

        public:
            void initDate()
            {
                date=1;
                month=1;
                year=2000;
            }

            void acceptDateOnConsole()
            {
                cout<<" Enter date, month, year: ";
                cin>>date>>month>>year;
            }

            void printDateOnConsole()
            {
                cout<<"\nDate: "<<this->date<<" / " <<this->month<<" / "<<this->year<<endl;
            }

            bool isLeapYear()
            {
                if(year%4==0)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
    };
}

int main()
{
    int choice;
    
    do{
        cout<<"0.EXIT"<<endl;
        cout<<"1.using class"<<endl;
        cout<<"2.using structure"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
            
        case 1:

            nc::Date d_class;
            d_class.acceptDateOnConsole();
            d_class.printDateOnConsole();
            if(d_class.isLeapYear()==0)
            {
                cout<<"It is a leap year."<<endl;
            }
            else{
                cout<<"It is not a leap year."<<endl;
            }
            break;

        case 2:
            struct ns::Date d_struct;
            d_struct.acceptDateOnConsole();
            d_struct.printDateOnConsole();
            if(d_struct.isLeapYear()==0)
            {
                cout<<"It is a leap year."<<endl;
            }
            else{
                cout<<"It is not a leap year."<<endl;
            }
            break;
        
        default:
            printf("Invalid choice..");
            break;

        }

    }
    while (choice!=0);
    printf("Thank you..");
    
    return 0;
}