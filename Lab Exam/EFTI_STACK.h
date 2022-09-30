#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
    N val;
    Node *Next;
    Node *Prev;
    Node(N val)
    {
        this->val = val;
        Next = NULL;
        Prev = NULL;
    }
};
template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }
    // PUSH
    void push(S val)
    {
        Node<S> *newNode = new Node <S> (val);
        if (head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }
        top->Next = newNode;
        newNode->Prev = top;
        top = newNode;
        count++;
    }
    // POP
    S pop()
    {
        Node<S> *delNode;
        delNode = top;
        if (top == head)
        {
            head = top = NULL;
        }
        else
        {
            top = delNode->Prev;
            top->Next = NULL;
        }
        S chk = delNode->val;
        delete delNode;
        count--;
        return chk;
    }
    // Empty
    bool empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    // Size
    int size()
    {
        return count;
    }
    // Top
    S Top()
    {
        S chk;
        if (top == NULL)
        {
            cout << "There is no element" << endl;
            chk;
        }
        else
        {
            chk = top->val;
        }
        return chk;
    }
    //mid
     S  mid() {
       Node <S> *mid = top;
       for (int i = 0; i < count/2; i++)
       {
           mid=mid->Prev;
       }
       return mid->val;
   }
};
