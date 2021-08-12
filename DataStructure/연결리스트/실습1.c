#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
	char element;
	struct ListNode *prev;
	struct ListNode *next;
}ListNode;
ListNode *init() {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->prev = NULL;
	p->next = NULL;
	p->element = NULL;
	return p;
}
void freeNode(ListNode *node) {
	if (node) {
		freeNode(node->next);
		free(node);
	}
}
void add(ListNode *node, int loc, char ele) {
	int i;
	ListNode *p = init();
	p->element = ele;
	for (i = 0; i < loc; i++) node = node->next;
	p->next = node;
	p->prev = node->prev;
	node->prev->next = p;
	node->prev = p;
}
void delete(ListNode *node, int loc) {
	int i;
	ListNode *p;
	p = node->next;
	for (i = 1; i < loc; i++) p = p->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	/*for (i = 0; i < loc; i++) node = node->next;
	node->prev->next = node->next;
	node->next->prev = node->prev;*/
}
char get(ListNode *node, int loc) {
	int i;
	for (i = 0; i < loc; i++) node = node->next;
	return node->element;
}
void print(ListNode *node) {
	while (1) {
		node = node->next;
		if (!node->next) break;
		printf("%c", node->element);
	}
}
int main() {
	ListNode *header, *trailer;
	int i, n, loc, cnt = 0;
	char order, ele;
	header = init();
	trailer = init();
	header->next = trailer;
	trailer->prev = header;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &order);
		if (order == 'A') {
			scanf("%d %c", &loc, &ele);
			if (loc <= cnt + 1) {
				add(header, loc, ele);
				cnt++;
			}
			else printf("invalid position\n");
		}
		else if (order == 'D') {
			scanf("%d", &loc);
			if (loc <= cnt ) {
				delete(header, loc);
				cnt--;
			}
			else printf("invalid position\n");
		}
		else if (order == 'G') {
			scanf("%d", &loc);
			if (loc <= cnt) printf("%c\n", get(header, loc));
			else printf("invalid position\n");
		}

		else {
			print(header);
			printf("\n");
		}


	}
	freeNode(header);
}