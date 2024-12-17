#include <stdio.h>
#include <stdlib.h>


struct LinkStNode {
	int data;
	struct LinkStNode* next;
};



void InitStNode(LinkStNode*& s) {
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

bool Push(LinkStNode*& s, int e) {
	LinkStNode* p;
	p=(LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}

bool Pop(LinkStNode* s, int e) {
	LinkStNode* p;
	if (s->next = NULL) 
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
}

int main() {
	LinkStNode* p = NULL;
	InitStNode(p);
	Push(p, 1);
	Push(p, 1);
	Push(p, 4);
	Push(p, 5);
	Push(p, 1);
	Push(p, 4);

}