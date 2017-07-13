#include <stdio.h>
#include <stdlib.h>
#include "UsefulHeap.h"
#include "PriorityQueue.h"

void PQueueInit(PQueue * ppq, Priority pc) {
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue * ppq) {
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue * ppq, PQData data) {
	HInsert(ppq, data);
}

PQData PDequeue(PQueue * ppq) {
	return HDelete(ppq);
}