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
};
int quick(int a[],int Beg,int End,int loc)
    {
        int left=Beg;
        int right=End;
        loc=Beg;
        while(a[loc]<=a[right]&&loc!=right)
        {
             right=right-1;
        }
        if(loc==right)
        {
            return loc;
        }
        if(a[loc]>a[right])
        {
            int temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;
            loc=right;
        }
        while (a[left]<=a[loc]&&left!=loc)
        {
            left=left+1;
        }
        if(loc==left)
        {
            return loc;
        }
        if(a[left]>a[loc])
        {
            int temp=a[loc];
            a[loc]=a[left];
            a[left]=temp;
            loc=left;
        }
    }
    void QuickSort(int A[])
    {
        cout<<"\nNO. of element in array\n";
        int n;
        int Top=1;
        Stack Upper,Lower;
        Upper.Push(n-1);
        Lower.Push(0);
        int Loc;
        while(Top!=0)
        {
            int Beg=Lower.pop();
            int End=Upper.pop();
            Top=Top-1;
            Loc=quick(A, Beg, End, Loc);
            if(Loc-1>Beg)
        {
                Top=Top+1;
                Lower.Push(Beg);
                Upper.Push(Loc-1);
        }
        if(Loc+1<End)
        {
                Top=Top+1;
                Lower.Push(Loc+1);
                Upper.Push(End);
        }
    }
    }
    int main()
    {
int a[5]={4,6,5,7,1};
QuickSort(a);
for (int i=0;i<5;i++)
{
    cout<<"\t"<<a[i]<<"\t";
}
return 0;
    }
