#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "account.h"
#define MAX_INPUT_SIZE 1024

void testAccountCreation (); 
void testAccountCreationWithDefaults (); 
void printAccountInformation (Account *testAccount);
int main (int argc, char ** argv) {
	switch (atoi(argv[1])) {
		case 0:
			testAccountCreation();
			break;
		case 1:
			testAccountCreationWithDefaults();
			break;
	}
	return 0;

}
void printAccountInformation (Account *testAccount) {
	printf("Account info:\n\tFname: %s\n\tMI: %s\n\tLname: %s\n\tAccountNumber: %d\n\tAccountBalance: %.2f\n",
		       testAccount->Fname,
		       testAccount->MI,
		       testAccount->Lname,
		       testAccount->accountNumber,
		       testAccount->accountBalance);
}
void testAccountCreation () {
	Account *testAccount;
	testAccount = createNewAccount();
	printAccountInformation(testAccount);
}
void testAccountCreationWithDefaults () { 
	Account *testAccount;
	char rawInput [MAX_INPUT_SIZE];

	if (fgets(rawInput,MAX_INPUT_SIZE, stdin) != NULL) { 
		char * Fname = strtok(rawInput, " ");
		char * MI = strtok(NULL, " ");
		char * Lname = strtok(NULL, " ");
		char * accountNumber = strtok(NULL, " ");
		char * accountBalance = strtok(NULL, " ");
		
		testAccount = createNewAccountWithDefaults (Fname, MI, Lname, atoi(accountNumber), atof(accountBalance));
		printAccountInformation(testAccount);
	}
}
