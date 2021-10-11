#include <stdio.h>
int findByk1(int *arr, int k1, int k2, int start, int end) {
	int mid;
	if (start > end) {
		if (arr[start] > k1 && arr[start] > k2) return -1;
		else return start;
	}
	else {
		mid = (start + end) / 2;
		if (arr[mid] < k1) {
			findByk1(arr, k1, k2, mid + 1, end);
		}
		else if (arr[mid] > k1) {
			findByk1(arr, k1, k2, start, mid - 1);
		}
		else return mid;
	}
}
int findByk2(int *arr, int k1, int k2, int start, int end) {
	int mid;
	if (start > end) {
		if (arr[end] > k2) return -1;
		else return end;
	}
	else {
		mid = (start + end) / 2;
		if (arr[mid] < k2) {
			findByk2(arr, k1, k2, mid + 1, end);
		}
		else if (arr[mid] > k2) {
			findByk2(arr, k1, k2, start, mid - 1);
		}
		else return mid;
	}
}
int main() {
	int n, k1, k2, *arr, i, min, max;
	scanf("%d %d %d", &n, &k1, &k2);
	arr = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	min = findByk1(arr, k1, k2, 0, n - 1);
	max = findByk2(arr, k1, k2, 0, n - 1);
	if (min == -1 || max == -1) printf(" -1");
	else for (i = min; i <= max; i++) printf(" %d", i);
	free(arr);
}