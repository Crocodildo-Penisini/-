#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define SurLen 20

struct stud {
    int school_number;
    char headmaster_surname[SurLen];
    int amount_of_children;
    bool equals(const stud& y) const {
        return school_number == y.school_number
            && strcmp(headmaster_surname, y.headmaster_surname) == 0
            && amount_of_children == y.amount_of_children;
    }
};

struct Node {
    stud d;
    Node* prev;
    Node* next;
    Node(const stud& data) : d(data), prev(nullptr), next(nullptr) {}
};

void printList(Node* head) {
    cout << "----DoublyLinkedList----\n";
    for (Node* p = head; p; p = p->next) {
        cout << "School number     : " << p->d.school_number << endl;
        cout << "Headmaster surname: " << p->d.headmaster_surname << endl;
        cout << "Amount of children: " << p->d.amount_of_children << endl;
        cout << endl;
    }
}

void append(Node*& head, Node*& tail) {
    stud d;
    cout << "\nSchool number     : "; cin >> d.school_number;
    cout << "Headmaster surname: "; cin >> d.headmaster_surname;
    cout << "Amount of children: "; cin >> d.amount_of_children;
    Node* new_node = new Node(d);
    if (!head) head = tail = new_node;
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    cout << endl;
}

void deleteList(Node*& head, Node*& tail) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
}

void deleteNode(Node*& head, Node*& tail, int pos) {
    if (!head || pos <= 0) return;
    Node* cur = head;
    for (int i = 1; cur && i < pos; ++i) cur = cur->next;
    if (!cur) return;
    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;
    delete cur;
}

int sizeOf(Node* head) {
    int cnt = 0;
    for (Node* p = head; p; p = p->next) ++cnt;
    return cnt;
}

Node* getKthNode(Node* head, int k) {
    if (k <= 0) return nullptr;
    Node* cur = head;
    for (int i = 1; cur && i < k; ++i) cur = cur->next;
    return cur;
}

// Clone src list into destHead and destTail
void cloneList(Node* srcHead, Node*& destHead, Node*& destTail) {
    destHead = destTail = nullptr;
    for (Node* cur = srcHead; cur; cur = cur->next) {
        Node* new_node = new Node(cur->d);
        if (!destHead) destHead = destTail = new_node;
        else {
            destTail->next = new_node;
            new_node->prev = destTail;
            destTail = new_node;
        }
    }
}

void mergeLists(Node*& head1, Node*& tail1, Node* head2, Node* tail2) {
    if (!head1) head1 = head2, tail1 = tail2;
    else if (head2) {
        tail1->next = head2;
        head2->prev = tail1;
        tail1 = tail2;
    }
}

void insertBefore(Node*& head, Node*& tail, int pos) {
    int n = sizeOf(head);
    if (pos < 1 || pos > n) { cout << "Invalid position\n"; return; }
    stud d;
    cout << "\nSchool number     : "; cin >> d.school_number;
    cout << "Headmaster surname: "; cin >> d.headmaster_surname;
    cout << "Amount of children: "; cin >> d.amount_of_children;
    Node* new_node = new Node(d);
    Node* cur = head;
    for (int i = 1; i < pos; ++i) cur = cur->next;
    new_node->prev = cur->prev;
    new_node->next = cur;
    if (cur->prev) cur->prev->next = new_node;
    else head = new_node;
    cur->prev = new_node;
}

int search(Node* head) {
    stud key;
    cout << "Enter element to search:\n";
    cout << "School number     : "; cin >> key.school_number;
    cout << "Headmaster surname: "; cin >> key.headmaster_surname;
    cout << "Amount of children: "; cin >> key.amount_of_children;
    Node* cur = head;
    int pos = 1;
    while (cur) {
        if (cur->d.equals(key)) return pos;
        cur = cur->next;
        ++pos;
    }
    return 0;
}

void splitList(Node* head, int p, int q) {
    int n = sizeOf(head);
    if (p + q > n) { cout << "Ratio exceeds length\n"; return; }
    Node* cur = head;
    for (int i = 1; i < p; ++i) cur = cur->next;
    Node* head2 = cur->next;
    cur->next = nullptr;
    if (head2) head2->prev = nullptr;
    printList(head);
    cout << "----Second part----\n";
    printList(head2);
}

void swapAdjacent(Node*& head, Node*& tail, int pos) {
    Node* x = getKthNode(head, pos);
    if (!x || !x->next) return;
    Node* y = x->next;
    if (x->prev) x->prev->next = y;
    else head = y;
    if (y->next) y->next->prev = x;
    else tail = x;
    x->next = y->next;
    y->prev = x->prev;
    y->next = x;
    x->prev = y;
}

int main() {
    Node* head = nullptr, * tail = nullptr;
    Node* cloneHead = nullptr, * cloneTail = nullptr;
    Node* head2 = nullptr, * tail2 = nullptr;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << left << setw(25) << "1- Clone list" << setw(25) << "7- InsertBefore" << "\n";
        cout << setw(25) << "2- Append" << setw(25) << "8- Search" << "\n";
        cout << setw(25) << "3- Size" << setw(25) << "9- Split" << "\n";
        cout << setw(25) << "4- Delete node" << setw(25) << "10- Print" << "\n";
        cout << setw(25) << "5- Merge" << setw(25) << "11- DeleteList" << "\n";
        cout << setw(25) << "6- Get Kth" << setw(25) << "12- SwapAdj" << "\n";
        cout << setw(25) << "0- Exit" << "\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cloneList(head, cloneHead, cloneTail);
            printList(cloneHead);
            break;
        case 2: append(head, tail); break;
        case 3: cout << "Size: " << sizeOf(head) << "\n"; break;
        case 4: {
            int pos; cout << "Position: "; cin >> pos;
            deleteNode(head, tail, pos);
            break;
        }
        case 5: {
            cout << "Build second list (1-append, other-exit):\n";
            int f;
            while (cin >> f && f == 1) append(head2, tail2);
            mergeLists(head, tail, head2, tail2);
            break;
        }
        case 6: {
            int k; cout << "K: "; cin >> k;
            Node* kn = getKthNode(head, k);
            if (kn) {
                cout << "School number     : " << kn->d.school_number << endl;
                cout << "Headmaster surname: " << kn->d.headmaster_surname << endl;
                cout << "Amount of children: " << kn->d.amount_of_children << endl;
            }
            else {
                cout << "No such element" << endl;
            }
            break;
        }
        case 7: {
            int pos; cout << "Pos: "; cin >> pos;
            insertBefore(head, tail, pos);
            break;
        }
        case 8: {
            int res = search(head);
            if (res) cout << "Found at " << res << "\n";
            else cout << "Not found\n";
            break;
        }
        case 9: {
            int p, q; cout << "p: "; cin >> p;
            cout << "q: "; cin >> q;
            splitList(head, p, q);
            break;
        }
        case 10: printList(head); break;
        case 11: deleteList(head, tail); break;
        case 12: {
            int pos; cout << "Pos: "; cin >> pos;
            swapAdjacent(head, tail, pos);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
