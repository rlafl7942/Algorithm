#include <stdio.h>
#include <string.h>
typedef struct Node {
	int id;
	struct Node *left;
	struct Node *right;
}Node;
Node *init() {
	Node *p = (Node *)malloc(sizeof(Node));
	p->id = NULL;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void add(Node *f) {
	int id, left, right;
	scanf("%d %d %d", &id, &left, &right);
	f->id = id;
	if (left != 0) {
		f->left = init();
		add(f->left);
	}
	if (right != 0) {
		f->right = init();
		add(f->right);
	}
}
void print(Node *f, char order[]) {
	int i=0, cnt=0;
	printf(" %d", f->id);
	for (i = 0; i < strlen(order); i++) {
		if (order[i] == 'L') {
			printf(" %d", f->left->id);
			f = f->left;
		}
		if (order[i] == 'R') {
			printf(" %d", f->right->id);
			f = f->right;
		}
	}
	printf("\n");

}
int main() {
	Node *f=init();
	int n, search, i;
	char order[101];
	scanf("%d", &n);
	add(f);
	scanf("%d", &search);
	getchar();
	for (i = 0; i < search; i++) {
		scanf("%s", order);
		print(f, order);
	}
}