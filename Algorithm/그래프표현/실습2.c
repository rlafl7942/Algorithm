#include <stdio.h>
#include <stdlib.h>
typedef struct vertex {
	int id;
}vertex;
typedef struct edge {
	int a;
	int b;
	int weight;
}edge;
typedef struct graph {
	int **matrix;
	struct edge *edges;
	struct vertex *vertices;
	int esize;
}graph;
void insertEdge(graph *g, int edgeId, int a, int b, int w) {
	g->edges[edgeId].a = a;
	g->edges[edgeId].b = b;
	g->edges[edgeId].weight = w;
}
void setMatrix(graph *g, int i, int j, int edgeId) {
	g->matrix[i][j] = edgeId;
}
void setGraph(graph *g) {
	int i, j;
	g->edges = (edge *)malloc(22 * sizeof(edge));
	g->vertices = (vertex *)malloc(6 * sizeof(vertex));
	g->matrix = (int **)malloc(6 * sizeof(int *));
	for (i = 0; i < 6; i++) g->matrix[i] = (int *)malloc(6 * sizeof(int));
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			g->matrix[i][j] = -1;
		}
	}
	for (i = 0; i < 6; i++) g->vertices[i].id = i + 1;
	g->esize = 8;

	insertEdge(g, 0, 1, 2, 1);
	insertEdge(g, 1, 1, 3, 1);
	insertEdge(g, 2, 1, 4, 1);
	insertEdge(g, 3, 1, 6, 2);
	insertEdge(g, 4, 2, 3, 1);
	insertEdge(g, 5, 3, 5, 4);
	insertEdge(g, 6, 5, 5, 4);
	insertEdge(g, 7, 5, 6, 3);

	setMatrix(g, 0, 1, 0);
	setMatrix(g, 1, 0, 0);
	setMatrix(g, 0, 2, 1);
	setMatrix(g, 2, 0, 1);
	setMatrix(g, 0, 3, 2);
	setMatrix(g, 3, 0, 2);
	setMatrix(g, 0, 5, 3);
	setMatrix(g, 5, 0, 3);
	setMatrix(g, 1, 2, 4);
	setMatrix(g, 2, 1, 4);
	setMatrix(g, 2, 4, 5);
	setMatrix(g, 4, 2, 5);
	setMatrix(g, 4, 4, 6);
	setMatrix(g, 4, 4, 6);
	setMatrix(g, 4, 5, 7);
	setMatrix(g, 5, 4, 7);
}
void print(graph *g, int id) {
	int i, edgeId;
	for (i = 0; i < 6; i++) {
		edgeId = g->matrix[id - 1][i];
		if (edgeId == -1) continue;
		else if (g->edges[edgeId].a == id) {
			printf(" %d %d", g->edges[edgeId].b, g->edges[edgeId].weight);
		}
		else if (g->edges[edgeId].b == id) {
			printf(" %d %d", g->edges[edgeId].a, g->edges[edgeId].weight);
		}
	}
	printf("\n");
}
void modifyGraph(graph *g, int a, int b, int w) {
	if (w == 0) {
		if (g->matrix[a - 1][b - 1] == -1) return; //존재 x
		else {
			g->matrix[a - 1][b - 1] = -1;
			g->matrix[b - 1][a - 1] = -1; //삭제
		}
	}
	else { //수정 or 생성
		if (g->matrix[a - 1][b - 1] != -1) { //간선 존재 o
			g->edges[g->matrix[a - 1][b - 1]].weight = w; //수정
		}
		else { //간선 존재 x -> 간선 생성
			insertEdge(g, g->esize, a, b, w);
			g->matrix[a - 1][b - 1] = g->esize;
			g->matrix[b - 1][a - 1] = g->esize;
			g->esize++;
		}
	}
}
void freeGraph(graph *g) {
	free(g->vertices);
	free(g->edges);
	free(g->matrix);
}
int main() {
	char order;
	int a, b, w, i, j;
	graph g;
	setGraph(&g);
	while (1) {
		scanf("%c", &order);
		if (order == 'a') {
			scanf("%d", &a);
			getchar();
			if (a > 6 || a < 1) {
				printf("-1\n");
				continue;
			}
			else print(&g, a);
		}
		else if (order == 'm') {
			scanf("%d %d %d", &a, &b, &w);
			getchar();
			if (a > 6 || a < 1 || b>6 || b < 1) {
				printf("-1\n");
				continue;
			}
			else modifyGraph(&g, a, b, w);
		}
		else if (order == 'q') break;
	}
	freeGraph(&g);
}