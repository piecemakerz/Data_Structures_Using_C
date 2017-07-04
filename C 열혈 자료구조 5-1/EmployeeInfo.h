#ifndef __EMPLOYEE_INFO_H__
#define __EMPLOYEE_INFO_H__

#define NAME_LEN 30

typedef struct _employee {
	int employeeNum;
	char employeeName[NAME_LEN];
}Employee;

#endif