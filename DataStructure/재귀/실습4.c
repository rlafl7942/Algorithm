#include <stdio.h>
int maxNum(int a[], int n) {
	int max = a[0];
	if (n - 1 > 0) max=maxNum(a, n - 1);
	if (max < a[n]) return a[n];
	else return max;
}
int main() {
	int n,i, a[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%d", maxNum(a,n-1));
}