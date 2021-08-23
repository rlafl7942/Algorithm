#include <stdio.h>
void insert(int *que, int e, int rear) {
	que[rear] = e;
}
void delete(int *que, int front) {
	que[front] = 0;
}
void print(int *que, int size) {
	int i=0;
	while (1) {
		if (i >= size) break;
		printf(" %d", que[i]);
		i++;
	}
	printf("\n");
}
int main() {
	int q, n, i, e;
	int *que, front=0, rear=0;
	char order;
	scanf("%d%d", &q,&n);
	que = (int *)calloc(q, sizeof(int));
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &order);
		if (order == 'I') {
			scanf("%d", &e);
			if ((rear+1) % q == front) {
				printf("overflow");
				print(que, q);
				return 0;
			}
			rear++;
			if (rear == q) rear = 0;
			insert(que, e, rear);
		}
		else if (order == 'D') {
			if (rear == front) {
				printf("underflow\n");
				return 0;
			}
			front++;
			delete(que, front);
		}
		else {
			print(que, q);
		}
	}
}