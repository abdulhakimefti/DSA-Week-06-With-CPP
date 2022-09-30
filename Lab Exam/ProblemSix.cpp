#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *Next;
    Node(int val)
    {
        this->val = val;
        Next = NULL;
    }
};
void insertValue(Node *&head, int val)
{
    Node *newNode = new Node(val);
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
void changeEvenNum(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
        return;
    while (temp != NULL)
    {
        if ((temp->val) % 2 == 0)
        {
            temp->val = -1;
        }
        temp = temp->Next;
    }
}
void display(Node *&head)
{

    while (head != NULL)
    {
        cout << head->val;
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

    changeEvenNum(head);

    display(head);
    return 0;
}