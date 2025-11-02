#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int v)
    {
        data = v;
        next = NULL;
    }
};

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void push(int val)
    {
        node *temp = new node(val);
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Lisst is empty" << endl;
            return -1;
        }

        else
        {
            node *temp = top;
            int val = temp->data;
            top = top->next;
            delete temp;
            return val;
        }
    }

    int peak()
    {
        if (!isEmpty())
        {
            return top->data;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        stack temp;

        while (!isEmpty())
        {
            int val = pop();
            temp.push(val);
        }

        while (!temp.isEmpty())
        {
            int val = temp.pop();
            cout << val << " ";
            push(val);
        }

        cout << endl;
    }
};

int main()
{
    stack s;
    s.push(5);
    s.push(2);
    s.push(6);
    s.push(3);
    s.push(8);
    s.display();
    cout << "Peak: " << s.peak() << endl;

    return 0;
}