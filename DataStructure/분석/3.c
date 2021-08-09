#include <stdio.h>
int* prefixAverages1(int X[], int n) {
	int i, j, *a, sum = 0;
	a = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += X[j];
		}
		a[i] = (int)((float)sum / (i + 1) + (0.5));
	}
	return a;
}
int *prefixAverages2(int X[], int n) {
	int sum = 0, *a = NULL, i;
	a = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		sum += X[i];
		a[i] = (int)((float)sum / (i + 1) + (0.5));
	}
	return a;
}
int main() {
	int i, n, *x = NULL;
	scanf("%d", &n);
	x = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", x + i);
	for (i = 0; i < n; i++) printf("%d ", *(prefixAverages1(x, n) + i));
	printf("\n");
	for (i = 0; i < n; i++) printf("%d ", *(prefixAverages2(x, n) + i));
	free(x);
}