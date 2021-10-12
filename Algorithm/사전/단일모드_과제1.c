#include <stdio.h>
void findMax(int *arr, int start, int end) {
	int i, mid;
	while (1) {
		if (start >= end) break;
		mid = (start + end) / 2;
		if (arr[mid] < arr[mid + 1]) start = mid + 1;
		if (arr[mid] > arr[mid + 1]) end = mid;
	}
	printf(" 1 %d", arr[start]);
}
void findMin(int *arr, int start, int end) {
	int i, mid;
	while (1) {
		if (start >= end) break;
		mid = (start + end) / 2;
		if (arr[mid] > arr[mid + 1]) start = mid + 1;
		if (arr[mid] < arr[mid + 1]) end = mid;
	}
	printf(" -1 %d", arr[start]);
}
int isUniModalArray(int *arr, int n) { //O(n)
	int i = 1, change = 0;
	if (arr[0] > arr[1]) { //감소->증가
		while (1) {
			if (i == n) break;
			if (change < 1) {
				if (arr[i] > arr[i - 1]) change++;
			}
			else {
				if (arr[i] < arr[i - 1]) change++;
			}
			i++;
		}
		if (change == 1) findMin(arr, 0, n-1);
	}
	else { //증가->감소
		while (1) {
			if (i == n) break;
			if (change < 1) {
				if (arr[i] < arr[i - 1]) change++;
			}
			else {
				if (arr[i] > arr[i - 1]) change++;
			}
			i++;
		}
		if (change == 1) findMax(arr, 0, n-1);
	}
	if (change > 1) printf(" 0");
}
int main() {
	int n, *arr, i;
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	isUniModalArray(arr, n);
	free(arr);
}