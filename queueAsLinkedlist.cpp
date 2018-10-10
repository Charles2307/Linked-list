#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class Queue
{
    node* head;
    public:
    Queue()
    {
        head=NULL;
    }
    void Insert(int x)
    {
        node *newl,*Endl;
        newl= new node;
        newl->data=x;
        if(head==NULL)
        {
            newl->next=NULL;
            head=newl;
            Endl=newl;
        }
        else
        {
            Endl->next=newl;
            newl->next=NULL;
            Endl=newl;
        }
    }
    int Delete()
    {
        if(head!=NULL)
        {
            int c=head->data;
            head=head->next;
        }
        else
        {
            cout<<"\nQueue is empty\n";
        }
    }
    void Display()
    {
         cout<<"\nDISPLAY FUNCTION:\n";
    node* tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->data;
            if(tmp->next!=NULL)
            {
                cout<<"\t";
            }
            tmp=tmp->next;
        }

    }
};
int main()
{
    Queue o1;
    o1.Insert(5);
    o1.Insert(2);
    o1.Insert(3);
    o1.Display();
    o1.Delete();
    o1.Display();
    return 0;
}
