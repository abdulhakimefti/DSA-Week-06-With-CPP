#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node * Next;
    Node * prev;

    Node(int value)
    {
        this->value=value;
        Next = NULL;
        prev = NULL;
    }
};

void Display(Node * head);
void Insertion_at_Head(Node*&head,int value);
void Insertion_at_Tail(Node*&head,int value);
int counting_the_size(Node* &head);
int search_a_value(Node*head,int value);
void Insertion_at_specific_posetion(Node*&head,int position,int value);

void Insertion_at_Head(Node*&head,int value)
{
    Node * add_tail = new Node(value);

    if(head==NULL)
    {
        head = add_tail;
        return ;
    }
    Node * temp = head;
    add_tail->Next = temp;
    temp->prev = add_tail;
    head = add_tail;
}

void Insertion_at_Tail(Node*&head,int value)
{
    Node * add_tail = new Node(value);

    if(head==NULL)
    {
        head = add_tail;
        return ;
    }
    Node * temp = head;
    while(temp->Next!=NULL)
    {
        temp = temp->Next;
    }
    temp->Next = add_tail;
    add_tail->prev = temp;
}

void Display(Node * head)
{
    if(head==NULL)
    {
        cout<<"Value NOT Found"<<endl;
        return;
    }
    while(head!=NULL)
    {
        cout<<head->value;
        head= head->Next;
        if(head!=NULL)
            cout<<"->";
    }

    cout<<endl;
}

int counting_the_size(Node* &head)
{
    Node * temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count ++;
        temp = temp->Next;
    }
    return count;
}

void Insertion_at_specific_posetion(Node*&head,int position,int value)
{
    Node * newNode = new Node(value);
    Node * temp = head;
    int count = counting_the_size(head);
    if(count+1<position||position<1)
    {
        cout<<" Position invalid " <<endl;
        return ;
    }
    if(position==1)
    {
        Insertion_at_Head(head,value);
        return;
    }
    int i=1;
    while(position-1>i)
    {
        temp = temp->Next;
        i++;
    }
    Node * tem = temp->Next;
    if(count+1 !=position) tem->prev = newNode;
    newNode->Next = tem;
    newNode->prev= temp;
    temp->Next = newNode;
}

int search_a_value(Node*head,int value)
{
    int count = 0;

    while(head!=NULL)
    {
        count++;
        if(head->value==value) return count;

        head = head->Next;
    }
    return count=0;
}

void Exam_Display(Node * head,int position,int size)
{
    int count = search_a_value(head,position);

    for(int i=1; i<count; i++)
    {
        head = head->Next;
    }
    if(count==size)
    {
         cout<<head->prev->value<<" "<<0<<endl;
         return;
    }
    if(count==1)
    {
         cout<<0<<" "<<head->Next->value<<endl;
         return;
    }
    cout<<head->prev->value<<" "<<head->Next->value<<endl;
}

int main()
{
    Node * head = NULL;
    int Y;
    cin>>Y;
    for(int i=1; i<=Y; i++)
    {
        int w,o;
        cin>>w>>o;
        int h =  search_a_value(head,i);
        if(h==0) Insertion_at_Head(head,i);
        if(w>0)
        {
            int c = search_a_value(head,i);
            int m = search_a_value(head,w);
            if(m==0)
            {
                if(c==1) Insertion_at_Head(head,w);
                else Insertion_at_specific_posetion(head,c,w);
            }
        }
        if(o>0)
        {
            int c =  search_a_value(head,i);
            int m =  search_a_value(head,o);
            if(m==0)
            {
                Insertion_at_specific_posetion(head,c+1,o);
            }
        }
    }

    for(int i=1; i<=Y; i++)
    {
        Exam_Display(head,i,Y);
    }
    return 0;
}