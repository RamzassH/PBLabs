#include <assert.h>
#include "matrix.h"

matrix_t get_mem_matrix(const int nRows, const int nCols) {
    int **values = (int **) malloc((sizeof(int *) * nRows));

    for (register size_t i = 0; i < nRows; ++i) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }

    return (matrix_t) {values, nRows, nCols};
}

matrix_t *get_mem_array_of_matrices(int nMatrices,
                            int nRows, int nCols) {
    matrix_t *(ms) = (matrix_t *) malloc(sizeof(matrix_t) * nMatrices);

    for (register size_t i = 0; i < nMatrices; ++i) {
        (ms)[i] = get_mem_matrix(nRows, nCols);
    }

    return (ms);
}

matrix_t create_matrix_from_array(const int *a, int nRows, int nCols) {
    matrix_t m = get_mem_matrix(nRows, nCols);

    int k = 0;
    for (register size_t i = 0; i < nRows; ++i) {
        for (register size_t j = 0; j < nCols; ++j) {
            (m).values[i][j] = a[k++];
        }
    }

    return (m);
}

matrix_t *create_array_of_matrix_from_array(const int *values, int nRows, int nCols, int nMatrices) {
    matrix_t *(ms) = get_mem_array_of_matrices(nMatrices, nRows, nCols);

    int l = 0;
    for (register size_t k = 0; k < nMatrices; ++k) {
        for (register size_t i = 0; i < nRows; ++i) {
            for (register size_t j = 0; j < nCols; ++j) {
                (ms)[k].values[i][j] = values[l++];
            }
        }
    }

    return (ms);
}

void free_mem_matrix(matrix_t (m)) {
    for (register size_t i = 0; i < (m).nRows; ++i) {
        free((m).values[i]);
    }

    free((m).values);
}

void free_mem_matrices(matrix_t *(ms), int nMatrices)
{
    for (register size_t i = 0; i < nMatrices; ++i) {
        free_mem_matrix((ms)[i]);
    }

    free(ms);
}

bool is_element_in_row(matrix_t (m), int rowElementIndex) {
    return rowElementIndex < (m).nRows;
}

bool is_element_in_col(matrix_t (m), int colElementIndex) {
    return colElementIndex < (m).nCols;
}

bool is_square_matrix(matrix_t (m)) {
    return (m).nRows == m.nCols;
}

bool are_two_matrices_equal(matrix_t (m1), matrix_t (m2)) {
    if (((m1).nRows != (m2).nRows) ||
        ((m1).nCols != (m2).nCols)) {
        return false;
    }

    for (register size_t i = 0; i < (m1).nRows; ++i) {
        for (register size_t j = 0; j < (m1).nCols; ++j) {
            if ((m1).values[i][j] != (m2).values[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool is_e_matrix(matrix_t (m)) {
    if (!is_square_matrix(m)) {
        return false;
    }

    for (register size_t i = 0; i < (m).nRows; ++i) {
        for (register size_t j = 0; j < (m).nCols; ++j) {
            if (((i == j) && ((m).values[i][j] != 1)) ||
                ((i != j) && ((m).values[i][j] != 0))) {
                return false;
            }
        }
    }
    return true;
}

bool is_symmetric_matrix(matrix_t (m)) {
        if (!is_square_matrix(m)) {
            return false;
        }

        for (register size_t i = 0; i < (m).nRows; ++i) {
            for (register size_t j = 0; j < (m).nCols; ++j) {
                if ((m).values[i][j] != (m).values[j][i]) {
                    return false;
                }
            }
        }

        return true;
}

void input_matrix(matrix_t (m)) {
    for (register size_t i = 0; i < (m).nRows; ++i) {
        for (register size_t j = 0; j < (m).nCols; ++j) {
            scanf("%d", &(m).values[i][j]);
        }
    }
}

void input_matrices(matrix_t *(ms), int nMatrices) {
    for (register size_t i = 0; i < nMatrices; ++i) {
        input_matrix(ms[i]);
    }
}

void output_matrix(matrix_t (m)) {
    for (register size_t i = 0; i < (m).nRows; ++i) {
        printf("{");
        for (register size_t j = 0; j < (m).nCols; ++j) {
            printf("%d ", (m).values[i][j]);
        }
        printf("\b}\n");
    }
    printf("\n");
}

void output_matrices(matrix_t *(ms), int nMatrices) {
    for (register size_t i = 0; i < nMatrices; ++i) {
        output_matrix((ms)[i]);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_rows(matrix_t (m), int i1, int i2) {
    if ((!is_element_in_row(m, i1)) ||
        (!is_element_in_row(m, i2))) {
        printf("\a");
        fprintf(stderr, "rows is not exists");
    }

    swap((int*) &((m).values[i1]), (int *) &((m).values[i2]));
}

void swap_columns(matrix_t (m), int j1, int j2) {
    if ((!is_element_in_col(m, j1)) ||
        (!is_element_in_col(m, j2))) {
        printf("\a");
        fprintf(stderr, "cols is not exists");

        exit(604);
    }

    for (register size_t i = 0; i < (m).nRows; ++i) {
        swap(&(m).values[i][j1], &(m).values[i][j2]);
    }
}

void transpose_square_matrix(matrix_t (m)) {
    if (!is_square_matrix(m)) {
        printf("\a");
        fprintf(stderr, "matrix is not squared");

        exit(604);
    }

    for (register size_t i = 0; i < (m).nRows; ++i) {
        for (register size_t j = 1; j < (m).nCols; ++j) {
            swap(&(m).values[i][j], &(m).values[j][i]);
        }
    }
}

int get_max(const int *a, const int n) {
    int max = *a;
    for (register size_t i = 0; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
        printf("\n");
        printf("%d ", max);
        printf("\n");

    return max;
}

void insert_sort_rows_matrix(matrix_t (m), int *aRows) {
        for (int i = 1; i < (m).nRows; ++i) {
            int temp = aRows[i];
            for (int j = i - 1; j >= 0; --j) {
                if (aRows[j] < temp){
                    break;
                }

                aRows[j + 1] = aRows[j];
                swap_rows((m), j + 1, j);
                aRows[j] = temp;
            }
        }
}

void output_array(int *a, int n) {
    for (register size_t i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}

void insertion_sort_rows_matrix_by_row_criteria(matrix_t (m),
                                                int (*criteria)(int *, int)) {
    int aRows[(m).nRows];

    for (register size_t i = 0; i < (m).nRows; ++i) {
        aRows[i] = criteria((m).values[i], (m).nCols);
    }

    insert_sort_rows_matrix(m, aRows);
}

void sort_rows_by_min_element(matrix_t (m)) {
    insertion_sort_rows_matrix_by_row_criteria(m, get_max);
}

int get_min(const int *a, const int n) {
    int min = *a;
    for (register size_t i = 0; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

void insert_sort_cols_matrix(matrix_t (m), int *aCols) {
    for (int i = 1; i < (m).nCols; ++i) {
        int temp = aCols[i];
        for (int j = i - 1; j >= 0; --j) {
            if (aCols[j] < temp){
                break;
            }

            aCols[j + 1] = aCols[j];
            swap_columns((m), j + 1, j);
            aCols[j] = temp;
        }
    }
}

void insertion_sort_cols_matrix_by_col_criteria(matrix_t (m),
                                                int (*criteria)(int *, int)) {
    int aCols[(m).nCols];
    int aTemp[(m).nRows];

    for (register size_t j = 0; j < (m).nCols; ++j) {
        for (register size_t k = 0; k < (m).nRows; ++k) {
            aTemp[k] = (m).values[k][j];
        }

        aCols[j] = criteria(aTemp, (m).nRows);
    }

    insert_sort_cols_matrix(m, aCols);
}

void sort_cols_by_min_element(matrix_t (m)) {
    insertion_sort_cols_matrix_by_col_criteria(m, get_min);
}

bool is_min_element(const int m1, const int m2) {
    return m1 < m2;
}

bool is_max_element(const int m1, const int m2) {
    return m1 > m2;
}

position_t liner_search_matrix(matrix_t (m),
                                   bool (*criteria)(int, int)) {
    position_t criteriaPos = {0, 0};

    for(register int i = 0; i < (m).nRows; ++i) {
        for (register int j = 0; j < (m).nCols; ++j) {
            if (criteria(m.values[i][j], m.values[criteriaPos.rowIndex][criteriaPos.colIndex])) {
                criteriaPos.rowIndex = i;
                criteriaPos.colIndex = j;
            }
        }
    }

    return criteriaPos;
}

position_t liner_search_matrix_min(matrix_t (m)) {
    liner_search_matrix(m, is_min_element);
}

position_t liner_search_matrix_max(matrix_t (m)) {
    liner_search_matrix(m, is_max_element);
}

position_t get_min_value_pos(matrix_t (m)) {
    liner_search_matrix_min(m);
}

position_t get_max_value_pos(matrix_t (m)) {
    liner_search_matrix_max(m);
}

matrix_t mul_matrices(matrix_t m1, matrix_t m2) {
    matrix_t mul_result = get_mem_matrix((m1).nRows, (m2).nCols);

    for(size_t i = 0; i < (m1).nRows; ++i) {
        for (size_t j = 0; j < (m2).nCols; j++) {
            for (size_t k = 0; k < (mul_result).nRows; k++) {
                (mul_result).values[i][j] += (m1).values[i][k] * (m2).values[k][j];
            }
        }
    }

    return (mul_result);
}

void get_square_of_matrix_if_symmetric(matrix_t *(m)) {
    *m = mul_matrices(*m, *m);
}
