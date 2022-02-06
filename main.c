#include <stdio.h>
#include "libs/data_structures/vector/test_vector/vector_test.h"
#include "libs/data_structures/vector/test_vector_void/test_vector_void.h"

int main() {
    vector_test();
    test_vector_void();
    vectorVoid_t v = {(int[]) {}, 0, 0, sizeof(int)};
    return 0;
}