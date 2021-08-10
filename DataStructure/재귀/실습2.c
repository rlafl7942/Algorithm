#include <stdio.h>
int divideNum(int a) {
	if (a / 10 == 0) printf("%d\n", a);
	else {
		divideNum(a / 10);
		printf("%d\n", a % 10);
	}
	
}
int main() {
	int n;
	scanf("%d", &n);
	divideNum(n);
}