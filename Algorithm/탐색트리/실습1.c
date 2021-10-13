#include <stdio.h>
typedef struct Node {
	struct Node *lChild;
	struct Node *rChild;
	struct Node *parent;
	int key;
}Node;
Node *init() {
	Node *p = (Node *)malloc(sizeof(Node));
	p->lChild = NULL;
	p->rChild = NULL;
	p->parent = NULL;
	return p;
}
void freeNode(Node *a) {
	if (a != NULL) {
		freeNode(a->lChild);
		freeNode(a->rChild);
		free(a);
	}
}
int isExternal(Node *a) {
	if (a->lChild == NULL && a->rChild == NULL) return 1; //true
	else return 0; //false
}
int isInternal(Node *a) {
	if (a->lChild != NULL || a->rChild != NULL) return 1; //true
	else return 0; //false
}
Node *treeSearch(Node *a, int k) {
	if (isExternal(a) == 1) return a;
	if (k == a->key) return a;
	else if (k < a->key) return treeSearch(a->lChild, k);
	else return treeSearch(a->rChild, k);
}
int findElement(Node *tree, int k) {
	Node *p;
	p = treeSearch(tree, k);
	if (isExternal(p) == 1) return -1; //NoSuchKey
	else return p->key;
}
void insertItem(Node *tree, int k) {
	Node *p;
	p = treeSearch(tree, k); //외부노드 받아옴
	if (isInternal(p) == 1) return;
	else {
		p->key = k;
		//expandExternal(p);
		p->lChild = init();
		p->rChild = init();
		p->lChild->parent = p;
		p->rChild->parent = p;
	}
}
Node *sibling(Node *a) {
	if (a->parent == NULL) return; //root
	if (a->parent->lChild == a) return a->parent->rChild;
	else return a->parent->lChild;
}
Node *inOrderSucc(Node *a) { //중위순회계승자 찾기
	Node *p;
	p = a->rChild;
	while (1) {
		if (isExternal(p->lChild) == 1) break;
		p = p->lChild;
	}
	return p;
}
Node *reduceExternal(Node *tree, Node *a) {
	Node *w, *zs, *g;
	w = a->parent;
	zs = sibling(a);
	if (w->parent == NULL) { //root일때
		tree = zs;
		zs->parent = NULL;
	}
	else {
		g = w->parent;
		zs->parent = g;
		if (w == g->lChild) g->lChild = zs;
		else g->rChild = zs;
	}
	free(a);
	free(w);
	return tree;
}
Node *removeElement(Node *tree, int k) {
	Node *w, *z, *y;
	int key;
	w = treeSearch(tree, k);
	if (isExternal(w) == 1) return -1; //NoSuchKey
	key = w->key;
	z = w->lChild;
	if (isExternal(z) == 0) z = w->rChild;
	if (isExternal(z) == 1) tree=reduceExternal(tree, z);
	else {
		y = inOrderSucc(w);
		z = y->lChild;
		w->key = y->key;
		tree=reduceExternal(tree, z);
	}
	return tree;
}
void preOrderPrint(Node *tree) {
	if (isExternal(tree) == 1) return;
	if (tree == NULL) return;
	else {
		printf(" %d", tree->key);
		preOrderPrint(tree->lChild);
		preOrderPrint(tree->rChild);
	}
}
int main() {
	Node *tree;
	char order;
	int key, i, find;
	tree = init();
	while (1) {
		scanf("%c", &order);
		if (order == 'i') {
			scanf("%d", &key);
			getchar();
			insertItem(tree, key);
		}
		else if (order == 'd') {
			scanf("%d", &key);
			getchar();
			find = findElement(tree, key);
			if (find == -1) printf("X\n");
			else {
				printf("%d\n", find);
				tree = removeElement(tree, key);
			}
		}
		else if (order == 's') {
			scanf("%d", &key);
			getchar();
			find = findElement(tree, key);
			if (find == -1) printf("X\n");
			else printf("%d\n", find);
		}
		else if (order == 'p') {
			preOrderPrint(tree);
			printf("\n");
		}
		else if (order == 'q') {
			break;
		}
	}
	freeNode(tree);
}