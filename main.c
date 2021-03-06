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

#ifndef UNISTD_H
#define UNISTD_H
#include <unistd.h>
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "account.h"
#endif

#ifndef BANK_H
#define BANK_H
#include "bank.h"
#endif

#ifndef MENU_H
#define MENU_H
#include "menu.h"
#endif

#define DATA_FILE "accounts.dat"

int main (int argc, char * * argv) {
	Bank *bank;
	bank = createOrLoadBank();
	int menuChoice = -1;		
	while (menuChoice != 0) {
		menuChoice = printMenuAndGetMenuChoice();

	}
	deallocateBankMemory(bank);
	return 0;
}

