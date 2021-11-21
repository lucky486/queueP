#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    int *arr;

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

/* Function to create Circular queue */
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1)))
    {
        cout<<"\nQueue is Full"<<endl;
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return;
    }
    cout<<"\nElements in Circular Queue are: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i]<<" ";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<<arr[i]<<" ";

        for (int i = 0; i <= rear; i++)
            cout<<arr[i]<<" ";
    }
    cout << endl;
}

/* Driver of the program */
int main()
{
    Queue q(5);
    bool flag = true;
    int ch;
    int n;
    while (flag)
    {
        cout << "-----------------------------------------" << endl;
        cout << "1. ENQUEUE " << endl;
        cout << "2. DEQUEUE  " << endl;
        cout << "3. DISPLAY " << endl;
        cout << "0. FOR EXIT " << endl;
        cout << "-----------------------------------------" << endl;
        cin >> ch;
        switch (ch)
        {
        case 0:
            flag = false;
            cout << "EXITING..." << endl;
            break;

        case 1:
            cout << "Enter the element to insert in circular queue  : ";
            cin >> n;
            q.enQueue(n);
            break;

        case 2:
            cout << "Deleted Value : " << q.deQueue() << endl;
            break;

        case 3:
            q.displayQueue();
            break;

        default:
            cout << "Wrong Choice" << endl;
            break;
        }
    }
    return 0;
}
