#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supplier.h"

#define MAX_SUPPLIERS 100

char supplierID[MAX_SUPPLIERS][30];
char supplierName[MAX_SUPPLIERS][100];
char email[MAX_SUPPLIERS][100];
char telephoneNumber[MAX_SUPPLIERS][20];
char town[MAX_SUPPLIERS][50];

int supplierCount = 0;

void supplierMenu()
{
    int choice;

    do
    {
        printf("\n");
        printf("========== SUPPLIER MANAGEMENT ==========\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier by ID\n");
        printf("4. Search Supplier by Name\n");
        printf("5. Exit\n");
        printf("==========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplierID();
                break;

            case 4:
                searchSupplierName();
                break;

            case 5:
                clear();
                printf("\nExiting Supplier Management...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 5);
}

void addSupplier()
{
    if(supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier storage is full.\n");
        return;
    }

    printf("\n========== ADD SUPPLIER ==========\n");

    printf("Enter Supplier ID: ");
    scanf("%s", supplierID[supplierCount]);

    printf("Enter Supplier Name: ");
    scanf(" %[^\n]", supplierName[supplierCount]);

    printf("Enter Email: ");
    scanf("%s", email[supplierCount]);

    printf("Enter Telephone Number: ");
    scanf("%s", telephoneNumber[supplierCount]);

    printf("Enter Town: ");
    scanf(" %[^\n]", town[supplierCount]);

    supplierCount++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers()
{
    if(supplierCount == 0)
    {
        printf("\nNo suppliers have been added yet.\n");
        return;
    }

    printf("\n========== ALL SUPPLIERS ==========\n");

    for(int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("----------------------------\n");
        printf("Supplier ID       : %s\n", supplierID[i]);
        printf("Supplier Name     : %s\n", supplierName[i]);
        printf("Email             : %s\n", email[i]);
        printf("Telephone Number  : %s\n", telephoneNumber[i]);
        printf("Town              : %s\n", town[i]);
    }

    printf("\n===================================\n");
}

void searchSupplierID()
{
    char searchID[30];
    int found = 0;

    printf("\n========== SEARCH SUPPLIER BY ID ==========\n");

    printf("Enter Supplier ID: ");
    scanf("%s", searchID);

    for(int i = 0; i < supplierCount; i++)
    {
        if(strcmp(supplierID[i], searchID) == 0)
        {
            printf("\nSupplier found!\n");
            printf("----------------------------\n");
            printf("Supplier ID       : %s\n", supplierID[i]);
            printf("Supplier Name     : %s\n", supplierName[i]);
            printf("Email             : %s\n", email[i]);
            printf("Telephone Number  : %s\n", telephoneNumber[i]);
            printf("Town              : %s\n", town[i]);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nSupplier with ID %s was not found.\n", searchID);
    }
}

void searchSupplierName()
{
    char searchName[100];
    int found = 0;

    printf("\n========== SEARCH SUPPLIER BY NAME ==========\n");

    printf("Enter Supplier Name: ");
    scanf(" %[^\n]", searchName);

    for(int i = 0; i < supplierCount; i++)
    {
        if(strcmp(supplierName[i], searchName) == 0)
        {
            printf("\nSupplier found!\n");
            printf("----------------------------\n");
            printf("Supplier ID       : %s\n", supplierID[i]);
            printf("Supplier Name     : %s\n", supplierName[i]);
            printf("Email             : %s\n", email[i]);
            printf("Telephone Number  : %s\n", telephoneNumber[i]);
            printf("Town              : %s\n", town[i]);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nSupplier named %s was not found.\n", searchName);
    }
}

