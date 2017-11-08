#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define DATA_FILE "accounts.dat"
// Define our struct to hold account info
typedef struct account_struct {
	char Fname 	[50];
	char MI 	[1];
	char Lname 	[50];
	int accountNumber;
	double accountBalance;
} account;
int main () {
	// Create a holder for the user choice
	int choice = 9;
	// Create account array to store all accounts in memory and load data
	account accountArray[50]; 
	int numOfRecords = 0;
	// Make sure file is there and readable
	if (access(DATA_FILE, R_OK) != -1) {
	} else {
		FILE * temp = fopen(DATA_FILE, "w");
		fclose(temp);
	}
	FILE * initalFp = fopen(DATA_FILE, "rb");
	numOfRecords = fread(&accountArray, sizeof(account), 50, initalFp);
	
	// Main loop
	while (choice != 0) {
		// Print menu
		printf("\nPlease choose an option:\n");
		printf("0. Exit\n");
		printf("1. Deposit\n");
		printf("2. Withdrawl\n");
		printf("3. Add account\n");
		printf("4. Remove account\n");
		printf("5. Balance inquiry\n");
		printf("6. View accounts\n\n");
		printf("Option:");
		scanf("%d", &choice);

		// Switch on which option they choose and pass required paramters to helper functions
		switch (choice) {
			case 0:;
			       break;
			case 1:;
				int holder3 = 0;
				printf("\n-> DEPOSIT");
				while(holder3 == 0) {
					printf("\n  Please enter an account to deposit to:");
					int queryAccountNumber;
					scanf("%d", &queryAccountNumber);

					if (queryAccountNumber < 1000000 && queryAccountNumber > 99999) {
						// Loop through and make sure that account number isnt taken
						for (int i = 0; i < numOfRecords; i++) {
							if (accountArray[i].accountNumber == queryAccountNumber) {
								printf("  Account belongs to:\t\t%s %c %s\n", accountArray[i].Fname, *accountArray[i].MI, accountArray[i].Lname);
								// Flip the holder bit to ensure we exit the while loop
								holder3 = 1;
								float deposit = 0;
								printf("  Please enter the amount to deposit:");
								scanf("%f", &deposit);
								accountArray[i].accountBalance += deposit;
								// Update Data file	
								FILE * fp = fopen(DATA_FILE, "wb");
								fwrite(&accountArray, sizeof(account), numOfRecords, fp);
								fclose(fp);
								// Display account information
								printf("  New balance: %.2f\n", accountArray[i].accountBalance);
								printf("-> DEPOSIT SUCCESSFUL\n\n");
								printf("===============================================================================\n\n");
							}
						}
						if (holder3 == 0)
							printf("\nPlease enter a valid account number.\n");
					} else {
						printf("\nPlease enter a valid account number.\n");
					}
				}
				break;				
			case 2:;
				printf("\n-> WITHDRAWL");
				int holder4 = 0;
				while(holder4 == 0) {
					printf("\n  Please enter an account to withdrawl from:");
					int queryAccountNumber;
					scanf("%d", &queryAccountNumber);

					if (queryAccountNumber < 1000000 && queryAccountNumber > 99999) {
						// Loop through and make sure that account number isnt taken
						for (int i = 0; i < numOfRecords; i++) {
							if (accountArray[i].accountNumber == queryAccountNumber) {
								printf("  Account belongs to:\t\t%s %c %s (balance: $%.2f)\n", accountArray[i].Fname, *accountArray[i].MI, accountArray[i].Lname, (float) accountArray[i].accountBalance);
								// Flip the holder bit to ensure we exit the while loop
								holder4 = 1;
								float withdrawlAmount = 0;
								printf("  Please enter the amount to withdrawl:");
								scanf("%f", &withdrawlAmount);
								if (accountArray[i].accountBalance - withdrawlAmount < 0) {
									printf("\nThe account does not have sufficent funds to cover this operation. Please choose a different amount and try again.\n");
									holder4 = 1;
								} else {
									accountArray[i].accountBalance -= withdrawlAmount;
									// Update Data file	
									FILE * fp = fopen(DATA_FILE, "wb");
									fwrite(&accountArray, sizeof(account), numOfRecords, fp);
									fclose(fp);
									// Display account information
									printf("  New balance: %.2f\n", accountArray[i].accountBalance);
									printf("-> WITHDRAWL SUCCESSFUL\n\n");
									printf("===============================================================================\n\n");
								}
							}
							if (holder4 == 0) {
								printf("\nPlease enter a valid account number.\n");
							}
						}
					} else {
						printf("\nPlease enter a valid account number.\n");
					}
				}
				break;				
			case 3:;
				printf("\n-> ACCOUNT CREATION");
				// Pack the struct with info from user
				printf("\n  Please enter the account first name:");
				scanf("%s", accountArray[numOfRecords].Fname);
				printf("  Please enter the middile initial:");
				scanf("%s", accountArray[numOfRecords].MI);
				printf("  Please enter the account last name:");
				scanf("%s", accountArray[numOfRecords].Lname);
				// Loop to make sure user enters a valid account number
				int holder = 0;
				while (holder == 0) {
					// Set the older bit to one to make logic easy to exit
					holder = 1;
					int newAccountNumber = 0;	
					printf("  Please enter a new account number containing 6 digits:");
					scanf("%d", &newAccountNumber);
					// Make sure they entered an account number that is 6 digits
					if (newAccountNumber < 1000000 && newAccountNumber > 99999) {
						// Loop through and make sure that account number isnt taken
						for (int i = 0; i < numOfRecords; i++) {
							if (accountArray[i].accountNumber == newAccountNumber) {
								printf("\n  This account number is already taken.  Please try a different one.");
								// Flip the holder bit to ensure we exit the while loop
								holder = 0;
							}
						}
					} else {
						printf("\n  Please enter a valid account number.");
						holder = 0;
					}
					// Check to see if we passed validation, if we did assign new account number
					if (holder == 1)
						accountArray[numOfRecords].accountNumber = newAccountNumber;

				}
				accountArray[numOfRecords].accountBalance = 0;
				// Write into to file
				FILE * fp = fopen(DATA_FILE, "wb");
				fwrite(&accountArray, sizeof(account), ++numOfRecords, fp);
				fclose(fp);
				printf("-> ACCOUNT CREATION SUCCESSFUL\n\n");
				printf("===============================================================================\n\n");
				break;
			case 4:;
				printf("\n-> ACCOUNT DELETION");
				int holder2 = 0;
				while(holder2 == 0) {
					printf("\n  Please enter an account to delete:");
					int queryAccountNumber;
					scanf("%d", &queryAccountNumber);

					if (queryAccountNumber < 1000000 && queryAccountNumber > 99999) {
						// Loop through and make sure that account is valid
						for (int i = 0; i < numOfRecords; i++) {
							if (accountArray[i].accountNumber == queryAccountNumber) {
								// Flip the holder bit to ensure we exit the while loop
								holder2 = 1;
								// Display account information
								accountArray[i] = (const account){ 0 };
								for (int j = i; j < numOfRecords; j++) {
									accountArray[j] = accountArray[j+1];
								}
								// Update data file
								FILE * fp = fopen(DATA_FILE, "wb");
								fwrite(&accountArray, sizeof(account), --numOfRecords, fp);
								fclose(fp);
							}
						}
						if (holder2 == 0)
							printf("\nAcccount number not found, please try again\n");
					} else {
						printf("\nPlease enter a valid account number.\n");
					}
				}
				printf("-> ACCOUNT DELETION SUCCESSFUL\n");
				printf("===============================================================================\n\n");
				break;				
			case 5:;
				printf("\n-> BALANCE INQUIRY");
				int holder1 = 0;
				while(holder1 == 0) {
					printf("\n  Please enter an account to query the balance of:");
					int queryAccountNumber;
					scanf("%d", &queryAccountNumber);

					if (queryAccountNumber < 1000000 && queryAccountNumber > 99999) {
						// Loop through and make sure that account number isnt taken
						for (int i = 0; i < numOfRecords; i++) {
							if (accountArray[i].accountNumber == queryAccountNumber) {
								// Flip the holder bit to ensure we exit the while loop
								holder1 = 1;
								printf("  Account No.:\t%d\n", accountArray[i].accountNumber);
								printf("  Name:\t\t%s %c %s\n", accountArray[i].Fname, *accountArray[i].MI, accountArray[i].Lname);
								printf("  Balance:\t$%.2f\n", (float) accountArray[i].accountBalance);
								printf("----------------------------------------------------\n");
							}
						}
						if (holder1 == 0)
							printf("Account number not found please try again.\n");
					} else {
						printf("\nPlease enter a valid account number.\n");
					}
				}
				break;				
			case 6:
				printf("-> VIEW ACCOUNTS");
				printf("\n-----------------------------------------------------------------------\n");
				for (int i = 0; i < numOfRecords; i++) {
					printf("  Account No.:\t%d\n", accountArray[i].accountNumber);
					printf("  Name:\t\t%s %c %s\n", accountArray[i].Fname, *accountArray[i].MI, accountArray[i].Lname);
					printf("  Balance:\t$%.2f\n", (float) accountArray[i].accountBalance);
					printf("----------------------------------------------------\n");
				}
				printf("===============================================================================\n\n");
				break;
			default:
				printf("\nPlease enter a valid choice.\n");
				break;
		}
	}
	return 0;
}

