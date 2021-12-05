#include "WithdrawTransaction.h"
#include <iomanip>
#include "../Repo/Repo.h"
#include "../Helper/Helper.h"
Withdraw::Withdraw(){

}

Withdraw::Withdraw(const string &ID, Card srcAccount, const long &cash, const float &fee, const bool &status, const string &statusCode, const Date &date)
    : Transaction(ID, srcAccount, cash, fee, status, statusCode, date)
{

}

Withdraw::Withdraw(const string &ID, Card srcAccount, const long &cash)
    : Transaction(ID, srcAccount, cash)
{

}

Withdraw::Withdraw(const Withdraw &W): Transaction(W){
}

Withdraw::~Withdraw(){

}

void Withdraw::show(){
    cout << "| " << left << setw(13) << this -> ID;
    cout << "| " << left << setw(13) << this -> getType();
    cout << "| " << left << setw(13) << this -> srcAccount.getID(); 
    cout << "| " << left << setw(13) << "--------";
    cout << "| " << left << setw(18) << moneyFormat(this -> cash);
    cout << "| " << left << setw(13) << moneyFormat(this -> fee);
    cout << "| " << left << setw(28);
    if (this -> status)
        cout << moneyFormat(this -> balance) + " (-" + moneyFormat(this -> cash + this -> fee)+ ")";
    else cout << moneyFormat(this -> balance);
    cout << "| ";
    if (this -> status) SetColor(0, 2);
    else SetColor(0, 4);
    cout << setw(13) << this -> getStrStatus();
    SetColor(0, 15);
    cout << "|  " << left << setw(5) << this -> statusCode;
    cout << "| " << this -> date << setw(3) << ' ' << "| " << endl;
    cout << setfill('-') << setw(173) << '-' << setfill(' ') << endl;
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

bool Withdraw::makeTransaction(const string &pin){
    if (((this -> srcAccount)).getPin() == pin) {
        if (this -> cash >= 50000) {
            if (((this -> srcAccount)).getBalance() >= this -> cash + this -> calFee()){
                this -> fee = calFee();
                cout << setw(54) << "THONG TIN GD" << endl;
                cout << setfill('-') << setw(96) << '-' << setfill(' ') << endl;
                cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(15) << "| SrcAccount" << left << setw(15) << "| DestAccount";
                cout << left << setw(20) << "| Ammount (VND)" << left << setw(15) << "| Fee (VND)" << "|" << endl;
                cout << setfill('-') << setw(96) << '-' << setfill(' ') << endl;
                cout << "| " << left << setw(13) << this -> ID;
                cout << "| " << left << setw(13) << this -> getType();
                cout << "| " << left << setw(13) << this -> srcAccount.getID(); 
                cout << "| " << left << setw(13) << "--------";
                cout << "| " << left << setw(18) << moneyFormat(this -> cash);
                cout << "| " << left << setw(13) << moneyFormat(this -> fee) << "|" << endl;
                cout << setfill('-') << setw(96) << '-' << setfill(' ') << endl;
                cout << "=> Ban co muon tiep tuc(Y/N): ";
                char choice;
                cin >> choice;
                while (choice != 'N' && choice != 'Y' && choice != 'n' && choice != 'y'){
                    cout << "=> Lua chon khong hop le, ban co muon tiep tuc thuc hien giao dich(Y/N): ";
                    cin >> choice;
                }
                if (choice == 'n' || choice == 'N') {
                    this -> statusCode = "000";
                    return false;
                }

                ((this -> srcAccount)).withdraw(this -> cash + this -> calFee());
                this -> status = true;
                this -> statusCode = "400";
                this -> date = Date::getCurrentDate();
                this -> balance = this -> srcAccount.getBalance();
                cout << "Successfully withdraw " << this -> cash << endl;
                return true;
            }
            else
                this -> statusCode = "100";
                cout << "Your balance doesn't enough to withdraw" << endl;
                return false;
        }else 
            this -> statusCode = "200";
            cout << "Require at least 50,000 VND to withdraw" << endl;
            return false;
    }else
        this -> statusCode = "300"; 
        cout << "Pin is not correct" << endl;
        return false;
    return false;
}

string Withdraw::getType(){
    return "Withdraw";
}

const Withdraw& Withdraw::operator=(const Withdraw &W){
    this -> ID = W.ID;
    this -> srcAccount = W.srcAccount;
    this -> cash = W.cash;
    this -> fee = W.fee;
    this -> balance = W.balance;
    this -> status = W.status;
    this -> statusCode = W.statusCode;
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
    if (W.srcAccount.isNull()) W.srcAccount.setID(srcAccountID); // Card đã bị xóa
    in >> W.cash;
    in >> W.fee;
    in >> W.balance;
    in >> W.status;
    in >> W.statusCode;
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
    out << W.balance << endl;
    out << W.status << endl;
    out << W.statusCode << endl;
    out << Withdraw(W).date.toString() << endl;
    return out;
}