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

