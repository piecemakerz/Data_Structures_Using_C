#include <stdio.h>
#include "CLinkedList.h"
#include "EmployeeInfo.h"
#include "EmployeeHandler.h"

int main(void) {
	List list;
	Data data;
	int i, nodeNum;
	ListInit(&list);

	Employee * emptr = (Employee*)malloc(sizeof(Employee));
	strcpy(emptr->employeeName, "������");
	emptr->employeeNum = 1;
	LInsert(&list, emptr);

	emptr = (Employee*)malloc(sizeof(Employee));
	strcpy(emptr->employeeName, "�̰���");
	emptr->employeeNum = 2;
	LInsert(&list, emptr);

	emptr = (Employee*)malloc(sizeof(Employee));
	strcpy(emptr->employeeName, "���¿�");
	emptr->employeeNum = 3;
	LInsert(&list, emptr);

	emptr = (Employee*)malloc(sizeof(Employee));
	strcpy(emptr->employeeName, "�̱���");
	emptr->employeeNum = 4;
	LInsert(&list, emptr);

	if (LFirst(&list, &data)) {
		ShowEmployeeInfo(data);

		for (int i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &data))
				ShowEmployeeInfo(data);
		}
	}
	printf("\n");

	ShowEmployeeInfo(ShowWhoIsDuty(&list, "�̱���", 5));
	return 0;
}