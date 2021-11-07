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
        int indexOf(const string&); // ID
        // int lastIndexOf(const T); // Index cuối cùng của T
        // int lastIndexOf(const string&); // ID
        bool insertAt(const T, const int&);
        bool add(const T); // Thêm vào đầu
        bool append(const T); // Thêm vào cuối
        // bool removeAt(const &int); // Xóa phần tử tại vị trí index
        // bool remove(const T); // Xóa phần tử T đầu tiên
        // bool remove(const string&); // Xóa phần tử bằng ID
        // bool removeAll(const T);
        // bool removeAll(const string&);
        // bool removeTail(); // Xóa phần tử cuối
        // bool removeHead(); // Xóa phần tử đầu
        int getLength(); //
        bool isEmpty(); // Kiểm tra xem danh sách có rỗng hay không
        // bool contains(const T); // Kiểm tra xem có tồn tại phần tử T hay không
        // bool contains(const string&);
        void show(); // Hiển thị
        // void sort(bool (*compare)(const T, const T));

        T& operator[](const int&);
        // ostream& operator<<(ostream&, const LinkedList&);
};

template <class T>
LinkedList<T>::LinkedList(){
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> length = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    Node<T> *temp = this -> head;
    while (this -> head != this -> tail){
        temp = this -> head;
        this -> head = this -> head -> getNext();
        delete temp;
    }
    delete this -> tail;
}

template <class T>
int LinkedList<T>::indexOf(const T element){
    Node<T> *ptr = this -> head;
    int index = 0;
    while (ptr != nullptr){
        if (ptr -> getData() == element) return index;
        index++;
        ptr = ptr -> getNext();
    }
    return -1;
}

template <class T>
int LinkedList<T>::indexOf(const string &ID){
    Node<T> *ptr = this -> head;
    int index = 0;
    while (ptr != nullptr){
        if (ptr -> getData().getID() == ID) return index;
        index++;
        ptr = ptr -> getNext();
    }
    return -1;
}

// template <class T>
// int LinkedList<T>::lastIndexOf(const T element){

// }

// template <class T>
// int LinkedList<T>::lastIndexOf(const string &ID){

// }

template <class T>
bool LinkedList<T>::add(const T element){
    Node<T> *newNode = new Node<T>(element);
    if (newNode == nullptr) return false;
    if (this -> head == nullptr && this -> tail == nullptr){
        this -> head = newNode;
        this -> tail = newNode;
    }else{
        newNode -> setNextNode(this -> head);
        this -> head -> setPrevNode(newNode);
        this -> head = newNode;
    }
    this -> length += 1;
    return true;
}

template <class T>
bool LinkedList<T>::insertAt(const T element, const int &index){
    int i = 0;
    if (index > this -> length) return false;
    if (index == 0) this -> add(element);
    else if (index == this -> length) this -> append(element);
    else{
        Node<T> *ptr = this -> head;
        Node<T> *newNode = new Node<T>(element);
        while (i != index){
            i++;
            ptr = ptr -> getNext();
        }
        newNode -> setPrevNode(ptr -> getPrev());
        newNode -> setNextNode(ptr);
        ptr -> getPrev() -> setNextNode(newNode);
        ptr -> setPrevNode(newNode);
    }
    this -> length += 1;
    return true;
}
template <class T>
bool LinkedList<T>::append(const T element){
    Node<T> *newNode = new Node<T>(element);
    if (newNode == nullptr) return false;
    if (this -> head == nullptr && this -> tail == nullptr){
        this -> head = newNode;
        this -> tail = newNode;
    }else{
        newNode -> setPrevNode(this -> tail);
        this -> tail -> setNextNode(newNode);
        this -> tail = newNode; 
    }
    this -> length += 1;
    return true;
}

// template <class T>
// bool LinkedList<T>::remove(const T element){

// }

// template <class T>
// bool LinkedList<T>::removeAt(const int &index){

// }

template <class T>
int LinkedList<T>::getLength(){
    return this -> length;
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (this -> head == nullptr);
}

// template <class T>
// bool LinkedList<T>::contains(const T element){

// }
template <class T>
void LinkedList<T>::show(){
    Node<T> *ptr = this -> head;
    while (ptr != nullptr){
        ptr -> getData().show();
        ptr = ptr -> getNext();
    }
}

// template <class T>
// void LinkedList<T>::sort(bool (*compare)(const T, const T)){
    
// }

template <class T>
T& LinkedList<T>::operator[](const int &index){
    static T empty;
    if (index < 0 || index >= this -> length) return empty;
    else{
        Node<T> *ptr = this -> head;
        int i = 0;
        while (i != index){
            i++;
            ptr = ptr -> getNext();
        }
        return ptr -> getRefData();
    }
}

// template <class T>
// ostream& operator<<(ostream &out, const LinkedList<T> &list){

// }
#endif
