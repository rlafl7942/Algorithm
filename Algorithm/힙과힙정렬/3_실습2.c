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
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &h[i]);
	buildHeap(1);
	printHeap();
}