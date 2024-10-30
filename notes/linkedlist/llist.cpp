#include <iostream>
#include <array>
using namespace std;

/*
 * Type: Node
 * ----------
 * This structure contains the data of the node and a link to the next one.
 */

struct Node {
    int data;
    Node *next;
};

int getListLength(Node* head);
Node *createNode(int data, Node *head);
Node *createList(int listArr[], int size);
void printListIterative(Node* head);

void insertInOrder(Node *head, int val);
Node *reverseList(Node *head);

/* Main program */
int main() {
//    Node* head = nullptr;  // Initialize an empty list
//
//    // Example usage of the linked list functions:
//    appendNode(head, 10);  // Append 10 to the list
//    appendNode(head, 20);  // Append 20 to the list
//    prependNode(head, 5);  // Prepend 5 to the list
//
//    // Print the list iteratively and recursively
//    cout << "List (iterative): ";
//    printListIterative(head);
//
//    cout << "List (recursive): ";
//    printListRecursive(head);
//    cout << endl;
//
//    // Insert a new node after a node with value 10
//    insertNodeAfter(head, 10, 15);
//    cout << "List after inserting 15 after 10: ";
//    printListIterative(head);
//
//    // Delete the node with value 20
//    deleteNodeByValue(head, 20);
//    cout << "List after deleting 20: ";
//    printListIterative(head);
//
//    // Print the length of the list
//    cout << "Length of list: " << getListLength(head) << endl;
//
//    // Free the memory allocated for the list
//    deleteList(head);

    int ascListArr[] = {10, 8, 6, 4, 2};
    int ascListSize = sizeof(ascListArr) / sizeof(ascListArr[0]);
    // init
    Node *ascList = createList(ascListArr, ascListSize);
    printListIterative(ascList);
//  insert in order
    insertInOrder(ascList, 7);
    printListIterative(ascList);
    // reverse list
    ascList = reverseList(ascList);
    printListIterative(ascList);
    return 0;
}

/*
 * Function: createList
 * Usage: Node *list = createList(listArr, size);
 * ----------------------------------------
 * Create a linked list.
 * The function builds the list backwards and returns a pointer to the first node.
 */

Node *createList(int listArr[], int size) {
    Node *tp = createNode(listArr[0], NULL);
    for (int i = 1; i < size; i++) {
        tp = createNode(listArr[i], tp);
    }
    return tp;
}

/*
 * Function: createNode
 * Usage: Node *node = createNode(data, head);
 * --------------------
 * Create a new Node structure with the specified data.
 */

Node *createNode(int data, Node *head) {
    // create a new node structure
    Node *node = new Node;
    node->data = data;
    // put the node first
    node->next = head;
    return node;    // new node as the new head
}

/*
 * Function: insertInOrder
 * Usage: void insertInorder(head, val);
 */

void insertInOrder(Node *head, int val) {
    Node *cur = head;
    while (cur->next != nullptr && cur->next->data < val) {
        cur = cur->next;
    }
    Node *node = new Node;
    node->data = val;
    if (cur->next != nullptr) {
        node->next = cur->next;
        cur->next = node;
    }
    cur->next = node;
}

/*
 * Function: getListLength()
 * Time complexity: O(n)
 * -------------------------
 * Function to measure the length of the linked list
 */

int getListLength(Node* head) {
    int length = 0;
    Node* cur = head;

    while (cur != nullptr) {
        length++;  // Count the nodes
        cur = cur->next;
    }

    return length;
}

/*
 * Function: reverseList
 * Usage: Node *reverseList(Node *head);
 */

Node *reverseList(Node *head) {
    Node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to insert a new node after a specific node in the list
// Time complexity: O(n)
/*
 * Function: 
 */
void insertNodeAfter(Node* head, int targetData, int newData) {
    Node* current = head;
    // Traverse to find the target node
    while (current != nullptr && current->data != targetData) {
        current = current->next;
    }

    // If the target node is found, insert a new node after it
    if (current != nullptr) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the contents of the list iteratively
// Time complexity: O(n), where n is the number of nodes
void printListIterative(Node* head) {
    // Traverse through the list starting from the first node
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " ";  // Output the data of each node
    }
    cout << endl;  // Newline after printing all nodes
}

// Function to print the contents of the list recursively
// Time complexity: O(n)
void printListRecursive(Node* head) {
    if (head == nullptr) {
        return;  // Base case: Stop recursion if the list is empty
    }
    cout << head->data << " ";  // Print current node's data
    printListRecursive(head->next);  // Recurse for the next node
}

// Function to free all memory allocated for the linked list
// Time complexity: O(n)
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* nextNode = head->next;  // Store the next node
        delete head;  // Delete current node
        head = nextNode;  // Move to the next node
    }
    head = nullptr;  // After freeing all nodes, reset head to nullptr
}

// Function to prepend a node to the beginning of the list
// Time complexity: O(1)
void prependNode(Node*& head, int newData) {
    Node* newNode = new Node;  // Allocate a new node
    newNode->data = newData;  // Set the data
    newNode->next = head;  // Point the new node to the current head
    head = newNode;  // Update the head to the new node
}

// Function to append a node to the end of the list
// Time complexity: O(n)
void appendNode(Node*& head, int newData) {
    Node* newNode = new Node;  // Create a new node
    newNode->data = newData;
    newNode->next = nullptr;  // Set it as the last node

    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;  // Append the new node at the end
}

// Function to delete a node by value
// Time complexity: O(n)
void deleteNodeByValue(Node*& head, int targetData) {
    Node* current = head;
    Node* previous = nullptr;

    // Traverse to find the target node
    while (current != nullptr && current->data != targetData) {
        previous = current;
        current = current->next;
    }

    // If the node is found, delete it
    if (current != nullptr) {
        if (previous != nullptr) {
            previous->next = current->next;  // Bypass the current node
        } else {
            head = current->next;  // If deleting the head, update head
        }
        delete current;  // Free memory
    }
}


