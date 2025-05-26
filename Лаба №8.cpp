#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
#define SurLen 20

struct stud
{
    int school_number;
    char headmaster_surname[SurLen];
    int amount_of_children;
    bool equals(stud& y)
    {
        return school_number == y.school_number && headmaster_surname == y.headmaster_surname && amount_of_children == y.amount_of_children;
    }
};

struct Node
{
    stud d;
    Node* next;
};

void output(Node* u)
{
    Node* p = u;

    while (p)
    {
        cout << "School numbers : " << p->d.school_number << endl;
        cout << "Input surname : " << p->d.headmaster_surname << endl;
        cout << "Amount of children : " << p->d.amount_of_children << endl;
        cout << "\n";
        p = p->next;
    }
    cout << endl;
}

void output_any(Node* u, int n)
{
    Node* p = u;

    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    cout << "School numbers : " << p->d.school_number << endl;
    cout << "Input surname : " << p->d.headmaster_surname << endl;
    cout << "Amount of children : " << p->d.amount_of_children << endl;
    cout << "\n";
}

void add_head(Node** begin)
{
    if (*begin == NULL)
    {
        *begin = new Node;

        stud d;
        cout << "\nSchool numbers : ";
        cin >> (*begin)->d.school_number;
        cout << "Input surname: ";
        cin >> (*begin)->d.headmaster_surname;
        cout << "Amount of children : ";
        cin >> (*begin)->d.amount_of_children;
        (*begin)->next = NULL;
        cout << "\n";
    }
    else
    {
        stud d;
        cout << "\nSchool numbers : ";
        cin >> d.school_number;
        cout << "Input surname: ";
        cin >> d.headmaster_surname;
        cout << "Amount of children : ";
        cin >> d.amount_of_children;
        cout << "\n";

        Node* t = new Node;
        t->d = d;
        t->next = *begin;
        *begin = t;
    }
}

void add_end(Node** begin)
{
    if (*begin == NULL)
    {
        *begin = new Node;

        Node d;
        cout << "\nSchool numbers : ";
        cin >> (*begin)->d.school_number;
        cout << "Input surname: ";
        cin >> (*begin)->d.headmaster_surname;
        cout << "Amount of children : ";
        cin >> (*begin)->d.amount_of_children;
        (*begin)->next = NULL;
        cout << "\n";
    }
    else
    {
        stud d;
        cout << "\nSchool numbers : ";
        cin >> d.school_number;
        cout << "Input surname: ";
        cin >> d.headmaster_surname;
        cout << "Amount of children : ";
        cin >> d.amount_of_children;
        cout << "\n";

        Node* t, * newt = new Node;
        for (t = *begin; t->next; t = t->next)
            ;
        newt->d = d;
        newt->next = NULL;
        t->next = newt;
    }
}

void del(Node*& begin, int n)
{
    Node* del = begin;
    Node* temp = begin;

    for (int i = 0; i < n - 1; i++)
    {
        del = temp;
        temp = temp->next;
    }
    if (n == 1)
    {
        begin = begin->next;
    }
    del->next = temp->next;
    delete temp;
}
void Next(Node* u, int n)
{
    return output_any(u, n + 1);
}
void Previous(Node* u, int n)
{
    return output_any(u, n - 1);
}

void swapNodes(Node** u, int pos1, int pos2)
{
    Node* p = *u;
    Node* b = *u;

    stud x, y;
    for (int i = 0; i < pos1 - 1; i++)
    {
        p = p->next;
    }
    x = p->d;

    for (int i = 0; i < pos2 - 1; i++)
    {
        b = b->next;
    }
    y = b->d;

    if (x.equals(y))
        return;

    Node* prevX = NULL, * currX = *u;
    while (currX && !currX->d.equals(x))
    {
        prevX = currX;
        currX = currX->next;
    }

    Node* prevY = NULL, * currY = *u;
    while (currY && !currY->d.equals(y))
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *u = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *u = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
int main()
{

    Node* header = NULL;

    int k = 0;

    int variant = 1;
    while (variant != 0)
    {

        cout << "\n\nChoose action: \n"
            << endl;
        cout << "1. Print list\n"
            << "2. Add to front\n"
            << "3. Add to apend\n"
            << "4. Delete elements\n"
            << "5. Get Nth element\n"
            << "6. Get size of list\n"
            << "7. Delete list\n"
            << "8. Next element:\n"
            << "9. Previous elements\n"
            << "10. Swap elements\n"
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
            output(header);
            break;

        case 2:
            add_head(&header);
            k++;
            break;

        case 3:
            add_end(&header);
            k++;
            break;

        case 4:
            cout << "\nInput element number to delete : ";
            int d;
            cin >> d;
            if (d > k)
            {
                cout << "\nElement is missing\n\n";
                continue;
            }
            del(header, d);
            cout << "\n"
                << d << " Element deleted!\n\n";
            k--;
            break;

        case 5:
            cout << "\nEnter the element number you want to display: ";
            int p;
            cin >> p;
            if (p > k)
            {
                cout << "\nElement is missing!\n\n";
                continue;
            }
            output_any(header, p);
            break;

        case 6:
            cout << "\nCurrent number of elemets in the list: " << k << "\n\n";
            break;

        case 7:
            header = NULL;
            k = 0;
            cout << "\nThe list is cleared!\n\n";
            break;
        case 8:
            cout << "Input element number :";
            int next;
            cin >> next;
            Next(header, next);
            break;

        case 9:
            cout << "Input element number :";
            int previous;
            cin >> previous;
            Previous(header, previous);
            break;

        case 10:
            cout << "Input elements position to swap" << endl;
            int pos1, pos2;

            cout << "Input position 1" << endl;
            cin >> pos1;

            cout << "Input position 2" << endl;
            cin >> pos2;

            swapNodes(&header, pos1, pos2);
            break;
        default:
            cout << "Input numbers from 1 to 10!\n\n";
            break;
        }
    }

    return 0;
}
