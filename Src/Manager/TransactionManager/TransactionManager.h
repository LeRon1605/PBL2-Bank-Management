#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H
#include "../../Transaction/Transaction.h"
#include "../../CTDL/LinkedList.h"
#include "../Manager.h"
class TransactionManager: Manager<Transaction*> 
{
    private:
        LinkedList<Transaction*> list;
        static int totalTransactionCreated;
    public:
        TransactionManager();
        ~TransactionManager();

        string generateID(); // Tạo ID
        void show(); // Hiển thị tất cả
        void showByID(const string&); // Hiển thị bằng ID
        Transaction* findByID(const string&) = 0; // Tìm bằng ID
        int indexOf(const Transaction*); // 
        int indexOf(const string&); 
        bool add(const Transaction*); // Thêm vào danh sách
        bool remove(const Transaction*); // Xóa
        bool removeByID(const string&); // Xóa bằng ID
        void listByDate(const Date&); // Liệt kê bằng ngày
    
        bool makeWithdraw(const string&, const long&, const string&); // Thực hiện giao dịch rút
        bool makeTransfer(const string&, const string&, const long&, const string&); // Thực hiện giao dịch chuyển khoản
        bool makeDeposit(const string&, const long&, const string&); // Thực hiện giao dịch nạp

        void showWithdraw(); // Hiển thị các giao dịch rút
        void showTransfer(); // Hiển thị tất cả các giao dịch chuyển khoản
        void showDeposit(); // Hiển thị tất cả cáp giao dịch nạp

        void showAllClientTransaction(const string&);
        void showAllCardTransaction(const string&); 
};
#endif