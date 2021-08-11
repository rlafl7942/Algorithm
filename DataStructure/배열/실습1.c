#include <stdio.h>
int main() {
	int tmp, n, x[100], i, j, rev, y[200], cnt = 0, a, b;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &x[i]);
	scanf("%d", &rev);
	for (i = 0; i < rev * 2; i++) scanf("%d", &y[i]);
	for (i = 0; i < rev * 2; i += 2) {
		a = y[i];
		b = y[i + 1];
		for (j = 0; j <= (b - a) / 2; j++) {
			tmp = x[a + j];
			x[a + j] = x[b - j];
			x[b - j] = tmp;
		}

	}
	for (i = 0; i < n; i++) printf(" %d", x[i]);
}