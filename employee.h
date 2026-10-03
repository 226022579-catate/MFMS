#ifndef EMPLOYEES_H
#define EMPLOYEES_H

/* -------- Configuration -------- */
#define MAX_EMPLOYEES 100
#define EMP_NAME_LEN  50
#define EMP_DEPT_LEN  30

/* -------- Main sub-menu (called from main.c) -------- */
void employeeMenu(void);

/* -------- Helpers for the Reports module (Student 5) -------- */
int    getEmployeeCount(void);
double getAverageSalary(void);
double getHighestSalary(void);
double getLowestSalary(void);

#endif /* EMPLOYEES_H */