#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;             // 存储节点数据
    struct Node *next;    // 指向下一个节点的指针
} Node;

// 创建新节点
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = data;  // 初始化节点数据
    newNode->next = NULL;  // 新节点的下一节点指针设为 NULL
    return newNode;
}

// 在值为a的节点之前插入值为b的新节点，如果a不存在，则插入到链表末尾
void insertBefore(Node **head, int a, int b) {
    Node *newNode = createNode(b);  // 创建新节点
    Node *current = *head;          // 用于遍历链表的指针
    Node *prev = NULL;              // 保存当前节点的前一个节点

    // 遍历链表，找到值为a的节点
    while (current != NULL && current->data != a) {
        prev = current;          // 记录前一个节点
        current = current->next; // 移动到下一个节点
    }

    // 如果找到了值为a的节点
    if (current != NULL) {
        if (prev == NULL) {
            // 如果a节点是头节点，将新节点插入到头节点之前
            newNode->next = *head;
            *head = newNode;
        } else {
            // 如果a节点不是头节点，将新节点插入到a节点之前
            prev->next = newNode;
            newNode->next = current;
        }
    } else {
        // 如果未找到值为a的节点，则插入到链表末尾
        if (*head == NULL) {
            *head = newNode;  // 链表为空时，将新节点设为头节点
        } else {
            // 找到链表尾部，插入新节点
            current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// 打印链表
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);  // 打印当前节点数据
        temp = temp->next;          // 移动到下一个节点
    }
    printf("\n");
}

// 释放链表所占用的内存
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // 创建链表并存储学号 24302081014
    int student_id[] = {2, 4, 3, 0, 2, 0, 8, 1, 0, 1, 4};
    int n = sizeof(student_id) / sizeof(student_id[0]);
    
    Node *head = NULL; // 初始化链表为空

    // 按顺序将学号各位数字插入链表
    for (int i = 0; i < n; i++) {
        insertBefore(&head, -1, student_id[i]);  // -1 作为不存在的值，等效于插入到链表末尾
    }

    printf("初始链表: ");
    printList(head);

    // 在值为8的节点前插入值为7的新节点
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == 8) {
            insertBefore(&head, 8, 7);  // 在值为8的节点之前插入7
        }
        temp = temp->next;
    }

    printf("插入后的链表: ");
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}
