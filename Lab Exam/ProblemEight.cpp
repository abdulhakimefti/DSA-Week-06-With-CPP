#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void insertValue(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}
int countLength(Node *head)
{
    int count = 0;
    Node *temp = head;
   while (temp != NULL)
    {
        temp = temp->Next;
        count++;
    } 
    return count;
}
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
   
}
void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
   
}
void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (temp != NULL && position <= countLength(head))
    {
        if (position == 1)
        {
            deletionAtHead(head);
        }
        else if (position == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    
}
void  traverseAndDelete(Node *&head,int l,int m){
    Node *temp = head;
    int a=1,b=1;
    int count=0;
    int countTwo=1;
    int len = countLength(head);
    while(count<=len){
        if(a<=l){
            countTwo++;
            count++;
            if(a==l){
                b=1;
            }a++;
        }
        else if(b<=m){
          count++;
            deletionAtSpecificPosition(head,countTwo);
            if(b==m){
                a=1;
            }    b++;
        }
    }
}

void display(Node *&head)
{

    while (head != NULL)
    {
        cout << head->value;
        if (head->Next != NULL)
        {
            cout << " -> ";
        }
        head = head->Next;
    }
}
int main()
{
    Node *head = NULL;
    int n,l,m;
    cin >> n;
    
    cin>>l>>m;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertValue(head, val);
    }

    traverseAndDelete(head,l,m);
    display(head);
    cout << endl;
    return 0;
}


