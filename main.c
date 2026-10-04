#include <stdio.h>
#include <stdlib.h>
#include "supplier.h"
#include "utilities.h"

// Function Declaration
void employeeMenu();
void budgetMenu();
void assetMenu();
void reportMenu();
void clear();

int main() {
//Veriable Declaration
  int choice;

  do {
        // MFMS main Menu. Displaying to the user what options she/he has to choice.
        printf("\a\n========= MUNICIPAL FINANCIAL MANAGEMENT SYSTEM ========= \n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");

        choice = readInt("Enter your choice: ");

        switch(choice) { //choicing the user choice
                case 1:
                    clear(); // clear the screan to the user
                    employeeMenu(); //calling the employee menu
                    break;
                case 2:
                    clear(); // clear the screan to the user
                    budgetMenu(); //calling the budget menu
                    break;
                case 3:
                    clear(); // clear the screan to the user
                    supplierMenu(); //calling the supplier menu
                    break;
                case 4:
                    clear(); // clear the screan to the user
                    assetMenu(); //calling asset menu
                    break;
                case 5:
                    clear(); // clear the screan to the user
                    reportMenu(); //calling report menu
                    break;
                default:
                    printf("\aInvalid choice. Please try again!!!\n"); /* Error message if the user's choice
                                                                        is not match with one of from the menu*/
        }

  } while (choice != 6); //still in running this menu until user choice 6 to exit the program.

  clear(); // cleaning the screen
  //Displaying finishing part to the user
  printf("\a\nExiting . . . . .");
  printf("\a\n*****************PROGRAM FINISHED*******************\n");
  
  return 0;

}

//code to simulate a cleaning a screen
void clear() {
        for(int i = 0; i < 50; i++) {
            printf("\n");
        }
}


