#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <stdlib.h>

void input();
void display();
void choice();
void answer();

struct quend
{
    string que;
    string optA;
    string optB;
    string optC;
    string optD;
    struct quend *next = NULL;
    struct quend *prev = NULL;
};

struct quend *node;
struct quend *head = NULL;
struct quend *ptr;

ifstream file;
string Q, A, B, C, D;

char Ans[10] = {'A', 'A', 'D', 'C', 'B', 'C', 'C', 'C', 'A', 'A'};

int i, j;
int ch;

void input(string q, string a, string b, string c, string d)
{

    node = (struct quend *)malloc(sizeof(struct quend));

    node->que = q;
    node->optA = a;
    node->optB = b;
    node->optC = c;
    node->optD = d;

    if (head == NULL)
    {
        head = node;
        ptr = node;
        ptr->prev = NULL;
    }
    else
    {
        ptr->next = node;
        node->prev = ptr;
        ptr = node;
        node->next = NULL;
    }
    return;
}

void display()
{

    cout << endl;
    cout << ptr->que << endl;
    cout << ptr->optA << endl;
    cout << ptr->optB << endl;
    cout << ptr->optC << endl;
    cout << ptr->optD << endl;

    cout << endl;

    return;
}

void answer()
{
    char c;
    cout << "Enter Answer(In Capital):";
    cin >> c;
    if (c == Ans[i])
    {
        cout << "...TRUE..." << endl;
    }
    else
    {
        cout << "...WRONG...Answer is " << Ans[i] << endl;
    }
    i++;
    return;
}

void choice()
{

    cout << "\nEnter '1' for the Question '2' to Quit :";
    cin >> ch;

    switch (ch)
    {
    case 1:
        getline(file, Q);
        getline(file, A);
        getline(file, B);
        getline(file, C);
        getline(file, D);
        input(Q, A, B, C, D);
        display();
        answer();
        choice();
        break;
    case 2:

        break;
    }
    return;
}

int main()
{

    cout << "\n ......WELCOME TO DATA STRUCTURES QUIZ....." << endl;

    file.open("DS.txt");

    i = 0;
    if (file.is_open())
    {
        choice();
    }
    else
    {
        cout << "ERROR";
    }
    file.close();

    return 0;
}
