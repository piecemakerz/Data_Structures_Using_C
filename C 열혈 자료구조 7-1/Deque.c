#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq) {
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = NULL;
	newNode->next = pdeq->head;
	
	if (!DQIsEmpty(pdeq)) 
		pdeq->head->prev = newNode;
	else	
		pdeq->tail = newNode;
	
	pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail;
	newNode->next = NULL;

	if (!DQIsEmpty(pdeq))
		pdeq->tail->next = newNode;
	else
		pdeq->head = newNode;

	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq) {
	Node * rnode = pdeq->head;
	Data save = rnode->data;

	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}

	pdeq->head = rnode->next;
	free(rnode);

	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return save;
}

Data DQRemoveLast(Deque * pdeq) {
	Node * rnode = pdeq->tail;
	Data save = rnode->data;

	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}

	pdeq->tail = rnode->prev;
	free(rnode);

	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	return save;
}

Data DQGetFirst(Deque * pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}
	return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}
	return pdeq->tail->data;
}