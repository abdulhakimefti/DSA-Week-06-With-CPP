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
Node* reverseKNodes(Node* head, int k)
{

    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
  

    while (current != NULL && count < k) {
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
        count++;
    }
  
    if (next != NULL)
        head->Next = reverseKNodes(next, k);
  

    return prev;
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertValue(head, val);
    }
    int position;
    cin >> position;
    Node * kNodes= reverseKNodes(head, position);
    display(kNodes);
    cout << endl;
    return 0;
}


