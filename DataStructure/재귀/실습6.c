#include <stdio.h>
int gcd(int a, int b) {
	int tmp;
	if (a == 0) return b;
	else if (b == 0) return a;
	gcd(b, a%b);
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));
}