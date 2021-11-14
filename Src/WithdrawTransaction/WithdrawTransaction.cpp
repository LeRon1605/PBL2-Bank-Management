#include "WithdrawTransaction.h"
#include "../Repo/Repo.h"
Withdraw::Withdraw(){

}

Withdraw::Withdraw(const string &ID, Card srcAccount, const long &cash, const float &fee, const bool &status, const Date &date)
    : Transaction(ID, srcAccount, cash, fee, status, date)
{

}

Withdraw::Withdraw(const string &ID, Card srcAccount, const long &cash)
    : Transaction(ID, srcAccount, cash)
{

}

Withdraw::Withdraw(const Withdraw &D){
    this -> ID = D.ID;
    this -> srcAccount = D.srcAccount;
    this -> cash = D.cash;
    this -> fee = D.fee;
    this -> status = D.status;
    this -> date = D.date;
}

Withdraw::~Withdraw(){

}

void Withdraw::show(){
    cout << "Transaction ID: " << this -> ID << endl;
    cout << "Source Account: " << ((this -> srcAccount)).getID() << endl;
    cout << "Amount: " << this -> cash << " VND" << endl;
    cout << "Fee: " << this -> fee << " VND" << endl;
    if (this -> status)
        cout << "Balance: " << ((this -> srcAccount)).getBalance() << " VND (-" << this -> cash - this -> fee << " VND)" << endl;
    else cout << "Balance: " << ((this -> srcAccount)).getBalance() << " VND" << endl;
    cout << "Status: " << this -> getStrStatus() << endl;
    cout << "Time: " << this -> date << endl;
}

// Số tiền dưới 10tr thì phí bằng 5000
// Số tiền dưới 100tr thì phí bằng 7000 + 0.5%
// Số tiền dưới 500tr thì phí bằng 10000 + 1%
// Số tiền trên 500tr thì phí bằng 13000
int Withdraw::calFee(){
    if (this -> cash < 10000000) return 5000;
    else if (this -> cash < 100000000) return (7000 + 0.005*this -> cash);
    else if (this -> cash < 500000000) return (10000 + 0.01*this -> cash);
    return 13000;
}

void Withdraw::makeTransaction(const string &pin){
    if (((this -> srcAccount)).getPin() == pin)
        if (this -> cash >= 50000) 
            if (((this -> srcAccount)).getBalance() >= this -> cash + this -> calFee()){
                ((this -> srcAccount)).withdraw(this -> cash + this -> calFee());
                this -> status = true;
                this -> fee = calFee();
                this -> date = Date::getCurrentDate();
                cout << "Successfully withdraw " << this -> cash << endl;
            }
            else
                cout << "Your balance doesn't enough to withdraw" << endl;
        else 
            cout << "Require at least 50,000 VND to withdraw" << endl;
    else 
        cout << "Pin is not correct" << endl;
}

string Withdraw::getType(){
    return "Withdraw";
}

const Withdraw& Withdraw::operator=(const Withdraw &W){
    cout << "Withdraw::operator";
    this -> ID = W.ID;
    this -> srcAccount = W.srcAccount;
    this -> cash = W.cash;
    this -> fee = W.fee;
    this -> status = W.status;
    this -> date = W.date;
    return (*this);
}

bool Withdraw::operator==(const Withdraw &newWithdraw){
    if(this->ID == newWithdraw.ID && this->srcAccount == newWithdraw.srcAccount && this->cash == newWithdraw.cash && this->fee == newWithdraw.fee && this->status == newWithdraw.status && this->date == newWithdraw.date){
        return true;
    }
    return false;
}


ifstream& operator>>(ifstream &in, Withdraw &W){
    string srcAccountID, date;
    getline(in >> ws, W.ID);
    getline(in >> ws, srcAccountID);
    W.srcAccount = Repository<Card>::getByID(srcAccountID, "Card.txt");
    in >> W.cash;
    in >> W.fee;
    in >> W.status;
    getline(in >> ws, date);
    W.date = Date(date.c_str());
    return in;
}
ofstream& operator<<(ofstream &out, const Withdraw &W){
    out << Withdraw(W).getType() << endl;
    out << W.ID << endl;
    out << Withdraw(W).srcAccount.getID() << endl;
    out << W.cash << endl;
    out << W.fee << endl;
    out << W.status << endl;
    out << Withdraw(W).date.toString() << endl;
    return out;
}