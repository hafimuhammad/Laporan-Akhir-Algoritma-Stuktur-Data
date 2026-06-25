#include "double_linked_list.h"
#include <iostream>
#include <stdexcept>
using namespace std;
 
void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}
 
bool DoubleLinkedList::is_empty() {
    return size == 0;
}
 
 
void DoubleLinkedList::add_front(char val) {
    Node* newNode = new Node();
    newNode->data = val;
    if (is_empty()) {
        newNode->next = newNode; 
        newNode->prev = newNode;
        head = tail = newNode;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode; 
        head = newNode;
    }
    size++;
}
 
void DoubleLinkedList::add_back(char val) {
    Node* newNode = new Node();
    newNode->data = val;
    if (is_empty()) {
        newNode->next = newNode; 
        newNode->prev = newNode;
        head = tail = newNode;
    } else {
        newNode->next = head;   
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;  
        tail = newNode;
    }
    size++;
}
 
void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) return;
    if (idx == 0) { add_front(val); return; }
    if (idx == size) { add_back(val); return; }
 
    Node* curr;
    if (idx < size / 2) {
        curr = head;
        for (int i = 0; i < idx; i++) curr = curr->next;
    } else {
        curr = tail;
        for (int i = size - 1; i > idx; i--) curr = curr->prev;
    }
 
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
    size++;
}
 
void DoubleLinkedList::delete_front() {
    if (is_empty()) return;
    Node* temp = head;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = tail; 
        tail->next = head; 
    }
    delete temp;
    size--;
}
 
void DoubleLinkedList::delete_back() {
    if (is_empty()) return;
    Node* temp = tail;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    delete temp;
    size--;
}
 
void DoubleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) return;
    if (idx == 0) { delete_front(); return; }
    if (idx == size - 1) { delete_back(); return; }
 
    Node* curr;
    if (idx < size / 2) {
        curr = head;
        for (int i = 0; i < idx; i++) curr = curr->next;
    } else {
        curr = tail;
        for (int i = size - 1; i > idx; i--) curr = curr->prev;
    }
 
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    size--;
}
 
void DoubleLinkedList::display() {
    if (is_empty()) return;
    Node* curr = head;
    for (int i = 0; i < size; i++) {
        cout << curr->data;
        if (i != size - 1) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}
 
char DoubleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) throw out_of_range("Index out of range");
    Node* curr;
    if (idx < size / 2) {
        curr = head;
        for (int i = 0; i < idx; i++) curr = curr->next;
    } else {
        curr = tail;
        for (int i = size - 1; i > idx; i--) curr = curr->prev;
    }
    return curr->data;
}
 
void DoubleLinkedList::set(char val, int idx) {
    if (idx < 0 || idx >= size) throw out_of_range("Index out of range");
    Node* curr;
    if (idx < size / 2) {
        curr = head;
        for (int i = 0; i < idx; i++) curr = curr->next;
    } else {
        curr = tail;
        for (int i = size - 1; i > idx; i--) curr = curr->prev;
    }
    curr->data = val;
}
 
void DoubleLinkedList::clear() {
    if (is_empty()) return;
    Node* curr = head;
    for (int i = 0; i < size; i++) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = tail = nullptr;
    size = 0;
}