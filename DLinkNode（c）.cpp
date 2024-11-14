#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MaxSize 100
using namespace std;
struct DLNode {
    int data;
    struct DLNode* prior;
    struct DLNode* next;
};
struct DLNode* head = NULL;
struct DLNode* Last = NULL;
void insertAtTail(struct DLNode*& Lnode, int a[], int n) {
    DLNode* s, * r;
    Lnode = (DLNode*)malloc(sizeof(DLNode));
    r = Lnode;
    for (int i = 0; i < n; ++i) {
        s = (DLNode*)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    Last = r;
    r->next = NULL;
}

void PSPrintList(struct DLNode*& head) {
    DLNode* p = head->next;
    while (p != NULL) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

void RSPrintList(struct DLNode*& Last) {
    DLNode* p = Last;
    while (p!=head) {
        cout << p->data;
        p = p->prior;
    }
    cout << endl;
}
int main() {
    int a[MaxSize];
    int n = 10;
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    insertAtTail(head, a, n);
    PSPrintList(head);
    RSPrintList(Last);
    return 0;
}
