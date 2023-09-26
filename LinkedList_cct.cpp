#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;
void linkedListTraversal(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

node* newNode(int data){
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {65, 75, 85, 95, 105};

    struct node *first = newNode(A[0]);
    node * temp = first;

    struct node* second = newNode(B[0]);
    node* temp2 = second;

    for(int i = 1;i < 5;i++){
        first->next = newNode(A[i]);
        first = first->next;
    }
    for(int i = 1;i<5;i++){
        second->next = newNode(B[i]);
        second = second->next;
    }

    cout << "Original Linked List:" << endl;
    linkedListTraversal(temp);
    linkedListTraversal(temp2);
    
    // LINK LIST MERGE
    first->next = temp2;
    linkedListTraversal(temp);

    //linkedListTraversal(second);
    // vector<int>v;
    // while(a!=NULL){
    //     v.push_back(a->data);
    //     a = a->next;
    }
