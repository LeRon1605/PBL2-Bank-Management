#include "DepositTransaction.h"
#include "../Repo/Repo.h"
Deposit::Deposit(){

}

Deposit::Deposit(const string &ID, Card srcAccount, const long &cash, const float &fee, const bool &status, const Date &date)
    : Transaction(ID, srcAccount, cash, fee, status, date)
{

}

Deposit::Deposit(const string &ID, Card srcAccount, const long &cash)
    : Transaction(ID, srcAccount, cash)
{

}

Deposit::Deposit(const Deposit &D){
    this -> ID = D.ID;
    this -> srcAccount = D.srcAccount;
    this -> cash = D.cash;
    this -> fee = D.fee;
    this -> status = D.status;
    this -> date = D.date;
}

Deposit::~Deposit(){

}

void Deposit::show(){
    cout << "Transaction ID: " << this -> ID << endl;
    cout << "Source Account: " << ((this -> srcAccount)).getID() << endl;
    cout << "Amount: " << this -> cash << " VND" << endl;
    cout << "Fee: " << this -> fee << " VND" << endl;
    if (this -> status)
        cout << "Balance: " << ((this -> srcAccount)).getBalance() << " VND (+" << this -> cash - this -> fee << " VND)" << endl;
    else cout << "Balance: " << ((this -> srcAccount)).getBalance() << " VND" << endl;
    cout << "Status: " << this -> getStrStatus() << endl;
    cout << "Time: " << this -> date << endl;
}

// Số tiền dưới 10tr thì phí bằng 5000
// Số tiền dưới 100tr thì phí bằng 5000 + 1%
// Số tiền dưới 500tr thì phí bằng 7000 + 1.5%
// Số tiền trên 500tr thì phí bằng 10000 + 2%
int Deposit::calFee(){
    if (this -> cash < 10000000) return 5000;
    else if (this -> cash < 100000000) return (5000 + 0.01*this -> cash);
    else if (this -> cash < 500000000) return (7000 + 0.015*this -> cash);
    return (10000 + 0.02*this -> cash);
}

void Deposit::makeTransaction(const string &pin){
    if (((this -> srcAccount)).getPin() == pin)
        if (this -> cash >= 50000){
            ((this -> srcAccount)).deposit(this -> cash - this -> calFee());
            this -> status = true;
            this -> fee = this -> calFee();
            this -> date = Date::getCurrentDate();
            cout << "Successfully Deposit " << this -> cash << endl;
        }    
        else 
            cout << "Require at least 50,000 VND to Deposit" << endl;
    else 
        cout << "Pin is not correct" << endl;
}

string Deposit::getType(){
    return "Deposit";
}

const Deposit& Deposit::operator=(const Deposit &W){
    this -> ID = W.ID;
    this -> srcAccount = W.srcAccount;
    this -> cash = W.cash;
    this -> fee = W.fee;
    this -> status = W.status;
    this -> date = W.date;
    return (*this);
}

bool Deposit::operator==(const Deposit &newDeposit){
    if(this->ID == newDeposit.ID && this->srcAccount == newDeposit.srcAccount && this->cash == newDeposit.cash && this->fee == newDeposit.fee && this->status == newDeposit.status && this->date == newDeposit.date){
        return true;
    }
    return false;
}

ifstream& operator>>(ifstream &in, Deposit &D){
    string srcAccountID, date;
    getline(in >> ws, D.ID);
    getline(in >> ws, srcAccountID);
    D.srcAccount = Repository<Card>::getByID(srcAccountID, "Card.txt");
    in >> D.cash;
    in >> D.fee;
    in >> D.status;
    getline(in >> ws, date);
    D.date = Date(date.c_str());
    return in;
}

ofstream& operator<<(ofstream &out, const Deposit &D){
    out << Deposit(D).getType() << endl;
    out << D.ID << endl;
    out << Deposit(D).srcAccount.getID() << endl;
    out << D.cash << endl;
    out << D.fee << endl;
    out << D.status << endl;
    out << Deposit(D).date.toString() << endl;
    return out;
}