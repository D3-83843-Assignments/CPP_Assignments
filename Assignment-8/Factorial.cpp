#include<iostream>
using namespace std;

int factorial(int n)
{
    int res=1;
    if(n<0)
        throw -1;
    for(int i=1;i<=n;i++)
    {
        res=res*i;
    }
    
    return res;
}

int main()
{
    int result=0,n;
    cout<<"Enter number: ";
    cin>>n;
    try
    {
       result= factorial(n);
    }
    catch(int e)
    {
        cout<<"Factorial for negative number not allowed."<<endl;
    }
    cout<<"Result: "<<result<<endl;
}