#include <stdio.h>
#include <stdlib.h>
#include "assets.h"

//Function Declaration
void reportMenu();
void assetReport();
void employeeReport();
void budgetReport();
void supplierReport();


//Displaying the menu for Reports
void reportMenu() {

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
        printf("\nEmployee Report selected.\n");
        break;

    case 2:
        printf("\nBudget Report selected.\n");
        break;

    case 3:
        printf("\nSupplier Report selected.\n");
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

