#include "double_linked_list.h"
#include <iostream>
using namespace std;

int main() {
    int n, r;
    if (!(cin >> n >> r)) return 0;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < n; i++) {
        char karakter;
        cin >> karakter;
        list.add_back(karakter);
    }

    if (list.is_empty()) {
        cout << "EMPTY" << endl;
        return 0;
    }

    Node* p1 = list.head;
    Node* p2 = list.tail;

    for (int i = 0; i < r; i++) {
        long long x, y;
        if (!(cin >> x >> y)) break;
        if (list.is_empty()) break;

        x = ((x % list.size) + list.size) % list.size;
        for (int j = 0; j < x; j++) p1 = p1->next; 

        y = ((y % list.size) + list.size) % list.size;
        for (int j = 0; j < y; j++) p2 = p2->prev; 

        if (p1 == p2) {
            Node* next_p1 = p1->next; 
            Node* next_p2 = p2->prev;

            int idx = 0;
            Node* curr = list.head;
            for (int j = 0; j < list.size; j++) {
                if (curr == p1) break;
                curr = curr->next;
                idx++;
            }

            list.delete_idx(idx);

            if (list.is_empty()) {
                p1 = p2 = nullptr;
            } else {
                p1 = next_p1;
                p2 = next_p2;
                if (p1 == p2 && list.size > 1) p2 = p1->prev;
            }
        }
        else {
            bool adjacent = (p1->next == p2 || p2->next == p1);

            if (adjacent) {
                char temp = p1->data;
                p1->data = p2->data;
                p2->data = temp;
            }
        }
    }

    if (list.is_empty()) {
        cout << "EMPTY" << endl;
    } else {
        Node* curr = list.head;
        for (int i = 0; i < list.size; i++) {
            cout << curr->data;
            curr = curr->next;
        }
        cout << endl;
    }

    return 0;
}