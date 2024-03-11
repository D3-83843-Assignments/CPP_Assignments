#include<iostream>
using namespace std;

class Matrix
{
    int *row;
    int *col;
    int size;
    int **marr;

    public:
        

        Matrix():Matrix(1){}

        Matrix(int size)
        {
            row= new int(size);
            col=new int(size);
            this->size=size;
        }

        void set_row(int size)
        {
            this->row=new int(size);
        }
        int get_row()
        {
            return *row;
        }
        void set_col(int size)
        {
            this->col=new int(size);
        }
        int get_col()
        {
            return *col;
        }

        void acceptMatrix()
        {
            marr=new int*[size];
            for(int i=0;i<*row;i++)
            {
                marr[i]= new int[*col];
            }
            for(int i=0;i<*row;i++)
            {
                for(int j=0;j<*col;j++)
                {
                    cin>>marr[i][j];
                }
            }
            cout<<"Matrix created."<<endl;

        }

        void displayMatrix()
        {
            for(int i=0;i<*row;i++)
            {
                for(int j=0;j<*col;j++)
                {
                    cout<<marr[i][j]<<" ";
                }
                cout<<endl;
            }
            
        }

};

void add(Matrix m1, Matrix m2)
{
    for(int i=0;i<m1.get_row();i++)
    {
        for(int j=0;j<m1.get_col();j++)
        {
            cout<<
        }
    }
}

int main()
{
    int size;
    cout<<"Enter size of matrix: "<<endl;
    cin>>size;

    Matrix m1(size);
    cout<<"Enter values for matrix 1:"<<endl;
    m1.acceptMatrix();
    cout<<endl<<"Matrix 1:"<<endl;
    m1.displayMatrix();

    Matrix m2(size);
    cout<<"Enter values for matrix 1:"<<endl;
    m2.acceptMatrix();
    cout<<endl<<"Matrix 2:"<<endl;
    m2.displayMatrix();
    return 0;
}