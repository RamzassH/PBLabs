//#include "task.h"
//#include "Z:/course_/libs/algorithms/array/array.h"
//#include "Z:/course_/libs/data_structures/matrix/matrix_t/matrix.h"
//
////TASK 1 //////////////////////////////////////
//void task1 () {
//    matrix_t (m) = get_mem_matrix(3, 3);
//
//    input_matrix(m);
//
//    if (!(is_square_matrix(m))) {
//        printf("\a");
//        fprintf_s(stderr, "is not squared matrix");
//    }
//
//    position_t minElementIndex = get_min_value_pos(m);
//    position_t maxElementIndex = get_max_value_pos(m);
//
//    swap_rows((m), (minElementIndex).rowIndex, (maxElementIndex).rowIndex);
//
//    output_matrix(m);
//}
//
////TASK 2 //////////////////////////////////////
//void task2() {
//    matrix_t (m) = get_mem_matrix(5, 3);
//
//    input_matrix(m);
//
//    sort_rows_by_min_element(m);
//
//    output_matrix(m);
//}
//
////TASK 3 //////////////////////////////////////
//void task3() {
//    matrix_t (m) = get_mem_matrix(3, 6);
//
//    input_matrix(m);
//
//    sort_cols_by_min_element(m);
//
//    output_matrix(m);
//}
//
////TASK 4 //////////////////////////////////////
//void task4 () {
//    matrix_t (m) = get_mem_matrix(3, 3);
//
//    input_matrix(m);
//
//    if (!(is_square_matrix(m)) ||
//        !(is_symmetric_matrix(m))) {
//        printf("\a");
//        fprintf_s(stderr, "is not squared/symmetric matrix");
//    }
//
//    get_square_of_matrix_if_symmetric(&m);
//
//    output_matrix(m);
//
//    free_mem_matrix(m);
//}
//
////TASK 5 //////////////////////////////////////
//void task5() {
//    matrix_t (m) = get_mem_matrix(3, 3);
//
//    input_matrix(m);
//
//    if (!(is_square_matrix(m))) {
//        printf("\a");
//        fprintf_s(stderr, "is not squared matrix");
//    }
//
//    transpose_if_matrix_has_not_equal_of_rows(m);
//
//    output_matrix(m);
//}
//
////TASK 6 //////////////////////////////////////
//void task6() {
//    matrix_t (a) = get_mem_matrix(3, 3);
//    matrix_t (b) = get_mem_matrix(3, 3);
//
//    input_matrix(a);
//    input_matrix(b);
//
//    printf("%d", is_mutually_inverse_matrices(a, b));
//}
//
////TASK 7 //////////////////////////////////////
//void task7() {
//    matrix_t (m) = get_mem_matrix(5, 3);
//
//    input_matrix(m);
//
//    long long sumOfDiagonals = find_sum_of_maxes_of_pseudo_diagonal(m);
//
//    printf("%lld", sumOfDiagonals);
//}
//
////TASK 8 //////////////////////////////////////
//void task8() {
//    matrix_t (m) = get_mem_matrix(3, 4);
//
//    input_matrix(m);
//
//    int minInArea = get_min_in_area(m);
//
//    printf("%d", minInArea);
//}
//
////TASK 9 //////////////////////////////////////
//void task9() {
//    matrix_t (m) = get_mem_matrix(3, 3);
//
//    input_matrix(m);
//
//    sort_by_distance(m);
//
//    output_matrix(m);
//
//}
//
////TASK 10 //////////////////////////////////////
//void task10() {
//        matrix_t(m) = get_mem_matrix(6, 2);
//
//        input_matrix(m);
//
//        int countUniqueElements = count_eq_classes_by_rows_sum(m);
//
//        printf("%d", countUniqueElements);
//    }
//
////TASK 11 //////////////////////////////////////
//void task11() {
//    matrix_t (m) = get_mem_matrix(3, 4);
//
//    input_matrix(m);
//
//    int nSpecials = get_n_special_element(m);
//
//    printf("%d", nSpecials);
//}
//
////TASK 12 //////////////////////////////////////
//void task12() {
//    matrix_t (m) = get_mem_matrix(3, 3);
//
//    input_matrix(m);
//
//    swap_penultimate_row(m, (m).nRows);
//
//    output_matrix(m);
//}
//
////TASK 13 //////////////////////////////////////
//void task13() {
//    int nMatrix;
//    scanf("%d", &nMatrix);
//    matrix_t *ms = get_mem_array_of_matrices(nMatrix, 2, 2);
//
//    input_matrices(ms, nMatrix);
//
//    int countSortedMatrices = count_non_descending_rows_matrices(ms, nMatrix);
//
//    printf("%d", countSortedMatrices);
//}
//
////TASK 14 //////////////////////////////////////
//void task14() {
//    int nMatrix;
//    scanf("%d", &nMatrix);
//    matrix_t *ms = get_mem_array_of_matrices(nMatrix, 3, 2);
//
//    input_matrices(ms, nMatrix);
//
//    print_matrices_with_max_zero_rows(ms, nMatrix);
//}
//
////TASK 15 //////////////////////////////////////
//void task15() {
//    int nMatrix;
//    scanf("%d", &nMatrix);
//    matrix_f_t *ms = get_mem_array_of_matrices_f(nMatrix, 2, 2);
//
//    input_matrices_f(ms, nMatrix);
//
//    print_matrices_with_min_abs(ms, nMatrix);
//}
//
////TASK 16 //////////////////////////////////////
//void task16() {
//    matrix_t (m) = get_mem_matrix(2, 4);
//
//    input_matrix(m);
//
//    printf("%d", get_n_special_element2(m));
//}
//
////TASK 18 //////////////////////////////////////
//void task18() {Z:\course_\libs\data_structures\matrix\task_matrix\task\task.c:209:42: error: 'b' undeclared (first use in this function)
//
//    matrix_t (m) = get_mem_matrix(3, 3);
//
//    input_matrix(m);
//
//    printf("%lld ", get_special_scalar_product(m));
//}
//
//void task() {
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
//    task17();
//    task18();
//}