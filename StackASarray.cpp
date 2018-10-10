#include<iostream>
using namespace std;
#define MAX 100
class Stack
{
    public:
    int top;
    int a[MAX];
    Stack()
    {
        top=-1;
    }
     bool Push(int b)
    {
        if(top>=MAX-1)
        {
            cout<<"\nStack Overflow\n";
            return false;
        }
        else
        {
            a[++top]=b;
            return true;
        }
    }
    int pop()
    {
        if(top<0)
        {
            cout<<"\nStack Underflow\n";
        }
        else
        {
            int x= a[top--];
            return x;
        }
    }
    void Print()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<a[i];
            if(i==0)
            {
                break;
            }
            else
            {
                cout<<"==>";
            }
        }
        cout<<"\n";
    }
};

int main()
{   int c;
    Stack o1;
    o1.Push(3);
    o1.Push(2);
    o1.Push(5);
    o1.Print();
    return 0;
}
