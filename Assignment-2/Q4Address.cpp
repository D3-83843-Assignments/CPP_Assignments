#include<iostream>
using namespace std;

class Address
{
    private:
        string building;
        string street;
        string city;
        int pin;

    public:
        //constructor
        Address():Address("unknown","unknown","unknown",101010) {}
       
        Address(string building,string street,string city,int pin)
        {
            this->building=building;
            this->street=street;
            this->city=city;
            this->pin=pin;
        }

        //setters and getters
        void setBuilding(string building)
        {
            this->building=building;
        }

        string getBuilding()
        {
            return building;
        }

        void setStreet(string street)
        {
            this->street=street;
        }

        string getStreet()
        {
            return street;
        }

        void setCity(string city)
        {
            this->city=city;
        }

        string getCity()
        {
            return city;
        }

        void setPin(int pin)
        {
            this->pin=pin;
        }

        int getPin()
        {
            return pin;
        }

        //Accept
        void acceptData()
        {
            cout<<"Enter building street city and pin: "<<endl;
            cin>>building>>street>>city>>pin;
            cout<<"Address entered."<<endl;
        }

        //display
        void displayAddress()
        {
            cout<<"Address : "<<endl;
            cout<<building<<", "<<street<<", "<<city<<", "<<pin<<endl;
        }

};

int main()
{
    //using parameterless constructor
    Address a1;
    a1.acceptData();
    a1.displayAddress();
    cout<<endl;

    //using parameterized constructor
    Address a2("MetroLife","Phase1","Pune",145146);
    a2.displayAddress();
    cout<<endl;
    
    //using getter setter
    Address a3;
    a3.setBuilding("Sunbeam");
    a3.setStreet("Phase 2");
    a3.setCity("Pune");
    a3.setPin(444000);
    cout<<"Building: "<<a3.getBuilding()<<endl;
    cout<<"Street: "<<a3.getStreet()<<endl;
    cout<<"City: "<<a3.getCity()<<endl;
    cout<<"Pin: "<<a3.getPin()<<endl;

}