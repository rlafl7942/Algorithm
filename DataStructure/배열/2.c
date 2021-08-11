#include <stdio.h>
int main() {
	int x[100], y[100], n, i, j, change,tmp,a;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &x[i]);
	scanf("%d", &change);
	for (i = 0; i < change; i++) scanf("%d", &y[i]);
	tmp = x[y[0]];
	for (i = 1; i < change; i++) {
		a = x[y[i]];
		x[y[i]] = tmp;
		tmp = a;
	}
	for (i = 0; i < n; i++) printf(" %d", x[i]);
}