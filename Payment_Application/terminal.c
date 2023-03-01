#include "stdTypes.h"
#include"terminal.h"
#include<string.h>
#include"stdio.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	printf("Enter transaction date/n");
	scanf("%s",termData->transactionDate);
	for (int local_it = 0; local_it < 5; local_it++) {
		if (local_it == 2|| local_it==4) {
			if (termData->transactionDate[local_it] != '/') {
				return WRONG_DATE;
			}
		}
		else if (termData->transactionDate[local_it] < 48 || termData->transactionDate[local_it]>57) {
			return WRONG_DATE;
		}
	}
	return OK;
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
	for (int local_it = 0; local_it < 10; local_it++) {
		if (cardData.cardExpirationDate[local_it] != termData.transactionDate[local_it]) {
			return EXPIRED_CARD;
		 }
	}
	return OK;
}
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData) {
	//cardData->primaryAccountNumber;


}


EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	printf("transaction amount\n");
	scanf("%f", &termData->transAmount);
	if (termData->transAmount <= 0) {
		return INVALID_AMOUNT; 
	}
	else 
	    return OK;
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	if (termData->transAmount > termData->maxTransAmount) {
		 return EXCEED_MAX_AMOUNT;
	}
	else
		return OK;
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
	termData->maxTransAmount -= termData->transAmount;
	/*if (termData->maxTransAmount <= 0) {
		return INVALID_MAX_AMOUNT;
	}
	else
		return OK;*/
	return OK;
}