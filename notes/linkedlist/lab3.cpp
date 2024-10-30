// Last Updated: Fri Oct 18 17:12:22 CST 2024

#include <iostream>
#include <vector>
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

vector<int> inputList();
Node *createNode(int data, Node *head);
Node *createList(vector<int> listArr);
void printListIterative(Node* head);
void insertInOrder(Node *head, int val);
Node *reverseList(Node *head);

/* Main program */
int main() {
    vector<int> ascListArr = inputList();
    // init
    Node *ascList = createList(ascListArr);
    cout << "Default list: " << endl;
    printListIterative(ascList);
    // insert in order
    insertInOrder(ascList, 7);
    cout << "After inserting in order: " << endl;
    printListIterative(ascList);
    // reverse list
    cout << "After reversing the list: " << endl;
    ascList = reverseList(ascList);
    printListIterative(ascList);
    return 0;
}

/*
 * Function: inputList
 * Usage: vector<int> inputList()
 */
 
vector<int> inputList() {
    vector<int> inputArray;
    int input;
    
    cout << "Please enter integers (enter -1 to stop):" << endl;
    
    while (true) {
        cin >> input;
        if (input == -1) {
            break;
        }
        inputArray.push_back(input);
    }

    return inputArray;
}

/*
 * Function: createList
 * Usage: Node *list = createList(listArr);
 * ----------------------------------------
 * Create a linked list.
 * The function builds the list backwards and returns a pointer to the first node.
 */
 
Node *createList(vector<int> listArr) {
    Node *tp = createNode(listArr[0], NULL);
    for (int i = 1; i < listArr.size(); i++) {
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
 * Function: reverseList
 * Usage: Node *reverseList(Node *head);
 * -------------------------------------
 * Function to reverse the list.
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

/*
 * Function: printListIterative
 * Time complexity: O(n), where n is the number of nodes
 * ----------------------------
 * Function to print the contents of the list iteratively
 */
 
void printListIterative(Node* head) {
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;
}