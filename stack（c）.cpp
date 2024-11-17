#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MaxSize 100
typedef struct Stack {
	int data[MaxSize];
	int top;
}SqStack;

static int Size=0;

void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestroyStack(SqStack*& s){
	free(s);
}

bool StackEmpty(SqStack*& s){
	return(s->top == 1);
}

bool StackFull(SqStack*& s) {
	return(s->top == MaxSize - 1);
}

bool PushStack(SqStack*& s, int e) {
	if (s->top == MaxSize - 1) {
		return false;
	}
	else {
		s->top++;
		s->data[s->top] = e;
		Size++;
		return true;
	}
}

bool PopStack(SqStack * &s, int& e) {
	if (s->top == -1) {
			return false;
		}
	else {
		e = s->data[s->top];
		s->top--;
		Size--;
		return true;
		}
}

bool GetStackTop(SqStack*& s,int& e) {
	if (s->top == -1) {
		return false;
	}
	else {
		e = s->data[s->top];
		return true;
	}
}

void StackOc(SqStack*& s) {
	printf("%d\n", Size);
}

int main() {
	Stack* s;
	int e;
	InitStack(s);
	PushStack(s, 1);
	PushStack(s, 1);
	PushStack(s, 4);
	PushStack(s, 5);
	PushStack(s, 1);
	PushStack(s, 4);
	StackEmpty(s);
	StackFull(s);
	GetStackTop(s,e);
	printf("%d\n", e);
	StackOc(s);
}