#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int e;
	struct Node *next;
}Node;
Node *init() {
	Node *node;
	node = (Node *)malloc(sizeof(Node));
	node->e = NULL;
	node->next = NULL;
	return node;
}
void freeNode(Node *node) {
	if (node) {
		freeNode(node->next);
		free(node);
	}
}
void append(int x, Node *n) {
	Node *new;
	while (1) {
		if (n->next == NULL) break;
		n = n->next;
	}
	new = init();
	new->e = x;
	n->next = new;
}
int subset(Node *p, Node *q) {
	if (p->next == NULL) return 0;
	while (1) {
		if (p== NULL || q== NULL) break;
		if (p->e == q->e) p = p->next;
		q = q->next;
	}
	if (p!= NULL) return p->e;
	else return 0;
}
int main() {
	int a, b,i,j,n;
	Node *q, *p, *result;
	q = init();
	p = init();
	result = init();
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		scanf("%d", &n);
		append(n, p);
	}
	scanf("%d", &b);
	for (i = 0; i < b; i++) {
		scanf("%d", &n);
		append(n, q);
	}
	printf("%d", subset(p, q));
	freeNode(p);
	freeNode(q);
}