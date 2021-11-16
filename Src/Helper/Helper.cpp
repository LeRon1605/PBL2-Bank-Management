#include "../Card/Card.h"
#include <iomanip>

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
    cout <<"|   1.Tao The Ngan Hang                                             |" << endl;
    cout <<"|   2.Xoa The Ngan Hang                                             |" << endl;
    cout <<"|   3.Xoa The Ngan Hang (ID)                                        |" << endl;
    cout <<"|   4.Cap Nhat Thong Tin The Ngan Hang                              |" << endl;
    cout <<"|   5.Doi Ma Pin Cua The Ngan Hang                                  |" << endl;
    cout <<"|   6.Hien Thi Thong Tin The Ngan Hang                              |" << endl;
    cout <<"|   7.Hien Thi Thong Tin Chu The                                    |" << endl;
    cout <<"|   8.Hien Thi Cac ID Giao Dich Cua The Ngan Hang                   |" << endl;
    cout <<"|   9.Tim Kiem The Ngan Hang                                        |" << endl;
    cout <<"|   10.Hien Thi Danh Sach The Ngan Hang                             |" << endl;
    cout <<"|   11.Hien Thi Danh Sach The Ngan Hang Cua Khach Hang              |" << endl;
    cout <<"|   12.Xoa Tat Ca The Ngan Hang Cua Khach Hang                      |" << endl;
    cout <<"|   13.Thong Ke The Ngan Hang Duoc Tao Theo Ngay                    |" << endl;
    cout <<"|   14.Exit                                                         |" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"---------------------------------------------------------------------" << endl;
}
void transactionManagerMenu(){
    cout <<"---------------------------------------------------------------------" << endl;
    cout <<"|                         Quan Li Khach Hang                        |" << endl;
    cout <<"|-------------------------------------------------------------------|" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"|   1.Thuc Hien Giao Dich Rut                                       |" << endl;
    cout <<"|   2.Thuc Hien Giao Dich Nap                                       |" << endl;
    cout <<"|   3.Thuc Hien Giao Dich Chuyen Khoan                              |" << endl;
    cout <<"|   4.Hien Thi Tat Ca Giao Dich Rut                                 |" << endl;
    cout <<"|   5.Hien Thi Tat Ca Giao Dich Nap                                 |" << endl;
    cout <<"|   6.Hien Thi Tat Ca Giao Dich Chuyen Khoan                        |" << endl;
    cout <<"|   7.Hien Thi Thong Tin Giao Dich                                  |" << endl;
    cout <<"|   8.Hien Thi Danh Sach Giao Dich                                  |" << endl;
    cout <<"|   9.Tim Kiem Giao Dich                                            |" << endl;
    cout <<"|   10.Hien Thi Tat Ca Giao Dich Cua Khach Hang                     |" << endl;
    cout <<"|   11.Hien Thi Tat Ca Giao Dich Cua The Ngan Hang                  |" << endl;
    cout <<"|   12.Thong Ke Giao Dich Theo Ngay                                 |" << endl;
    cout <<"|   13.Exit                                                         |" << endl;
    cout <<"|                                                                   |" << endl;
    cout <<"---------------------------------------------------------------------" << endl;
}

void print(const string &str, const int &length){
    int paddingLeft = (length - str.size())/2;
    int paddingRight = length - str.size() - paddingLeft;
    cout << setw(paddingLeft) << str << setw(paddingRight) << ' ';
}