#include "app.h"
#include"card.h"
#include"terminal.h"
#include"server.h"
#include"stdio.h"
void appStart(void) {

	ST_cardData_t datacard;
	ST_terminalData_t termdata;
	ST_transaction trans;
	trans.transactionSequenceNumber = 0;
	termdata.maxTransAmount = 20000.0;
	if (getCardHolderName(&datacard) == OK) {
		if (getCardExpiryDate(&datacard) == OK) {
			if (getCardPAN(&datacard) == OK) {
				if (getTransactionDate(&termdata)==OK) {
					if (isCardExpired(datacard, termdata)==OK) {
						if (getTransactionAmount(&termdata) == OK) {
							if (isBelowMaxAmount(&termdata) == OK) {
								if (isValidAccount(&datacard)==OK) {
									if (isAmountAvailable(&termdata) == OK) {
										if (setMaxAmount(&termdata) == OK) {
											if (saveTransaction(&trans) == OK) {
												if (getTransaction(trans.transactionSequenceNumber, &trans) == OK) {
													printf("success! pull your card ^ ^\n");
												}
											}
										}
									}
									else {
										printf("there is no enough balance.\n");
										return ;
									}
								}
								else {
									printf("stolen card?!\n");
									return ;
								}
							}
							else {
								printf("you have exceeded the maximum avilable amount of money for today.\n");
								return ;
							}
						}
						else {
							printf("enter valid transaction amount!\n");
							return ;
						}
					}
					else {
						printf("this card is expired.\n");
						return ;
					}
				}
				else {
					printf("transaction date must be in formate --/--/----\n");
					return ;
				}
			}
			else {
				printf("PAN must be between 16 and 19 digit/character.\n");
				return ;
			}
		}
		else {
			printf("expiry date must be in formate --/--\n");
			return ;
		}
	}
	else {
		printf("name must be between 20 and 24.\n");
		return ;
	}
	
	

	return;

}
