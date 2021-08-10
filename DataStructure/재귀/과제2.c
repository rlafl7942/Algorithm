#include <stdio.h>
int calc(int *p, int n) {
	int *q = NULL, i;
	if (n != 0) {
		q = (int *)malloc(n * sizeof(int));
		for (i = 0; i < n; i++) {
			*(q + i) = *(p + i) + *(p + i + 1);
		}
		calc(q, n - 1);
		for (i = 0; i < n + 1; i++) printf(" %d", *(p + i));
		printf("\n");
		free(p);
	}
	else {
		printf(" %d\n", *p);
		free(p);
	}
}
int main() {
	int n, *p = NULL, i;
	scanf("%d", &n);
	p = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", p + i);
	calc(p, n - 1);
}