// Sat Sep 28 12:50:34 CST 2024

#include <iostream>
using namespace std;

struct Node {
    int data; // data
    Node* next; // pointer
};

// Prints the contents of a linked list, in order.
void printList(Node* list) {
    for (Node* cur = list; cur != nullptr; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << endl;
}

// freeList or deleteList
// Frees all the momory used by a linked list
void freeList(Node* list) {
    while (list != nullptr) {
        // store where to go next
        Node* next = list->next;
        delete list;
        list = next;
    }
}

int measureList(Node* list) {
    int count = 0;
    while (list != nullptr) {
        count++;
        list = list->next;
    }
    return count;
}

int main() {
    Node* list = new Node;
    list->data = 6;
    list->next = nullptr; // 6 (l)
    printList(list);
    
    Node* second = new Node;
    second->data = 4;
    second->next = nullptr;
    list->next = second; // 6 (l) -> 4
    printList(list);
    
    Node* newFront = new Node;
    newFront->data = 1;
    newFront->next = list;
    list = newFront; // 1 (n, l) -> 6 -> 4
    printList(list);
    
    Node* mystery = new Node;
    mystery->data = 10;
    mystery->next = list->next; // 1 (n, l) -> 10 (m) -> 6 -> 4
    list->next = mystery;
    printList(list);
    
    Node* tenNode = list->next;
    Node* fourNode = list->next->next->next;
//    tenNode->next = fourNode; // wrong
    delete tenNode->next;
    tenNode->next = fourNode;
    printList(list); // 1 -> 10 -> 4
    
    freeList(list);
    
    return 0;
}