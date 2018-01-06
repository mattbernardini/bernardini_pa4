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

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#define LENGTH_OF_NAME 50

typedef struct {
	char Fname [LENGTH_OF_NAME];
	char MI [2];
	char Lname [LENGTH_OF_NAME];
	int accountNumber;
	double accountBalance;
} Account;

void getFnameFromUser (char * Fname);
void getMiFromUser (char * MI);
void getLnameFromUser (char * Lname);
void getAccountNumberFromUser (int * accountNumber);
void setFname (Account *account, char * Fname);
void setMi (Account *account, char * MI);
void setLname (Account *account, char * Lname);
Account * createNewAccount ();
Account * createNewAccountWithDefaults (
		char * Fname,
		char * MI,
		char * Lname,
		int accountNumber,
		double accountBalance);
