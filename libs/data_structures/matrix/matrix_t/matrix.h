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
    int rowIndex;
    int colIndex;
}position_t;

/*
 * Размещает в динамической памяти матрицу размером
 * nRows на nCols.
 * Возвращает матрицу.
 */
matrix_t get_mem_matrix(int nRows, int nCols);

matrix_t *get_mem_array_of_matrices(int nMatrices, int nRows, int nCols);

void free_mem_matrix(matrix_t m);

void free_mem_matrices(matrix_t *ms, int nMatrices);

void input_matrix(matrix_t m);

void input_matrices(matrix_t *ms, int nMatrices);

void output_matrix(matrix_t m);

void output_matrices(matrix_t *ms, int nMatrices);

void swap_rows(matrix_t m, int i1, int i2);

void swap_columns(matrix_t m, int j1, int j2);

void insertion_sort_rows_matrix_by_row_criteria(matrix_t m,
                                               int (*criteria)(int *, int));

void insertion_sort_cols_matrix_by_col_criteria(matrix_t m,
                                               int (*criteria)(int *, int));

bool is_square_matrix(matrix_t m);

bool is_two_matrices_equal(matrix_t m1, matrix_t m2);

bool is_e_matrix(matrix_t m);

bool is_symmetric_matrix(matrix_t m);

void transpose_square_matrix(matrix_t m);

position_t get_min_value_pos(matrix_t m);

position_t get_max_value_pos(matrix_t m);




#endif
