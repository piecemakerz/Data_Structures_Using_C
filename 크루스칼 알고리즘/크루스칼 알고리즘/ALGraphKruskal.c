#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

int PQWeightComp(Edge d1, Edge d2) {
	return d1.weight - d2.weight;
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

	PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph * pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV, int weight) {
	Edge edge = { fromV, toV, weight };

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;

	PEnqueue(&(pg->pqueue), edge);
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
		return TRUE;
	}
}

void DFShowGraphVertex(ALGraph * pg, int startV) {
	Stack stack;
	int curV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, curV);
	SPush(&stack, curV);

	while(TRUE) {
		int visitFlag = FALSE;
		LFirst(&(pg->adjList[curV]), &nextV);
		
		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, curV);
			curV = nextV;
			visitFlag = TRUE;

		}

		else {
			while (LNext(&(pg->adjList[curV]), &nextV) == TRUE) {
				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, curV);
					curV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) {
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				curV = SPop(&stack);

		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void RemoveOneWayEdge(ALGraph * pg, int v1, int v2) {
	int nextV;

	if(LFirst(&(pg->adjList[v1]), &nextV)) {

		if (nextV == v2) {
			LRemove(&(pg->adjList[v1]));
			return;
		}

		while (LNext(&(pg->adjList[v1]), &nextV)) {
			if (nextV == v2) {
				LRemove(&(pg->adjList[v1]));
				return;
			}
		}
	}
}

void RemoveEdge(ALGraph * pg, int v1, int v2) {
	RemoveOneWayEdge(pg, v1, v2);
	RemoveOneWayEdge(pg, v2, v1);
	(pg->numE)--;
}

int IsConnVertex(ALGraph * pg, int v1, int v2) {
	Stack stack;
	int curV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, curV);
	SPush(&stack, curV);

	while (LFirst(&(pg->adjList[curV]), &nextV) == TRUE) {
		int visitFlag = FALSE;

		if (nextV == v2) {
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, curV);
			curV = nextV;
			visitFlag = TRUE;

		}

		else {
			while (LNext(&(pg->adjList[curV]), &nextV) == TRUE) {
				if (nextV == v2) {
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, curV);
					curV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) {
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				curV = SPop(&stack);

		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;
}

void RecoverEdge(ALGraph * pg, int v1, int v2) {
	LInsert(&(pg->adjList[v1]), v2);
	LInsert(&(pg->adjList[v2]), v1);
	pg->numE++;
}

void ConKruskalMST(ALGraph * pg) {
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;

	while (pg->numE + 1 > pg->numV) {
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2);

		if (!IsConnVertex(pg, edge.v1, edge.v2)) {
			RecoverEdge(pg, edge.v1, edge.v2);
			recvEdge[eidx++] = edge;
		}
	}

	for (int i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph * pg) {
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ)) {
		edge = PDequeue(&copyPQ);
		printf("(%c-%c), w:%d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}