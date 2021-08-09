#include <stdio.h>
int mostOnes(int A[][100], int n) {
	int i, j = 0, max = 0;
	for (i = 0; i < n; i++) {
		while (1) {
			if (A[i][j] == 0) {
				break;
			}
			j++;
			max = i;
		}
	}
	return max;
}
int main() {
	int i, j, n, a, A[100][100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a);
			A[i][j] = a;
		}
	}
	printf("%d", mostOnes(A, n));
}