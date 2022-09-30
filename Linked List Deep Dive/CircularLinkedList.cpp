#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
}
void InsertHead(Node *&head, int val)
{

    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    newNode->next = head;
    Node *temp = head;
    while (temp->next != newNode->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    head = newNode;
}
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        Node *delNode = temp;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = delNode->next;
        head = delNode->next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the linked List" << endl;
    }
}
void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else
    {
        // Head is null
        if (temp == NULL)
        {
            cout << "There is no value in the linked List" << endl;
        }
        // Head is  tail
        else
        {
            cout << "There is no value in the linked List" << endl;
        }
    }
}
int countLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    do
    {
        temp = temp->next;
        count++;
    } while (temp != head);
    return count;
}

void display(Node *n)
{
    if (n == NULL)
    {
        cout << "The linked list is empty" << endl;
        return;
    }
    Node *temp = n;
    do
    {
        cout << temp->value;
        temp = temp->next;
        if (temp != n)
            cout << " -> ";
    } while (temp != n);
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int n, position;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2:Insertion at Tail" << endl
         << "Choice 3:Insertion at Specific Position" << endl
         << "Choice 4:Search a value (Unique List)" << endl
         << "Choice 5:Search a value (Duplication enable list)" << endl
         << "Choice 6:Insertion after a specific value (Unique list)" << endl
         << "Choice 7:Deletion At head" << endl
         << "Choice 8:Deletion At Tail" << endl
         << "Choice 9:Deletion At Specific Position" << endl
         << "Choice 10:Deletion By value (Unique List)" << endl
         << "Choice 11:Reversal of linked list (Non-Recursive)" << endl
         << "Choice 12:Reversal of linked list (Recursive)" << endl
         << "Choice 13:Finding the mid (slow-fast-pointer method)" << endl
         << "Choice 14:Make cycle" << endl
         << "Choice 15:Detect Cycle" << endl
         << "Choice 16:Remove cycle" << endl
         << "Choice 0: Exit" << endl;
    int choice = 2;
    while (choice != 0)
    {
        cout << endl;
        cout << "Next Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> n;
            InsertHead(head, n);

            break;
        case 2:
            cout << "Enter the value: ";
            cin >> n;
            insertAtTail(head, n);
            break;

        case 3:
            
            deletionAtTail(head);
            break;

        case 4:
           
        deletionAtHead(head);
            break;

        default:
            break;
        }
    }

    cout << "Linked List : ";
    display(head);
    cout << "Length of the list: " << countLength(head) << endl;
    return 0;
}