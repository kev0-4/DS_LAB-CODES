#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
};

void insertAtHead(Node *&head, int val)
{
    Node *n = new Node;
    n->previous = NULL;

    n->data = val;
    n->next = head;
    if (head != NULL)
        head->previous = n;

    head = n;
}
void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    Node *n = new Node;
    n->data = val;
    Node *temp = new Node;
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->previous = temp;
    n->next = NULL;
}

void deleteAthead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp;
}

// 1 temp 2
// 1->next = 2, 2->previous = 1, free(temp)
void deletion(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAthead(head);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->previous->next = temp->next;
    if (temp->next != NULL)
        temp->next->previous = temp->previous;

    delete temp;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 60);
    insertAtTail(head, 70);
    insertAtHead(head, 5);
    display(head);
    deletion(head, 4);
    display(head);
    deletion(head, 1);
    display(head);
    return 0;
}