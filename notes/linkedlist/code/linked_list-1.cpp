// Sat Sep 28 23:03:51 CST 2024

#include <iostream>
using namespace std;

struct Node {
    int data; // data
    Node* next; // pointer
};

// Prints the contents of a linked list, in order.
// O(n)
void printList(Node* list) {
    for (Node* cur = list; cur != nullptr; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << endl;
}

// Prints the contents of a linked list, in recursive approach
void printListRec(Node* list) {
    // Base case
    if (list == nullptr) {
        return;
    }
    // Recursive case
    cout << list->data << endl;
    printListRec(list->next);
}

// freeList or deleteList
// Frees all the momory used by a linked list
void freeList(Node* head) {
    Node* next = head;
    while (head != nullptr) {
        next = head->next;  // store where to go next
        delete head;
        head = next;
    }
}

// O(1)
void prependList(Node* head, int data) {
    Node* newFront = new Node;
    newFront->data = data;
    newFront->next = head;
    head = newFront;
}

// O(n)
void insertNode(Node* head, int val, int data) {
    Node* cur = head;
    while (cur != nullptr && cur->data != val) {
        cur = cur->next;
    }
    Node* toInsert = new Node;
    toInsert->data = data;
    toInsert->next = cur->next;
    cur->next = toInsert;
}

// O(n)
void appendList(Node* head, int data) {
    Node* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    Node* newEnd = new Node;
    newEnd->data = data;
    newEnd->next = nullptr;
    cur->next = newEnd;
}

// O(n)
void insertOrAppend(Node* head, int val, int data) {
    // traverse to node before value to insert
    Node* prev = nullptr;
    Node* cur = head;
    bool flag = 0;
    while (cur != nullptr) {
        if (cur->data == val) {
            // insert
            Node* toInsert = new Node;
            toInsert->data = data;
            prev->next = toInsert;
            toInsert->next = cur;
            flag = 1;
        }
        prev = cur;
        cur = cur->next;
    }
    // append
    if (!flag) {
        appendList(head, data);
    }
}

// O(n)
void deleteNode(Node* head, int val) {
    // traverse to node before value to delete
    Node* prev = nullptr;
    Node* cur = head;
    while (cur != nullptr && cur->data != val) {
        prev = cur;
        cur = cur->next;
    }
    // delete and rewire
    Node* next = cur->next;
    delete cur;
    if (prev != nullptr) {
        prev->next = next;
    } else {
        head = next;
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
    // init
    Node* stuNum = new Node;
    stuNum->data = 2;
    
    appendList(stuNum, 4);
    appendList(stuNum, 3);
    appendList(stuNum, 0);
    appendList(stuNum, 2);
    appendList(stuNum, 0);
    appendList(stuNum, 8);
    appendList(stuNum, 1);
    appendList(stuNum, 0);
    appendList(stuNum, 1);
    appendList(stuNum, 5);
    
    cout << "My student number after initilization: " << endl;
    printList(stuNum);
    
    // insert or append
    insertOrAppend(stuNum, 8, 7);
    cout << "My student number after inserting or appending by value: " << endl;
    printList(stuNum);
    
    return 0;
}