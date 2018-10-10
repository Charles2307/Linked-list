#include<iostream>
using namespace std;
 struct node/*node Structure*/
 {
     int data;
     node* next;
 };
class linklist/*Link nodes */
{
    node* head;/*Head node of linklist*/
    public:
    linklist()/*Define constructor for Instance*/
    {
        head=NULL;
    }
    void create();/*Create nodes and link them*/
    void display();/*Display the Info of nodes*/
    void Front(int value)/*Add node in Front*/
    {
        node* tmp= new node;
        tmp->data=value;
        tmp->next=head;
        head=tmp;
    }
    void End(int value)/*Add node at the end*/
    {
        node* tmp;
        tmp=head;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        node* n= new node;
        n->data=value;
        n->next=NULL;
        tmp->next=n;
    }

    void after(int position, int value)/*Add node after a given Position*/
    {
        int j=1;
        node* tmp=head;
        while(position!=j)
        {
            tmp=tmp->next;
            j++;
        }
        node* p= new node;
        p->data=value;
        p->next=tmp->next;
        tmp->next=p;
    }
    void delF()/*Delete node in the  Front*/
    {
        node* tmp=head;
        head=tmp->next;
    }
    void delA(node* A)/*Delete node after a given node*/
    {
        node* tmp=A->next;
        A->next=tmp->next;
        delete tmp;
    }
    node* getHead()/*REturn the head node of a LInklist*/
    {
        return(head);
    }
    void delE()/*Delete the node at the end of link list*/
    {
        node* tmp=head;
        while(tmp->next->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=NULL;
    }
    void SortIns(int value)/*Insert node in the sorted Link list*/
    {
        node* tmp=head;
        int i=1;
        if(value<=tmp->data)
        {
            Front(value);

        }
        else
        {
            while(value>tmp->next->data && tmp->next->next!=NULL)
            {
                tmp=tmp->next;
                cout<<tmp->data;
                i++;
            }
            if(tmp->next==NULL or value>tmp->next->data)
            {
                End(value);
            }
            else
            {
             after(i,value);
            }
        }

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
                newl->next=NULL;
                head=newl;
                cout<<"\nFIRST NODE created.\n";
                end=newl;
            }
            else
            {
                end->next=newl;
                end=newl;
                end->next=NULL;
                cout<<"\nOther nodes linked successfully\n";
            }


        }
    }

}
void linklist::display()
{
    cout<<"\nDISPLAY FUNCTION:\n";
    node* tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->data;
            if(tmp->next!=NULL)
            {
                cout<<"==>";
            }
            tmp=tmp->next;
        }

}
int main()
{
    linklist o1;
    o1.create();
    o1.display();
    return 0;
}
