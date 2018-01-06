#include "bank.h"

bool doesAccountNumberExist (Bank *bank, int accountNumberToTest) {
	node traveler;
	traveler = bank->accounts;
	while(traveler != NULL) {
		if (traveler->data->accountNumber == accountNumberToTest) {
			return true;
		}
		traveler = traveler->next;
	}
	return false;
}

bool canWithdrawlAmount (Account *account, double amountToWithdrawl) {
	double possibleAmount = account->accountBalance - amountToWithdrawl;
	if (possibleAmount > 0) {
		return true;
	} else {
		return false;
	}
}

void withdrawl (Account *account, double amountToWithdrawl) {
	if (canWithdrawlAmount(account, amountToWithdrawl)) {
		account->accountBalance -= amountToWithdrawl;
	} else {
		printf("Sorry, the amount you requested can not be withdrawn.  Please try again");
	}
}

void deposit (Account *account, double amountToDepost) {
	account->accountBalance += amountToDepost;
}

void addAccountToAccounts (struct Bank_Struct *bank, Account *account) {
	bank->numberOfAccounts++;
	bank->accounts = addNode(bank->accounts, account);
}

void createNewBankAccount(Bank *bank) {
	char tempNameHolder [LENGTH_OF_NAME * 2];
	bool accountNumerIsNotValid = true;
	int localAccountNumber = 0;
	Account * newAccount;
	newAccount = createNewAccount();
	
	getFnameFromUser(tempNameHolder);
	setFname(newAccount, tempNameHolder);
	
	memset(tempNameHolder, '\0', sizeof tempNameHolder);

	getMiFromUser(tempNameHolder);
	setMi(newAccount, tempNameHolder);

	memset(tempNameHolder, '\0', sizeof tempNameHolder);

	getLnameFromUser(tempNameHolder);
	setLname(newAccount, tempNameHolder);
	
	while (accountNumerIsNotValid) {
		printf("\nPlease enter an account number between 100,000 and 1,000,000\n");
		scanf("%d", &localAccountNumber);
		if (!doesAccountNumberExist(bank, localAccountNumber)){
			newAccount->accountNumber = localAccountNumber;
			accountNumerIsNotValid = false;
		} else {
			printf("Sorry, that account number is in use, please try again.");
		}
	}
	addAccountToAccounts(bank, newAccount);
}

Bank * createOrLoadBank () {
	Bank *bank;
	bank = malloc(sizeof(Bank));	
	bank->accounts = NULL;
	bank->dataFile = fopen(DATA_FILE, "ab+");

	while (!feof(bank->dataFile)) {
		Account *localAccount = createNewAccount();
		fread(localAccount, sizeof(Account), 1, bank->dataFile);
		addAccountToAccounts(bank, localAccount);
	}
	return bank;
}

void deallocateBankMemory (Bank *bank) {
	node traveler;
	
	traveler = bank->accounts;

	while (traveler != NULL) {
		node nextNode = traveler->next;
		free(traveler->data);
		free(traveler);
		traveler = nextNode;
	}

	fclose(bank->dataFile);

	free(bank);
}
