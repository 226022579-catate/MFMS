#include <stdio.h>
#include <stdlib.h>

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

        printf("Enter your choice: ");
        scanf("%d", &choice); // storing the user choice

        switch(choice) { //choicing the user choice
                case 1:
                    printf("\nEmployee Management\n");
                    break;
                case 2:
                    printf("\nBudget Management\n");
                    break;
                case 3:
                    printf("\nSupplier Management\n");
                    break;
                case 4:
                    printf("\nAsset Management\n");
                    break;
                case 5:
                    printf("\nReports\n");
                    break;
                default:
                    printf("\aInvalid choice. Please try again!!!\n"); /* Error message if the user's choice
                                                                        is not match with one of from the menu*/
        }

  } while (choice != 6); //still in running this menu until user choice 6 to exit the program.

  //Displaying finishing part to the user
  printf("\a\nExiting . . . . .");
  printf("\a\n*****************PROGRAM FINISHED*******************\n");
  
  return 0;

}


