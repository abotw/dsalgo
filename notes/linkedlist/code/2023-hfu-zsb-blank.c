#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node *next;
} Node;

int main(void)
{
    Node *head, *end, *p;
    int begin = ____;  // blank_1
    
    while (1) {
        p = (Node *)malloc(sizeof(Node));
        scanf("%d", &p->x);
        if (____) // blank_2
            break;
        if (____) { // blank_3
            head = end = p;
            begin = 0;
        } else {
            end->next = p;
            ____; // blank_4
        }
    }
    free(____);    // blank_5
    return 0;
}
