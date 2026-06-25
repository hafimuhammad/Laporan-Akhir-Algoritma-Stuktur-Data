#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

void init(Stack* s) {
    s->top = nullptr;
}

bool isEmpty(const Stack* s) {
    return s->top == nullptr;
}

bool isFull(const Stack* s) {
    return s->top == &(s->data[MAX - 1]);
}

void push(Stack* s, int value) {
    if (isFull(s))
        throw "Stack penuh";

    if (isEmpty(s)) {
        s->top = s->data;
    } else {
        s->top++;
    }

    *s->top = value;
}

int pop(Stack* s) {
    if (isEmpty(s))
        throw "Stack kosong";

    int value = *s->top;

    if (s->top == s->data) {
        s->top = nullptr;
    } else {
        s->top--;
    }

    return value;
}

int peek(const Stack* s) {
    if (isEmpty(s))
        throw "Stack kosong";

    return *s->top;
}

int HasilOperasi(Stack* s, int n, string input[]) {
    for (int i = 0; i < n; i++) {
        string val = input[i];

        if (val == "+" || val == "-" || val == "*" || val == "/") {
            int bil2 = pop(s);
            int bil1 = pop(s);
            int hasil;

            if (val == "+") {
                hasil = bil1 + bil2;
            } else if (val == "-") {
                hasil = bil1 - bil2;
            } else if (val == "*") {
                hasil = bil1 * bil2;
            } else if (val == "/") {
                if (bil2 == 0) {
                    hasil = 0;
                } else {
                    hasil = bil1 / bil2;
                }
            }

            push(s, hasil);
        } else {
            int bil = stoi(val);

            if (bil < -1000 || bil > 1000) {
                throw "Bilangan diluar jangkauan";
            }

            push(s, bil);
        }
    }

    return isEmpty(s) ? 0 : pop(s);
}