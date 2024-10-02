#include <iostream>

using namespace std;

class Node
{
public:
    Node* next;
    Node* prev;
    int data;
    Node()
    {
        next=NULL;
        prev=NULL;
        data=0;
    }

};

class DoubleLinkedList
{
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList()
    {
        head=NULL;
        tail=NULL;
    }

    bool IsEmpty()
    {
        return (head==NULL&&tail==NULL);
    }

    void InsertFirst(int newitem)
    {
        Node* newnode=new Node();
        newnode->data=newitem;
        if (IsEmpty())
        {
            head = tail = newnode;
            return;
        }
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=NULL;
        head=newnode;
    }
    bool InsertAfter(int newitem,int nodeOffset)
    {

        if(nodeOffset<1)
        {
            cout << "Invalid index. Must be >= 1." << endl;
            return false;
        }

        if(nodeOffset==1)
        {
            InsertFirst(newitem);
            return true;
        }
        Node* temp=head;
        int i=1;
        while(temp!=NULL && i<nodeOffset-1)
        {
            temp=temp->next;
            i++;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return false;
        }

        Node* newnode=new Node();
        newnode->data=newitem;

        newnode->next=temp->next;
        temp->next->prev=newnode;
        newnode->prev=temp;
        temp->next=newnode;

        return true;

    }

    void InsertLast(int newitem)
    {
        Node* newnode=new Node();
        newnode->data=newitem;
        if (IsEmpty())
        {
            head = tail = newnode;
            return;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        newnode->next=NULL;

    }


    void DisplayForword()
    {
        if (IsEmpty())
        {
            cout << "List empty" << endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void DisplayBackword()
    {
        if (IsEmpty())
        {
            cout << "List empty" << endl;
            return;
        }
        Node* temp=tail;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

    void RemoveFirst()
    {
        if (IsEmpty())
        {
            cout << "List is empty, nothing to remove.\n";
            return;
        }
        Node* del=head;
        if(head==tail)
        {
            head=tail=NULL;
        }
        else
        {
            head->next->prev=NULL;
            head=head->next;
        }
        delete del;
    }

    void RemoveLast()
    {
        if (IsEmpty())
        {
            cout << "List is empty, nothing to remove.\n";
            return;
        }
        Node* del=tail;
        if(head==tail)
        {
            head=tail=NULL;
        }
        else
        {
            tail->prev->next=NULL;
            tail=tail->prev;
        }
        delete del;
    }

    void RemoveMiddel(int item)
    {
        Node* del=head;
        while(del!=NULL && del->data!=item)
        {
            del=del->next;
        }
        if(del==NULL)
        {
            cout<<"Invalid position\n";
            return;
        }
        if(del==head)
        {
            RemoveFirst();
            return;
        }
        else if(del==tail)
        {
            RemoveLast();
            return;
        }

        del->prev->next=del->next;
        del->next->prev=del->prev;

        delete del;

    }



};

int main()
{
    DoubleLinkedList listob;

    int n1;
    cout<<"Enter count of number List  : ";
    cin>>n1;
    cout<<"\nEnter the Element of Double_Linked_List  : ";
    for(int i=0; i<n1; i++)
    {
        int num;
        cin>>num;
        listob.InsertLast(num);
    }
    cout<<endl;
    //listob.InsertFirst(6);
    //cout<<listob.InsertAfter(0,10)<<endl;
    cout<<"\nElement of Double_Linked_List Backword : ";
    listob.DisplayBackword();
    cout<<endl;
    cout<<"\nElement of Double_Linked_List Forword : ";
    listob.DisplayForword();
    cout<<endl;

    //remove
    listob.RemoveFirst();
    cout<<"\nElement of Double_Linked_List Forword After remove first: ";
    listob.DisplayForword();
    cout<<endl;

    listob.RemoveLast();
    cout<<"\nElement of Double_Linked_List Forword After remove last: ";
    listob.DisplayForword();
    cout<<endl;

    listob.RemoveMiddel(5);
    cout<<"\nElement of Double_Linked_List Forword After remove Middel: ";
    listob.DisplayForword();
    cout<<endl;

    return 0;
}
