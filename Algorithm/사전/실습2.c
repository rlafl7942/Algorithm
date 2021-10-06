#include <stdio.h>
int findElement(int *arr, int e, int n) {
	int i, mid = -1, start = 0;
	n = n - 1;
	while (1) {
		if (start > n) {
			if (arr[n] < e) mid = n + 1;
			break;
		}
		mid = (start + n) / 2;
		if (arr[mid] == e) break;
		else if (arr[mid] > e) {
			n = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return mid;
}
int main() {
	int n, e, *arr, i;
	scanf("%d %d", &n, &e);
	arr = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf(" %d", findElement(arr, e, n));
	free(arr);
}