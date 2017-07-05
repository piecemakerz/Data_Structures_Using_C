#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

int main(void) {
	List list;
	int data, i;
	ListInit(&list);

	for (i = 0; i < 8; i++)
		LInsert(&list, i + 1);

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);

		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	if (LFirst(&list, &data)) {
		if (data % 2 == 0)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}