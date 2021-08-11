#include <stdio.h>
int main() {
	int n, m, x[100][100], i = 0, j = 0, k = 1, total, up=0,down,right,left=0;
	scanf("%d %d", &n, &m);
	total = n * m;
	down = n - 1;
	right = m - 1;
	while (1) {
		if (k >= total) break;
		for (j = left; j <= right ; j++) {
			x[i][j] = k++;
		}
		j--;
		up++;
		for (i = up; i <= down; i++) {
			x[i][j] = k++;
		}
		i--;
		right--;
		for (j = right; j >= left; j--) {
			x[i][j] = k++;
		}
		j++;
		down--;
		for (i = down; i >= up; i--) {
			x[i][j] = k++;
		}
		i++;
		left++;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) printf(" %d", x[i][j]);
		printf("\n");
	}
}