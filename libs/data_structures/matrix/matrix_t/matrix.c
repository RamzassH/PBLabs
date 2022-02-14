#include <assert.h>
#include "matrix.h"

matrix_t get_mem_matrix(int nRows, int nCols) {
    int **values = (int **) malloc((sizeof(int *) * nRows));

    for (register size_t i = 0; i < nRows; ++i) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }

    return (matrix_t) {values, nRows, nCols};
}

matrix_t *get_mem_array_of_matrices(int nMatrices,
                            int nRows, int nCols) {
    matrix_t *(ms) = (matrix_t *) malloc(sizeof(matrix_t) * nMatrices);

    for (size_t i = 0; i < nMatrices; ++i) {
        (ms)[i] = get_mem_matrix(nRows, nCols);
    }

    return (ms);
}

void free_mem_matrix(matrix_t (m)) {
    for (size_t i = 0; i < (m).nRows; ++i) {
        free((m).values[i]);
    }

    free((m).values);
}

void free_mem_matrices(matrix_t *(ms), int nMatrices)
{
    for (size_t i = 0; i < nMatrices; ++i) {
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

bool is_two_matrices_equal(matrix_t (m1), matrix_t (m2)) {
    return ((m1).values == (m2).values) &&
            ((m1).nRows == (m2).nCols) &&
            ((m1).nCols == (m2).nCols);
}

bool is_e_matrix(matrix_t (m)) {
    if (!is_square_matrix(m)) {
        return false;
    }

    for (size_t i = 0; i < (m).nRows; ++i) {
        for (size_t j = 0; j < (m).nCols; ++j) {
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

        for (size_t i = 0; i < (m).nRows; ++i) {
            for (size_t j = 0; j < (m).nCols; ++j) {
                if ((m).values[i][j] != (m).values[j][i]) {
                    return false;
                }
            }
        }

        return true;
}

void input_matrix(matrix_t (m)) {
    for (size_t i = 0; i < (m).nRows; ++i) {
        for (size_t j = 0; j < (m).nCols; ++j) {
            scanf("%d", &(m).values[i][j]);
        }
    }
}

void input_matrices(matrix_t *(ms), int nMatrices) {
    for (size_t i = 0; i < nMatrices; ++i) {
        input_matrix(ms[i]);
    }
}

void output_matrix(matrix_t (m)) {
    for (size_t i = 0; i < (m).nRows; ++i) {
        printf("{");
        for (size_t j = 0; j < (m).nCols; ++j) {
            printf("%d ", (m).values[i][j]);
        }
        printf("\b}\n");
    }
    printf("\n");
}

void output_matrices(matrix_t *(ms), int nMatrices) {
    for (size_t i = 0; i < nMatrices; ++i) {
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

    for (size_t i = 0; i < (m).nRows; ++i) {
        swap(&(m).values[i][j1], &(m).values[i][j2]);
    }
}

void transpose_square_matrix(matrix_t m) {
    if (!is_square_matrix(m)) {
        printf("\a");
        fprintf(stderr, "matrix is not squared");

        exit(604);
    }

    for (size_t i = 0; i < (m).nRows; ++i) {
        for (size_t j = 1; j < (m).nCols; ++j) {
            swap(&(m).values[i][j], &(m).values[j][i]);
        }
    }
}

