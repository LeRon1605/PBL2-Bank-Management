#include "TransferTransaction.h"
#include <iomanip>
#include "../Repo/Repo.h"
#include "../Helper/Helper.h"
Transfer::Transfer(){

}

Transfer::Transfer(const string &ID, Card srcAccount, Card destAccount, const long &cash, const float &fee, const string &statusCode, const Date &date)
    : Transaction(ID, srcAccount, cash, fee, statusCode, date)
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
    cout << "| " << left << setw(13) << moneyFormat(this -> fee) << "| ";
    SetColor(0, 4);
    cout << left << setw(18);
    if (this -> statusCode == "400")
        cout << "-" + moneyFormat(this -> cash + this -> fee);
    else cout << "-0,000";
    SetColor(0, 15);
    cout << "| ";
    if (this -> statusCode == "400") SetColor(0, 2);
    else SetColor(0, 4);
    cout << setw(28) << this -> getStrStatus();
    SetColor(0, 15);
    cout << "| " << this -> date << setw(3) << ' ' << "| " << endl;
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
    this -> fee = this -> calFee();
    if (((this -> srcAccount)).getPin() == pin){
        if (this -> cash >= 50000){ 
            if (((this -> srcAccount)).getBalance() >= this -> cash + this -> fee){
                cout << setw(54) << "THONG TIN GD" << endl;
                cout << setfill('-') << setw(96) << '-' << setfill(' ') << endl;
                cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(15) << "| SrcAccount" << left << setw(15) << "| DestAccount";
                cout << left << setw(20) << "| Ammount (VND)" << left << setw(15) << "| Fee (VND)" << "|" << endl;
                cout << setfill('-') << setw(96) << '-' << setfill(' ') << endl;
                cout << "| " << left << setw(13) << this -> ID;
                cout << "| " << left << setw(13) << this -> getType();
                cout << "| " << left << setw(13) << this -> srcAccount.getID(); 
                cout << "| " << left << setw(13) << this -> destAccount.getID();
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
                
                ((this -> srcAccount)).withdraw(this -> cash + this -> fee);
                ((this -> destAccount)).deposit(this -> cash);
                this -> statusCode = "400";
                this -> date = Date::getCurrentDate();
                cout << "Successfully Transfer " << this -> cash << " to " << ((this -> destAccount)).getID() << endl;
                return true;
            }
            else
                this -> statusCode = "100";
                cout << "Your balance doesn't enough to Transfer" << endl;
                return false;
        }else{
            this -> statusCode = "200";
            cout << "Require at least 50,000 VND to transfer" << endl;
            return false;
        }
    }else 
        this -> statusCode = "300";
        cout << "Pin is not correct" << endl;
    return false;
}

string Transfer::getType(){
    return "Transfer";
}
bool Transfer::operator==(const Transfer &newTransfer){
    if(this -> ID == newTransfer.ID && this->srcAccount == newTransfer.srcAccount &&  this->destAccount == newTransfer.destAccount && this->cash == newTransfer.cash && this->fee == newTransfer.fee  && this->date == newTransfer.date){
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
    in >> T.statusCode;
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
    out << T.statusCode << endl;
    out << Transfer(T).date.toString() << endl;
    return out;
}