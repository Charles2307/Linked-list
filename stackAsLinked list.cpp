#include<iostream>
using namespace std;
struct node/* DEfine node As Struct*/
{
    int data;
    node* next;
};
class stacklist/*Class representing link list as Stack*/
{
    node* head;
    public:
        stacklist()/*Constructor*/
        {
            head=NULL;
        }
        void Push(int x)/*node creation and linking*/
        {
            node* newl;
            newl=new node;
            if(head==NULL)
            {
                newl->data=x;
                newl->next= NULL;
                head=newl;
            }
            else
            {
                newl->data=x;
                newl->next=head;
                head=newl;
            }
        }
        void display()/*Display the content of Stack*/
        {
            cout<<"\nDisplay Function\n";
            node* tmp;
            tmp=head;
            while(tmp!=NULL)
            {
                cout<<tmp->data;
                if(tmp->next!=NULL)
                {
                    cout<<"<==";
                }
                tmp=tmp->next;
            }
        }
        int pop()/*return the integer Popped out of Stack*/
        {
            int c=head->data;
            node* tmp =head;
            head=head->next;
            cout<<"\nData popped Successfully\n";
            delete(tmp);
            return c;
        }

};
int main ()
{
    stacklist o1;
    o1.Push(5);
    o1.Push(3);
    o1.Push(2);
    o1.display();
    int c=o1.pop();
    o1.display();
    cout<<"\n"<<c;
    return 0;
}
