#include <stdio.h>
#include <string.h>
int check(char *str, char c, int len) {
	int cnt = 0;
	if (len < 0) return 0;
	else {
		if (*(str + len) == c) cnt = 1;
		len--;
		return check(str, c, len)+cnt;
	}
}
int main() {
	char str[100], c;
	scanf("%s", str);
	getchar();
	scanf("%c", &c);
	printf("%d", check(str, c, strlen(str)-1));
}