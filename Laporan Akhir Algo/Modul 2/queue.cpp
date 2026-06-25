#include "queue.h"
#include <iostream>

using namespace std;

void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    if (isEmpty(q)) {
        return false;
    }

    int nextRearIdx = (q->rear - q->data + 1) % MAX;
    return (q->data + nextRearIdx) == q->front;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw "Queue penuh";
    }

    if (isEmpty(q)) {
        q->front = q->data;
        q->rear = q->data;
    } else {
        int nextRearIdx = (q->rear - q->data + 1) % MAX;
        q->rear = q->data + nextRearIdx;
    }

    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw "Queue kosong";
    }

    if (q->front == q->rear) {
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        int nextFrontIdx = (q->front - q->data + 1) % MAX;
        q->front = q->data + nextFrontIdx;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw "Queue kosong";
    }

    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw "Queue kosong";
    }

    return *(q->rear);
}

void hasilQueue(int n, int k, int inputData[]) {
    Queue q;

    for (int i = 0; i <= n - k; i++) {
        init(&q);

        for (int j = i; j < i + k; j++) {
            enqueue(&q, inputData[j]);
        }

        long long currentSum = 0;

        while (!isEmpty(&q)) {
            currentSum += front(&q);
            dequeue(&q);
        }

        cout << currentSum << (i == n - k ? "" : " ");
    }

    cout << endl;
}