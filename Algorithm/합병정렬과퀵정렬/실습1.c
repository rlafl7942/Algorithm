#include <stdio.h>
typedef struct Node {
	int ele;
	struct Node *next;
}Node;
typedef struct partList {
	struct Node *l1;
	struct Node *l2;
}partList;
void *init() {
	Node *p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	p->ele = 0;
	return p;
}
void freeNode(Node *x) {
	if (x) {
		freeNode(x->next);
		free(x);
	}
}
void add(Node *x, int a) {
	Node *p = init();
	int i = 0;
	p->ele = a;
	while (1) {
		if (x->next == NULL) break;
		x = x->next;
	}
	x->next = p;
}
void print(Node *x) {
	while (1) {
		if (x->next == NULL) break;
		printf(" %d", x->ele);
		x = x->next;
	}
	printf(" %d", x->ele);
	printf("\n");
}
Node *merge(Node *l1, Node *l2) { //합병 정렬
	Node *p, *l;
	/*printf("l1:");
	print(l1);
	printf("l2:");
	print(l2);*/
	if (l1->ele <= l2->ele) {
		l = l1;
		l1 = l1->next;
		p = l; 
	}
	else {
		l = l2;
		l2 = l2->next;
		p = l;
	}
	while (l1!=NULL && l2!=NULL) {
		if (l1->ele <= l2->ele) {
			p->next = l1;
			l1 = l1->next;
			p = p->next;
		}
		else {
			p->next = l2;
			l2 = l2->next;
			p = p->next;
		}
	}
	while (1) {
		if (l1==NULL) break;
		p->next = l1;
		p = l1;
		l1 = l1->next;
	}
	while (1) {
		if (l2==NULL) break;
		p->next = l2;
		p = l2;
		l2 = l2->next;
	}
	return l;
}
void partition(Node *l, int k, Node *l1, Node *l2) { //분할
	int i;
	Node *tmp = l;
	if (k == 1) {
		*l1 = *tmp;
		*l2 = *tmp->next;
		l1->next = NULL;
		return;
	}
	*l1 = *tmp;
	for (i = 0; i < k - 1; i++) {
		tmp = tmp->next;
	}
	*l2 = *tmp->next;
	tmp->next = NULL;

}
void mergeSort(Node *x, int n) { 
	Node *a, *b;
	a = init();
	b = init();
	if (n > 1) {
		partition(x, n / 2, a, b);
		mergeSort(a, n / 2);
		mergeSort(b, n - n / 2);
		*x = *merge(a, b);
	}
}
int main() {
	Node *header;
	int n, i, a;
	scanf("%d", &n);
	header = init();
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		add(header, a);
	}
	mergeSort(header->next, n);
	print(header->next);
	freeNode(header);
}