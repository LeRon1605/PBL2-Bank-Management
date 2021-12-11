#include "DepositTransaction.h"
#include <iomanip>
#include "../Repo/Repo.h"
#include "../Helper/Helper.h"
Deposit::Deposit(){

}

Deposit::Deposit(const string &ID, Card srcAccount, const long &cash, const float &fee, const string &statusCode, const Date &date)
    : Transaction(ID, srcAccount, cash, fee, statusCode, date)
{

}

Deposit::Deposit(const string &ID, Card srcAccount, const long &cash)
    : Transaction(ID, srcAccount, cash)
{

}

Deposit::Deposit(const Deposit &D): Transaction(D){
}

Deposit::~Deposit(){

}

void Deposit::show(){
    cout << "| " << left << setw(13) << this -> ID;
    cout << "| " << left << setw(13) << this -> getType();
    cout << "| " << left << setw(13) << this -> srcAccount.getID(); 
    cout << "| " << left << setw(13) << "--------";
    cout << "| " << left << setw(18) << moneyFormat(this -> cash);
    cout << "| " << left << setw(13) << moneyFormat(this -> fee) << "| ";
    SetColor(0, 2);
    cout << left << setw(18);
    if (this -> statusCode == "400")
        cout << "+" + moneyFormat(this -> cash - this -> fee);
    else  cout << "+0,000";
    SetColor(0, 15);
    cout << "| ";
    if (this -> statusCode == "400") SetColor(0, 2);
    else SetColor(0, 4);
    cout << setw(28) << this -> getStrStatus();
    SetColor(0, 15);
    cout << "| " << this -> date << setw(3) << ' ' << "| " << endl;
    cout << setfill('-') << setw(170) << '-' << setfill(' ') << endl;
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

bool Deposit::makeTransaction(const string &pin){
    this -> fee = this -> calFee();
    if (((this -> srcAccount)).getPin() == pin){
        if (this -> cash >= 50000){
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

            ((this -> srcAccount)).deposit(this -> cash - this -> fee);
            this -> statusCode = "400";
            this -> date = Date::getCurrentDate();
            cout << "Successfully Deposit " << this -> cash << endl;
            return true;
        }    
        else 
            this -> statusCode = "200";
            cout << "Require at least 50,000 VND to Deposit" << endl;
            return false;
    }else 
        this -> statusCode = "300";
        cout << "Pin is not correct" << endl;
    return false;
}

string Deposit::getType(){
    return "Deposit";
}

const Deposit& Deposit::operator=(const Deposit &D){
    this -> ID = D.ID;
    this -> srcAccount = D.srcAccount;
    this -> cash = D.cash;
    this -> fee = D.fee;
    this -> statusCode = D.statusCode;
    this -> date = D.date;
    return (*this);
}

bool Deposit::operator==(const Deposit &newDeposit){
    if(this->ID == newDeposit.ID && this->srcAccount == newDeposit.srcAccount && this->cash == newDeposit.cash && this->fee == newDeposit.fee  && this->date == newDeposit.date){
        return true;
    }
    return false;
}

ifstream& operator>>(ifstream &in, Deposit &D){
    string srcAccountID, date;
    getline(in >> ws, D.ID);
    getline(in >> ws, srcAccountID);
    D.srcAccount = Repository<Card>::getByID(srcAccountID, "Card.txt");
    if (D.srcAccount.isNull()) D.srcAccount.setID(srcAccountID); //  Card đã bị xóa
    in >> D.cash;
    in >> D.fee;
    in >> D.statusCode;
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
    out << D.statusCode << endl;
    out << Deposit(D).date.toString() << endl;
    return out;
}