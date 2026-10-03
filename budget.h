#ifndef BUDGET_H
#define BUDGET_H
 
#define MAX_DEPTS 20
#define NAME_LEN  50
 
void   budgetMenu(void);
void   addDepartmentBudget(void);
void   enterExpenditure(void);
double calculateRemaining(double allocated, double spent);
int    isWithinBudget(double allocated, double spent);
void   displayBudgets(void);
void   displayExceededDepartments(void);
double getTotalAllocated(void);
double getTotalExpenditure(void);
int    getDeptCount(void);
 
#endif