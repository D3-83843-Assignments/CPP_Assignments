#include<iostream>
using namespace std;

template <class T>
class Stack
{
    int size;
    T *stack=new T[size];    
    int top;
    T element;

    public:
        Stack(){
            this->size=5;
            this->top=-1;
            this->element=0;
        }

        Stack(int size,int top,T element)
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

        void push(T ele)
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

class Box
{
    private:
        int length;
        int breadth;

    public:
        Box(){
            length=10;
            breadth=10;
        }

        Box(int length,int breadth)
        {
            this->length=length;
            this->breadth=breadth;
        }
};

int main()
{
    Stack <int>s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout<<"Stack s1: "<<endl;
    s1.display();
    s1.pop();
    s1.pop();
    cout<<"Stack s1 after pop: "<<endl;
    s1.display();

    cout<<endl;
    Stack <double>s2(5,-1,10.2);
    s2.push(10.2);
    s2.push(20.3);
    s2.push(30.4);
    s2.push(40.5);
    s2.push(50.6);
    cout<<"Stack s2: "<<endl;
    s2.display();
    s2.pop();
    s2.pop();
    cout<<"Stack s2 after pop: "<<endl;
    s2.display();

}