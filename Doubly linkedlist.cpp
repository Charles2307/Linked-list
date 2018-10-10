#include<iostream>
using namespace std;
/*creates nodes*/
 struct node
 {
     int data;
     node* next;
     node* prev;
 };
 /*create linkedlist*/
class linklist
{
    node* head; node* tail;
    public:
    /*constructor*/
    linklist()
    {
        head=NULL;
        tail=NULL;
    }
    void create();/*create nodes and link them*/
    void display();/*display data*/
    void Front(int value);/*add node in the front*/
    void End(int value);/*add node at the end*/
    void after(int position, int value);/*add node after a given position*/
    void delF()/*delete node in the front*/
    {
        node* tmp=head->next;
        tmp->prev=NULL;
        head=tmp;
    }
    void delA(node* A)/*delete node after a given node*/
    {
        node* tmp,*n;
        tmp=A->next;
        n=tmp->next;
        A->next=tmp->next;
        n->prev=tmp->prev;
    }
    node* getHead()/*return the position of head of a linkedlist*/
    {
        return(head);
    }
    void delE()/*delete node at the end of a linkedlist*/
    {
        node* tmp;
        tmp=tail->prev;
        tmp->next=NULL;
        tail=tmp;
    }
};
void linklist::create()
{
    node* newl=NULL, *end=newl;
    int info;
    while(1)
    {
        char k;
        cout<<"\n\nEnter E to terminate or A to add: \n";
        cin>>k;
        if(k=='E')
        {
            break;
        }
        else
        {
            cout<<"\nEnter info: ";
            cin>>info;
            newl=new node;
            newl->data=info;
            if(head==NULL)
            {
                newl->prev=NULL;
                newl->next=NULL;
                head=newl;
                cout<<"\nFIRST NODE created.\n";
                end=newl;
                tail=end;
            }
            else
            {
                end->next=newl;
                newl->prev=end;
                end=newl;
                end->next=NULL;
                tail=end;
                cout<<"\nOther nodes linked successfully\n";
            }


        }
    }

}
void linklist::display()
{
    cout<<"\nDISPLAY FUNCTION:\n";
    cout<<"\nEnter F to display from beginning or E to display from end of linklist: \n";
    char K;
    cin>>K;
    if(K=='E')
    {
    node* tmp=tail;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"<->";
        tmp=tmp->prev;
    }
    }
    else
    {
        node* tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->data<<"<->";
            tmp=tmp->next;
        }
    }
    cout<<"NULL";
}
void linklist::Front(int value)
{
    node* tmp=new node;
    tmp->data=value;
    tmp->prev=NULL;
    tmp->next=head;
    head->prev=tmp;
    head=tmp;

}
void linklist::after(int position, int value)
{
    int j=1;
    node* tmp= head;
    while(j!=position)
    {
        tmp=tmp->next;
        j++;
    }
    node* k=tmp->next;
    node* p =new node;
    p->data=value;
    p->next=k;
    k->prev=p;
    p->prev=tmp;
    tmp->next=p;
}
void linklist::End(int value)
{
    node* tmp=new node;
    tmp->data=value;
    tmp->next=NULL;
    tmp->prev=tail;
    tail->next=tmp;
    tail=tmp;
}
int main()
{
    linklist o1;
    o1.create();
    o1.display();
    o1.delE();
    o1.display();
    return 0;
}
