#include <stdio.h>
int findElement(int *arr, int e, int start, int end) {
	int i, mid;
	if (start > end) {
		if (arr[0] > e) return -1;
		else return end;
	}
	else {
		mid = (end + start) / 2;
		if (arr[mid] == e) {
			return mid;
		}
		else if (arr[mid] > e) {
			findElement(arr, e, start, mid - 1);
		}
		else {
			findElement(arr, e, mid + 1, end);
		}
	}
}
int main() {
	int n, e, *arr, i;
	scanf("%d %d", &n, &e);
	arr = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf(" %d", findElement(arr, e, 0, n - 1));
	free(arr);
}