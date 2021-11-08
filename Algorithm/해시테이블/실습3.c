#include <stdio.h>
#include <stdlib.h>
void insertItem(int *h, int key, int m, int q) {
	int loc, i, cnt = 0, j;
	i = key % m;
	loc = q - (key%q);
	while (1) {
		if (h[i%m] == 0) {
			h[i%m] = key;
			printf("%d\n", i%m);
			return;
		}
		else {
			printf("C");
			cnt++;
			i = key % m;
			i = i + loc * cnt;
		}
	}
}
int searchItem(int *h, int key, int m) {
	int i;
	for (i = 0; i < m; i++) {
		if (h[i] == key) return i;
	}
	return -1;
}
void printHashTable(int *h, int m) {
	int i;
	for (i = 0; i < m; i++) printf(" %d", h[i]);
}
int main() {
	int m, n, *h, i, key, find, q;
	char order;
	scanf("%d %d %d", &m, &n, &q);
	h = (int *)malloc(m * sizeof(int));
	for (i = 0; i < m; i++) h[i] = 0;
	i = 0;
	while (1) {
		scanf("%c", &order);
		if (order == 'i') {
			if (i >= n) continue;
			i++;
			scanf("%d", &key);
			getchar();
			insertItem(h, key, m, q);
		}
		else if (order == 's') {
			scanf("%d", &key);
			getchar();
			find = searchItem(h, key, m);
			if (find == -1) printf("-1\n");
			else printf("%d %d\n", find, key);
		}
		else if (order == 'p') {
			printHashTable(h, m);
			printf("\n");
		}
		else if (order == 'e') {
			printHashTable(h, m);
			break;
		}
	}
	free(h);
}