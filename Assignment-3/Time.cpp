#include<iostream>
using namespace std;

class Time
{
    int hour;
    int minute;
    int seconds;

    public:
        Time():Time(1,1,1){}

        Time(int hour,int minute,int seconds)
        {
            this->hour=hour;
            this->minute=minute;
            this->seconds=seconds;
        }

        void setHour(int hour)
        {
            this->hour=hour;
        }
        int getHour()
        {
            return hour;
        }

        void setMinute(int minute)
        {
            this->minute=minute;
        }
        int getMinute()
        {
            return minute;
        }

        void setSeconds(int seconds)
        {
            this->seconds=seconds;
        }
        int getSeconds()
        {
            return seconds;
        }

        void printTime()
        {
            cout<<"H:M:S = "<<hour<<":"<<minute<<":"<<seconds<<endl;
        }

        ~Time(){}
};

int main()
{
    Time *tarr[3];  //pointer array for time objects in dynamic memory
    int h,m,s;
    for(int i=0;i<3;i++)
    {
        cout<<"Enter hour min and sec: "<<endl;
        cin>>h>>m>>s;
        tarr[i]=new Time(h,m,s);
    }
    for(int i=0;i<3;i++)
    {
        //*tarr[i].printTime();
        tarr[i]->printTime();
    }
}