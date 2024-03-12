#include<iostream>
using namespace std;

enum EMenu
{
    BOOK=1,TAPE,BILL,EXIT
};

class Product
{
    protected:
        int id;
        string title;
        double price;

    public:
        void set_id(int id)
        {
            this->id=id;
        }
        int get_id()
        {
            return id;
        }
        void set_title(string title)
        {
            this->title=title;
        }
        string get_title()
        {
            return title;
        }
        void set_price(double price)
        {
            this->price=price;
        }
        double get_price()
        {
            return price;
        }

        virtual void accept()=0;

        virtual void display()=0;
       
};

class Book:public Product
{
    private:
        string author;

    public:
        Book():Book("Unknown"){}

        Book(string author)
        {
            this->author=author;
        }

        void accept()
        {
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter title: ";
            cin>>title;
            cout<<"Enter author: ";
            cin>>author;
            cout<<"Enter price: ";
            cin>>price;
        }

        void display()
        {
            cout<<"Id: "<<id<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Author: "<<author<<endl;
        }
};

class Tape:public Product
{
    private:
        string artist;

    public:
        Tape():Tape("Unknown"){}

        Tape(string artist)
        {
            this->artist=artist;
        }

        void accept()
        {
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter title: ";
            cin>>title;
            cout<<"Enter artist: ";
            cin>>artist;
            cout<<"Enter price: ";
            cin>>price;
        }

        void display()
        {

            cout<<"Id: "<<id<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Artist: "<<artist<<endl;
        }
};

int main()
{
    int choice,i=0,num;
    double bookPrice=0,tapePrice=0,OriginalTotal,FinalPrice;

    cout<<"Enter number of products: ";
    cin>>num;
    Product *prodptr[num];
    do
    {
        cout<<"....CHECKOUT........"<<endl;
        cout<<"1: BOOK "<<endl;
        cout<<"2: TAPE "<<endl;
        cout<<"3. BILL "<<endl;
        cout<<"4: EXIT "<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        cout<<endl;
        switch(EMenu(choice))
        {
            case BOOK:
                if(i<num)
                {   
                    cout<<"i: "<<i<<endl;
                    prodptr[i]=new Book();
                    prodptr[i]->accept();
                    bookPrice= bookPrice + prodptr[i]->get_price();
                    cout<<prodptr[i]->get_price()<<endl;
                    i++;
                    break;
                }
                else
                {
                    cout<<"Bag full."<<endl;
                    break;
                }
                
            case TAPE:
                if(i<num)
                {
                    cout<<i<<endl;
                    prodptr[i]=new Tape();
                    prodptr[i]->accept();
                    prodptr[i]->display();

                    tapePrice = tapePrice + prodptr[i]->get_price();
                    cout<<prodptr[i]->get_price()<<endl;
                    i++;
                    break;
                }
                else
                {
                    cout<<"Bag full."<<endl;
                    break;
                }

            case BILL:
                OriginalTotal=bookPrice+tapePrice;
                bookPrice= (bookPrice) -(bookPrice*10/100);
                tapePrice= (tapePrice) -(tapePrice*5/100);
                FinalPrice= bookPrice+tapePrice;

                //Bill
                for(int j=0;j<i;j++)
                {
                    prodptr[j]->display();
                    cout<<endl;
                }
                cout<<"Total price: "<<OriginalTotal<<endl;
                cout<<"Discount: "<<(bookPrice*10/100)+(tapePrice*5/100)<<endl;
                cout<<"Final total: "<<FinalPrice<<endl;
                break;

            case EXIT:
                cout<<"Thank you"<<endl;
                break;

            default:
                cout<<"Invalid.."<<endl;
        }
    } 
    while(EMenu(choice)!=4);

    for(int j=0;j<num;j++)
    {
        delete prodptr[j];
    }
}