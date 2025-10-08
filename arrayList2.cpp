#include <iostream>
using namespace std;

class arrayList
{
    int *curr, *arr;
    int length;
    int capacity;

public:
    arrayList(int s)
    {
        capacity = s;
        arr = new int[s];
        length = 0;
        curr = arr;
    }

    ~arrayList()
    {
        delete[] arr;
    }

    void start()
    {
        curr = arr;
    }

    void back()
    {
        curr--;
    }

    void next()
    {
        curr++;
    }

    void tail()
    {
        curr = arr + length - 1;
    }

    bool isEmpty()
    {
        if (length == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFULL()
    {
        if (length == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int val, int pos)
    {
        if (isFULL())
        {
            cout << "List is full" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        tail();
        for (int i = length; i >= pos; i--)
        {
            *(curr + 1) = *curr;
            back();
        }

        *(curr + 1) = val;
        length++;
    }

    void remove(int pos)
    {
        if (isEmpty())
        {
            cout << "List is emoty" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
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

    void clear()
    {
        while (length != 0)
        {
            remove(1);
        }
    }

    int get(int pos)
    {
        if (isEmpty())
        {
            cout << "List is emoty" << endl;
            return -1;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return -1;
        }

        start();
        curr = arr + pos - 1;
        return *curr;
    }

    void update(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        start();
        for (int i = 1; i < pos; i++)
        {
            next();
        }

        *curr = val;
    }

    int getLength()
    {
        return length;
    }

    bool find(int val)
    {
        start();
        for (int i = 0; i < length; i++)
        {
            if (val == *curr)
            {
                return true;
            }
            next();
        }
        return false;
    }

    void removeDuplicates()
    {
        start();

        for (int i = 0; i < length; i++)
        {
            int currentVal = *curr;

            // Check if the current value is a duplicate
            for (int j = i + 1; j < length; j++)
            {
                if (arr[j] == currentVal)
                {
                    // Shift elements to the left to remove the duplicate
                    for (int k = j; k < length - 1; k++)
                    {
                        arr[k] = arr[k + 1];
                    }
                    length--; // Reduce the length of the list
                    j--;      // Adjust the index to recheck the same index for new value
                }
            }

            next(); // Move to the next element
        }
    }

    int findMax()
    {
        start();
        int max = *curr;
        for (int i = 1; i < length; i++)
        {
            next();
            if (max < *curr)
            {
                max = *curr;
            }
        }
        return max;
    }

    int findOdd()
    {
        start();
        int count = 0;
        int n;

        for (int i = 1; i <= length; i++)
        {
            n = *curr;
            if (n % 2 != 0)
            {
                count++;
            }
            next();
        }
        return count;
    }
    void shift(int s)
    {
        if (s > 0)
        {
        }

        else if (s < 0)
        {
        }
    }

    void sortAssending()
    {
        start();
        for (int i = 1; i <= length; i++)
        {
            for (int j = i + 1; j <= length; j++)
            {
                if (*curr > *(curr + 1))
                {
                    int temp = *curr;
                    *curr = *(curr + 1);
                    *(curr + 1) = temp;
                }
                next();
            }
            start();
        }
    }

    void sortDesending()
    {
        start();
        for (int i = 1; i <= length; i++)
        {
            for (int j = i + 1; j <= length; j++)
            {
                if (*curr < *(curr + 1))
                {
                    int temp = *curr;
                    *curr = *(curr + 1);
                    *(curr + 1) = temp;
                }
                next();
            }
            start();
        }
    }

    void insertNEW(int val)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }

        if (isFULL())
        {
            cout << "List is full" << endl;
            return;
        }

        start();
        int count = 0;
        while (count < length && val > *curr)
        {
            next();
            count++;
        }

        tail();
        for (int i = length; i > count; i--)
        {
            *(curr + 1) = *curr;
            back();
        }

        *(curr + 1) = val;
        length++;
    }

    void display()
    {
        start();
        for (int i = 0; i < length; i++)
        {
            cout << *curr << "  ";
            next();
        }
        cout << endl;
    }
};

int main()
{
    arrayList l(5);
    l.insert(2, 1);
    l.insert(13, 2);
    l.insert(4, 3);
    l.insert(3, 4);
    l.display();
    l.update(10, 1);
    l.display();
    l.sortDesending();
    cout<<"Desending: ";
    l.display();
    cout<<"\nAssending: ";
    l.sortAssending();
    l.display();
    l.insertNEW(9);
    l.display();
    l.removeDuplicates();
    l.display();
    cout << "Max Is: " << l.findMax() << endl;
    cout << "ODD number is Is: " << l.findOdd() << endl;

    return 0;
}
