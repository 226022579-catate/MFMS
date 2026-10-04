#include <stdio.h>
#include <stdlib.h>
#include "assets.h"
#include "budget.h"
#include "employee.h"
#include "supplier.h"
#include "report.h"


//Displaying the menu for Reports
void reportMenu(void) {

    int choice;

    printf("\n========== REPORT MENU ==========\n");
    printf("\n1. Employee Report\n");
    printf("2. Budget Report\n");
    printf("3. Supplier Report\n");
    printf("4. Asset Report\n");
    printf("5. Back to Main Menu\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1:
    employeeReport();
    break;

    case 2:
    budgetReport();
    break;

    case 3:
    supplierReport();
    break;

    case 4:
    assetReport();
    break;

    case 5:
        printf("\nReturning to Main Menu...\n");
        break;

    default:
        printf("\nInvalid choice. Please try again.\n");
    }
}



void assetReport(void)
{
    int count = getAssetCount();
    int i;

    printf("\n========== ASSET REPORT ==========\n");

    if (count == 0) {
        printf("No assets registered yet.\n");
        return;
    }

    printf("Total assets: %d\n", count);
    printf("Total asset value: N$%.2f\n\n", getTotalAssetValue());

    printf("%-6s %-20s %-14s %-14s %-16s %-10s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");

    printf("-----------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-6d %-20s %-14s %-14.2f %-16s %-10s\n",
               getAssetID(i),
               getAssetName(i),
               getAssetType(i),
               getAssetValue(i),
               getAssetDepartment(i),
               getAssetCondition(i));
    }
}



void budgetReport(void)
{
    double totalAllocated;
    double totalExpenditure;
    double totalRemaining;

    totalAllocated = getTotalAllocated();
    totalExpenditure = getTotalExpenditure();
    totalRemaining = totalAllocated - totalExpenditure;

    printf("\n========== BUDGET REPORT ==========\n");

    if (getDeptCount() == 0)
    {
        printf("No budget information available.\n");
        return;
    }

    printf("\nTotal Departments: %d\n", getDeptCount());
    printf("Total Allocated: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Total Remaining: N$%.2f\n", totalRemaining);

    printf("\n========== DEPARTMENT BUDGETS ==========\n");

    displayBudgets();

    printf("\n========== DEPARTMENTS OVER BUDGET ==========\n");

    displayExceededDepartments();
}


void employeeReport(void)
{
    int count;

    count = getEmployeeCount();

    printf("\n========== EMPLOYEE REPORT ==========\n");

    if (count == 0)
    {
        printf("No employees registered yet.\n");
        return;
    }

    printf("\nTotal Employees: %d\n", count);
    printf("Average Salary: N$%.2f\n", getAverageSalary());
    printf("Highest Salary: N$%.2f\n", getHighestSalary());
    printf("Lowest Salary: N$%.2f\n", getLowestSalary());
}


void supplierReport(void)
{
    printf("\n========== SUPPLIER REPORT ==========\n");

    printf("\nRegistered Suppliers:\n");
    displaySuppliers();
}
