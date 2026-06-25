#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return size == 0;
}

void SingleLinkedList::add_front(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    if (is_empty()) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    if (is_empty()) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) throw std::out_of_range("Index out of range");
    if (idx == 0) {
        add_front(val);
    } else if (idx == size) {
        add_back(val);
    } else {
        Node* newNode = new Node();
        newNode->data = val;
        Node* curr = head;
        for (int i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
}

void SingleLinkedList::delete_front() {
    if (is_empty()) throw std::out_of_range("List is empty");
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) throw std::out_of_range("List is empty");
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* curr = head;
        while (curr->next != tail) curr = curr->next;
        delete tail;
        tail = curr;
        tail->next = head;
    }
    size--;
}

void SingleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index out of range");
    if (idx == 0) delete_front();
    else if (idx == size - 1) delete_back();
    else {
        Node* curr = head;
        for (int i = 0; i < idx - 1; i++) curr = curr->next;
        Node* target = curr->next;
        curr->next = target->next;
        delete target;
        size--;
    }
}

void SingleLinkedList::display() {
    if (is_empty()) return;
    Node* curr = head;
    for (int i = 0; i < size; i++) {
        std::cout << curr->data << (i == size - 1 ? "" : " ");
        curr = curr->next;
    }
    std::cout << std::endl;
}

int SingleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index out of range");
    Node* curr = head;
    for (int i = 0; i < idx; i++) curr = curr->next;
    return curr->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index out of range");
    Node* curr = head;
    for (int i = 0; i < idx; i++) curr = curr->next;
    curr->data = val;
}

void SingleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}