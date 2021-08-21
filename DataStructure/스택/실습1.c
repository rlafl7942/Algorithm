#include <stdio.h>
void push(char *stack, char c) {
	int i = 0;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	stack[i] = c;
}
char pop(char *stack) {
	int i = 0;
	char tmp;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	tmp = stack[i - 1];
	stack[i - 1] = '\0';
	return tmp;
}
void peek(char *stack) {
	int i = 0;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	printf("%c\n", stack[i - 1]);
}
void duplicate(char *stack) {
	char tmp;
	tmp = pop(stack);
	push(stack, tmp);
	push(stack, tmp);
}
void upRotate(char *stack, int n) {
	int i = 0, top;
	char tmp;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	top = i - 1;
	tmp = stack[top];
	for (i = 0; i < n - 1; i++) {
		stack[top - i] = stack[top - i - 1];
	}
	stack[top - n + 1] = tmp;
}
void downRotate(char *stack, int n) {
	int i = 0, top;
	char tmp;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	top = i - 1;
	tmp = stack[top - n + 1];
	for (i = 0; i < n - 1; i++) {
		stack[top - n + 1 + i] = stack[top - n + 1 + i + 1];
	}
	stack[top] = tmp;
}
void print(char *stack) {
	int i = 0, j;
	while (1) {
		if (stack[i] == '\0') break;
		i++;
	}
	for (j = i - 1; j >= 0; j--) printf("%c", stack[j]);
	printf("\n");
}
int main() {
	int n, i, o, cnt = 0, a;
	char *stack, order[6], c;
	scanf("%d", &n);
	stack = (char *)malloc(n * sizeof(char) + 1);
	for (i = 0; i <= n; i++) stack[i] = '\0';
	scanf("%d", &o);
	getchar();
	for (i = 0; i < o; i++) {
		scanf("%s", order);
		getchar();
		if (strcmp(order, "PUSH") == 0) {
			scanf("%c", &c);
			getchar();
			if (cnt >= n) {
				printf("Stack FULL\n");
			}
			else {
				push(stack, c);
				cnt++;
			}
		}
		else if (strcmp(order, "POP") == 0) {
			if (cnt == 0) {
				printf("Stack Empty\n");
			}
			else {
				pop(stack);
				cnt--;
			}
		}
		else if (strcmp(order, "PEEK") == 0) {
			if (cnt == 0) {
				printf("Stack Empty\n");
			}
			else {
				peek(stack);
				cnt++;
			}
		}
		else if (strcmp(order, "DUP") == 0) {
			if (cnt >= n) {
				printf("Stack FULL\n");
			}
			else {
				duplicate(stack);
				cnt++;
			}
		}
		else if (strcmp(order, "UpR") == 0) {
			scanf("%d", &a);
			getchar();
			if (cnt >= a)
				upRotate(stack, a);

		}
		else if (strcmp(order, "DownR") == 0) {
			scanf("%d", &a);
			getchar();
			if (cnt >= a) downRotate(stack, a);
		}
		else {
			print(stack);
		}
	}
}