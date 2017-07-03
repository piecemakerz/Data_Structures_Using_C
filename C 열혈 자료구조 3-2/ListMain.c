#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {
	List list;
	NameCard * nameptr;

	ListInit(&list);

	nameptr = MakeNameCard("������", "010-3053-3919");
	LInsert(&list, nameptr);

	nameptr = MakeNameCard("��ö��", "010-3333-3333");
	LInsert(&list, nameptr);

	nameptr = MakeNameCard("�̿���", "010-7777-7777");
	LInsert(&list, nameptr);

	printf("���� �������� ��: %d \n", LCount(&list));
	
	if (LFirst(&list, &nameptr)) {
		if (!NameCompare(nameptr, "�̿���"))
			ShowNameCardInfo(nameptr);

		while (LNext(&list, &nameptr)) {
			if (!NameCompare(nameptr, "�̿���")) {
				ShowNameCardInfo(nameptr);
				break;
			}
		}
	}

	printf("\n");

	if (LFirst(&list, &nameptr)) {
		if (!NameCompare(nameptr, "������"))
			ChangePhoneNum(nameptr, "010-2580-3919");

		while (LNext(&list, &nameptr)) {
			if (!NameCompare(nameptr, "������")) {
				ChangePhoneNum(nameptr, "010-2580-3919");
				break;
			}
		}
	}

	printf("\n");

	if (LFirst(&list, &nameptr)) {
		if (!NameCompare(nameptr, "��ö��")) {
			nameptr = LRemove(&list);
			free(nameptr);
		}
		while (LNext(&list, &nameptr)) {
			if (!NameCompare(nameptr, "��ö��")) {
				nameptr = LRemove(&list);
				free(nameptr);
				break;
			}
		}
	}

	printf("���� �������� ��: %d \n", LCount(&list));
	return 0;
}