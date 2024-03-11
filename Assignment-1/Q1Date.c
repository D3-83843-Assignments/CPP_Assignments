#include<stdio.h>

struct Date
{
    int date;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->date=1;
    ptrDate->month=1;
    ptrDate->year=2001;
    printf("\nDone initialization.");
}

void acceptDateOnConsole(struct Date *ptrDate)
{
    printf("\nEnter day, month and year: ");
    scanf("%d %d %d",&ptrDate->date,&ptrDate->month,&ptrDate->year);
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("\nDate: %d:%d:%d",ptrDate->date,ptrDate->month,ptrDate->year);
}

int main()
{
    struct Date d;
    int choice;

    do
    {
        printf("\n0.Exit");
        printf("\n1.Initialize Date");
        printf("\n2.Accept date:");
        printf("\n3.Display date:");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
                initDate(&d);
                break;
            
            case 2:
                acceptDateOnConsole(&d);
                break;

            case 3:
                printDateOnConsole(&d);
                break;

            default:
                printf("\nInvalid choice... ");
        }
    }
    while(choice!=0);
    printf("\nThank you..");
    return 0;
}