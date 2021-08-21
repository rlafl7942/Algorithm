#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int e;
	struct Node *next;
}Node;
Node *init() {
	Node *node;
	node = (Node *)malloc(sizeof(Node));
	node->e = 0;
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
Node *unionset(Node *a, Node *b) {
	Node *u;
	u = init();
	if (a->next == NULL && b->next == NULL) {
		append(0, u);
		return u;
	}
	a = a->next;
	b = b->next;
	while (1) {
		if (a == NULL || b == NULL) break;
		if (a->e < b->e) {
			append(a->e, u);
			a = a->next;
		}
		else if (a->e > b->e) {
			append(b->e, u);
			b = b->next;
		}
		else {
			append(a->e, u);
			a = a->next;
			b = b->next;
		}
	}
	if (a != NULL) {
		while (1) {
			if (a == NULL) break;
			append(a->e, u);
			a = a->next;
		}
	}
	else if (b != NULL) {
		while (1) {
			if (b == NULL) break;
			append(b->e, u);
			b = b->next;
		}
	}
	return u;
}
Node *intersect(Node *a, Node *b) {
	Node *u;
	u = init();
	if (a->next == NULL || b->next == NULL) {
		append(0, u);
		return u;
	}
	a = a->next;
	b = b->next;
	while (1) {
		if (a == NULL || b == NULL) break;
		if (a->e == b->e) {
			append(a->e, u);
			a = a->next;
			b = b->next;
		}
		else if (a->e < b->e) a = a->next;
		else b = b->next;
	}
	return u;

}
int main() {
	Node *a, *b, *result;
	int n, e, i;
	a = init();
	b = init();
	result = init();
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &e);
		append(e, a);
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &e);
		append(e, b);
	}
	result = unionset(a, b);
	while (1) {
		result = result->next;
		printf(" %d", result->e);
		if (!result->next) break;
	}
	printf("\n");
	result = init();
	result = intersect(a, b);
	while (1) {
		result = result->next;
		printf(" %d", result->e);
		if (!result->next) break;
	}
}