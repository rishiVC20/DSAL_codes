//Rishikesh Chaudhari
//E11 23304

/*Implement stack as an ADT using singly linked list and use this conversion of
a) Infix expression to postfix
b) Infix expression to prefix
c) Evaluation of Postfix Expression
d) Evaluation of Prefix Expression
*/

#include <iostream>
using namespace std;

struct Employee
{
    string name;
    int ID;
    string designation;
};
class Queue
{
private:
    int front;
    int rear;
    int size;
    Employee E[20];

public:
    void enqueue();
    void dequeue();
    bool isEmpty();
    bool isFull();
    void show();
    Queue()
    {
        front = -1;
        rear = -1;
        cout << "Enter size " << endl;
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            E[i].ID = 0;
        }
    }
};

bool Queue ::isFull()
{
    if ((front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1))
        return true;
    else
        return false;
}

bool Queue ::isEmpty()
{
    if (front == -1)
        return true;

    else
        return false;
}

void Queue ::enqueue()
{
    cout << "Enter element " << endl;
    int data;
    cin >> data;
    if (isFull())
    {
        cout << "Queue is Full" << endl;
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
        E[rear].ID = data;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        E[rear].ID = data;
    }
    else
    {
        rear++;
        E[rear].ID = data;
    }
}

void Queue ::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    int ans = E[front].ID;
    E[front].ID = -1;
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void Queue::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << E[i].ID << " ";
    }
    cout << endl;
}

int main()
{
    Queue cq;
    int choice;

    do
    {
        cout << "1.Enqueue(enter element) \n2.Dequeue(delete Element) \n3.isEmpty(Check if queue is empty) \n4.isFull(Check if queue is full) \n5.Display queue " << endl;
        cout << "Enter operation : ";

        int n;
        cin >> n;
        if (n == 1)
        {
            cq.enqueue();
        }
        else if (n == 2)
        {
            cq.dequeue();
        }
        else if (n == 3)
        {

            if (cq.isEmpty())
            {
                cout << "Queue is empty. " << endl;
            }
            else
            {
                cout << "Queue is not empty. " << endl;
            }
        }
        else if (n == 4)
        {
            if (cq.isFull())
            {
                cout << "Queue is full. " << endl;
            }
            else
            {
                cout << "Queue is not full. " << endl;
            }
        }
        else if (n == 5)
        {

            cq.show();
        }
        else
        {
            cout << "Invalid input" << endl;
        }
        cout << "Enter 1 to continue : ";
        cin >> choice;

    } while (choice == 1);

    return 0;
}
