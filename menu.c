#include "menu.h"

int printMenuAndGetMenuChoice () {
	int choice;
	printf("\nPlease choose an option:\n");
	printf("0. Exit\n");
	printf("1. Deposit\n");
	printf("2. Withdrawl\n");
	printf("3. Add account\n");
	printf("4. Remove account\n");
	printf("5. Balance inquiry\n");
	printf("6. View accounts\n\n");
	printf("Option: ");
	scanf("%d", &choice);
	return choice;
}

void handleMenuChoice (int menuChoice) {
	switch (menuChoice) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5: 
			break;
		case 6:
			break;
		default:
			printf("\nPlease enter a valid option.");
	}
}
