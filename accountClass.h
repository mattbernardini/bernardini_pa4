#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDBOOL_H
#define STDBOOL_H
#include <stdbool.h>
#endif

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "account.h"
#endif

typedef struct account_class {
	Account *accountData;
	
	void (*setFname) (Account *account, char * Fname);
	void (*setLname) (Account *account, char * Lanem);
	void (*setAccountNumber) (Account *account, int * accountNumber);
	void (*setAccountBalance) (Account *account, int * amountToChange);
	void (*printAccountInformation) (const Account *account);
	bool (*canWithdrawlAmount) (const Account *account, int amountToWithdrawl);
} AccountClass;

void setFname (Account *account, char * Fname);
void setLname (Account *account, char * Lname);
void setAccountNumber (Account *account, int * accountNumber);
void setAccountBalance (Account *account, int * amountToChange);
void printAccountInformation (const AccountClass *account);
bool canWithdrawlAmount (const AccountClass *account, int amountToWithdrawl);
