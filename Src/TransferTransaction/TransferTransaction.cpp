#include "TransferTransaction.h"

Transfer::Transfer(){

}

Transfer::Transfer(const string &ID, Card srcAccount, Card desAccount, const long &cash, const float &fee, const bool &status, const Date &date)
    : Transaction(ID, srcAccount, cash, fee, status, date)
{
    this -> desAccount = desAccount;
}

Transfer::Transfer(const string &ID, Card srcAccount, Card desAccount, const long &cash)
    : Transaction(ID, srcAccount, cash)
{
    this -> desAccount = (Card::isValidID((desAccount).getID())) ? desAccount : Card();
}

Transfer::Transfer(const Transfer &D){
    this -> ID = D.ID;
    this -> srcAccount = D.srcAccount;
    this -> desAccount = D.desAccount;
    this -> cash = D.cash;
    this -> fee = D.fee;
    this -> status = D.status;
    this -> date = D.date;
}

Transfer::~Transfer(){

}

void Transfer::setDesAccount(Card C){
    this -> desAccount = C;
}

Card Transfer::getDesAccount(){
    return (this -> desAccount);
}

void Transfer::show(){
    cout << "Transaction ID: " << this -> ID << endl;
    cout << "Source Account: " << ((this -> srcAccount)).getID() << endl;
    cout << "Destination Account: " << ((this -> desAccount)).getID() << endl;
    cout << "Amount: " << this -> cash << " VND" << endl;
    cout << "Fee: " << this -> fee << " VND" << endl;
    if (this -> status)
        cout << "Balance: " << ((this -> srcAccount)).getBalance() << " VND (-" << this -> cash - this -> fee << " VND)" << endl;
    else cout << "Balance: " << ((this -> srcAccount)).getBalance() << " VND" << endl;
    cout << "Status: " << this -> getStrStatus() << endl;
    cout << "Time: " << this -> date << endl;
}

// Số tiền dưới 10tr thì phí bằng 5000 + 1% Số tiền chuyển
// Số tiền dưới 50tr thì phí bằng 7000 + 2% Số tiền chuyển
// Số tiền dưới 100tr thì phí bằng 10000 + 2% Số tiền chuyển
// Số tiền dưới 500tr thì phí bằng 20000 + 3% số tiền chuyển
// Số tiền lớn hơn 500tr thì phí bằng 50000 + 3% số tiền chuyển
int Transfer::calFee(){
    if (this -> cash < 10000000) return (5000 + 0.01*this -> cash);
    else if (this -> cash < 50000000) return (7000 + 0.02*this -> cash);
    else if (this -> cash < 100000000) return (10000 + 0.02*this -> cash);
    else if (this -> cash < 500000000) return (20000 + 0.03*this -> cash);
    return (50000 + 0.03*this -> cash);
}

void Transfer::makeTransaction(const string &pin){
    if (((this -> srcAccount)).getPin() == pin)
        if (this -> cash >= 50000) 
            if (((this -> srcAccount)).getBalance() >= this -> cash + this -> calFee()){
                ((this -> srcAccount)).withdraw(this -> cash + this -> calFee());
                ((this -> desAccount)).deposit(this -> cash);
                this -> status = true;
                this -> fee = calFee();
                this -> date = Date::getCurrentDate();
                cout << "Successfully Transfer " << this -> cash << " to " << ((this -> desAccount)).getID() << endl;
            }
            else
                cout << "Your balance doesn't enough to Transfer" << endl;
        else 
            cout << "Require at least 50,000 VND to transfer" << endl;
    else 
        cout << "Pin is not correct" << endl;
}