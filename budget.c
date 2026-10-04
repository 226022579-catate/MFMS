#include <stdio.h>
#include <string.h>
#include "budget.h"
 
char   deptNames[MAX_DEPTS][NAME_LEN];   
double allocated[MAX_DEPTS];            
double spent[MAX_DEPTS];                 
int    deptCount = 0;             
 
double readAmount(char prompt[]) {
    double value;
    int result;
    char junk[100];
 
    printf("%s", prompt);
    result = scanf("%lf", &value);
 
    while (result != 1 || value < 0) {
        if (result != 1) {
            printf("Invalid input. Please enter a number.\n");
            scanf("%99s", junk);          
        } else {
            printf("Amount cannot be negative.\n");
        }
        printf("%s", prompt);
        result = scanf("%lf", &value);
    }
    return value;
}

void readName(char name[]) {
    int len;

    printf("Enter department name: ");
    do {
        fgets(name, NAME_LEN, stdin);
        len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';          
        }
    } while (strlen(name) == 0);           
}
 
int findDepartment(char name[]) {
    int i;
    for (i = 0; i < deptCount; i++) {
        if (strcmp(deptNames[i], name) == 0) {
            return i;
        }
    }
    return -1;
}
 
double calculateRemaining(double alloc, double sp) {
    return alloc - sp;
}
 
int isWithinBudget(double alloc, double sp) {
    if (sp <= alloc) {
        return 1;
    } else {
        return 0;
    }
}
 
void addDepartmentBudget(void) {
    char name[NAME_LEN];
    double amount;
 
    if (deptCount >= MAX_DEPTS) {
        printf("Department list is full.\n");
        return;
    }
 
    readName(name);
 
    if (findDepartment(name) != -1) {
        printf("That department already exists.\n");
        return;
    }
 
    amount = readAmount("Enter allocated budget (N$): ");
 
    strcpy(deptNames[deptCount], name);
    allocated[deptCount] = amount;
    spent[deptCount] = 0;
    deptCount++;
 
    printf("Department added.\n");
}
 
void enterExpenditure(void) {
    char name[NAME_LEN];
    int position;
    double amount;
 
    if (deptCount == 0) {
        printf("No departments yet. Add a department first.\n");
        return;
    }
 
    readName(name);
    position = findDepartment(name);
 
    if (position == -1) {
        printf("Department not found.\n");
        return;
    }
 
    amount = readAmount("Enter expenditure (N$): ");
    spent[position] = spent[position] + amount;
 
    printf("Expenditure recorded.\n");
    if (isWithinBudget(allocated[position], spent[position]) == 0) {
        printf("WARNING: This department is over budget!\n");
    }
}
 
void displayBudgets(void) {
    int i;
 
    if (deptCount == 0) {
        printf("No budget information available.\n");
        return;
    }
 
    for (i = 0; i < deptCount; i++) {
        printf("\nDepartment: %s\n", deptNames[i]);
        printf("Allocated Budget: N$%.2f\n", allocated[i]);
        printf("Expenditure: N$%.2f\n", spent[i]);
        printf("Remaining Budget: N$%.2f\n",
               calculateRemaining(allocated[i], spent[i]));
 
        if (isWithinBudget(allocated[i], spent[i]) == 1) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: OVER BUDGET\n");
        }
    }
}
 
void displayExceededDepartments(void) {
    int i;
    int found = 0;
 
    printf("\nDepartments over budget:\n");
    for (i = 0; i < deptCount; i++) {
        if (isWithinBudget(allocated[i], spent[i]) == 0) {
            printf("%s (over by N$%.2f)\n", deptNames[i],
                   spent[i] - allocated[i]);
            found = 1;
        }
    }
 
    if (found == 0) {
        printf("No department has exceeded its budget.\n");
    }
}
 
double getTotalAllocated(void) {
    double total = 0;
    int i;
    for (i = 0; i < deptCount; i++) {
        total = total + allocated[i];
    }
    return total;
}
 
double getTotalExpenditure(void) {
    double total = 0;
    int i;
    for (i = 0; i < deptCount; i++) {
        total = total + spent[i];
    }
    return total;
}
 
int getDeptCount(void) {
    return deptCount;
}
 
void budgetMenu(void) {
    int choice = 0;
    int result;
    char junk[100];
 
    while (choice != 5) {
        printf("\n===== BUDGET MANAGEMENT =====\n");
        printf("1. Add department budget\n");
        printf("2. Enter expenditure\n");
        printf("3. Display all budgets\n");
        printf("4. Show departments over budget\n");
        printf("5. Back to main menu\n");
        printf("Enter your choice: ");
 
        result = scanf("%d", &choice);
 
        if (result != 1) {
            printf("Invalid input. Enter a number from 1 to 5.\n");
            scanf("%99s", junk);          
            choice = 0;
        } else {
            switch (choice) {
                case 1:
                    addDepartmentBudget();
                    break;
                case 2:
                    enterExpenditure();
                    break;
                case 3:
                    displayBudgets();
                    break;
                case 4:
                    displayExceededDepartments();
                    break;
                case 5:
                    printf("Returning to main menu...\n");
                    break;
                default:
                    printf("Invalid choice. Enter a number from 1 to 5.\n");
            }
        }
    }
}
 