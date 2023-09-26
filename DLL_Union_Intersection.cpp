#include <iostream>
#include <unordered_set>

using namespace std;

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to find the intersection of two lists
Node* findIntersection(Node* list1, Node* list2) {
    unordered_set<int> elements;
    Node* result = nullptr;
    
    // Traverse list1 and store elements in a set
    Node* current = list1;
    while (current != nullptr) {
        elements.insert(current->data);
        current = current->next;
    }
    
    // Traverse list2 and check if elements are in the set
    current = list2;
    while (current != nullptr) {
        if (elements.find(current->data) != elements.end()) {
            insertAtEnd(result, current->data);
        }
        current = current->next;
    }
    
    return result;
}

// Function to find the union of two lists
Node* findUnion(Node* list1, Node* list2) {
    unordered_set<int> elements;
    Node* result = nullptr;
    
    // Traverse list1 and store elements in a set and result list
    Node* current = list1;
    while (current != nullptr) {
        elements.insert(current->data);
        insertAtEnd(result, current->data);
        current = current->next;
    }
    
    // Traverse list2 and check if elements are in the set, if not, add to result
    current = list2;
    while (current != nullptr) {
        if (elements.find(current->data) == elements.end()) {
            insertAtEnd(result, current->data);
        }
        current = current->next;
    }
    
    return result;
}

// Function to display a doubly linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Insert elements into list1 and list2
    insertAtEnd(list1, 1);
    insertAtEnd(list1, 2);
    insertAtEnd(list1, 3);
    
    insertAtEnd(list2, 2);
    insertAtEnd(list2, 3);
    insertAtEnd(list2, 4);

    // Find and display the intersection
    Node* intersection = findIntersection(list1, list2);
    cout << "Intersection: ";
    displayList(intersection);

    // Find and display the union
    Node* unionList = findUnion(list1, list2);
    cout << "Union: ";
    displayList(unionList);

    return 0;
}
