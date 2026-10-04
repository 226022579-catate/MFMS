/* asset.c - Asset Management module (MFMS Project A) */
#include <stdio.h>
#include <string.h>
#include "assets.h"

#define MAX_ASSETS 100

/* Asset data stored in parallel arrays */
int   assetID[MAX_ASSETS];
char  assetName[MAX_ASSETS][50];
char  assetType[MAX_ASSETS][50];
float assetValue[MAX_ASSETS];
char  assetDepartment[MAX_ASSETS][50];
char  assetCondition[MAX_ASSETS][20];
int   assetCount = 0;

/* Function prototypes */
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void printAsset(int index);
int  findAssetByID(int id);
int   readAssetInt(void);
float readAssetFloat(void);

/* ---------- Asset menu ---------- */
void assetMenu(void)
{
    int choice;

    do {
        printf("\n========== ASSET MANAGEMENT ==========\n");
        printf("1. Add asset\n");
        printf("2. Display all assets\n");
        printf("3. Search asset\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        choice = readAssetInt();

        switch (choice) {
            case 1:
                addAsset();
                break;
            case 2:
                displayAssets();
                break;
            case 3:
                searchAsset();
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please enter 1 to 4.\n");
        }
    } while (choice != 4);
}

/* ---------- Add an asset ---------- */
void addAsset(void)
{
    int id;
    int condition;
    float value;

    if (assetCount >= MAX_ASSETS) {
        printf("The asset register is full.\n");
        return;
    }

    printf("\n--- Add Asset ---\n");

    /* Asset ID: must be positive and not already used */
    printf("Enter Asset ID: ");
    id = readAssetInt();
    while (id <= 0 || findAssetByID(id) != -1) {
        if (id <= 0) {
            printf("Asset ID must be greater than 0.\n");
        } else {
            printf("Asset ID already exists.\n");
        }
        printf("Enter Asset ID: ");
        id = readAssetInt();
    }
    assetID[assetCount] = id;

    printf("Enter Asset Name (one word, e.g. Toyota_Hilux): ");
    scanf("%49s", assetName[assetCount]);

    printf("Enter Asset Type (e.g. Vehicle, Computer, Building): ");
    scanf("%49s", assetType[assetCount]);

    /* Purchase value: must not be negative */
    printf("Enter Purchase Value (N$): ");
    value = readAssetFloat();
    while (value < 0) {
        printf("Purchase value cannot be negative.\n");
        printf("Enter Purchase Value (N$): ");
        value = readAssetFloat();
    }
    assetValue[assetCount] = value;

    printf("Enter Department: ");
    scanf("%49s", assetDepartment[assetCount]);

    /* Condition: choose 1, 2 or 3 */
    printf("Condition (1=Good, 2=Fair, 3=Poor): ");
    condition = readAssetInt();
    while (condition < 1 || condition > 3) {
        printf("Invalid choice. Please enter 1, 2 or 3.\n");
        printf("Condition (1=Good, 2=Fair, 3=Poor): ");
        condition = readAssetInt();
    }

    if (condition == 1) {
        strcpy(assetCondition[assetCount], "Good");
    } else if (condition == 2) {
        strcpy(assetCondition[assetCount], "Fair");
    } else {
        strcpy(assetCondition[assetCount], "Poor");
    }

    assetCount++;
    printf("Asset added successfully.\n");
}

/* ---------- Display all assets ---------- */
void displayAssets(void)
{
    if (assetCount == 0) {
        printf("\nNo assets have been registered yet.\n");
        return;
    }

    printf("\n--- Asset Register ---\n");
    for (int i = 0; i < assetCount; i++) {
        printAsset(i);
    }
    printf("----------------------\n");
    printf("Total Assets: %d\n", assetCount);
    printf("Total Asset Value: N$%.2f\n", getTotalAssetValue());
}

/* ---------- Search for an asset ---------- */
void searchAsset(void)
{
    int option;
    int id;
    int index;
    int found = 0;
    char searchText[50];

    if (assetCount == 0) {
        printf("\nNo assets have been registered yet.\n");
        return;
    }

    printf("\n--- Search Asset ---\n");
    printf("1. Search by Asset ID\n");
    printf("2. Search by Asset Name\n");
    printf("3. Search by Department\n");
    printf("Enter your choice: ");
    option = readAssetInt();

    if (option == 1) {
        printf("Enter Asset ID: ");
        id = readAssetInt();
        index = findAssetByID(id);
        if (index != -1) {
            printAsset(index);
            found = 1;
        }
    } else if (option == 2) {
        printf("Enter Asset Name: ");
        scanf("%49s", searchText);
        for (int i = 0; i < assetCount; i++) {
            if (strcmp(assetName[i], searchText) == 0) {
                printAsset(i);
                found = 1;
            }
        }
    } else if (option == 3) {
        printf("Enter Department: ");
        scanf("%49s", searchText);
        for (int i = 0; i < assetCount; i++) {
            if (strcmp(assetDepartment[i], searchText) == 0) {
                printAsset(i);
                found = 1;
            }
        }
    } else {
        printf("Invalid search option.\n");
        return;
    }

    if (!found) {
        printf("No matching asset found.\n");
    }
}

/* ---------- Print one asset ---------- */
void printAsset(int index)
{
    printf("ID: %d | Name: %s | Type: %s | Value: N$%.2f | Dept: %s | Condition: %s\n",
           assetID[index], assetName[index], assetType[index],
           assetValue[index], assetDepartment[index], assetCondition[index]);
}

/* ---------- Find an asset by ID: returns its position, or -1 ---------- */
int findAssetByID(int id)
{
    for (int i = 0; i < assetCount; i++) {
        if (assetID[i] == id) {
            return i;
        }
    }
    return -1;
}

/* ---------- Input validation helpers ---------- */
/* scanf returns the number of items read, so a result of 1 means valid input */
int readAssetInt(void)
{
    int number;
    char junk[50];

    while (scanf("%d", &number) != 1) {
        scanf("%49s", junk);   /* throw away the invalid text */
        printf("Invalid input. Please enter a whole number: ");
    }
    return number;
}

float readAssetFloat(void)
{
    float number;
    char junk[50];

    while (scanf("%f", &number) != 1) {
        scanf("%49s", junk);
        printf("Invalid input. Please enter a number: ");
    }
    return number;
}

/* ---------- Functions for the Reports module ---------- */
int getAssetCount(void)
{
    return assetCount;
}

int getAssetID(int index)
{
    return assetID[index];
}

float getAssetValue(int index)
{
    return assetValue[index];
}

void getAssetName(int index, char name[])
{
    strcpy(name, assetName[index]);
}

void getAssetType(int index, char type[])
{
    strcpy(type, assetType[index]);
}

void getAssetDepartment(int index, char department[])
{
    strcpy(department, assetDepartment[index]);
}

void getAssetCondition(int index, char condition[])
{
    strcpy(condition, assetCondition[index]);
}

float getTotalAssetValue(void)
{
    float total = 0;

    for (int i = 0; i < assetCount; i++) {
        total = total + assetValue[i];
    }
    return total;
}