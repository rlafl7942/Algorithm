#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int key;
	struct node *next;
}node;
void init(node *p) {
	p->key = -1;
	p->next = NULL;
}
void insertItem(node *h, int key, int m) {
	int i;
	i = key % m;
	node *p = (node *)malloc(sizeof(node));
	p->key = key;
	p->next = (h + i)->next;
	(h + i)->next = p;
}
int searchItem(node *h, int key, int m) {
	int rank = 0, i, find;
	node *p = h;
	i = key % m;
	p = (h + i)->next;
	while (1) {
		rank++;
		if (p == NULL) break;
		if (p->key == key) return rank;
		p = p->next;
	}
	return -1;
}
int deleteItem(node *h, int key, int m) {
	int i, rank = 0;
	node *p;
	i = key % m;
	p = h + i;
	while (1) {
		rank++;
		if (p->next == NULL) break;
		if (p->next->key == key) {
			p->next = p->next->next;
			return rank;
		}
		p = p->next;
	}
	return -1;
}
void printHashTable(node *h, int m) {
	int i;
	node *p;
	for (i = 0; i < m; i++) {
		p = (h + i)->next;
		while (1) {
			if (p == NULL) break;
			printf(" %d", p->key);
			p = p->next;
		}
	}
	printf("\n");
}
void freeNode(node *a) {
	if (a != NULL) {
		a = a->next;
		free(a);
	}
}
int main() {
	int m, key, i, find;
	char order;
	node *h;
	scanf("%d", &m);
	h = (node *)malloc(m * sizeof(node));
	for (i = 0; i < m; i++) {
		init(h + i);
	}
	while (1) {
		scanf("%c", &order);
		if (order == 'i') {
			scanf("%d", &key);
			getchar();
			insertItem(h, key, m);
		}
		else if (order == 's') {
			scanf("%d", &key);
			getchar();
			find = searchItem(h, key, m);
			if (find == -1) printf("0\n");
			else printf("%d\n", find);
		}
		else if (order == 'd') {
			scanf("%d", &key);
			getchar();
			find = deleteItem(h, key, m);
			if (find == -1) printf("0\n");
			else printf("%d\n", find);
		}
		else if (order == 'p') {
			printHashTable(h, m);
		}
		else if (order == 'e') break;
	}
	for (i = 0; i < m; i++) {
		freeNode(h + i);
	}
}