#include <stdio.h>
int n = 0;
int h[99];
void insertItem(int key) {
	n = n + 1;
	h[n] = key;
	upHeap(n);
}
int removeMax() {
	int key;
	key = h[1];
	h[1] = h[n];
	n = n - 1;
	downHeap(1);
	return key;
}
int upHeap(int i) {
	int parent, tmp;
	parent = i / 2;
	if (parent < 1) return;
	if (h[parent] >= h[i]) return;
	if (h[parent] < h[i]) {
		tmp = h[parent];
		h[parent] = h[i];
		h[i] = tmp;
	}
	upHeap(parent);
}
int downHeap(int i) {
	int left, right, greater, tmp;
	left = 2 * i;
	right = 2 * i + 1;
	if (left > n) return;
	greater = left;
	if (right <= n) {
		if (h[right] > h[greater]) greater = right;
	}
	if (h[i] >= h[greater]) return;
	tmp = h[i];
	h[i] = h[greater];
	h[greater] = tmp;
	downHeap(greater);
}
void printHeap() {
	int i;
	for (i = 1; i <= n; i++) printf(" %d", h[i]);
}
int main() {
	int i, k;
	char order;
	while (1) {
		scanf("%c", &order);
		if (order == 'q') break;
		else if (order == 'i') {
			scanf("%d", &k);
			insertItem(k);
			printf("0\n");
		}
		else if (order == 'd') {
			printf("%d\n", removeMax());
		}
		else if (order == 'p') {
			printHeap();
			printf("\n");
		}
	}
}