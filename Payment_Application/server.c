#include "server.h"
#include"terminal.h"
#include"stdio.h"
#include<string.h>
ST_accountsDB_t Astr_Accounts[5] = { {1000.0,"AAAAAAAAAAAAAAAAAA"},{2000.0,"AAAAAAAAAAAAAAAAAZ"}, {3000.0,"AAAAAAAAAAAAAAAAAW"},{4000.0,"AAAAAAAAAAAAAAAAAX"},{5000.0,"AAAAAAAAAAAAAAAAAAY"}};

EN_transStat_t recieveTransactionData(ST_transaction* transData) {





	/*
	//not used para!
	printf("Enter your PAN\n");
	char local_pan[21];
	scanf("%s", local_pan);
	printf("Enter the transaction amount\n");
	float amount;
	scanf("%f", &amount);
	char flag = 0;
	int local_itr;
	for ( local_itr = 0; local_itr < 5; local_itr++) {
		if (strcmp(Astr_Accounts->primaryAccountNumber[local_it], local_pan) == 0)
		{
			if (Astr_Accounts[local_itr].balance > amount) {
				return DECLINED_INSUFFECIENT_FUND;
			}
			else {
				flag = 1;
				Astr_Accounts[local_itr].balance -= amount;
				break;
			}
		}
	}
	if (flag == 0) {
		return DECLINED_STOLEN_CARD;
	}
	return APPROVED;*/

}
int local_it;
EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
	for (local_it = 0; local_it < 5; local_it++) {
		if (strcmp(cardData->primaryAccountNumber, Astr_Accounts[local_it].primaryAccountNumber) == 0) {
			return APPROVED;
		}
	}
	return DECLINED_STOLEN_CARD;
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
	if (termData->transAmount <= Astr_Accounts[local_it].balance) {
		return LOW_BALANCE;
	}
	else {
			//Astr_Accounts[local_it].balance -= termData->transAmount;
			return OK;
	}
}
EN_serverError_t saveTransaction(ST_transaction* transData) {
	Astr_Accounts[local_it].balance -= transData->terminalData.transAmount;
	transData->transactionSequenceNumber++;
	return OK;
	
}
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction* transData) { 
	printf("transaction number: %d", transData->transactionSequenceNumber);
	printf("clint name: \n", transData->cardHolderData.cardHolderName);
	printf("transacted amount: \n", transData->terminalData.transAmount);
	printf("remaining balance: \n", Astr_Accounts[local_it].balance);
	printf("remaning transaction amounts for today: \n", transData->terminalData.maxTransAmount);
	return OK;
}