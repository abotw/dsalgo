Here's a C++ implementation of a singly linked list with detailed comments explaining each part. The code will be named `LinkedList.cpp`.

## `LinkedList.cpp`

```cpp
#include <iostream>
using namespace std;

// Node class representing an element in the linked list
class Node {
public:
    int data;  // Variable to store the data part of the node
    Node* next; // Pointer to point to the next node in the list

    // Constructor to initialize node with data and set next as NULL
    Node(int value) {
        data = value;
        next = nullptr; // Initially, the next pointer is set to null
    }
};

// LinkedList class to manage the linked list operations
class LinkedList {
private:
    Node* head;  // Pointer to the first node (head) of the linked list

public:
    // Constructor to initialize an empty list (head is null)
    LinkedList() {
        head = nullptr;
    }

    // Function to add a node with a given value to the front of the list
    void insertAtFront(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        newNode->next = head; // Make the new node point to the current head
        head = newNode; // Update head to point to the new node
    }

    // Function to insert a node with a given value at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        if (head == nullptr) {
            // If the list is empty, set the new node as the head
            head = newNode;
        } else {
            Node* temp = head; // Temporary pointer to traverse the list
            while (temp->next != nullptr) {
                temp = temp->next; // Move to the next node
            }
            temp->next = newNode; // Set the last node's next pointer to the new node
        }
    }

    // Function to delete a node from the front of the list
    void deleteFromFront() {
        if (head != nullptr) {
            Node* temp = head; // Temporary pointer to hold the current head
            head = head->next; // Move the head pointer to the next node
            delete temp; // Delete the original head node
        } else {
            cout << "List is already empty." << endl;
        }
    }

    // Function to delete a node from the end of the list
    void deleteFromEnd() {
        if (head == nullptr) {
            // If the list is empty, there is nothing to delete
            cout << "List is empty." << endl;
        } else if (head->next == nullptr) {
            // If there is only one node, delete it and set head to null
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next; // Move to the second-to-last node
            }
            delete temp->next; // Delete the last node
            temp->next = nullptr; // Set the second-to-last node's next pointer to null
        }
    }

    // Function to display the list contents
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head; // Temporary pointer to traverse the list
        while (temp != nullptr) {
            cout << temp->data << " -> "; // Print the current node's data
            temp = temp->next; // Move to the next node
        }
        cout << "NULL" << endl; // Indicate the end of the list
    }

    // Destructor to free the memory of all nodes when the list is destroyed
    ~LinkedList() {
        while (head != nullptr) {
            deleteFromFront(); // Keep deleting nodes from the front
        }
    }
};

// Main function to demonstrate linked list operations
int main() {
    LinkedList list; // Create an instance of the LinkedList class

    // Inserting elements into the linked list
    list.insertAtFront(10); // Insert 10 at the front
    list.insertAtFront(20); // Insert 20 at the front
    list.insertAtEnd(30);   // Insert 30 at the end
    list.insertAtEnd(40);   // Insert 40 at the end

    // Display the linked list
    cout << "Current list: ";
    list.display();

    // Deleting elements from the linked list
    list.deleteFromFront(); // Delete the front element
    cout << "After deleting from front: ";
    list.display();

    list.deleteFromEnd(); // Delete the last element
    cout << "After deleting from end: ";
    list.display();

    return 0;
}
```

### Explanation:
- **Node Class**: This represents each element in the linked list, containing data and a pointer to the next node.
- **LinkedList Class**: Contains the head pointer and methods to manipulate the linked list (insert, delete, display).
- **insertAtFront / insertAtEnd**: Functions to add elements either at the beginning or the end of the list.
- **deleteFromFront / deleteFromEnd**: Functions to remove elements from the beginning or the end.
- **Destructor**: Ensures that all allocated memory is released when the linked list object is destroyed.

This implementation gives a basic overview of how a linked list works in C++.