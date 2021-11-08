#include <stdio.h>
#include <stdlib.h>
typedef struct list { //인접리스트
	int edgeId;
	struct list *next;
}list;
typedef struct vertex { //정점
	int id;
	list *list; //incidence List
}vertex;
typedef struct edge { //간선
	int a;
	int b;
	int weight;
}edge;
typedef struct graph { //그래프
	vertex *vertices;
	edge *edges;
	int esize;
}graph;
int opposite(graph *g, list *l, int a) { //내가 a면 b , b면 a 리턴
	edge e = g->edges[l->edgeId];
	if (e.a == a) return e.b;
	else return e.a;
}
void insertEdge(graph *g, int edgeId, int a, int b, int w) {
	g->edges[edgeId].a = a;
	g->edges[edgeId].b = b;
	g->edges[edgeId].weight = w;
}
void insertList(graph *g, int a, int b, int w) {
	list *p = (list *)malloc(sizeof(list));
	list *q = g->vertices[a].list;
	int i;
	for (i = 0; i < g->esize; i++) {
		if (g->edges[i].a == a && g->edges[i].b == b) {
			g->edges[i].weight = w;
			return;
		}
		else if (g->edges[i].b == a && g->edges[i].a == b) {
			g->edges[i].weight = w;
			return;
		}
	}
	p->edgeId = g->esize;
	p->next = NULL;
	insertEdge(g, g->esize, a, b, w);
	while (q->next && opposite(g, q->next, a) < b) q = q->next;
	p->next = q->next;
	q->next = p;
	if (a != b) {
		list *x = (list *)malloc(sizeof(list));
		list *y = g->vertices[b].list;
		x->edgeId = g->esize;
		x->next = NULL;
		while (y->next && opposite(g, y->next, b) < a) y = y->next;
		x->next = y->next;
		y->next = x;
	}
	g->esize = g->esize + 1;

}
void makeGraph(graph *g) {
	int i;
	list *p;
	g->edges = (edge *)malloc(22 * sizeof(edge));
	g->vertices = (vertex *)malloc(7 * sizeof(vertex));
	g->esize = 0;
	for (i = 0; i < 7; i++) {
		p = (list *)malloc(sizeof(list));
		p->edgeId = -1;
		p->next = NULL;
		g->vertices[i].id = i;
		g->vertices[i].list = p;
	}
	for (i = 0; i < 22; i++) {
		g->edges[i].weight = 0;
	}

	insertList(g, 1, 2, 1);
	insertList(g, 1, 3, 1);
	insertList(g, 1, 4, 1);
	insertList(g, 1, 6, 2);
	insertList(g, 2, 3, 1);
	insertList(g, 3, 5, 4);
	insertList(g, 5, 5, 4);
	insertList(g, 5, 6, 3);

	insertEdge(g, 0, 1, 2, 1);
	insertEdge(g, 1, 1, 3, 1);
	insertEdge(g, 2, 1, 4, 1);
	insertEdge(g, 3, 1, 6, 2);
	insertEdge(g, 4, 2, 3, 1);
	insertEdge(g, 5, 3, 5, 4);
	insertEdge(g, 6, 5, 5, 4);
	insertEdge(g, 7, 5, 6, 3); //간선배열 추가


}

void print(graph *g, int id) {
	list *p;
	p = g->vertices[id].list->next;
	while (p) {
		if (g->edges[p->edgeId].weight != 0)
		{
			if (id == g->edges[p->edgeId].a) {
				printf(" %d %d", g->edges[p->edgeId].b, g->edges[p->edgeId].weight);
			}
			else if (id == g->edges[p->edgeId].b) {
				printf(" %d %d", g->edges[p->edgeId].a, g->edges[p->edgeId].weight);
			}
		}

		p = p->next;
	}
	printf("\n");
}
void freeList(list *l) {
	list *p;
	while (l) {
		p = l->next;
		free(l);
		l = p;
	}
}
void freeGraph(graph *g) {
	int i;
	for (i = 0; i < 7; i++) {
		freeList(g->vertices[i].list);
	}
	free(g->vertices);
	free(g->edges);
}
int main() {
	int a, b, w;
	char order;
	graph graph;
	makeGraph(&graph);
	while (1) {
		scanf("%c", &order);
		if (order == 'a') {
			scanf("%d", &a);
			getchar();
			if (a > 6 || a < 1) {
				printf("-1\n");
				continue;
			}
			else print(&graph, a);
		}
		else if (order == 'm') {
			scanf("%d %d %d", &a, &b, &w);
			getchar();
			if (a > 6 || a < 1 || b>6 || b < 1) {
				printf("-1\n");
				continue;
			}
			else insertList(&graph, a, b, w);
		}
		else if (order == 'q') break;
	}
	freeGraph(&graph);
}