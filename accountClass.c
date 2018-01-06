#include "accountClass.h"

void deposit (AccountClass *account, int amountToDeposit) {
	AccountClass *localAccount = (AccountClass *) account;
	*localAccount->accountData->accountBalance += (double) amountToDeposit;
}

void withdrawl (AccountClass *account, int amountToWithdrawl) {
	AccountClass *localAccount = (AccountClass *) account;
	*localAccount->accountData->accountBalance += (double) amountToWithdrawl;
}

void printAccountInformation (const AccountClass *account) {
	const AccountClass *localAccount = (const AccountClass *) account;
	printf("  Account No.:\t%d\n", *localAccount->accountData->accountNumber);
        printf("  Name:\t\t%s %c %s\n", (char*)localAccount->accountData->Fname, (int)*localAccount->accountData->MI, (char*)localAccount->accountData->Lname);
        printf("  Balance:\t$%.2f\n", (float) *localAccount->accountData->accountBalance);
        printf("----------------------------------------------------\n");
}       

bool canWithdrawlAmount (const AccountClass *account, int amountToWithdrawl) {
	AccountClass *localAccount = (AccountClass *) account;
	int newPotentialBalance = *localAccount->accountData->accountBalance - amountToWithdrawl;
	if (newPotentialBalance > 0) {
		return true;
	} else {
		return false;
	}
}	


