#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

struct SqQueue {
	int data[Maxsize];
	int front, rear;
};

void InitQueue(SqQueue*&q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

bool EnQueue(SqQueue*&q,int e){
	if (q->rear == Maxsize-1) {
		return false;
	}
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

bool deQueue(SqQueue*& q, int e) {
	if (q->front == q->rear) {
		return false;
	}
	q->front++;
	e = q->data[q->front];
	return true;
}

void PrintQueue(SqQueue*&q){
	int p;
	p = q->front;
	p++;
	for (p; p <= q->rear; p++) {
		printf("%d\n",q->data[p]);
	}
}

int main() {
	SqQueue* q;
	InitQueue(q);
	EnQueue(q, 1);
	EnQueue(q, 1);
	EnQueue(q, 4);
	EnQueue(q, 5);
	EnQueue(q, 1);
	EnQueue(q, 4);
	PrintQueue(q);
}