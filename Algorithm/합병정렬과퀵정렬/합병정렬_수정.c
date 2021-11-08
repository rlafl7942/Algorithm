#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	struct node *next;
	int key;
}node;
typedef struct lists {
	struct node *l1;
	struct node *l2;
}lists;
node *init() {
	node *p = (node *)malloc(sizeof(node));
	p->next = NULL;
	return p;
}
void freeNode(node *node) {
	if (node) {
		freeNode(node->next);
		free(node);
	}
}
void insertItem(node *list, int k) {
	node *p = init();
	p->key = k;
	while (1) {
		if (list->next == NULL) break;
		list = list->next;
	}
	list->next = p;
}
void printList(node *list) {
	while (list != NULL) {
		printf(" %d", list->key);
		list = list->next;
	}
	printf("\n");
}
lists partition(node *list, int n) {
	lists p;
	int i;
	p.l1 = list;
	for (i = 0; i < n - 1; i++) list = list->next;
	p.l2 = list->next;
	list->next = NULL;
	return p;
}
node *merge(node *l1, node *l2) {
	node *list = init(), *tmp;
	tmp = list;
	if (l1->key <= l2->key) {
		list->next = l1;
		list = list->next;
		l1 = l1->next;
	}
	else {
		list->next = l2;
		list = list->next;
		l2 = l2->next;
	}
	while (l1 != NULL && l2 != NULL) {
		if (l1->key <= l2->key) {
			list->next = l1;
			list = list->next;
			l1 = l1->next;
		}
		else {
			list->next = l2;
			list = list->next;
			l2 = l2->next;
		}
	}
	while (l1 != NULL) {
		list->next = l1;
		l1 = l1->next;
		list = list->next;
	}
	while (l2 != NULL) {
		list->next = l2;
		l2 = l2->next;
		list = list->next;
	}
	return tmp->next;
}
void mergeSort(node **list, int n) {
	//partition, merge
	lists p;
	if (n > 1) {
		p = partition(*list, n / 2);
		mergeSort(&p.l1, n / 2);
		mergeSort(&p.l2, n - n / 2);
		*list = merge(p.l1, p.l2);
	}
}
int main() {
	node *list;
	int n, i, k;
	list = init();
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		insertItem(list, k);
	}
	mergeSort(&list->next, n);
	printList(list->next);
	freeNode(list);
}