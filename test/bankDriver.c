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

#ifndef ACCOUNTCLASS_H
#define ACCOUNTCLASS_H
#include "accountClass.h"
#endif

#include "bank.h"

int main (int argc, char ** argv) {
	Account *account;
	Bank *bank;
	account = createNewAccount();
	bank = createOrLoadBank();

	return 0;
}
