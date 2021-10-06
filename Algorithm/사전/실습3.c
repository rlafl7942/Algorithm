#include <stdio.h>
int main() {
	int a, b, yncnt, i, mid;
	char *s;
	scanf("%d %d %d", &a, &b, &yncnt);
	getchar();
	s = (char *)malloc((yncnt+1) * sizeof(char));
	gets(s);
	for (i = 0; i < yncnt; i++) {
		mid = (a + b) / 2;
		if (s[i] == 'N') {
			b = mid;
		}
		else {
			a = mid+1;
		}
	}
	printf("%d", a);
	free(s);
}