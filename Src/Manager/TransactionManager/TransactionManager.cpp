#include "TransactionManager.h"
#include "../../WithdrawTransaction/WithdrawTransaction.h"
#include "../../TransferTransaction/TransferTransaction.h"
#include "../../DepositTransaction/DepositTransaction.h"
#include "../../Repo/Repo.h"
#include <fstream>
int TransactionManager::totalTransactionCreated = 0;
TransactionManager::TransactionManager(){
    ifstream in;
    in.open("../Data/Transaction.txt");
    int n;
    string transactionType;
    in >> n >> TransactionManager::totalTransactionCreated;
    for (int i = 0; i < n; i++){
        in >> transactionType;
        if (transactionType == "Withdraw"){
            Withdraw temp;
            in >> temp;
            Transaction *ptr = new Withdraw(temp);
            this -> list.addTail(ptr);
        }
        else if (transactionType == "Deposit"){
            Deposit temp;
            in >> temp;
            Transaction *ptr = new Deposit(temp);
            this -> list.addTail(ptr);
        }
        else if (transactionType == "Transfer"){
            Transfer temp;
            in >> temp;
            Transaction *ptr = new Transfer(temp);
            this -> list.addTail(ptr);
        }
    }
    in.close();
}

TransactionManager::~TransactionManager(){
    ofstream out;
    out.open("../Data/Transaction.txt");
    out << this -> list.getLength() << endl;
    out << TransactionManager::totalTransactionCreated << endl;
    Node<Transaction*> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr -> getData() -> getType() == "Withdraw"){
            Withdraw temp = *((Withdraw*)(ptr -> getData()));
            out << temp;
        }
        else if (ptr -> getData() -> getType() == "Deposit"){
            Deposit temp = *((Deposit*)(ptr -> getData()));
            out << temp;
        }
        else if (ptr -> getData() -> getType() == "Transfer"){
            Transfer temp = *((Transfer*)(ptr -> getData()));
            out << temp;
        }
        ptr = ptr -> getNext();
    }
    out.close();
}

string TransactionManager::generateID(){
    return (to_string(10000000 + TransactionManager::totalTransactionCreated));
}

void TransactionManager::show(){
    Node<Transaction*> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}

void TransactionManager::showByID(const string &ID){
    Node<Transaction*> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr -> getData() -> getID() == ID) ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}

Transaction* TransactionManager::findByID(const string &ID){
    Node<Transaction*> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr -> getData() -> getID() == ID) return ptr -> getData();
        ptr = ptr -> getNext();
    }
    return nullptr;
}

int TransactionManager::indexOf(Transaction *T){
    // Node<Transaction*> *ptr = this -> list.getHead();
    // int index = 0;
    // while (ptr != nullptr){
    //     if (Withdraw(*T) == ptr -> getData() && T -> getType() == "Withdraw") return index;
    //     if (Deposit(*T) == ptr -> getData() && T -> getType() == "Deposit") return index;
    //     if (Transfer(*T) == ptr -> getData() && T -> getType() == "Transfer") return index;
    //     index++;
    //     ptr = ptr-> getNext();
    // }
    return -1;
}

int TransactionManager::indexOf(const string &ID){
    return -1;
}

bool TransactionManager::add(Transaction *T){
    TransactionManager::totalTransactionCreated++;
    return this -> list.addTail(T);
}

bool TransactionManager::remove(Transaction *T){
    // int index = this -> indexOf(T);
    // if (index == -1) return false;
    // return this -> list.removeAt(index);
    return false;
}

bool TransactionManager::removeByID(const string &ID){
    int index = this -> indexOf(ID);
    return this -> list.removeAt(index);
}

void TransactionManager::listByDate(const Date &D){

}

bool TransactionManager::makeWithdraw(const string &CardID, const long &cash, const string &PIN){
    Transaction *ptr = new Withdraw(this -> generateID(), Repository<Card>::getByID(CardID, "Card.txt"), cash);
    bool result = ptr -> makeTransaction(PIN);
    Repository<Card>::findAndUpdate(ptr -> getSrcAccount(), "Card.txt");
    this -> add(ptr);
    return result;
}

bool TransactionManager::makeTransfer(const string &SrcAccount, const string &DestAccount, const long &cash, const string &PIN){
    Transfer T = Transfer(this -> generateID(), Repository<Card>::getByID(SrcAccount, "Card.txt"), Repository<Card>::getByID(DestAccount, "Card.txt"), cash);
    bool result = T.makeTransaction(PIN);
    Repository<Card>::findAndUpdate(T.getSrcAccount(), "Card.txt");
    Repository<Card>::findAndUpdate(T.getDestAccount(), "Card.txt");
    Transaction *ptr = new Transfer(T);
    this -> add(ptr);
    return false;
}

bool TransactionManager::makeDeposit(const string &CardID, const long &cash, const string &PIN){
    return false;
}

void TransactionManager::showWithdraw(){

}

void TransactionManager::showTransfer(){
    Node<Transaction*> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr -> getData() -> getType() == "Transfer") ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}

void TransactionManager::showDeposit(){

}

void TransactionManager::showAllClientTransaction(const string &ClientID){
    Node<Transaction*> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr -> getData() -> getSrcAccount().getHolder().getID() == ClientID) ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}

void TransactionManager::showAllCardTransaction(const string &CardID){
    
}