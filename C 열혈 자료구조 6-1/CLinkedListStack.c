#include <stdio.h>
#include <stdlib.h>
#include "CLinkedListStack.h"

void StackInit(Stack * pstack) {
	List * list = (List*)malloc(sizeof(List));
	ListInit(&list);
	pstack->plist = &list;
}

int SIsEmpty(Stack * pstack) {
	if (pstack->plist->tail == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) {
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack * pstack) {
	Data delData;
	LFirst(pstack->plist, &delData);
	LRemove(pstack->plist);
	return delData;
}

Data SPeek(Stack * pstack) {

}