#include <stdio.h>
int calc(int n, int k) {
	if (n == k || k == 0) return 1;
	else if (k > 0 && k < n) {
		return calc(n - 1, k - 1) + calc(n - 1, k);
	}
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", calc(n, k));
}