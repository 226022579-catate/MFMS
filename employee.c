#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"

//Desplaying the Employee Management Menu


 /* -------- Parallel arrays (module storage) -------- */
static int    empID[MAX_EMPLOYEES];
static char   empName[MAX_EMPLOYEES][EMP_NAME_LEN];
static char   empDept[MAX_EMPLOYEES][EMP_DEPT_LEN];
static double empBasic[MAX_EMPLOYEES];
static double empHousing[MAX_EMPLOYEES];
static double empTransport[MAX_EMPLOYEES];
static int    empCount = 0;

/* -------- Internal helpers -------- */
static void   readLine(const char *prompt, char *dest, size_t size);
static int    readPositiveInt(const char *prompt);
static double readPositiveDouble(const char *prompt);
static void   addEmployee(void);
static void   displayEmployees(void);
static void   searchEmployee(void);
static void   calculateSalary(void);

/* ============================================================
 *  employeeMenu - the sub-menu called from main.c
 * ============================================================ */
void employeeMenu(void)
{
    int choice;

    do {
        printf("\n==================================================\n");
        printf("            EMPLOYEE MANAGEMENT\n");
        printf("==================================================\n");
        printf("  1. Add Employee\n");
        printf("  2. Display All Employees\n");
        printf("  3. Search Employee by ID\n");
        printf("  4. Calculate Employee Salary\n");
        printf("  5. Back to Main Menu\n");
        printf("==================================================\n");

        choice = readPositiveInt("Enter your choice: ");

        switch (choice) {
            case 1: addEmployee();      break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee();   break;
            case 4: calculateSalary();  break;
            case 5: printf("\nReturning to main menu...\n"); break;
            default:
                printf("\n  [!] Invalid choice. Please select 1-5.\n");
        }
    } while (choice != 5);
}

/* ============================================================
 *  readLine - safe string input
 * ============================================================ */
static void readLine(const char *prompt, char *dest, size_t size)
{
    printf("%s", prompt);
    fflush(stdout);

    if (fgets(dest, (int)size, stdin) != NULL) {
        size_t len = strlen(dest);
        if (len > 0 && dest[len - 1] == '\n') {
            dest[len - 1] = '\0';
        }
    }
}

/* ============================================================
 *  readPositiveInt - validated integer input
 * ============================================================ */
static int readPositiveInt(const char *prompt)
{
    char buffer[100];
    int  value;

    while (1) {
        printf("%s", prompt);
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return 0;
        }
        if (sscanf(buffer, "%d", &value) == 1 && value > 0) {
            return value;
        }
        printf("  [!] Invalid input. Please enter a positive whole number.\n");
    }
}

/* ============================================================
 *  readPositiveDouble - validated decimal input
 * ============================================================ */
static double readPositiveDouble(const char *prompt)
{
    char   buffer[100];
    double value;

    while (1) {
        printf("%s", prompt);
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return 0.0;
        }
        if (sscanf(buffer, "%lf", &value) == 1 && value >= 0.0) {
            return value;
        }
        printf("  [!] Invalid input. Please enter a non-negative number.\n");
    }
}

/* ============================================================
 *  addEmployee
 * ============================================================ */
static void addEmployee(void)
{
    if (empCount >= MAX_EMPLOYEES) {
        printf("\n  [!] Employee storage is full.\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

    int newID = readPositiveInt("Employee ID       : ");

    for (int i = 0; i < empCount; i++) {
        if (empID[i] == newID) {
            printf("  [!] An employee with that ID already exists.\n");
            return;
        }
    }

    empID[empCount] = newID;

    readLine("Full Name         : ", empName[empCount], EMP_NAME_LEN);
    if (strlen(empName[empCount]) == 0) {
        printf("  [!] Name cannot be empty. Employee not added.\n");
        return;
    }

    readLine("Department        : ", empDept[empCount], EMP_DEPT_LEN);
    if (strlen(empDept[empCount]) == 0) {
        printf("  [!] Department cannot be empty. Employee not added.\n");
        return;
    }

    empBasic[empCount]     = readPositiveDouble("Basic Salary      : ");
    empHousing[empCount]   = readPositiveDouble("Housing Allowance : ");
    empTransport[empCount] = readPositiveDouble("Transport Allow.  : ");

    empCount++;
    printf("\n  Employee added successfully. Total employees: %d\n", empCount);
}

/* ============================================================
 *  displayEmployees
 * ============================================================ */
static void displayEmployees(void)
{
    if (empCount == 0) {
        printf("\n  No employees have been added yet.\n");
        return;
    }

    printf("\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("%-6s %-20s %-15s %12s %12s %12s %12s\n",
           "ID", "Name", "Department",
           "Basic", "Housing", "Transport", "Gross");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < empCount; i++) {
        double gross = empBasic[i] + empHousing[i] + empTransport[i];
        printf("%-6d %-20s %-15s %12.2f %12.2f %12.2f %12.2f\n",
               empID[i], empName[i], empDept[i],
               empBasic[i], empHousing[i], empTransport[i], gross);
    }

    printf("---------------------------------------------------------------------------------\n");
    printf("  Total employees: %d\n", empCount);
}

/* ============================================================
 *  searchEmployee
 * ============================================================ */
static void searchEmployee(void)
{
    if (empCount == 0) {
        printf("\n  No employees have been added yet.\n");
        return;
    }

    int target = readPositiveInt("\nEnter Employee ID to search: ");

    int found = 0;
    for (int i = 0; i < empCount; i++) {
        if (empID[i] == target) {
            double gross = empBasic[i] + empHousing[i] + empTransport[i];
            printf("\n  Employee found:\n");
            printf("  ID        : %d\n",   empID[i]);
            printf("  Name      : %s\n",   empName[i]);
            printf("  Department: %s\n",   empDept[i]);
            printf("  Basic     : %.2f\n", empBasic[i]);
            printf("  Housing   : %.2f\n", empHousing[i]);
            printf("  Transport : %.2f\n", empTransport[i]);
            printf("  Gross     : %.2f\n", gross);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n  [!] No employee found with ID %d.\n", target);
    }
}

/* ============================================================
 *  calculateSalary
 * ============================================================ */
static void calculateSalary(void)
{
    if (empCount == 0) {
        printf("\n  No employees have been added yet.\n");
        return;
    }

    int target = readPositiveInt("\nEnter Employee ID: ");

    for (int i = 0; i < empCount; i++) {
        if (empID[i] == target) {
            double gross = empBasic[i] + empHousing[i] + empTransport[i];
            double tax   = gross * 0.15;
            double net   = gross - tax;

            printf("\n--- Salary Calculation ---\n");
            printf("  Employee  : %s (ID %d)\n", empName[i], empID[i]);
            printf("  Basic     : %.2f\n", empBasic[i]);
            printf("  Housing   : %.2f\n", empHousing[i]);
            printf("  Transport : %.2f\n", empTransport[i]);
            printf("  ------------------------\n");
            printf("  Gross     : %.2f\n", gross);
            printf("  Tax (15%%) : %.2f\n", tax);
            printf("  Net       : %.2f\n", net);
            return;
        }
    }

    printf("\n  [!] No employee found with ID %d.\n", target);
}

/* ============================================================
 *  Reports helpers (used by report.c)
 * ============================================================ */
int getEmployeeCount(void)
{
    return empCount;
}

double getAverageSalary(void)
{
    if (empCount == 0) return 0.0;

    double total = 0.0;
    for (int i = 0; i < empCount; i++) {
        total += empBasic[i] + empHousing[i] + empTransport[i];
    }
    return total / empCount;
}

double getHighestSalary(void)
{
    if (empCount == 0) return 0.0;

    double highest = empBasic[0] + empHousing[0] + empTransport[0];
    for (int i = 1; i < empCount; i++) {
        double gross = empBasic[i] + empHousing[i] + empTransport[i];
        if (gross > highest) highest = gross;
    }
    return highest;
}

double getLowestSalary(void)
{
    if (empCount == 0) return 0.0;

    double lowest = empBasic[0] + empHousing[0] + empTransport[0];
    for (int i = 1; i < empCount; i++) {
        double gross = empBasic[i] + empHousing[i] + empTransport[i];
        if (gross < lowest) lowest = gross;
    }
    return lowest;
}
