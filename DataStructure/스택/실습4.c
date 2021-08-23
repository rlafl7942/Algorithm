#include <stdio.h>
int pop(char stack[]) {
	int i = 0, tmp;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	i = i - 1;
	tmp = stack[i]-'0';
	stack[i] = '\0';
	//printf("tmp:%d %d\n", tmp, stack[i-1]);
	return tmp;
}
void push(char stack[], char c) {
	int i = 0, a, b;
	while (1) {
		if (stack[i] == '\0') break;
		//printf(" %d", stack[i]);
		i++;
	}
	i = i - 1;
	if (c >= '0' && c <= '9') {
		stack[i+1] = c;
		return;
	}
	else {
		a = pop(stack);
		b = pop(stack);
		if (c == '*') stack[i-1] = a * b+48;
		else if (c == '/') stack[i-1] = b / a+48;
		else if (c == '+') stack[i-1] = a + b+48;
		else if (c == '-') stack[i-1] = b - a+48;
	}
}
int main() {
	int n, i, j, len;
	char str[101], stack[100];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		getchar();
		len = strlen(str);
		for (j = 0; j < len; j++) stack[j] = '\0';
		for (j = 0; j < len; j++) {
			push(stack, str[j]);
		}
		printf("%d\n", stack[0]-48);
	}
}