#include <stdio.h>
#include "ALGraphBFS.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

void GraphInit(ALGraph * pg, int nv) {
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->visitInfo = (int*)malloc(sizeof(int)*nv);

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	memset(pg->visitInfo, 0, sizeof(int)*nv);

}

void GraphDestroy(ALGraph * pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;
}

void ShowGraphEdgeInfo(ALGraph * pg) {
	int data;

	for (int i = 0; i < pg->numV; i++) {
		printf("%c와 연결된 정점: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &data)) {
			printf("%c ", data + 65);

			while (LNext(&(pg->adjList[i]), &data)) {
				printf("%c ", data + 65);
			}
		}
		printf("\n");
	}
}

int VisitVertex(ALGraph * pg, int visitV) {
	if (pg->visitInfo[visitV])
		return FALSE;
	else {
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
}

void BFShowGraphVertex(ALGraph * pg, int startV) {
	Queue queue;
	int curV = startV;
	int nextV;

	QueueInit(&queue);
	
	while (TRUE) {

		if (LFirst(&(pg->adjList[curV]), &nextV) == TRUE) {
			if(VisitVertex(pg, nextV) == TRUE)
				Enqueue(&queue, nextV);

			while (LNext(&(pg->adjList[curV]), &nextV) == TRUE) {
				if (VisitVertex(pg, nextV) == TRUE)
					Enqueue(&queue, nextV);
			}
		}

		if (QIsEmpty(&queue) == TRUE)
			break;
		else
			curV = Dequeue(&queue);
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}