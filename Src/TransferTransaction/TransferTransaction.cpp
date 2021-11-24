#include "TransferTransaction.h"
#include <iomanip>
#include "../Repo/Repo.h"
#include "../Helper/Helper.h"
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

Transfer::Transfer(const Transfer &T): Transaction(T){
    this -> destAccount = T.destAccount;
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
    cout << "| " << left << setw(13) << this -> ID;
    cout << "| " << left << setw(13) << this -> getType();
    cout << "| " << left << setw(13) << this -> srcAccount.getID(); 
    cout << "| " << left << setw(13) << this -> destAccount.getID();
    cout << "| " << left << setw(18) << moneyFormat(this -> cash);
    cout << "| " << left << setw(13) << moneyFormat(this -> fee);
    cout << "| " << left << setw(28);
    if (this -> status)
        cout << moneyFormat(this -> balance) + " (-" + moneyFormat(this -> cash + this -> fee) + ")";
    else cout << moneyFormat(this -> balance);
    cout << "| ";
    if (this -> status) SetColor(0, 2);
    else SetColor(0, 4);
    cout << setw(13) << this -> getStrStatus();
    SetColor(0, 15);
    cout << "| " << this -> date << setw(8) << ' ' << "| " << endl;
    cout << setfill('-') << setw(170) << '-' << setfill(' ') << endl;
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
                this -> balance = this -> srcAccount.getBalance();
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
    if (T.srcAccount.isNull()) T.srcAccount.setID(srcAccountID); // Card đã bị xóa
    if (T.destAccount.isNull()) T.destAccount.setID(destAccountID); // Card đã bị xóa
    in >> T.cash;
    in >> T.fee;
    in >> T.balance;
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
    out << T.balance << endl;
    out << T.status << endl;
    out << Transfer(T).date.toString() << endl;
    return out;
}