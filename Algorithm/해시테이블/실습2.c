#include <stdio.h>
#include <stdlib.h>
void insertItem(int *h, int key, int m) {
	int loc, i;
	i = key % m;
	while (1) {
		if (h[i%m] == 0) {
			h[i%m] = key;
			printf("%d\n", i%m);
			return;
		}
		else {
			printf("C");
			i++;
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
int main() {
	int m, n, *h, i, key, find;
	char order;
	scanf("%d %d", &m, &n);
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
			insertItem(h, key, m);
		}
		else if (order == 's') {
			scanf("%d", &key);
			getchar();
			find = searchItem(h, key, m);
			if (find == -1) printf("-1\n");
			else printf("%d %d\n", find, key);
		}
		else if (order == 'e') break;
	}
	free(h);
}