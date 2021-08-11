#include <stdio.h>
int main() {
	int n, m, x[100][100], i = 0, j = 0, k = 1, total, a=0,b=0;
	scanf("%d %d", &n, &m);
	total = n * m;
	while (1) {
		if (k > total) break;
		for (i = a, j = b; i < n&& j >=0; i++, j--) {
			x[i][j] = k++;
		}
		if (b < m - 1) b++;
		else a++;

	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) printf(" %d", x[i][j]);
		printf("\n");
	}
}