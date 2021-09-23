#include <stdio.h>
int n;
int h[99];
void rBuildHeap(int i) {
	if (i > n) return;
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
}
void buildHeap() {
	int i;
	for (i = n / 2; i >= 1; i--) downHeap(i);
}
void inPlaceHeapSort() { 
	int i, tmp, N;
	N = n;
	buildHeap();
	for (i = N; i >= 2; i--) {
		tmp = h[1];
		h[1] = h[i];
		h[i] = tmp;
		n--;
		downHeap(1);
	}
	n = N;
}
void printArray() {
	int i;
	for (i = 1; i <= n; i++) printf(" %d", h[i]);
}
void insertItem(int key) {
	n = n + 1;
	h[n] = key;
	upHeap(n);
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
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &h[i]);
	inPlaceHeapSort();
	printArray();
}