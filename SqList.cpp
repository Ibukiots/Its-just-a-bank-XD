#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100  

typedef struct {
    int data[MaxSize];
    int length;
} List;

void initList(List* list) {
    list->length = 0;
}

void setNode(List* list, int val) {
    if (list->length >= MaxSize) {
        fprintf(stderr, "List is full!\n");
        return;
    }
    list->data[list->length++] = val;
}

void printNode(const List* list) {
    for (int i = 0; i < list->length; ++i) {
        printf("%d\n", list->data[i]);
    }
}

void modifyNode(List* list, int index, int val) {
    if (index < 0 || index >= list->length) {
        fprintf(stderr, "Index out of range!\n");
        return;
    }
    list->data[index] = val;
}

int main() {
    List demoList;
    initList(&demoList);

    setNode(&demoList, 1);
    setNode(&demoList, 1);
    setNode(&demoList, 4);
    setNode(&demoList, 5);
    setNode(&demoList, 1);
    setNode(&demoList, 3);
    modifyNode(&demoList, 5, 4);
    printNode(&demoList);

    return 0;
}