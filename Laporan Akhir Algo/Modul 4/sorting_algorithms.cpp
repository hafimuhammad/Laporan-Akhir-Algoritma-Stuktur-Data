#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            m.comparisons++;
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            m.comparisons++;
            if (data[j] < data[min]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(data[i], data[min ]);
            m.swaps++;
        }
    }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0) {
            m.comparisons++;
            if (data[j] > key) {
                data[j + 1] = data[j];
                m.shifts++;
                j--;
            } else {
                break;
            }
        }
        data[j + 1] = key;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();
    auto recursive_mergesort = [&](auto self, int left, int right) -> void {
        m.recursive_calls++;
        if (left < right) {
            int mid = left + (right - left) / 2;

            self(self, left, mid);
            self(self, mid + 1, right);

            int n1 = mid - left + 1;
            int n2 = right - mid;

            std::vector<int> L(n1);
            std::vector<int> R(n2);
            for (int i = 0; i < n1; i++) L[i] = data[left + i];
            for (int j = 0; j < n2; j++) R[j] = data[mid + 1 + j];

            int i = 0; 
            int j = 0; 
            int k = left; 

            while (i < n1 && j < n2) {
                m.comparisons++; 
                if (L[i] <= R[j]) {
                    data[k] = L[i];
                    i++;
                } else {
                    data[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) data[k++] = L[i++];
            while (j < n2) data[k++] = R[j++];
        }
    };

    if (!data.empty()) {
        recursive_mergesort(recursive_mergesort, 0, (int)data.size() - 1);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}




void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();
    auto recursive_qsort = [&](auto self, int low, int high) -> void {
        m.recursive_calls++;
        if (low < high) {
            int mid = low + (high - low) / 2;
            int pivot = data[mid];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                m.comparisons++;
                if (data[j] <= pivot) {
                    i++;
                    std::swap(data[i], data[j]);
                    m.swaps++;
                }
            }
            std::swap(data[mid], data[high]);
            std::swap(data[i + 1], data[high]);
            m.swaps++;
            int pi = i + 1;
            self(self, low, pi - 1);
            self(self, pi + 1, high);
        }
    };

    if (!data.empty()) {
        recursive_qsort(recursive_qsort, 0, (int)data.size() - 1);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int max_val = data[0];
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] > max_val) max_val = data[i];
    }

    int n = data.size();
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        std::vector<int> output(n);
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(data[i] / exp) % 10]++;
            m.array_accesses++; 
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
            m.array_accesses += 2; 
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = (data[i] / exp) % 10;
            output[count[digit] - 1] = data[i];
            m.array_accesses += 2; 
            count[digit]--;
            m.array_accesses++; 
        }

        for (int i = 0; i < n; i++) {
            data[i] = output[i];
            m.array_accesses++; 
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}