#include <stdio.h>
int main() {
	int *p, n, i, j, max=0, tmp;
	scanf("%d", &n);
	p = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", &p[i]);
	for (i = n - 1; i > 0; i--) {
		max = i;
		for (j = i - 1; j >= 0; j--) {
			if (p[max] < p[j]) max = j;
		}
		tmp = p[i];
		p[i] = p[max];
		p[max] = tmp;
	}
	for (i = 0; i < n; i++) printf(" %d", p[i]);
}