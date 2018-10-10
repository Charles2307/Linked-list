#include<iostream>
using namespace std;
#define Max 5
class Queue
{
    public:
    int Front;
    int Rear;
    int a[Max];
    Queue()
    {
        Front=-1;
        Rear=-1;
    }
    void Push(int x)
    {
        if(Front==0&&Rear==Max)
        {
            cout<<"\nOVERFLOW\n";
        }
        if(Front==-1)
        {
            Front=0;Rear=0;
        }
        else
        {
            if(Rear==Max-1)
            {
                Rear=0;
            }
            else
            {
                Rear=Rear+1;
            }
        }
        a[Rear]=x;
    }
    int Pop()
    {
        if(Front==-1)
        {
            cout<<"\nUNDERFLOW\n";
            return 0;
        }
        int c=a[Front];
        if(Front==Rear)
        {
                Front=-1;
                Rear=-1;

        }
        else
        {
            if(Front==Max-1)
            {
                Front=0;
            }
            else
            {
            Front+=1;
            }
        }
        return c;
    }
    void Display()
    {
        if (Front<Rear)
        {
            for(int i=Front;i<=Rear;i++)
            {
                cout<<a[i]<<"\t";
            }
        }
        else
        {
            for(int j=Front;j<Max;j++)
            {
                cout<<a[j]<<"\t";
            }
            for(int c=0;c<=Rear;c++)
            {
                cout<<a[c]<<"\t";
            }

        }
        cout<<"\n";
    }

};
int main()
{
    Queue o1;
    o1.Push(5);

    return(0);
}
