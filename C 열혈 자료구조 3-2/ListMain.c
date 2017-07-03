#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {
	List list;
	NameCard * nameptr;

	ListInit(&list);

	nameptr = MakeNameCard("이혁원", "010-3053-3919");
	LInsert(&list, nameptr);

	nameptr = MakeNameCard("이철수", "010-3333-3333");
	LInsert(&list, nameptr);

	nameptr = MakeNameCard("이영희", "010-7777-7777");
	LInsert(&list, nameptr);

	printf("현재 데이터의 수: %d \n", LCount(&list));
	
	if (LFirst(&list, &nameptr)) {
		if (!NameCompare(nameptr, "이영희"))
			ShowNameCardInfo(nameptr);

		while (LNext(&list, &nameptr)) {
			if (!NameCompare(nameptr, "이영희")) {
				ShowNameCardInfo(nameptr);
				break;
			}
		}
	}

	printf("\n");

	if (LFirst(&list, &nameptr)) {
		if (!NameCompare(nameptr, "이혁원"))
			ChangePhoneNum(nameptr, "010-2580-3919");

		while (LNext(&list, &nameptr)) {
			if (!NameCompare(nameptr, "이혁원")) {
				ChangePhoneNum(nameptr, "010-2580-3919");
				break;
			}
		}
	}

	printf("\n");

	if (LFirst(&list, &nameptr)) {
		if (!NameCompare(nameptr, "이철수")) {
			nameptr = LRemove(&list);
			free(nameptr);
		}
		while (LNext(&list, &nameptr)) {
			if (!NameCompare(nameptr, "이철수")) {
				nameptr = LRemove(&list);
				free(nameptr);
				break;
			}
		}
	}

	printf("현재 데이터의 수: %d \n", LCount(&list));
	return 0;
}