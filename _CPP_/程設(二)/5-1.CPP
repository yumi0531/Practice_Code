#include <iostream>
using namespace std;

struct node
{
    string data;
    node *next;
} word;

void add(node **head, string data);
void insert(node **head, string target, string input);
void remove(node **head, string target);
void show(node **head);

void add(node **head, string data)
{
    node *temp;      // temp is a pointer, point to a node
    temp = new node; // new 一個記憶體空間
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        node *ptr;
        for (ptr = *head; ptr->next != NULL; ptr = ptr->next)
            ;
        ptr->next = temp;
    }
}

void insert(node **head, string target, string input)
{
    node *temp;
    temp = new node;
    temp->data = input;
    node *ptr;
    if ((*head)->data == target)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        for (ptr = *head; ptr->next->data != target; ptr = ptr->next)
            ;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void remove(node **head, string target)
{
    node *ptr;
    if ((*head)->data == target)
    {
        *head = (*head)->next;
    }
    else
    {
        for (ptr = *head; ptr->next->data != target; ptr = ptr->next)
            ;
        ptr->next = ptr->next->next;
    }
}

void show(node **head)
{
    node *ptr;
    for (ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->data;
        if (ptr->next != NULL)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    string str;
    string x, n;
    // string str_arr[30];
    node *head; //一開始先創一個head
    head = NULL;
    node *current = head;
    while (cin >> str)
    {
        if (str == "ADD")
        {
            cin >> x;
            add(&head, x);
        }
        else if (str == "INSERT")
        {
            cin >> x;
            cin >> n;
            insert(&head, n, x);
        }
        else if (str == "REMOVE")
        {
            cin >> x;
            remove(&head, x);
        }
        else if (str == "SHOW")
        {
            show(&head);
        }
    }

    return 0;
}