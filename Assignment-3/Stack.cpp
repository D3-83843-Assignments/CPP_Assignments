#include<iostream>
using namespace std;

enum Estack
{
    PUSH=1,
    POP,
    PEEK,
    DISPLAY,
    EXIT
};

class Stack
{
    int size;
    int *stack=new int[size];    
    int top;
    int element;

    public:
        Stack():Stack(5,-1,0){}

        Stack(int size,int top,int element)
        {
            this->size=size;
            this->top=top;
            this->element=element;
        }

        void setSize(int size)
        {
            this->size=size;
        }
        int getSize()
        {
            return size;
        }

        void push(int ele)
        {
            if(isEmpty()==true)
            {
                stack[top+1]=ele;
                top++;
            }
            else{
                cout<<"Stack overflow"<<endl;
            }
        }

        void pop()
        {
            if(isFull()==true)
            {
                cout<<"Pop: "<<stack[top]<<endl;
                stack[top]=0;
                top--;
            }
            else
            {
                cout<<"Stack underflow"<<endl;
            }
        }

        void peek()
        {
            cout<<"Top element: "<<stack[top]<<endl;
        }

        void display()
        {
            int i=0;
            while(i<=top)
            {
                cout<<"stack["<<i<<"]: "<<stack[i]<<endl;
                i++;
            }
        }

        bool isFull()
        {
            if(top==size-1)
            {
                return true;
            }
            else{
                return false;
            }
        }

        bool isEmpty()
        {
            if(top<size-1)
            {
                return true;
            }
            else{
                return false;
            }
        }
};

int main()
{
    int size,ele,num,ch;
    Stack s;
    cout<<"Enter size of stack: ";
    cin>>size;
    s.setSize(size);
    do
    {
        cout<<"......Stack operations......."<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display stack"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(Estack(ch))
        {
            case PUSH:
                cout<<"Enter no of elements to push: ";
                cin>>num;
                if(num>s.getSize())
                {
                    cout<<"Size is larger than expected."<<endl;
                }
                else{
                    for(int i=0;i<num;i++)
                    {
                        cout<<"Enter element "<<i<<" to push: ";
                        cin>>ele;
                        s.push(ele);
                    }
                }
                break;

            case POP:
                s.pop();
                break;

            case PEEK:
                s.peek();
                break;

            case DISPLAY:
                s.display();
                break;

            case EXIT:
                cout<<"Thank you..."<<endl;
                break;

            default:
                cout<<"Invalid option.."<<endl;
                break;
        }
    }
    while(Estack(ch)!=5);
}