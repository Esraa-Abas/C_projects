#include <stdio.h>
#include <string.h>

#include "stdTypes.h"
#include "card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	
	printf("Please, enter your name.\n");
	
	scanf("%s",cardData->cardHolderName); //&
	if (strlen(cardData->cardHolderName) < 20 || strlen(cardData->cardHolderName) > 24) {
		return WRONG_NAME;
	}
	else {
		return OK;
	}
	
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	printf("Please, enter the expiry date\n");
	scanf("%s",cardData->cardExpirationDate);
	if (strlen(cardData->cardExpirationDate) != 5) {
		return WRONG_EXP_DATE;
	}
	for (int local_it = 0; local_it < 5; local_it++) {
		if (local_it == 2) {
			if (cardData->cardExpirationDate[local_it] != '/') {
				return WRONG_EXP_DATE;
			}
		}
		else if (cardData->cardExpirationDate[local_it] < 48 || cardData->cardExpirationDate[local_it]>57) {
				return WRONG_EXP_DATE;
		}
	}
	return OK;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	prinf("Enter your card's Primary Account Number\n");
	scanf("%s",cardData->primaryAccountNumber);
	if (strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19) {
		return WRONG_PAN;
	}
	else
		return OK;
	
}