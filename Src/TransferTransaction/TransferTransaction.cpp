#include "TransferTransaction.h"
#include "../Repo/Repo.h"
Transfer::Transfer(){

}

Transfer::Transfer(const string &ID, Card srcAccount, Card destAccount, const long &cash, const float &fee, const bool &status, const Date &date)
    : Transaction(ID, srcAccount, cash, fee, status, date)
{
    this -> destAccount = destAccount;
}

Transfer::Transfer(const string &ID, Card srcAccount, Card destAccount, const long &cash)
    : Transaction(ID, srcAccount, cash)
{
    this -> destAccount = (Card::isValidID((destAccount).getID())) ? destAccount : Card();
}

Transfer::Transfer(const Transfer &D){
    this -> ID = D.ID;
    this -> srcAccount = D.srcAccount;
    this -> destAccount = D.destAccount;
    this -> cash = D.cash;
    this -> fee = D.fee;
    this -> status = D.status;
    this -> date = D.date;
}

Transfer::~Transfer(){

}

void Transfer::setDestAccount(Card C){
    this -> destAccount = C;
}

Card Transfer::getDestAccount(){
    return (this -> destAccount);
}

void Transfer::show(){
    cout << "Transaction ID: " << this -> ID << endl;
    cout << "Source Account: " << ((this -> srcAccount)).getID() << endl;
    cout << "Destination Account: " << ((this -> destAccount)).getID() << endl;
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

bool Transfer::makeTransaction(const string &pin){
    if (((this -> srcAccount)).getPin() == pin)
        if (this -> cash >= 50000) 
            if (((this -> srcAccount)).getBalance() >= this -> cash + this -> calFee()){
                ((this -> srcAccount)).withdraw(this -> cash + this -> calFee());
                ((this -> destAccount)).deposit(this -> cash);
                this -> status = true;
                this -> fee = calFee();
                this -> date = Date::getCurrentDate();
                cout << "Successfully Transfer " << this -> cash << " to " << ((this -> destAccount)).getID() << endl;
                return true;
            }
            else
                cout << "Your balance doesn't enough to Transfer" << endl;
        else 
            cout << "Require at least 50,000 VND to transfer" << endl;
    else 
        cout << "Pin is not correct" << endl;
    return false;
}

string Transfer::getType(){
    return "Transfer";
}
bool Transfer::operator==(const Transfer &newTransfer){
    if(this->ID == newTransfer.ID && this->srcAccount == newTransfer.srcAccount &&  this->destAccount == newTransfer.destAccount && this->cash == newTransfer.cash && this->fee == newTransfer.fee && this->status == newTransfer.status && this->date == newTransfer.date){
        return true;
    }
    return false;
}

ifstream& operator>>(ifstream &in, Transfer &T){
    string srcAccountID, destAccountID, date;
    getline(in >> ws, T.ID);
    getline(in >> ws, srcAccountID);
    T.srcAccount = Repository<Card>::getByID(srcAccountID, "Card.txt");
    getline(in >> ws, destAccountID);
    T.destAccount = Repository<Card>::getByID(destAccountID, "Card.txt");
    in >> T.cash;
    in >> T.fee;
    in >> T.status;
    getline(in >> ws, date);
    T.date = Date(date.c_str());
    return in;
}
ofstream& operator<<(ofstream &out, const Transfer &T){
    out << Transfer(T).getType() << endl;
    out << T.ID << endl;
    out << Transfer(T).srcAccount.getID() << endl;
    out << Transfer(T).destAccount.getID() << endl;
    out << T.cash << endl;
    out << T.fee << endl;
    out << T.status << endl;
    out << Transfer(T).date.toString() << endl;
    return out;
}