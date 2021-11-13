#include "TransactionManager.h"

TransactionManager::TransactionManager(){

}

TransactionManager::~TransactionManager(){

}

string TransactionManager::generateID(){

}

void TransactionManager::show(){

}

void TransactionManager::showByID(const string &ID){

}

Transaction* TransactionManager::findByID(const string &ID){

}

int TransactionManager::indexOf(const Transaction *T){

}

int TransactionManager::indexOf(const string &ID){

}

bool TransactionManager::add(const Transaction *T){

}

bool TransactionManager::remove(const Transaction *T){

}

bool TransactionManager::removeByID(const string &ID){

}

void TransactionManager::listByDate(const Date &D){

}

bool TransactionManager::makeWithdraw(const string &CardID, const long &cash, const string &PIN){

}

bool TransactionManager::makeTransfer(const string &SrcAccount, const string &DestAccount, const long &cash, const string &PIN){

}

bool TransactionManager::makeDeposit(const string &CardID, const long &cash, const string &PIN){

}

void TransactionManager::showWithdraw(){

}

void TransactionManager::showTransfer(){

}

void TransactionManager::showDeposit(){

}

void TransactionManager::showAllClientTransaction(const string &ClientID){

}

void TransactionManager::showAllCardTransaction(const string &CardID){
    
}