#include "Transaction.h"

Transaction::Transaction(){

}

Transaction::Transaction(const string &ID, const Card &srcAccount, const long &cash, const float &fee, const bool &status, const Date &date){
    this -> ID = ID;
    this -> srcAccount = (Card::isValidID(Card(srcAccount).getID())) ? srcAccount : Card();
    this -> cash = (cash > 0) ? cash : 0;
    this -> fee = (fee > 0) ? fee : 0;
    this -> status = status;
    this -> date = (Date(date).isValidDate()) ? date : Date();
}

Transaction::Transaction(const string &ID, const Card &srcAccount, const long &cash){
    this -> ID = ID;
    this -> srcAccount = (Card::isValidID(Card(srcAccount).getID())) ? srcAccount : Card();
    this -> cash = (cash > 0) ? cash : 0;
    this -> date = Date::getCurrentDate();
}

Transaction::Transaction(const Transaction &T){
    this -> ID = T.ID;
    this -> srcAccount = T.srcAccount;
    this -> cash = T.cash;
    this -> fee = T.fee;
    this -> status = T.status;
    this -> date = T.date;
}

Transaction::~Transaction(){

}

string Transaction::getID(){
    return this -> ID;
}

Card Transaction::getSrcAccount(){
    return this -> srcAccount;
}

long Transaction::getCash(){
    return this -> cash;
}

int Transaction::getFee(){
    return this -> fee;
}

int Transaction::getStatus(){
    return this -> status;
}

string Transaction::getStrStatus(){
    return (this -> status) ? "Success" : "Failure";
}

Date Transaction::getDate(){
    return this -> date;
}

void Transaction::setID(const string &ID){
    this -> ID = (Transaction::isValidID(ID)) ? ID : "";
}

void Transaction::setSrcAccount(const Card &C){
    this -> SrcAccount = C;
}

void Transaction::setCash(const long &cash){
    this -> cash = cash;
}

void Transaction::setFee(const int &fee){
    this -> fee = fee;
}

void Transaction::setStatus(const bool &status){
    this -> status = status;
}

void Transaction::setDate(const Date &date){
    this -> date = date;
}

bool Transaction::isValidID(const string &str){
    if (str.size() != 8) return false;
    for (int i = 0; i < str.size();i++){
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}