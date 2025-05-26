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

struct StackNode
{
    stud data;
    StackNode* next;
};

void print(StackNode* head)
{
    if (head == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    while (head != NULL)
    {
        head->data.studout();
        head = head->next;
    }
}

StackNode* newNode(stud data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode* root)
{
    return !root;
}

void push(StackNode** root, stud data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

void pop(StackNode** root)
{
    if (isEmpty(*root)) {
        cout << "stack is empty" << endl;
        return;
    }
    *root = (*root)->next;
}

stud peek(StackNode* root)
{
    if (isEmpty(root))
        throw(0);
    return root->data;
}

int main()
{

    StackNode* root = NULL;

    int variant = 1;
    while (variant != 0)
    {

        cout << "\n\nChoose action: \n"
            << endl;
        cout << "1. Push element\n"
            << "2. Pop element\n"
            << "3. Get root element\n"
            << "4. Print Stack\n"
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
            push(&root, newdata);
            break;

        case 2:
            pop(&root);
            break;

        case 3:
            stud r;

            try
            {
                r = peek(root);
                r.studout();
            }
            catch (int exception)
            {
                cout << "Stack is empty" << endl;
            }
            break;

        case 4:
            print(root);
            break;

        default:
            cout << "Input numbers from 1 to 4!\n\n";
            break;
        }
    }

    return 0;
}
