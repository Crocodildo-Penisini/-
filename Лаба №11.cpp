#include <iostream>
#include <windows.h>

using namespace std;
#define SurLen 20

struct stud
{
    int school_number;
    char headmaster_surname[SurLen];
    int amount_of_children;
    bool equals(stud& y)
    {
        return school_number == y.school_number &&
            strcmp(headmaster_surname, y.headmaster_surname) == 0 &&
            amount_of_children, y.amount_of_children == 0;
    }
    void studout()
    {
        cout << "School number : " << school_number << endl;
        cout << "Input Headmaster surname: " << headmaster_surname << endl;
        cout << "Amount of children : " << amount_of_children << endl;
        cout << "\n";
    }
    void studin()
    {
        cout << "School number :";
        cin >> school_number;
        cout << "Input Headmaster surname :";
        cin >> headmaster_surname;
        cout << "Amount of children :";
        cin >> amount_of_children;
        cout << "\n";
    }
};

struct Node
{
    stud data;
    Node* prev, * next;

    static Node* getnode(stud data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};

struct Deque
{
    Node* front;
    Node* rear;

public:
    Deque()
    {
        front = rear = NULL;
    }

    void insertFront(stud data);
    void insertRear(stud data);
    void deleteFront();
    void deleteRear();
    stud getFront();
    stud getRear();
    int size();
    bool isEmpty();
    void erase();
    void print();
};

bool Deque::isEmpty()
{
    return (front == NULL);
}

int Deque::size()
{
    if (front == NULL)
        throw (0);
    int Size = 0;
    Node* temp = front;
    while (temp != NULL)
    {
        Size++;
        temp = temp->next;
    }
    return Size;
}

void Deque::insertFront(stud data)
{
    Node* newNode = Node::getnode(data);

    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        if (front == NULL)
            rear = front = newNode;

        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }
}

void Deque::insertRear(stud data)
{
    Node* newNode = Node::getnode(data);

    if (newNode == NULL)
    {
        cout << "OverFlow\n";
        throw(0);
    }

    if (rear == NULL)
        front = rear = newNode;

    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
}

void Deque::deleteFront()
{

    if (isEmpty())
    {
        cout << "UnderFlow\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;
    free(temp);
}

void Deque::deleteRear()
{

    if (isEmpty())
    {
        cout << "UnderFlow\n";
        return;
    }

    Node* temp = rear;
    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;
    free(temp);
}

stud Deque::getFront()
{

    if (isEmpty())
        throw(0);
    return front->data;
}

stud Deque::getRear()
{

    if (isEmpty())
        throw(0);
    return rear->data;
}

void Deque::erase()
{
    rear = NULL;
    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        free(temp);
    }
}
void Deque::print()
{
    if (front == NULL)
    {
        cout << "Dequeue is empty" << endl;
        return;
    }
    Node* temp = front;
    while (temp != NULL)
    {
        temp->data.studout();
        temp = temp->next;
    }
}
int main()
{
    Deque deque;

    int variant = 1;
    while (variant != 0)
    {
        cout << "\n\nChoose action: \n"
            << endl;
        cout << "1.Add element at front\n"
            << "2. Add element at rear\n"
            << "3. Remove element at front\n"
            << "4. Remove element at rear\n"
            << "5. Get front element \n"
            << "6. Get rear element\n"
            << "7. Get size of deque\n"
            << "8. Clear deque\n"
            << "9. Print deque\n"
            << "0. Exit\n"
            << endl;
        cin >> variant;

        switch (variant)
        {
        case 0:
            variant = 0;
            break;
        case 1:
            cout << "\n";
            stud newdata;
            newdata.studin();
            deque.insertFront(newdata);
            break;

        case 2:
            cout << "\n";
            stud new_data;
            new_data.studin();
            deque.insertRear(new_data);

            break;

        case 3:
            deque.deleteFront();
            break;

        case 4:
            deque.deleteRear();

            break;
        case 5:
            stud front;

            try
            {
                front = deque.getFront();
                front.studout();
            }
            catch (int exception)
            {
                cout << "Deque is empty" << endl;
            }

            break;
        case 6:
            stud rear;

            try
            {
                rear = deque.getRear();
                rear.studout();
            }
            catch (int exception)
            {
                cout << "Deque is empty" << endl;
            }
            break;
        case 7:
            try
            {
                int size = deque.size();
                cout << "size of deque is: " << size << endl;
            }
            catch (int exception)
            {
                cout << "Deque is empty" << endl;
            }
            break;
        case 8:
            deque.erase();
            break;
        case 9:
            deque.print();
            break;
        default:
            cout << "Input numbers from 1 to 9!\n\n";
            break;
        }
    }

    return 0;
}
