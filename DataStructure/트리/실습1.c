#include <stdio.h>
typedef struct Node {
	int ele;
	struct Node *left;
	struct Node *right;
}Node;
Node *init() {
	Node *p = (Node *)malloc(sizeof(Node));
	p->ele = NULL;
	p->left = NULL;
	p->right = NULL;
	return p;
}
Node *add(int ele, Node *left, Node *right) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->ele = ele;
	p->left = left;
	p->right = right;
	return p;
}
void print(Node *f) {
	printf("%d ", f->ele);
	if (f->left != NULL) printf("%d ", f->left->ele);
	if (f->right != NULL) printf("%d ", f->right->ele);
	
}
int main() {
	Node *f[8];
	int a;
	f[7] = add(80, NULL, NULL);
	f[6] = add(130, NULL, NULL);
	f[5] = add(120, f[6], f[7]);
	f[2] = add(50, NULL, f[5]);
	f[3] = add(70, NULL, NULL);
	f[4] = add(90, NULL, NULL);
	f[1] = add(30, f[3], f[4]);
	f[0] = add(20, f[1], f[2]);
	scanf("%d", &a);
	if (a > 8) {
		printf("-1");
		return 0;
	}
	print(f[a-1]);
}