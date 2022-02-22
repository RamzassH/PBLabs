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

    transpose_if_matrix_has_not_equal_of_rows(m);

    output_matrix(m);
}

void task6() {
    matrix_t (a) = get_mem_matrix(3, 3);
    matrix_t (b) = get_mem_matrix(3, 3);

    input_matrix(a);
    input_matrix(b);

    printf("%d", is_mutually_inverse_matrices(a, b));
}

void task7() {
    matrix_t (m) = get_mem_matrix(5, 3);

    input_matrix(m);

    long long sumOfDiagonals = find_sum_of_maxes_of_pseudo_diagonal(m);

    printf("%lld", sumOfDiagonals);
}

void task8() {
    matrix_t (m) = get_mem_matrix(3, 4);

    input_matrix(m);

    int minInArea = get_min_in_area(m);

    printf("%d", minInArea);
}

void task9() {
}

void task10() {
    matrix_t (m) = get_mem_matrix(6,2);

    input_matrix(m);

    int countUniqueElements = count_eq_classes_by_rows_sum(m);

    printf("%d", countUniqueElements);
}

void task11() {
    matrix_t (m) = get_mem_matrix(3, 4);

    input_matrix(m);

    int nSpecials = get_n_special_element(m);

    printf("%d", nSpecials);
}

void task12() {
    matrix_t (m) = get_mem_matrix(3, 3);

    input_matrix(m);

    swap_penultimate_row(m, (m).nRows);

    output_matrix(m);
}

void task13() {
    int nMatrix;
    scanf("%d", &nMatrix);
    matrix_t *ms = get_mem_array_of_matrices(nMatrix, 2, 2);

    input_matrices(ms, nMatrix);

    int countSortedMatrices = count_non_descending_rows_matrices(ms, nMatrix);

    printf("%d", countSortedMatrices);

}

void task14() {
    int nMatrix;
    scanf("%d", &nMatrix);
    matrix_t *ms = get_mem_array_of_matrices(nMatrix, 3, 2);

    input_matrices(ms, nMatrix);

    print_matrices_with_max_zero_rows(ms, nMatrix);
}

void task15() {
    int nMatrix;
    scanf("%d", &nMatrix);
    matrix_f_t *ms = get_mem_array_of_matrices_f(nMatrix, 2, 2);

    input_matrices_f(ms, nMatrix);

    print_matrices_with_min_abs(ms, nMatrix);
}

void task16() {
    matrix_t (m) = get_mem_matrix(2, 4);

    input_matrix(m);

    printf("%d", get_n_special_element2(m));
}

void task17() {
    matrix_t (m) = get_mem_matrix(3, 3);

    input_matrix(m);

    get_vector_index_with_max_angle( m, &b);

}

void task18() {
    matrix_t (m) = get_mem_matrix(3, 3);

    input_matrix(m);

    printf("%lld ", get_special_scalar_product(m));
}

int main() {
//    vector_test();
//    test_vector_void();
//    test_matrix();

//    task1();
//    task2();
//    task3();
//    task4();
//    task5();
//    task6();
//    task7();
//    task8();
//    task9();
//    task10();
//    task11();
//    task12();
//    task13();
//    task14();
//    task15();
//    task16();
    task17();
//    task18();
    return 0;
}