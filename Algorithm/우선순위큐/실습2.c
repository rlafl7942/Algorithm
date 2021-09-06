#include <stdio.h>
int main() {
	int *p, n, i, j, min=0, tmp, temp;
	scanf("%d", &n);
	p = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", &p[i]);
	for (i = 1; i < n; i++) {
		tmp = p[i];
		j = i - 1;
		while (1) {
			if (p[j] <= tmp) break;
			p[j + 1] = p[j];
			j = j - 1;
		}
		p[j+1] = tmp;
	}
	for (i = 0; i < n; i++) printf(" %d", p[i]);
}