#ifndef __EMPLOYEE_HANDLER_H__
#define __EMPLOYEE_HANDLER_H__

#include "EmployeeInfo.h"
#include "CLinkedList.h"

void ShowEmployeeInfo(Data employee);
Data ShowWhoIsDuty(List * plist, char * name, int days);

#endif