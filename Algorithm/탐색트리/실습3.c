#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	struct Node *lChild;
	struct Node *rChild;
	struct Node *parent;
	int height;
	int key;
}Node;
Node *init() {
	Node *p = (Node *)malloc(sizeof(Node));
	p->lChild = NULL;
	p->rChild = NULL;
	p->parent = NULL;
	p->height = 0;
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
Node *restructure(Node **tree, Node *x, Node *y, Node *z) {
	Node *a, *b, *c;
	Node *t0, *t1, *t2, *t3;
	//중위 순서 대로 a,b,c -> 왼쪽자식 부모 오른쪽자식
	//single rotation
	if (x->key > y->key && y->key > z->key) {
		a = z;
		b = y;
		c = x;
		t0 = a->lChild;
		t1 = b->lChild;
		t2 = c->lChild;
		t3 = c->rChild;
	}
	else if (x->key < y->key && y->key < z->key) {
		a = x;
		b = y;
		c = z;
		t0 = a->lChild;
		t1 = a->rChild;
		t2 = b->rChild;
		t3 = c->rChild;
	}
	//double rotation
	else if (z->key<x->key && y->key>x->key) {
		a = z;
		b = x;
		c = y;
		t0 = a->lChild;
		t1 = b->lChild;
		t2 = b->rChild;
		t3 = c->rChild;
	}
	else {
		a = y;
		b = x;
		c = z;
		t0 = a->lChild;
		t1 = b->lChild;
		t2 = b->rChild;
		t3 = c->rChild;
	}
	//z의 부트리 b의 부트리로 변경
	if (z->parent == NULL) {
		//tree=b;
		//b->parent=NULL;
		(*tree) = b;
		b->parent = NULL;
	}
	else if (z->parent->lChild == z) {
		z->parent->lChild = b;
		b->parent = z->parent;
	}
	else {
		z->parent->rChild = b;
		b->parent = z->parent;
	}


	//t0과 t1를 a의 왼쪽 오른쪽 부트리로 만듦
	a->lChild = t0;
	a->rChild = t1;
	t0->parent = a;
	t1->parent = a;
	updateHeight(a);

	//t2와 t3을 c의 왼쪽 오른쪽 부트리로 만듦
	c->lChild = t2;
	c->rChild = t3;
	t2->parent = c;
	t3->parent = c;
	updateHeight(c);

	//a와 c를 b의 왼쪽 오른쪽으로 만듦
	b->lChild = a;
	b->rChild = c;
	a->parent = b;
	c->parent = b;
	updateHeight(b);

	return b;
}
int updateHeight(Node *a) { //두 자식들 중에 높은 높이 내가 갖고 1늘리고 1줄여주기
	int max;
	if (a->rChild->height > a->lChild->height) max = a->rChild->height;
	else max = a->lChild->height;
	if (max + 1 != a->height) {
		a->height = max + 1;
		return 1; //높이 개조했음
	}
	else return 0; //높이 개조하지 않았음
}
int isBalanced(Node *a) {
	int diff;
	diff = (a->lChild->height) - (a->rChild->height); //양쪽 자식들간의 높이 비교
	if (diff > 1 || diff < -1) return 0; //개조 필요
	else return 1; //안정된 상태
}
void searchAndFixAfterInsertion(Node **tree, Node *a) {
	//루트로 향해 올라가다가 처음 만나는 불균형 노드 z
	Node *z, *y, *x;
	if (a->parent == NULL) return; //root
	z = a->parent;
	while (updateHeight(z) == 1 && isBalanced(z) == 1) { //높이 개조해서 안정된 상태일때 돌아감
		if (z->parent == NULL) {
			return tree; //root면 return
		}
		z = z->parent;
	}
	if (isBalanced(z) == 1) return tree; //안정된 상태면 개조 필요없음
	if (z->lChild->height > z->rChild->height) y = z->lChild; //z의 큰 자식을 y로
	else y = z->rChild;
	if (y->lChild->height > y->rChild->height) x = y->lChild; //y의 큰 자식을 x로
	else x = y->rChild;
	restructure(tree, x, y, z);
}
void insertItem(Node **tree, int k) {
	Node *p;
	p = treeSearch(*tree, k); //외부노드 받아옴
	if (isInternal(p) == 1) return;
	else {
		p->key = k;
		//expandExternal(p);
		p->lChild = init();
		p->rChild = init();
		p->lChild->parent = p;
		p->rChild->parent = p;

		//자식들 높이는 0
		p->lChild->height = 0;
		p->rChild->height = 0;

		//삽입하는 노드의 높이는 1
		p->height = 1;
		searchAndFixAfterInsertion(tree, p);
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
void searchAndFixAfterRemoval(Node **tree, Node *a) {
	Node *x, *y, *z, *b;
	if (a == NULL) return; //root
	z = a;
	while (updateHeight(z) == 1 && isBalanced(z) == 1) {
		if (z->parent == NULL) return;
		z = z->parent;
	}
	if (isBalanced(z) == 1) return;
	if (z->lChild->height > z->rChild->height) y = z->lChild;
	else y = z->rChild;
	if (y->lChild->height > y->rChild->height) x = y->lChild;
	else if (y->lChild->height < y->rChild->height) x = y->rChild;
	else {
		if (z->lChild == y) x = y->lChild;
		else x = y->rChild;
	}
	b = restructure(tree, x, y, z);
	if (b->parent == NULL) return;
	searchAndFixAfterRemoval(tree, b->parent);
}
Node *reduceExternal(Node **tree, Node *a) {
	Node *w, *zs, *g;
	w = a->parent;
	zs = sibling(a);
	if (w->parent == NULL) { //root일때
		(*tree) = zs;
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
	return zs;
}
int removeElement(Node **tree, int k) {
	Node *w, *z, *y, *zs;
	int key;
	w = treeSearch(*tree, k);
	if (isExternal(w) == 1) return -1; //NoSuchKey
	key = w->key;
	z = w->lChild;
	if (isExternal(z) == 0) z = w->rChild;
	if (isExternal(z) == 1) zs = reduceExternal(tree, z);
	else {
		y = inOrderSucc(w);
		z = y->lChild;
		w->key = y->key;
		zs = reduceExternal(tree, z);
	}
	searchAndFixAfterRemoval(tree, zs->parent);
	return key;
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
	char order;
	Node *tree;
	int key, find;
	tree = init();
	while (1) {
		scanf("%c", &order);
		if (order == 'i') {
			scanf("%d", &key);
			getchar();
			insertItem(&tree, key);
		}
		else if (order == 's') {
			scanf("%d", &key);
			getchar();
			find = findElement(tree, key);
			if (find == -1) printf("X\n");
			else printf("%d\n", find);
		}
		else if (order == 'd') {
			scanf("%d", &key);
			getchar();
			find = removeElement(&tree, key);
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