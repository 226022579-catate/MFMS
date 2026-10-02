#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "assets.h"

#define MAX_ASSETS 100
#define NAME_LEN   50
 
/* ---------- Private data (only visible inside assets.c) ---------- */
static int   assetID[MAX_ASSETS];
static char  assetName[MAX_ASSETS][NAME_LEN];
static char  assetType[MAX_ASSETS][NAME_LEN];
static float assetValue[MAX_ASSETS];
static char  assetDepartment[MAX_ASSETS][NAME_LEN];
static char  assetCondition[MAX_ASSETS][NAME_LEN];
static int   assetCount = 0;
 
/* ---------- Private prototypes ---------- */
static void addAsset(void);
static void displayAssets(void);
static void searchAsset(void);
static void printAsset(int index);
static int  findAssetByID(int id);
static int  isIdUsed(int id);
static int  readInt(const char *prompt);
static float readPositiveFloat(const char *prompt);
static void readText(const char *prompt, char *dest, int size);
static void readCondition(char *dest, int size);
static void toLowerCopy(const char *src, char *dest, int size);

//Function Declaration
void assetMenu();

//Displaying the Asset Menu
/* ================= MENU ================= */
void assetMenu(void) {

    printf("Municipal Financial Management System\n");

    int choice;
    do {
        printf("\n========== ASSET MANAGEMENT ==========\n");
        printf("1. Add asset\n");
        printf("2. Display all assets\n");
        printf("3. Search asset\n");
        printf("4. Back to main menu\n");
        choice = readInt("Enter your choice: ");
 
        switch (choice) {
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAsset();   break;
            case 4: break;
            default: printf("Invalid choice. Please enter 1-4.\n");
        }
    } while (choice != 4);

}
 
/* ================= CORE FUNCTIONS ================= */
static void addAsset(void)
{
    int id;
    float value;
 
    if (assetCount >= MAX_ASSETS) {
        printf("Asset register is full (%d assets).\n", MAX_ASSETS);
        return;
    }
 
    printf("\n--- Add Asset ---\n");
 
    id = readInt("Asset ID (positive number): ");
    while (id <= 0 || isIdUsed(id)) {
        if (id <= 0)
            printf("Asset ID must be greater than 0.\n");
        else
            printf("Asset ID %d already exists.\n", id);
        id = readInt("Asset ID (positive number): ");
    }
 
    assetID[assetCount] = id;
    readText("Asset name: ", assetName[assetCount], NAME_LEN);
    readText("Asset type (e.g. Vehicle, Computer, Building): ",
             assetType[assetCount], NAME_LEN);
 
    value = readPositiveFloat("Purchase value (N$): ");
    assetValue[assetCount] = value;
 
    readText("Department: ", assetDepartment[assetCount], NAME_LEN);
    readCondition(assetCondition[assetCount], NAME_LEN);
 
    assetCount++;
    printf("Asset added successfully.\n");
}
 
static void displayAssets(void)
{
    int i;
 
    if (assetCount == 0) {
        printf("\nNo assets registered yet.\n");
        return;
    }
 
    printf("\n--- Asset Register (%d assets) ---\n", assetCount);
    printf("%-6s %-20s %-14s %-14s %-16s %-10s\n",
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("-----------------------------------------------------------------------------\n");
    for (i = 0; i < assetCount; i++) {
        printAsset(i);
    }
    printf("-----------------------------------------------------------------------------\n");
    printf("Total asset value: N$%.2f\n", getTotalAssetValue());
}
 
static void searchAsset(void)
{
    int option, i, found = 0;
 
    if (assetCount == 0) {
        printf("\nNo assets registered yet.\n");
        return;
    }
 
    printf("\n--- Search Asset ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by name (partial match allowed)\n");
    printf("3. Search by department\n");
    option = readInt("Enter your choice: ");
 
    if (option == 1) {
        int id = readInt("Enter asset ID: ");
        int index = findAssetByID(id);
        if (index >= 0) {
            printf("\nAsset found:\n");
            printAsset(index);
        } else {
            printf("No asset with ID %d.\n", id);
        }
    } else if (option == 2 || option == 3) {
        char term[NAME_LEN], termLower[NAME_LEN], fieldLower[NAME_LEN];
        readText("Enter search text: ", term, NAME_LEN);
        toLowerCopy(term, termLower, NAME_LEN);
 
        for (i = 0; i < assetCount; i++) {
            const char *field = (option == 2) ? assetName[i] : assetDepartment[i];
            toLowerCopy(field, fieldLower, NAME_LEN);
            if (strstr(fieldLower, termLower) != NULL) {
                if (!found) printf("\nMatching assets:\n");
                printAsset(i);
                found++;
            }
        }
        if (!found) printf("No matching assets found.\n");
        else        printf("%d asset(s) found.\n", found);
    } else {
        printf("Invalid search option.\n");
    }
}
 
static void printAsset(int index)
{
    printf("%-6d %-20s %-14s %-14.2f %-16s %-10s\n",
           assetID[index], assetName[index], assetType[index],
           assetValue[index], assetDepartment[index], assetCondition[index]);
}
 
static int findAssetByID(int id)
{
    int i;
    for (i = 0; i < assetCount; i++) {
        if (assetID[i] == id) return i;
    }
    return -1;
}
 
static int isIdUsed(int id)
{
    return findAssetByID(id) != -1;
}
 
/* ================= INPUT VALIDATION HELPERS ================= */
static int readInt(const char *prompt)
{
    char line[64], *end;
    long v;
    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof line, stdin) == NULL) return 0;
        v = strtol(line, &end, 10);
        if (end != line && (*end == '\n' || *end == '\0')) return (int)v;
        printf("Invalid input. Please enter a whole number.\n");
    }
}
 
static float readPositiveFloat(const char *prompt)
{
    char line[64], *end;
    float v;
    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof line, stdin) == NULL) return 0;
        v = strtof(line, &end);
        if (end == line || (*end != '\n' && *end != '\0'))
            printf("Invalid input. Please enter a number.\n");
        else if (v < 0)
            printf("Value cannot be negative.\n");
        else
            return v;
    }
}
 
/* Reads a non-empty line (spaces allowed) into dest */
static void readText(const char *prompt, char *dest, int size)
{
    char line[128];
    size_t len;
    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof line, stdin) == NULL) { strcpy(dest, "N/A"); return; }
        len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[--len] = '\0';
        if (len == 0) { printf("This field cannot be empty.\n"); continue; }
        if ((int)len >= size) { printf("Too long (max %d characters).\n", size - 1); continue; }
        strcpy(dest, line);
        return;
    }
}
 
static void readCondition(char *dest, int size)
{
    int c;
    for (;;) {
        printf("Condition: 1=Good  2=Fair  3=Poor\n");
        c = readInt("Choose condition: ");
        switch (c) {
            case 1: strncpy(dest, "Good", size - 1); dest[size - 1] = '\0'; return;
            case 2: strncpy(dest, "Fair", size - 1); dest[size - 1] = '\0'; return;
            case 3: strncpy(dest, "Poor", size - 1); dest[size - 1] = '\0'; return;
            default: printf("Invalid choice. Enter 1, 2 or 3.\n");
        }
    }
}
 
static void toLowerCopy(const char *src, char *dest, int size)
{
    int i;
    for (i = 0; i < size - 1 && src[i] != '\0'; i++)
        dest[i] = (char)tolower((unsigned char)src[i]);
    dest[i] = '\0';
}
 
/* ================= GETTERS FOR REPORTS MODULE ================= */
int         getAssetCount(void)            { return assetCount; }
int         getAssetID(int i)              { return assetID[i]; }
const char *getAssetName(int i)            { return assetName[i]; }
const char *getAssetType(int i)            { return assetType[i]; }
float       getAssetValue(int i)           { return assetValue[i]; }
const char *getAssetDepartment(int i)      { return assetDepartment[i]; }
const char *getAssetCondition(int i)       { return assetCondition[i]; }
 
float getTotalAssetValue(void)
{
    float total = 0;
    int i;
    for (i = 0; i < assetCount; i++) total += assetValue[i];
    return total;
}