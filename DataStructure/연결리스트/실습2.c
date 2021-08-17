#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int coef;
	int exp;
	struct Node *next;
}Node;
Node *init() {
	Node *node;
	node = (Node *)malloc(sizeof(Node));
	node->coef = NULL;
	node->exp = NULL;
	node->next = NULL;
	return node;
}
void appendTerm(Node *node, int c, int e) {
	Node *t;
	t = init();
	t->coef = c;
	t->exp = e;
	t->next = NULL;
	while (1) {
		if (node->next == NULL) break;
		node = node->next;
	}
	node->next = t;
	node = t;
	//return node;
}
Node *addPoly(Node *x, Node *y) {
	Node *result, *i, *j, *k;
	int sum = 0;
	result = init();
	result->next = NULL;
	i = x->next;
	j = y->next;
	k = result;
	while ((i != NULL) && (j != NULL)) {
		if (i->exp > j->exp) {
			appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(k, j->coef, j->exp);
			j = j->next;
		}
		else {
			sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(k, sum, i->exp);
			}
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(k, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		appendTerm(k, j->coef, j->exp);
		j = j->next;
	}
	return result;
}
int main() {
	int a, b, i, coef, exp;
	Node *p, *q, *result;
	p = init();
	q = init();
	result = init();
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(p, coef, exp);
	}
	scanf("%d", &b);
	for (i = 0; i < b; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(q, coef, exp);
	}
	result = addPoly(p, q);
	while (1) {
		result = result->next;
		if (!result) break;
		printf(" %d %d", result->coef, result->exp);
	}
}