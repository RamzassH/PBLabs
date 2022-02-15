#include "libs/data_structures/vector/test_vector/vector_test.h"
#include "libs/data_structures/vector/test_vector_void/test_vector_void.h"
#include "libs/data_structures/matrix/test_matrix/test_matrix.h"

void task1 () {
    matrix_t (m) = get_mem_matrix(3, 3);

    input_matrix(m);

    if (!(is_square_matrix(m))) {
        printf("\a");
        fprintf_s(stderr, "is not squared matrix");
    }

    position_t minElementIndex = get_min_value_pos(m);
    position_t maxElementIndex = get_max_value_pos(m);

    swap_rows((m), (minElementIndex).rowIndex, (maxElementIndex).rowIndex);

    output_matrix(m);
}

void task2() {
    matrix_t (m) = get_mem_matrix(5, 3);

    input_matrix(m);

    sort_rows_by_min_element(m);

    output_matrix(m);
}

void task3() {
    matrix_t (m) = get_mem_matrix(3, 6);

    input_matrix(m);

    sort_cols_by_min_element(m);

    output_matrix(m);
}

void task4 () {
    matrix_t (m) = get_mem_matrix(3, 3);

    input_matrix(m);

    if (!(is_square_matrix(m)) ||
        !(is_symmetric_matrix(m))) {
        printf("\a");
        fprintf_s(stderr, "is not squared/symmetric matrix");
    }

    get_square_of_matrix_if_symmetric(&m);

    output_matrix(m);

    free_mem_matrix(m);
}

void task5() {
    matrix_t (m) = get_mem_matrix(3, 3);

    input_matrix(m);

    if (!(is_square_matrix(m))) {
        printf("\a");
        fprintf_s(stderr, "is not squared matrix");
    }

    transpose_if_matrix_has_Not_equal_of_rows(m);
}

int main() {
//    vector_test();
//    test_vector_void();
//    test_matrix();

//    task1();
//    task2();
//    task3();
//    task4();

    return 0;
}