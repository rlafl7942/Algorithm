#include <stdio.h>
void pop(char stack[], char c) {
	int i = 0;
	char tmp;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	tmp = stack[i - 1];
	if (tmp == c) stack[i - 1] = '\0';
}
void push(char stack[], char c) {
	int i = 0;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	stack[i] = c;
}
int main() {
	char str[1000], stack[1000] = { 0 };
	int i, cnt = 0;
	gets(str);
	for (i = 0;; i++) {
		if (str[i] == '\0') break;

		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			push(stack, str[i]);
			cnt++;
		}
		else if (str[i] == ')') {
			if (stack[0] == '\0') push(stack, str[i]);
			else pop(stack, '(');
			cnt++;
		}
		else if (str[i] == ']') {
			if (stack[0] == '\0') push(stack, str[i]);
			else pop(stack, '[');
			cnt++;
		}
		else if (str[i] == '}') {
			if (stack[0] == '\0') push(stack, str[i]);
			else pop(stack, '{');
			cnt++;
		}
	}
	if (stack[0] != '\0') printf("Wrong_%d", cnt);
	else printf("OK_%d", cnt);
}