#include "TransactionManager.h"
#include "../../WithdrawTransaction/WithdrawTransaction.h"
#include "../../TransferTransaction/TransferTransaction.h"
#include "../../DepositTransaction/DepositTransaction.h"
#include "../../Repo/Repo.h"
#include <fstream>
#include <iomanip>
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
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
    cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(20) << "| SrcAccount" << left << setw(20) << "| DestAccount";
    cout << left << setw(15) << "| Ammount" << left << setw(15) << "| Fee" << left << setw(20) << "| Balance (VND)" << left << setw(15) << "| Status" << left << setw(29) << "| Date" << "| " << endl;
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
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
    //     if (ptr -> getData() == Withdraw(*T) && T -> getType() == "Withdraw") return index;
    //     if (ptr -> getData() == Deposit(*T) && T -> getType() == "Deposit") return index;
    //     if (ptr -> getData() == Transfer(*T) && T -> getType() == "Transfer") return index;
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
    return false;
}

bool TransactionManager::removeByID(const string &ID){
    int index = this -> indexOf(ID);
    if (index == -1) return false;
    else return this -> list.removeAt(index);
}
//
void TransactionManager::listByDate(const Date &D){
    Node<Transaction*> *ptr = this -> list.getHead();
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
    cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(20) << "| SrcAccount" << left << setw(20) << "| DestAccount";
    cout << left << setw(15) << "| Ammount" << left << setw(15) << "| Fee" << left << setw(20) << "| Balance (VND)" << left << setw(15) << "| Status" << left << setw(29) << "| Date" << "| " << endl;
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
    while (ptr != nullptr){
        if (Date::compareDate(ptr ->getData()->getDate(), D)) {
            ptr -> getData()->show();
        }
        ptr = ptr -> getNext();
    }
}

bool TransactionManager::makeWithdraw(const string &CardID, const long &cash, const string &PIN){
    if (Repository<Card>::getByID(CardID, "Card.txt").isNull()){
        cout << "The khong ton tai" << endl;
        return false;
    }
    Transaction *ptr = new Withdraw(this -> generateID(), Repository<Card>::getByID(CardID, "Card.txt"), cash);
    bool result = ptr -> makeTransaction(PIN);
    Repository<Card>::findAndUpdate(ptr -> getSrcAccount(), "Card.txt");
    this -> add(ptr);
    return result;
}

bool TransactionManager::makeTransfer(const string &SrcAccount, const string &DestAccount, const long &cash, const string &PIN){
    if (Repository<Card>::getByID(SrcAccount, "Card.txt").isNull() || Repository<Card>::getByID(DestAccount, "Card.txt").isNull()){
        cout << "The khong ton tai" << endl;
        return false;
    }
    Transfer T = Transfer(this -> generateID(), Repository<Card>::getByID(SrcAccount, "Card.txt"), Repository<Card>::getByID(DestAccount, "Card.txt"), cash);
    bool result = T.makeTransaction(PIN);
    Repository<Card>::findAndUpdate(T.getSrcAccount(), "Card.txt");
    Repository<Card>::findAndUpdate(T.getDestAccount(), "Card.txt");
    Transaction *ptr = new Transfer(T);
    this -> add(ptr);
    return result;
}

bool TransactionManager::makeDeposit(const string &CardID, const long &cash, const string &PIN){
    if (Repository<Card>::getByID(CardID, "Card.txt").isNull()){
        cout << "The khong ton tai" << endl;
        return false;
    }
    Transaction *ptr = new Deposit(this -> generateID(), Repository<Card>::getByID(CardID, "Card.txt"), cash);
    bool result = ptr -> makeTransaction(PIN);
    Repository<Card>::findAndUpdate(ptr -> getSrcAccount(), "Card.txt");
    this -> add(ptr);
    return result;
}

void TransactionManager::showWithdraw(){
    Node<Transaction*> *ptr = this->list.getHead();
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
	cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(20) << "| SrcAccount" << left << setw(20) << "| DestAccount";
	cout << left << setw(15) << "| Ammount" << left << setw(15) << "| Fee" << left << setw(20) << "| Balance (VND)" << left << setw(15) << "| Status" << left << setw(29) << "| Date" << "| " << endl;
	cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
    while (ptr != nullptr){
        if (ptr -> getData() -> getType() == "Withdraw") ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}

void TransactionManager::showTransfer(){
    Node<Transaction*> *ptr = this -> list.getHead();
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
	cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(20) << "| SrcAccount" << left << setw(20) << "| DestAccount";
	cout << left << setw(15) << "| Ammount" << left << setw(15) << "| Fee" << left << setw(20) << "| Balance (VND)" << left << setw(15) << "| Status" << left << setw(29) << "| Date" << "| " << endl;
	cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
    while (ptr != nullptr){
        if (ptr -> getData() -> getType() == "Transfer") ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}

void TransactionManager::showDeposit(){
    Node<Transaction*> *ptr = this -> list.getHead();
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
	cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(20) << "| SrcAccount" << left << setw(20) << "| DestAccount";
	cout << left << setw(15) << "| Ammount" << left << setw(15) << "| Fee" << left << setw(20) << "| Balance (VND)" << left << setw(15) << "| Status" << left << setw(29) << "| Date" << "| " << endl;
	cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
    while (ptr != nullptr){
        if (ptr -> getData() -> getType() == "Deposit") ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}

void TransactionManager::showAllClientTransaction(const string &ClientID){
    Node<Transaction*> *ptr = this -> list.getHead();
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
	cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(20) << "| SrcAccount" << left << setw(20) << "| DestAccount";
	cout << left << setw(15) << "| Ammount" << left << setw(15) << "| Fee" << left << setw(20) << "| Balance (VND)" << left << setw(15) << "| Status" << left << setw(29) << "| Date" << "| " << endl;
	cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
    while (ptr != nullptr){
        if (ptr -> getData() -> getSrcAccount().getHolder().getID() == ClientID) ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}

void TransactionManager::showAllCardTransaction(const string &CardID){
    Node<Transaction*> *ptr = this -> list.getHead();
    cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
	cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(20) << "| SrcAccount" << left << setw(20) << "| DestAccount";
	cout << left << setw(15) << "| Ammount" << left << setw(15) << "| Fee" << left << setw(20) << "| Balance (VND)" << left << setw(15) << "| Status" << left << setw(29) << "| Date" << "| " << endl;
	cout << setfill('-') << setw(165) << '-' << setfill(' ') << endl;
    while (ptr != nullptr){
        if(ptr -> getData()-> getSrcAccount().getID() == CardID)  ptr -> getData() -> show();
        ptr = ptr -> getNext();
    }
}