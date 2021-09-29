#include <stdio.h>
#include <stdlib.h>
int findPivot(int L, int l, int r) {
	int random;
	random = rand() % (r + 1 - l) + l;
	return random;
}
int inPlacePartition(int *L, int l, int r, int k) {
	int p, i, j, tmp;
	p = L[k];
	tmp = L[k];
	L[k] = L[r];
	L[r] = tmp;
	i = l;
	j = r - 1;
	while (i <= j) {
		while (i <= j && L[i] <= p) {
			i = i + 1;
		}
		while (j >= i && L[j] >= p) {
			j = j - 1;
		}
		if (i < j) {
			tmp = L[i];
			L[i] = L[j];
			L[j] = tmp;
		}
	}
	tmp = L[i];
	L[i] = L[r];
	L[r] = tmp;
	return i; //pivot index
}
void inPlaceQuickSort(int *L, int l, int r) {
	int k, a, b, i;
	if (l >= r) return;
	k = findPivot(L, l, r);
	a = inPlacePartition(L, l, r, k);
	b = a;
	while (L[a] == L[k]) a--; //중복처리
	while (L[b] == L[k]) b++;
	inPlaceQuickSort(L, l, a);
	inPlaceQuickSort(L, b, r);
}
int main() {
	int *x, i, n;
	scanf("%d", &n);
	x = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", &x[i]);
	inPlaceQuickSort(x, 0, n - 1);
	for (i = 0; i < n; i++) printf(" %d", x[i]);
	free(x);
}