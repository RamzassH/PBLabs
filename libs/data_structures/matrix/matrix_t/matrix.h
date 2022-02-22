#ifndef INC__MATRIX_H
#define INC__MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#include "Z:/course_/libs/algorithms/array/array.h"

typedef struct {
    int **values;   //элементы матрицы
    int nRows;      //количество рядов
    int nCols;      //количество столбцов
}matrix_t;

typedef struct {
    double **values;   //элементы матрицы
    int nRows;      //количество рядов
    int nCols;      //количество столбцов
}matrix_f_t;

typedef struct {
    int rowIndex;
    int colIndex;
}position_t;

/*
 * Размещает в динамической памяти матрицу размером
 * nRows на nCols.
 * Возвращает матрицу.
 */
matrix_t get_mem_matrix(int nRows, int nCols);

matrix_f_t get_mem_matrix_f(const int nRows, const int nCols);

matrix_t *get_mem_array_of_matrices(int nMatrices, int nRows, int nCols);

matrix_f_t *get_mem_array_of_matrices_f(int nMatrices, int nRows, int nCols);

void free_mem_matrix(matrix_t m);

void free_mem_matrices(matrix_t *ms, int nMatrices);

void input_matrix(matrix_t m);

void input_matrix_f(matrix_f_t (m));

void input_matrices(matrix_t *ms, int nMatrices);

void input_matrices_f(matrix_f_t *(ms), int nMatrices);

void output_matrix(matrix_t m);

void output_matrix_f(matrix_f_t (m));

void output_matrices(matrix_t *ms, int nMatrices);

void swap_rows(matrix_t m, int i1, int i2);

void swap_columns(matrix_t m, int j1, int j2);

void insertion_sort_rows_matrix_by_row_criteria(matrix_t m,
                                               int (*criteria)(int *, int));

void insertion_sort_cols_matrix_by_col_criteria(matrix_t m,
                                               int (*criteria)(int *, int));

bool is_square_matrix(matrix_t m);

bool are_two_matrices_equal(matrix_t m1, matrix_t m2);

bool is_e_matrix(matrix_t m);

bool is_symmetric_matrix(matrix_t m);

bool is_mutually_inverse_matrices(matrix_t m1, matrix_t m2);

void transpose_square_matrix(matrix_t m);

position_t get_min_value_pos(matrix_t m);

position_t get_max_value_pos(matrix_t m);

matrix_t mul_matrices(matrix_t m1, matrix_t m2);

void get_square_of_matrix_if_symmetric(matrix_t *m);

void sort_rows_by_min_element(matrix_t (m));

void sort_cols_by_min_element(matrix_t (m));

void transpose_if_matrix_has_not_equal_of_rows(matrix_t m);

long long find_sum_of_maxes_of_pseudo_diagonal(matrix_t m);

int get_min_in_area(matrix_t m);

void sort_by_distance(matrix_t m);

int get_n_special_element(matrix_t m);

int count_eq_classes_by_rows_sum(matrix_t m);

void swap_penultimate_row(matrix_t m, int n);

int count_non_descending_rows_matrices(matrix_t *ms, int nMatrix);

void print_matrices_with_max_zero_rows(matrix_t *ms, int nMatrix);

void print_matrices_with_min_abs(matrix_f_t *ms, int nMatrix);

int get_n_special_element2(matrix_t (m));

long long get_special_scalar_product(matrix_t m);

double get_vector_index_with_max_angle(matrix_t m, int *b);

#endif
