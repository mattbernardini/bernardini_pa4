#include "account.h"
#ifndef LENGTH_OF_NAME
#define LENGTH_OF_NAME 50
#endif

void buildScanfNameRestrictor (char * nameRestrictor) {
	strcat(nameRestrictor, "%");
	char lengthOfName [50];
	sprintf(lengthOfName, "%d", LENGTH_OF_NAME); // Cast the int to char and allocate memory
	strcat(nameRestrictor, lengthOfName);
	strcat(nameRestrictor, "s");
}

Account * createNewAccount () {
	Account *account = NULL;
	account = malloc(sizeof(Account));

	if (account == NULL) {
		printf("malloc failed");
		return NULL;
	}

	return account;
}

Account * createNewAccountWithDefaults (
		char * Fname,
		char * MI,
		char * Lname,
		int accountNumber,
		double accountBalance) 
{
	Account *account;

	account = malloc(sizeof(Account));

	if (account == NULL) {
		printf("malloc failed");
		return NULL;
	}
	memcpy(account->Fname, Fname, LENGTH_OF_NAME);
	memcpy(account->MI, MI, 1);
	memcpy(account->Lname, Lname, LENGTH_OF_NAME);
	account->accountNumber = accountNumber;
	account->accountBalance = accountBalance;

	return account;
}

void getFnameFromUser (char * Fname) {
	char nameRestrictor[100];
	buildScanfNameRestrictor(nameRestrictor);
	printf("\nPlease enter your first name: ");
	scanf(nameRestrictor, Fname);
}

void getMiFromUser (char * MI) {
	printf("\nPlease enter your middle initial: ");
	scanf("%1s", MI);
}

void getLnameFromUser (char * Lname) {
	char nameRestrictor[100];
	buildScanfNameRestrictor(nameRestrictor);
	printf("\nPlease enter your last name: ");
	scanf(nameRestrictor, Lname);
}

void getAccountNumberFromUser (int * accountNumber) {
	printf("\nPlease enter an account number :");
	scanf("%d", accountNumber);
}

void setFname (Account *account, char * Fname) {
	memcpy(account->Fname, Fname, LENGTH_OF_NAME);
}

void setMi (Account *account, char * MI) {
	memcpy(account->MI, MI, 1);
}

void setLname (Account *account, char * Lname) {
	memcpy(account->Lname, Lname, LENGTH_OF_NAME);
}

