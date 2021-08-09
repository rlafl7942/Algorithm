#include <stdio.h>
int modulo(int a, int b) {
	while (1) {
		if (a < b) break;
		a = a - b;
	}
	return a;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));
}