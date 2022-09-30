#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int val;
    doublyNode *prev;
    doublyNode *next;
    doublyNode(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

void InsertTail(doublyNode *&head, int val);
void InsertHead(doublyNode *&head, int val);
void display(doublyNode *n);

void InsertTail(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void InsertHead(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void display(doublyNode *n)
{
    while (n != NULL)
    {
        cout << n->val << " ";
        if (n->next != NULL)
            cout << " -> ";
        n = n->next;
    }
    cout << endl;
}
void displayReverse(doublyNode *n)
{
    doublyNode *temp = n;
    while (temp->next != NULL)
    {

        temp = temp->next;
    }
    while (temp != NULL)
    {

        cout << temp->val << " ";
        if (temp->prev != NULL)
            cout << " -> ";
        temp = temp->prev;
    }
    cout << endl;
}
int countLength(doublyNode *head)
{
    int count = 0;
    doublyNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int main()
{
    doublyNode *head = NULL;
    int n, position;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2:Insertion at Tail" << endl
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
            InsertTail(head, n);
            break;
        default:
            break;
        }
    }

    cout << "Doubly Linked List : ";
    display(head);
    cout << "Length of the list: " << countLength(head) << endl;
    cout << "Doubly Linked List (Reverse): ";
    displayReverse(head);
    return 0;
}