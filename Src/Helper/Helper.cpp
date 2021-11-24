#include "../Card/Card.h"
#include <windows.h>
#include <iomanip>
#include <string>

bool compareHolderID(Card C, const string &holderID){
    return (C.getHolder().getID() == holderID);
}

void background(){
    cout <<"---------------------------------------------------------------------" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"|                           DO AN PBL2                              |" << endl;
    cout <<"|                    DE TAI: QUAN LI NGAN HANG                      |" << endl;
    cout <<"|   Sinh Vien Thuc Hien:                                            |" << endl;
    cout <<"|       1.Le Quoc Ron                                               |" << endl;
    cout <<"|       2.Huynh Tan Nang                                            |" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"---------------------------------------------------------------------" << endl;
}
void mainMenu(){
    cout <<"---------------------------------------------------------------------" << endl;
    cout <<"|                               MENU                                |" << endl;
    cout <<"|-------------------------------------------------------------------|" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"|   1. Quan Li Khach Hang                                           |" << endl;
    cout <<"|   2. Quan Li The Ngan Hang                                        |" << endl;
    cout <<"|   3. Quan Li Giao dich                                            |" << endl;
    cout <<"|   4. Exit                                                         |" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"---------------------------------------------------------------------" << endl;
} 
void clientManagerMenu(){
    cout <<"---------------------------------------------------------------------" << endl;
    cout <<"|                         Quan Li Khach Hang                        |" << endl;
    cout <<"|-------------------------------------------------------------------|" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"|   1. Them Khach Hang                                              |" << endl;
    cout <<"|   2. Xoa Khach Hang                                               |" << endl;
    cout <<"|   3. Cap Nhat Thong Tin Khach Hang                                |" << endl;
    cout <<"|   4. Tim Kiem Thong Tin Khach Hang                                |" << endl;
    cout <<"|   5. Hien Thi Danh Sach Khach Hang                                |" << endl;
    cout <<"|   6. Thong Ke Khach Hang Moi Theo Ngay                            |" << endl;
    cout <<"|   7. Exit                                                         |" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"---------------------------------------------------------------------" << endl;
}
void cardManagerMenu(){
    cout <<"---------------------------------------------------------------------" << endl;
    cout <<"|                        Quan Li The Ngan Hang                      |" << endl;
    cout <<"|-------------------------------------------------------------------|" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"|   1. Tao The Ngan Hang                                            |" << endl;
    cout <<"|   2. Xoa The Ngan Hang (ID)                                       |" << endl; 
    cout <<"|   3. Doi Ma Pin Cua The Ngan Hang                                 |" << endl;
    cout <<"|   4. Hien Thi Thong Tin The Ngan Hang                             |" << endl;
    cout <<"|   5. Hien Thi Danh Sach The Ngan Hang                             |" << endl;
    cout <<"|   6. Hien Thi Danh Sach The Ngan Hang Cua Khach Hang              |" << endl;  
    cout <<"|   7. Xoa Tat Ca The Ngan Hang Cua Khach Hang                      |" << endl;  
    cout <<"|   8. Thong Ke The Ngan Hang Duoc Tao Theo Ngay                    |" << endl;
    cout <<"|   9 .Exit                                                         |" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"---------------------------------------------------------------------" << endl;
}
void transactionManagerMenu(){
    cout <<"---------------------------------------------------------------------" << endl;
    cout <<"|                         Quan Li Giao Dich                         |" << endl;
    cout <<"|-------------------------------------------------------------------|" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"|   1. Thuc Hien Giao Dich Rut                                      |" << endl;
    cout <<"|   2. Thuc Hien Giao Dich Nap                                      |" << endl;
    cout <<"|   3. Thuc Hien Giao Dich Chuyen Khoan                             |" << endl;
    cout <<"|   4. Hien Thi Tat Ca Giao Dich Rut                                |" << endl;
    cout <<"|   5. Hien Thi Tat Ca Giao Dich Nap                                |" << endl;
    cout <<"|   6. Hien Thi Tat Ca Giao Dich Chuyen Khoan                       |" << endl;
    cout <<"|   7. Hien Thi Danh Sach Giao Dich                                 |" << endl;
    cout <<"|   8. Tim Kiem Giao Dich                                           |" << endl;
    cout <<"|   9. Hien Thi Tat Ca Giao Dich Cua Khach Hang                     |" << endl;
    cout <<"|   10.Hien Thi Tat Ca Giao Dich Cua The Ngan Hang                  |" << endl;
    cout <<"|   11.Thong Ke Giao Dich Theo Ngay                                 |" << endl;
    cout <<"|   12.Exit                                                         |" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"---------------------------------------------------------------------" << endl;
}

void print(const string &str, const int &length){
    int paddingLeft = (length - str.size())/2;
    int paddingRight = length - str.size() - paddingLeft;
    cout << setw(paddingLeft) << str << setw(paddingRight) << ' ';
}

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void transactionPanel(){
    cout << setfill('-') << setw(170) << '-' << setfill(' ') << endl;
    cout << left << setw(15) << "| ID" << left << setw(15) << "| Type" << left << setw(15) << "| SrcAccount" << left << setw(15) << "| DestAccount";
    cout << left << setw(20) << "| Ammount (VND)" << left << setw(15) << "| Fee (VND)" << left << setw(30) << "| Balance (VND)" << left << setw(15) << "| Status" << left << setw(29) << "| Date" << "| " << endl;
    cout << setfill('-') << setw(170) << '-' << setfill(' ') << endl;
}

void clientPanel(){
    cout << setfill('-') << setw(150) << '-' << endl << setfill(' ');
    cout << left << setw(15) << "| ID" << left << setw(20) << "| Name" << left << setw(10) << "| Gender";
    cout << left << setw(20) << "| Address" << left << setw(10) << "| Age" << left << setw(15) << "| Birth";
    cout << left << setw(30) << "| Created At" << left << setw(29) << "| Updated At" << "|" << endl;
    cout << setfill('-') << setw(150) << '-' <<  setfill(' ') << endl;
}

void cardPanel(){
    cout << setfill('-') << setw(155) << '-' << endl << setfill(' ');
    cout << left << setw(20) << "| ID" << left << setw(15) << "| ID Holder";
    cout << left << setw(10) << "| Pin" << left << setw(20) << "| Balance (VND)";
    cout << left << setw(30) << "| Created At" << left << setw(30) << "| Updated At" << left << setw(29) << "| Pin Updated At" << '|' << endl;
    cout << setfill('-') << setw(155) << '-' << endl << setfill(' ');
}

string moneyFormat(long money){
    string result;
    if (money == 0) return "0,000";
    while (money){
        if (money / 1000) {
            string temp = to_string(money % 1000);
            while (temp.size() != 3 && temp.size() <= 3) temp = "0" + temp;
            result = "," + temp + result;
        }
        else {
            result = to_string(money % 1000) + result;
        }
        money /= 1000;
    }
    if (result.size() <= 3) result = "0," + result;
    return result;
}