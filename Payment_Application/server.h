#pragma once
#ifndef SERVER_H
#define SERVER_H

#include "card.h"
#include "terminal.h"

typedef struct ST_accountsDB_t
{
	float balance;
	char primaryAccountNumber[20];
}ST_accountsDB_t;

typedef enum EN_serverError_t
{
	OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t;

typedef enum EN_transState_t
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transStat_t;

typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transStat_t transState;
	uint32_t  transactionSequenceNumber; 
}ST_transaction;

EN_transStat_t recieveTransactionData(ST_transaction* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);
EN_serverError_t saveTransaction(ST_transaction* transData);
EN_serverError_t getTransaction(int transactionSequenceNumber, ST_transaction* transData);


#endif
