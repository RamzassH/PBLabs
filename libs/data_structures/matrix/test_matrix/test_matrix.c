#include "test_matrix.h"

void test_input_and_output_matrix() {
    matrix_t m = get_mem_matrix(4, 4);

    matrix_t *ms = get_mem_array_of_matrices(4, 2, 2);

    input_matrices(ms, 4);

    output_matrices(ms, 4);

    free_mem_matrices(ms, 4);
}

void test_swap_rows_matrix() {
    matrix_t m = get_mem_matrix(3, 3);

    input_matrix(m);
    output_matrix(m);
    printf("\n");
    swap_rows(m, 1, 2);
    output_matrix(m);
}

void test_swap_cols_matrix() {
    matrix_t m = get_mem_matrix(3, 3);

    input_matrix(m);
    output_matrix(m);
    printf("\n");
    swap_columns(m, 1, 2);
    output_matrix(m);
}

void test_is_e_matrix1() {
    matrix_t m = get_mem_matrix(3, 3);

    input_matrix(m);
    output_matrix(m);

    assert(is_e_matrix(m) == true);

    free_mem_matrix(m);
}

void test_is_e_matrix2() {
    matrix_t m = get_mem_matrix(2, 3);

    input_matrix(m);
    output_matrix(m);

    assert(is_e_matrix(m) == false);

    free_mem_matrix(m);
}

void test_is_e_matrix3() {
    matrix_t m = get_mem_matrix(3, 3);

    input_matrix(m);
    output_matrix(m);

    assert(is_e_matrix(m) == false);

    free_mem_matrix(m);
}

void test_is_e_matrix() {
    test_is_e_matrix1();
    test_is_e_matrix2();
    test_is_e_matrix3();
}

void test_is_symmetric_matrix1() {
    matrix_t m = get_mem_matrix(3, 3);

    input_matrix(m);
    output_matrix(m);

    assert(is_symmetric_matrix(m) == true);

    free_mem_matrix(m);
}

void test_is_symmetric_matrix2() {
    matrix_t m = get_mem_matrix(2, 3);

    input_matrix(m);
    output_matrix(m);

    assert(is_symmetric_matrix(m) == false);

    free_mem_matrix(m);
}

void test_is_symmetric_matrix3() {
    matrix_t m = get_mem_matrix(3, 3);

    input_matrix(m);
    output_matrix(m);

    assert(is_symmetric_matrix(m) == false);

    free_mem_matrix(m);
}

void test_is_symmetric_matrix() {
    test_is_symmetric_matrix1();
    test_is_symmetric_matrix2();
    test_is_symmetric_matrix3();
}

void test_transposes_matrix() {
    matrix_t m = get_mem_matrix(3, 3);

    input_matrix(m);
    transpose_square_matrix(m);

    output_matrix(m);

    free_mem_matrix(m);
}

void test_get_matrix_min_pos() {
    matrix_t m = get_mem_matrix(3, 3);

    input_matrix(m);
    output_matrix(m);

    position_t p = get_min_value_pos(m);

    assert(m.values[p.rowIndex][p.colIndex] == m.values[0][0]);

    free_mem_matrix(m);
}

void test_matrix() {
//    test_input_and_output_matrix();
//    test_swap_rows_matrix();
//    test_swap_cols_matrix();
//    test_is_e_matrix();
//    test_is_symmetric_matrix();
//    test_transposes_matrix();
    test_get_matrix_min_pos();
}