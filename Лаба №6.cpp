#include <iostream>
#include <string>
#define N 11
using namespace std;

const int SurLen = 20;
struct stud
{
    int school_number;
    char headmaster_surname[SurLen];
    int amount_of_children;
    void stud_out()
    {
        cout << school_number << "\t" << headmaster_surname << "\t" << amount_of_children << "\t" << endl;
    }
};

int main()
{
    stud N1[N], N2[N], N3[N];
    for (int i = 0; i < N; i++)
    {
        cout << "School number :";
        cin >> N1[i].school_number;
        cout << "Input Headmaster surname :";
        cin >> N1[i].headmaster_surname;
        cout << "Amount of children :";
        cin >> N1[i].amount_of_children;
        N2[i] = N3[i] = N1[i];
    }

    int exit = 1;
    while (exit != 0)
    {
        cout << "Pick order of passenger info:" << endl;
        cout << "1-Sorted by School number   \t 2- Sorted by Amount of children" << endl;
        cout << "3- in previous order \t 0- Exit" << endl;
        int menu;
        cin >> menu;
        switch (menu)
        {
        case 0:
            exit = 0;
            cout << "Exit successfully" << endl;
            break;

        case 1:
            for (int i = 0; i < N; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (N2[i].school_number > N2[j].school_number)
                    {
                        swap(N2[i], N2[j]);
                    }
                }
            }

            for (int i = 0; i < N; i++)
            {
                N2[i].stud_out();
            }
            break;

        case 2:
            for (int i = 0; i < N; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (N3[i].amount_of_children > N3[j].amount_of_children)
                    {
                        swap(N3[i], N3[j]);
                    }
                }
            }

            for (int i = 0; i < N; i++)
            {
                N3[i].stud_out();
            }
            break;

        case 3:
            for (int i = 0; i < N; i++)
            {
                N1[i].stud_out();
            }
            break;

        default:
            cout << "Error" << endl;
            exit = 0;
            break;
        }
    }
}
