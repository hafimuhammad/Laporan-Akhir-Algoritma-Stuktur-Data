    #ifndef STACK_H
    #define STACK_H

    #define MAX 100
    #include <string>

    struct Stack {
    int data[MAX];
    int* top;
    };

    void init(Stack* s);
    bool isEmpty(const Stack* s);
    bool isFull(const Stack* s);
    void push(Stack* s, int value);
    int pop(Stack* s);
    int peek(const Stack* s);
    int HasilOperasi(Stack* s, int n, std::string input[]);

    #endif