#include <stdio.h>
typedef struct Node {
	int ele;
	struct Node *next;
	struct Node *prev;
}Node;
typedef struct Deque {
	struct Node *front;
	struct Node *rear;
}Deque;
void add_front(Deque *deq, int e) {
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->prev = NULL;
	p->ele = e;
	if (deq->front == NULL && deq->rear == NULL) {
		deq->front = p;
		deq->rear = p;
		return;
	}
	else {
		p->next = deq->front;
		deq->front->prev = p;
		deq->front = p;
	}
}
void add_rear(Deque *deq, int e) {
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->prev = NULL;
	p->ele = e;
	if (deq->front == NULL && deq->rear == NULL) {
		deq->front = p;
		deq->rear = p;
		return;
	}
	else {
		p->prev = deq->rear;
		deq->rear->next = p;
		deq->rear = p;
	}
}
void delete_front(Deque *deq) {
	deq->front = deq->front->next;
	deq->front->prev = NULL;
}
void delete_rear(Deque *deq) {
	deq->rear = deq->rear->prev;
	deq->rear->next = NULL;
}
void print(Deque *deq) {
	while (1) {
		if (deq->rear->next == NULL) break;
		printf(" %d", deq->front->ele);
		deq->front = deq->front->next;
	}
}
int main() {
	Deque *deq;
	int n, i, e, cnt=0;
	char order[3];
	scanf("%d", &n);
	deq->front = NULL;
	deq->rear = NULL;
	for (i = 0; i < n; i++) {
		scanf("%s", &order);
		if (strcmp(order,'AF') == 0) {
			scanf("%d", &e);
			add_front(deq, e);
			cnt++;
		}
		else if (strcmp(order, 'AD') == 0) {
			scanf("%d", &e);
			add_rear(deq, e);
			cnt++;
		}
		else if (strcmp(order, 'DF') == 0) {
			if (cnt <= 0) {
				printf("underflow");
				return 0;
			}
			else {
				delete_front(deq);
				cnt--;
			}
		}
		else if (strcmp(order, 'DR') == 0) {
			if (cnt <= 0) {
				printf("underflow");
				return 0;
			}
			else {
				delete_rear(deq);
				cnt--;
			}
		}
		else print(deq);
		
	}
}