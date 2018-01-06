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

#ifndef UNISTD_H
#define UNISTD_H
#include <unistd.h>
#endif

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "linkedlist.h"
#endif

#define DATA_FILE "accounts.dat"

typedef struct Bank_Struct {
	node accounts;
	FILE * dataFile;
	int numberOfAccounts;
} Bank;
void addAccountToAccounts (Bank *bank, Account *account);
bool doseAccountNumberExist (Bank *bank, int accountNumberToTest);
void deposit (Account *account, double amountToDeposit);
void withdrawl (Account *account, double amountToWithdrawl);
bool canWithdrawlAmount (Account *account, double amountToWithdrawl);
void createNewBankAccount (Bank *bank);
void deleteAccount (Account *account);
Bank * createOrLoadBank ();
void deallocateBankMemory (Bank *bank);
