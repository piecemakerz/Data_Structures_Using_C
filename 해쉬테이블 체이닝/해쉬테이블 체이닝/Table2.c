#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"
#include "DLinkedList.h"

void TBLInit(Table * pt, HashFunc * f) {
	for (int i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v) {
	int hv = pt->hf(k);
	Slot data = { k,v };

	if (TBLSearch(pt, k) != NULL) {
		printf("키 중복 오류 발생 \n");
		return;
	}
	else {
		LInsert(&(pt->tbl[hv]), data);
	}
}

Value TBLDelete(Table * pt, Key k) {
	int hv = pt->hf(k);
	Slot delData;

	if (LFirst(&(pt->tbl[hv]), &delData)) {
		if (delData.key == k) {
			LRemove(&(pt->tbl[hv]));
			return delData.val;
		}
		else {
			while (LNext(&(pt->tbl[hv]), &delData)) {
				if (delData.key == k) {
					LRemove(&(pt->tbl[hv]));
					return delData.val;
				}
			}
		}
	}

	return NULL;
}

Value TBLSearch(Table * pt, Key k) {
	int hv = pt->hf(k);
	Slot data;

	if (LFirst(&(pt->tbl[hv]), &data)) {
		if (data.key == k) {
			return data.val;
		}
		else {
			while (LNext(&(pt->tbl[hv]), &data)) {
				if (data.key == k)
					return data.val;
			}
		}
	}
	return NULL;
}
