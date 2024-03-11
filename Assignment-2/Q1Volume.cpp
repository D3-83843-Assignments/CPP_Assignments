#include<iostream>
using namespace std;

class volume
{
    private:
        int length;
        int width;
        int height;
        int vol;

    public:
        volume()
        {
            this->length=1;
            this->width=1;
            this->height=1;
        }

        void acceptData()
        {
            cout<<" Enter length, width and height: "<<endl;
            cin>>length>>width>>height;
        }

        void calcVolume()
        {
            this->vol=length*width*height;
            cout<<"Volume calculated."<<endl;
        }

        void displayVolume()
        {
            cout<<" Volume of the box = "<<this->vol<<endl;
        }
};

int main()
{
    int ch;
    volume v;
    do
    {
        cout<<"\n1. Enter data "<<endl;
        cout<<"2. Calculate volume"<<endl;
        cout<<"3. Display volume"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;

        switch (ch)
        {
        case 1:
            v.acceptData();
            break;

        case 2:
            v.calcVolume();
            break;

        case 3:
            v.displayVolume();
            break;
        
        case 4:
            break;
            
        default:
            cout<<"Invalid..."<<endl;
            break;
        }
    } while (ch!=4);
    
    
}