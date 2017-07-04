#include <stdio.h>
#include "EmployeeHandler.h"

void ShowEmployeeInfo(Data employee) {
	printf("사번: %d\n", employee->employeeNum);
	printf("이름: %s\n", employee->employeeName);
}

Data ShowWhoIsDuty(List * plist, char * name, int days) {
	Data pdata;
	int i;
	/*if (LFirst(plist, &pdata)) {
		if (!strcmp(pdata->employeeName, name)) {
			for (int i = 0; i < days; i++) {
				LNext(plist, &pdata);
			}
			return pdata;
		}
	}

	for (int i = 0; i < LCount(plist) - 1; i++) {
		if (LNext(plist, &pdata)) {
			if (!strcmp(pdata->employeeName, name)) {
				for (int i = 0; i < days; i++) {
					LNext(plist, &pdata);
				}
				return pdata;
			}
		}
	}
	
	return NULL;
	*/
	int num = LCount(plist);
	
	LFirst(plist, &pdata);

	if (strcmp(pdata->employeeName, name) != 0) {
		for (i = 0; i < num - 1; i++) {
			LNext(plist, &pdata);

			if (strcmp(pdata->employeeName, name) == 0)
				break;
		}
		if (i >= num - 1)
			return NULL;
	}
	
	for (i = 0; i < days; i++)
		LNext(plist, &pdata);

	return pdata;
}