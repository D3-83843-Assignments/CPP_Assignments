#include<iostream>
using namespace std;

enum EMenu
{
    ACCEPT=1, PRINT, SEARCH, SORT,EXIT
};

class Student
{
    string name;
    string gender;
    int rollNumber;
    int *marks=new int[3]{0,0,0};
    float percentage;

    public:
        Student():Student("unknown","NA",00){}

        Student(string name,string gender,int rollNumber)
        {
            this->name=name;
            this->gender=gender;
            this->rollNumber=rollNumber;
        }

        void set_name(string name)
        {
            this->name=name;
        }
        string get_name()
        {
            return name;
        }
        void set_rollNumber(int rollNumber)
        {
            this->rollNumber=rollNumber;
        }
        int get_rollNUmber()
        {
            return rollNumber;
        }

        void acceptMarks()
        {
            float sum=0;
            cout<<"Enter marks for CPP, JAVA and OS: "<<endl;
            for(int i=0;i<3;i++)
            {
                cin>>marks[i];
                sum+=marks[i];
            }
            percentage= sum /3;
        }

        void accept()
        {
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter gender: ";
            cin>>gender;
            cout<<"Enter roll no: ";
            cin>>rollNumber;
            acceptMarks();
        }

        void print()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Roll no: "<<rollNumber<<endl;
            cout<<"Gender: "<<gender<<endl;
            cout<<"Percentage: "<<percentage<<endl;
            cout<<endl;
        }
};

void sortRecords(Student arr[],int no)
{
    Student min;
    for(int j=0;j<no;j++)
    {
        for(int k=j+1;k<no;k++)
        {
            if(arr[k].get_rollNUmber()<arr[j].get_rollNUmber())
            {
                min=arr[k];
                arr[k]=arr[j];
                arr[j]=min;
            }
        }
    }
    cout<<"Records sorted."<<endl;
}

int searchRecords(Student arr[],int no)
{   
    int rollno,flag=-1;
    cout<<"Enter roll number of student: ";
    cin>>rollno;

    for(int i=0;i<no;i++)
    {
        if(rollno==arr[i].get_rollNUmber())
        {
            flag=i;
        }
    }
    return flag;
}

int main()
{
    int num,ch,index;
    cout<<"Enter number of students: ";
    cin>>num;
    Student arr[num];
    int i=0;
    do
    {
        cout<<"-----MENU-----"<<endl;
        cout<<"1. Accept student"<<endl;
        cout<<"2. Print studnts"<<endl;
        cout<<"3. Search student"<<endl;
        cout<<"4. Sort student"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        switch(EMenu(ch))
        {
            case 1:
                if(i>=num)
                {
                    cout<<"No more students accepted."<<endl;
                }
                else
                {
                    arr[i].accept();
                    i++;
                }
                break;

            case 2:
                for(int j=0;j<i;j++)
                {
                    arr[j].print();
                }
                break;

            case 3:
                index=searchRecords(arr,i);
                if(index==-1)
                {
                    cout<<"Student not found."<<endl;
                }
                else{
                    cout<<"Student found at index "<<index<<endl;
                    cout<<"Name of student: "<<arr[index].get_name()<<endl;
                }
                break;

            case 4:
                sortRecords(arr,i);
                break;

                case 5:
                    cout<<"THANK YOU."<<endl;
                    break;

        }

    } while (EMenu(ch)!=5);
    
}