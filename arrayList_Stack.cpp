#include <iostream>
using namespace std;

class list
{
private:
    int *arr;
    int *curr;
    int capacity;
    int length;

public:
    list(int c)
    {
        capacity = c;
        length = 0;
        arr = new int[c];
        curr = arr;
    }

    ~list()
    {
        delete[] arr;
    }

    void start()
    {
        curr = arr;
    }

    void next()
    {
        curr++;
    }

    void back()
    {
        curr--;
    }

    void tail()
    {
        curr = arr + length - 1;
    }

    void insert(int val, int pos)
    {
        if (length == capacity)
        {
            cout << "FULL" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position.." << endl;
            return;
        }

        tail();
        for (int i = length; i >= pos; i++)
        {
            *(curr + 1) = *curr;
            back();
        }

        *(curr + 1) = val;
        length++;
    }

    void remove(int pos)
    {
        if (length == capacity)
        {
            cout << "FULL" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position.." << endl;
            return;
        }

        start();

        curr = arr + pos - 1;

        for (int i = pos; i < length; i++)
        {
            *curr = *(curr + 1);
            next();
        }

        length--;
    }

    bool isFULL()
    {
        if (length == capacity)
        {
            return true;
        }
        else
            return false;
    }

    bool isEmpty()
    {
        if (length == 0)
        {
            return true;
        }
        else
            return false;
    }

    int get(int pos)
    {
        if (isEmpty())
        {
            cout << "EMPTY LIST" << endl;
            return -1; // Return a default value (you can choose another value if needed)
        }
        else
        {
            if (pos < 1 || pos > length)
            {
                cout << "Invalid position.." << endl;
                return -1; // Return a default value (you can choose another value if needed)
            }

            curr = arr + pos - 1;
            return *curr;
        }
    }

    void display()
    {
        start();
        cout << "length is " << length << endl;
        for (int i = 0; i < length; i++)
        {

            cout << *curr << "  ";
            next();
        }
    }
};

class stack : public list
{
private:
    int top;

public:
    stack(int s) : list(s)
    {
        top = 0;
    }

    void push(int val)
    {
        if (isFULL())
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        insert(val, top);
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underFlow" << endl;
            return -1;
        }

        int val = get(top);
        remove(top);
        top--;

        return val;
    }
};

int main()
{

    stack s(5);
    s.push(3);
    s.push(7);
    s.push(1);
    s.push(6);
    s.display();
    s.pop();
    s.display();

    return 0;
}