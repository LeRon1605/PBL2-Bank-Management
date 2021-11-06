#ifndef NODE_H
#define NODE_H
template <class T> 
class Node{
    private:
        T data; // Node
        Node *prev; // Node trước
        Node *next; // Node sau
    public:
        Node(const T); // Khởi tạo node
        ~Node();

        bool hasNext(); // Kiểm tra xem node hiện tại có node next hay không
        bool hasPrev(); // Kiểm tra xem node hiện tại có node prev hay không
        Node* getNext(); // Lấy ra node next
        Node* getPrev(); // Lấy ra node prev
        T getData(); // Lấy ra data
        void setNextNode(Node*); // Set node next
        void setPrevNode(Node*); // Set node prev
        void setData(const T);  // Set Data
};
#endif