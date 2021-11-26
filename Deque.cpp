#include "Deque.hpp"
// Constructor
DLinkedList::DLinkedList(){
header = new DNode;
trailer = new DNode;
header->next = trailer; //pointing the two sentinals to each other will make the list doubly linked
trailer->prev = header;
}


// Destructor
DLinkedList::~DLinkedList(){
    while(!isEmpty()) { //we will keep removing items from the front until the list is empty
        removeFront();
    }
    //we will remove the sentinels as well
    delete header;
    delete trailer;
}

//to check is the list is empty
//if the node next to the header is pointing to the trailer, the list must be empty
bool DLinkedList::isEmpty() const{
    return (header->next == trailer);
}

// to return the first element of the doubly linked list
const Elem& DLinkedList::front() const{
    return header->next->elem;
}

// to return the last element of the doubly linked list
const Elem& DLinkedList::back() const{
    return trailer->prev->elem;
}

// to add a new element at the front of the doubly linked list
void DLinkedList::addFront(const Elem& element){
    add(header->next, element);
}

// to addd a new element at the back of the doubly linked list
void DLinkedList::addBack(const Elem& element){
    add(trailer, element);
}

// to remove the first element from the front of the doubly linked list
void DLinkedList::removeFront(){
remove(header->next);
}

// to remove the last element from the back of the doubly linked list
void DLinkedList::removeBack(){
remove(trailer->prev);
}

// to insert a new node before the reference node
void DLinkedList::add(DNode* v, const Elem& element){
DNode* newNode = new DNode;
newNode->elem = element;
newNode->next = v;
newNode->prev = v->prev;
v->prev->next = v->prev = newNode;
}

// to remove a node
void DLinkedList::remove(DNode* v){
DNode* predecessor = v->prev;
DNode* successor = v->next;
predecessor->next = successor;
successor->prev = predecessor;
delete v;
}

// to check if the deque is empty
bool Deque::isEmpty() const{
return DList.isEmpty();
}

// to return the first element of the deque
const Elem& Deque::front(){
    return DList.front();
}

// to return the last element in the deque
const Elem& Deque::back(){
    return DList.back();
}

// to return the number of items in the deque
int Deque::size() const{
    return n;
}

// to insert a new element at the beginning of the deque
void Deque::insertFront(const Elem& element){
    DList.addFront(element);
    n++;
}

// to insert a new element at the end of the deque
void Deque::insertBack(const Elem& element){
    DList.addBack(element);
    n++;
}

// to remove the first element of the deque
void Deque::removeFront(){
    if(isEmpty()){ throw("Empty deque");}
    DList.removeFront();
    n--;
}

// Remove the last element of the deque
void Deque::removeBack(){
    if(isEmpty()){ throw("Empty deque");}
    DList.removeBack();
    n--;
}