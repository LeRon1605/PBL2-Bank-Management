#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "../Datetime/Datetime.h"
template <class T>
class Manager{
    private:
    public:
        virtual string generateID() = 0; // Tạo ID
        virtual void show() = 0; // Hiển thị tất cả
        virtual void showByID(const string&) = 0; // Hiển thị bằng ID
        virtual T findByID(const string&) = 0; // Tìm bằng ID
        virtual int indexOf(const T) = 0; // 
        virtual int indexOf(const string&) = 0; 
        virtual bool add(const T) = 0; // Thêm vào danh sách
        virtual bool remove(const T) = 0; // Xóa
        virtual bool removeByID(const string&) = 0; // Xóa bằng ID
        virtual void listByDate(const Date&) = 0; // Liệt kê bằng ngày
        // virtual bool updateByID(const T, const string&) = 0;  // Cập nhật bằng ID
};
#endif