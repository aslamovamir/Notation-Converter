#ifndef DEQUE_H
#define DEQUE_H

//genralization of the type for the list
typedef char Elem;
class DNode {
    private:
        Elem elem;
        DNode* prev;
        DNode* next;
        friend class DLinkedList;
};

// Class of a doubly linked list
class DLinkedList{
public:
    DLinkedList(); // Constructor
    ~DLinkedList(); // Destructor
    bool isEmpty() const; // Check if the doubly linked list is empty
    const Elem& front() const; // Return the first element of the doubly linked list
    const Elem& back() const; // Return the last element of the doubly linked list
    void addFront(const Elem& element); // Add a new element at the front of the doubly linked list
    void addBack(const Elem& element); // Add a new element at the back of the doubly linked list
    void removeFront(); // Remove the first element from the front of the doubly linked list
    void removeBack(); // Remove the last element from the back of the doubly linked list
    private:
    DNode* header;
    DNode* trailer;
    protected:
        void add(DNode* v, const Elem& element); // Insert a new node before the reference node
        void remove (DNode* v); // Remove the reference node
};


// Class of a linked deque
class Deque{
public:
    int size() const; // Return number of elements in the deque
    bool isEmpty() const; // Check if the deque is empty or not
    const Elem& front(); // Return first element of the deque
    const Elem& back(); // Return last element of the deque
    void insertFront(const Elem& element); // Insert new first element
    void insertBack(const Elem& element); // Insert new last element
    void removeFront(); // Remove first element
    void removeBack(); // Remove last element
    private:
        DLinkedList DList; // Doubly linked list of elements
        int n = 0; // Count for the number of elements in the deque
        friend class NotationConverter;
};

#endif