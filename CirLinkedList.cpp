#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MaxSize 100
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtTail(struct Node*& Lnode, int a[], int n) {
    Node* s, * r;
    Lnode = (Node*)malloc(sizeof(Node));
    r = Lnode;
    for (int i = 0; i < n; ++i) {
        s = (Node*)malloc(sizeof(Node));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = head;
}

void printList(struct Node*& head) {
    Node* p = head->next;
    while (p != head) {
        cout << p->data;
        p = p->next;
    }

}
int main() {
    int a[MaxSize];
    int n = 10;
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    insertAtTail(head, a, n);
    printList(head);
    return 0;
}
