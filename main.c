#include "libs/data_structures/vector/test_vector/vector_test.h"
#include "libs/data_structures/vector/test_vector_void/test_vector_void.h"
#include "libs/data_structures/matrix/test_matrix/test_matrix.h"

int main() {
    vector_test();
    test_vector_void();
    test_matrix();

    vectorVoid_t v = {(int[]) {}, 0, 0, sizeof(int)};

    return 0;
}