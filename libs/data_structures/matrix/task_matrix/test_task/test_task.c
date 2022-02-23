#include <assert.h>
#include "../task/task.h"
#include "Z:/course_/libs/data_structures/matrix/matrix_t/matrix.h"

void test_task1_1() {
    matrix_t (m) = create_matrix_from_array(
            (int[]) {
                    1, 2, 0,
                    3, 6, 9,
                    7, 8, 5,
            },
            3, 3);

    task1(m);

    matrix_t (expectedM) = create_matrix_from_array(
            (int[]) {
                    3, 6, 9,
                    1, 2, 0,
                    7, 8, 5,
            },
            3, 3);

    assert(are_two_matrices_equal(m, expectedM));

    free_mem_matrix(m);
}

void test_task1_2() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    9, 8, 7,
                    6, 5, 4,
                    3, 2, 1,
            },
            3, 3);

    task1(m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    3, 2, 1,
                    6, 5, 4,
                    9, 8, 7,
            },
            3, 3);

    assert(are_two_matrices_equal(m, expectedM));

    free_mem_matrix(m);
}

void test_task2_1() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3,
            },
            3, 3);
    task2(m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1,
            },
            3, 3);

    assert(are_two_matrices_equal(m, expectedM));

    free_mem_matrix(m);
}

void test_task2_2() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    2, 4, 1,
                    1, 7, 7,
                    0, 2, 9,
            },
            3, 3);
    task2(m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    2, 4, 1,
                    1, 7, 7,
                    0, 2, 9,
            },
            3, 3);

    assert(are_two_matrices_equal(m, expectedM));

    free_mem_matrix(m);
}

void test_task3_1() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3,
            },
            3, 6);

    task3(m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4,
            },
            3, 6);

    assert(are_two_matrices_equal(m, expectedM));

    free_mem_matrix(m);
    
}

void test_task4_1() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    3, 5, 2,
                    2, 5, 1,
                    6, 1, 4,
            },
            3, 3);

    task4(&m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    3, 5, 2,
                    2, 5, 1,
                    6, 1, 4,
            },
            3, 3);
    assert(are_two_matrices_equal(m, expectedM));
    free_mem_matrix(m);
    
}

void test_task4_2() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    1, 2, 6,
                    2, 1, 1,
                    6, 1, 1,
            },
            3, 3);

    task4(&m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    41, 10, 14,
                    10, 6, 14,
                    14, 14, 38,
            },
            3, 3);
    assert(are_two_matrices_equal(m, expectedM));
    free_mem_matrix(m);
    
}

void test_task5_1() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    1, 2, 7,
                    2, 4, 1,
                    6, 1, 9,
            },
            3, 3);
    task5(m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    1, 2, 6,
                    2, 4, 1,
                    7, 1, 9,
            },
            3, 3);

    assert(are_two_matrices_equal(m, expectedM));

    free_mem_matrix(m);
    
}

void test_task5_2() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    1, 2, 7,
                    2, 4, 4,
                    6, 1, 9,
            },
            3, 3);
    task5(m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    1, 2, 7,
                    2, 4, 4,
                    6, 1, 9,
            },
            3, 3);
    assert(are_two_matrices_equal(m, expectedM));
    free_mem_matrix(m);
    
}

void test_task6_1() {
    matrix_t m1 = create_matrix_from_array(
            (int[]) {
                    2, 3,
                    3, 4,
            },
            2, 2);

    matrix_t m2 = create_matrix_from_array(
            (int[]) {
                    -4, 3,
                    3, -2,
            },
            2, 2);

    assert(is_mutually_inverse_matrices(m1, m2));

    free_mem_matrix(m1);
    free_mem_matrix(m2);
}

void test_task6_2() {
    matrix_t m1 = create_matrix_from_array(
            (int[]) {
                    1, 4,
                    3, 4,
            },
            2, 2);

    matrix_t m2 = create_matrix_from_array(
            (int[]) {
                    3, 3,
                    3, 3,
            },
            2, 2);
    assert(!is_mutually_inverse_matrices(m1, m2));

    free_mem_matrix(m1);
    free_mem_matrix(m2);
}

void test_task7() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    1, 2, 7, 3,
                    2, 4, 4, 5,
                    6, 9, 1, 2,
            },
            3, 4);
    long long sum = find_sum_of_maxes_of_pseudo_diagonal(m);
    int expectedSum = 29;
    assert((sum == expectedSum));
    free_mem_matrix(m);
}

void test_task8() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    1, 2, 7, 3,
                    2, 4, 4, 5,
                    6, 9, 1, 2,
            },
            3, 4);

    int min = get_min_in_area(m);
    int expectedMin = 1;
    assert(min == expectedMin);
    free_mem_matrix(m);
}

void test_task9() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    1, 2, 7,
                    2, 4, 4,
                    6, 1, 9,
            },
            3, 3);
    sort_by_distance(m);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    2, 4, 4,
                    1, 2, 7,
                    6, 1, 9,
            },
            3, 3);

    assert(are_two_matrices_equal(m, expectedM));
    free_mem_matrix(m);
    
}

void test_task10() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    5, 2,
                    4, 3,
                    3, 1,
            },
            3, 2);
    int res = count_eq_classes_by_rows_sum(m);
    int expectedRes = 1;
    assert(res == expectedRes);
    free_mem_matrix(m);
}

void test_task11() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    3, 5, 5,
                    2, 3, 6,
                    12, 2, 1,
            },
            3, 3);
    int res = get_n_special_element(m);
    int expectedRes = 1;
    assert(res == expectedRes);
    free_mem_matrix(m);
}

void test_task12_1() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1,
            },
            3, 3);
    swap_penultimate_row(m, (m).nRows);

    matrix_t expectedM = create_matrix_from_array(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1,
            },
            3, 3);

    assert(are_two_matrices_equal(m, expectedM));
    free_mem_matrix(m);
    
}

void test_task12_2() {
    matrix_t *ms = create_array_of_matrix_from_array(
            (int[]) {
                    7, 1,
                    1, 1,
                    1, 6,
                    2, 2,
                    5, 4,
                    1, 2,
                    1, 3,
                    7, 9,
            },
            4, 2, 2);
    int count = count_non_descending_rows_matrices(ms, 4);
    int expectedRes = 2;
    assert(count == expectedRes);
    free_mem_matrices(ms, 4);
}

void test_task13_1() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    0, 0, 0,
                    2, 3, 6,
                    12, 2, 1,
            },
            3, 3);
    int res = count_zero_rows(m);
    int expectedRes = 1;
    assert(res == expectedRes);
    free_mem_matrix(m);
}

void test_task13_2() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            3, 3);
    int res = count_zero_rows(m);
    int expectedRes = 3;
    assert(res == expectedRes);
    free_mem_matrix(m);
}

void test_task14() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    2, 3, 5, 5, 4,
                    6, 2, 3, 8, 12,
                    12, 12, 2, 1, 2,
            },
            3, 5);
    int count = get_n_special_element2(m);
    int expectedCount = 4;
    assert(count == expectedCount);
    free_mem_matrix(m);
}

void test_task15() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    4, 5, 6,
                    7, 8, 9,
                    1, 2, 3,
            },
            3, 3);

    int v[] = {
            2, 2, 2
    };

    int expectedIndex = 2;
    int index = get_vector_index_with_max_angle(m, v);

    assert(expectedIndex == index);

    free_mem_matrix(m);
}

void test_task17() {
    matrix_t m = create_matrix_from_array(
            (int[]) {
                    2, 3, 4,
                    5, 6, 9,
                    1, 3, 7,
            },
            3, 3);

    long long result = get_special_scalar_product(m);
    long long expectedResult = 49;

    assert(result == expectedResult);
    free_mem_matrix(m);
}

void tests() {
    test_task1_1();
    test_task1_2();
    test_task2_1();
    test_task2_2();
    test_task3_1();
    test_task4_1();
    test_task4_2();
    test_task5_1();
    test_task5_2();
    test_task6_1();
    test_task6_2();
    test_task7();
    test_task8();
    test_task9();
    test_task10();
    test_task11();
    test_task12_1();
    test_task12_2();
    test_task13_1();
    test_task13_2();
    test_task14();
    test_task15();
    test_task17();
}