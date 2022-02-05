#include <stdio.h>
#include "libs/data_structures/vector/test/vector_test.h"
#include "libs/data_structures/vector/vector_void/vector_void.h"

int main() {
    vector_test();
    vectorVoid_t v = {(int[]) {}, 0, 0, sizeof(int)};
    return 0;
}