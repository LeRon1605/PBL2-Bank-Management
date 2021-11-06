#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class LinkedList{
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;
    public:
        LinkedList();
        ~LinkedList();

        int indexOf(const T); // Index đầu của T
        int lastIndexOf(const T); // Index cuối cùng của T
        bool add(const T); // Thêm vào đầu
        bool append(const T); // Thêm vào cuối
        bool removeAt(const &int); // Xóa phần tử tại vị trí index
        bool remove(const T); // Xóa phần tử T đầu tiên
        int getLength(); //
        bool isEmpty(); // Kiểm tra xem danh sách có rỗng hay không
        bool contains(const T); // Kiểm tra xem có tồn tại phần tử T hay không
        void show(); // Hiển thị
        void sort(bool (*compare)(const T, const T));

        T& operator[](const &int);
        ostream& operator<<(ostream&, const LinkedList&);
};
#endif