#include "random_generation_functions.h"

void generate_random_sequence(int *array, size_t n) {
    srand(time(NULL));
    for (register size_t i = 0; i < n; i++) {
        array[i] = rand() % 100;
    };
}

void generate_ordered_sequence(int *array, size_t n) {
    for (register size_t i = 0; i < n; ++i) {
        array[i] = i;
    }
}

void generate_ordered_backward(int *array, size_t n) {
    for (register int i = 0; i < n; ++i) {
        array[i] = n - i;
    }
}