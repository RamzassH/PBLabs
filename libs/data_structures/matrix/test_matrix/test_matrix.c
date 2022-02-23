#include "test_matrix.h"

void test_get_mem_matrix() {
    int n_test_cases = 5;
    int test_cases[][2] = {
            {1, 1},
            {2, 2},
            {1, 3},
            {3, 3},
            {9, 10}
    };

    for (int i = 0; i < n_test_cases; i++) {
        int nRows = test_cases[i][0];
        int nCols = test_cases[i][1];

        matrix_t m =
                get_mem_matrix(nRows, nCols);

        assert((m).nRows == nRows);
        assert((m).nCols == nCols);

        // проверяем размер блока памяти, выделенного под массив указателей
        // на базовый тип
        assert(_msize((m).values) == sizeof(int*) * nRows);

        // проверяем размер массива элементов базового типа
        for (int row_index = 0; row_index < nRows; row_index++)
            assert(_msize((m).values[row_index]) == sizeof(int) * nCols);

        free_mem_matrix(m);
    }
}

void test_get_mem_matrix1() {
    int n_test_cases = 5;
    // matrix_tnRows and nCols
    int test_cases[][2] = {
            {1, 1},
            {2, 2},
            {1, 3},
            {3, 3},
            {9, 10}
    };

    for (int i = 0; i < n_test_cases; i++) {
        int nRows = test_cases[i][0];
        int nCols = test_cases[i][1];

        matrix_t m =
                get_mem_matrix(nRows, nCols);

        assert((m).nRows == nRows);
        assert((m).nCols == nCols);

        size_t mem_size =
                sizeof(int*) * nRows + sizeof(int) * nCols * nRows;

        assert(_msize((m).values) == mem_size);

        for (int j = 0; j < nRows; j++)
            assert((m).values[j] == (int*) ((m).values + nRows + j * nCols));

        free_mem_matrix(m);
    }
}


void test_matrix_free_mem() {
    int n_test_cases = 5;
    // matrix_tnRows and nCols
    int test_cases[][2] = {
            {1, 1},
            {2, 2},
            {1, 3},
            {3, 3},
            {9, 10}
    };

    for (int i = 0; i < n_test_cases; i++) {
        int nRows = test_cases[i][0];
        int nCols = test_cases[i][1];
        matrix_t m = get_mem_matrix(nRows, nCols);
        int** memory = (m).values;

        free_mem_matrix(m);

        assert((m).nCols == 0 && (m).nRows == 0);
        assert((m).values == NULL);

        assert(_msize(memory) == -1);
    }
}

void test_matrix_free_mem1() {
    int n_test_cases = 5;
    // matrix_tnRows and nCols
    int test_cases[][2] = {
            {1, 1},
            {2, 2},
            {1, 3},
            {3, 3},
            {9, 10}
    };

    for (int i = 0; i < n_test_cases; i++) {
        int nRows = test_cases[i][0];
        int nCols = test_cases[i][1];
        matrix_t m = get_mem_matrix(nRows, nCols);
        int** memory = (m).values;

        free_mem_matrix(m);

        assert((m).nCols == 0 && (m).nRows == 0);
        assert((m).values == NULL);
        assert(_msize(memory) == -1);
    }
}


void test_get_mem_array_of_matrices() {
    int n_test_cases = 5;
    
    int test_cases[][3] = {
            {1, 1,  5},
            {2, 2,  3},
            {1, 3,  10},
            {3, 3,  7},
            {9, 10, 8}
    };

    for (int i = 0; i < n_test_cases; i++) {
        int nRows = test_cases[i][0];
        int nCols = test_cases[i][1];
        int n_matrices = test_cases[i][2];

        size_t expected_size = sizeof(matrix_t) * n_matrices;

        matrix_t* ms = get_mem_array_of_matrices(n_matrices, nRows, nCols);
        assert(expected_size == _msize(ms));

        free_mem_matrices(ms, n_matrices);
    }
}

void test_get_mem_array_of_matrices1() {
    int n_test_cases = 5;
    int test_cases[][3] = {
            {1, 1,  5},
            {2, 2,  3},
            {1, 3,  10},
            {3, 3,  7},
            {9, 10, 8}
    };

    for (int i = 0; i < n_test_cases; i++) {
        int nRows = test_cases[i][0];
        int nCols = test_cases[i][1];
        int n_matrices = test_cases[i][2];

        size_t expected_size = sizeof(matrix_t) * n_matrices;

        matrix_t* ms = get_mem_array_of_matrices(n_matrices, nRows, nCols);
        assert(expected_size == _msize(ms));

        free_mem_matrices(ms, n_matrices);
    }
}


void test_free_mem_matrices() {
    int n_test_cases = 5;
    
    int test_cases[][3] = {
            {1, 1,  5},
            {2, 2,  3},
            {1, 3,  10},
            {3, 3,  7},
            {9, 10, 8}
    };

    for (int i = 0; i < n_test_cases; i++) {
        int nRows = test_cases[i][0];
        int nCols = test_cases[i][1];
        int n_matrices = test_cases[i][2];

        matrix_t* ms = get_mem_array_of_matrices(n_matrices, nRows, nCols);
        free_mem_matrices(ms, n_matrices);

        assert(_msize(ms) == -1);
    }
}

void test_free_mem_matrices2() {
    int n_test_cases = 5;
    
    int test_cases[][3] = {
            {1, 1,  5},
            {2, 2,  3},
            {1, 3,  10},
            {3, 3,  7},
            {9, 10, 8}
    };

    for (int i = 0; i < n_test_cases; i++) {
        int nRows = test_cases[i][0];
        int nCols = test_cases[i][1];
        int n_matrices = test_cases[i][2];

        matrix_t* ms = get_mem_array_of_matrices(n_matrices, nRows, nCols);
        free_mem_matrices(ms, n_matrices);

        assert(_msize(ms) == -1);
    }
}


void test_matrix_swap_rows() {
    int values[] = {1, 2, 3, 4, 5, 6,
                    7, 8, 9, 10, 11, 12};

    int n_test_cases = 3;

    matrix_t* test_cases =
            create_array_of_matrix_from_array(values, n_test_cases, 2, 2);

    int expected_values[] = {3, 4, 1, 2, 7, 8,
                             5, 6, 11, 12, 9, 10};

    matrix_t* expected_matrices =
            create_array_of_matrix_from_array(expected_values, n_test_cases, 2, 2);

    for (int i = 0; i < n_test_cases; i++) {
        swap_rows(test_cases[i], 0, 1);
        assert(are_two_matrices_equal(test_cases[i], expected_matrices[i]));
    }

    free_mem_matrices(test_cases, n_test_cases);
    free_mem_matrices(expected_matrices, n_test_cases);
}

void test_matrix_swap_columns() {
    int values[] = {1, 2, 3, 4, 5, 6,
                    7, 8, 9, 10, 11, 12};

    int n_test_cases = 3;
    matrix_t* test_cases =
            create_array_of_matrix_from_array(values, n_test_cases, 2, 2);

    int expected_values[] = {2, 1, 4, 3, 6, 5,
                             8, 7, 10, 9, 12, 11};

    matrix_t* expected_matrices =
            create_array_of_matrix_from_array(expected_values, n_test_cases, 2, 2);

    for (int i = 0; i < n_test_cases; i++) {
        swap_columns(test_cases[i], 0, 1);
        assert(are_two_matrices_equal(test_cases[i], expected_matrices[i]));
    }

    free_mem_matrices(test_cases, n_test_cases);
    free_mem_matrices(expected_matrices, n_test_cases);
}


void test_is_two_matrices_equal() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};

    matrix_t m1 = create_matrix_from_array(values, 3, 3);
    matrix_t m2 = create_matrix_from_array(values, 3, 3);

    bool expected_result = true;
    bool result = are_two_matrices_equal(m1, m2);

    assert(expected_result == result);

    m2.values[0][0] = !m2.values[0][0];

    expected_result = false;
    result = are_two_matrices_equal(m1, m2);

    assert(expected_result == result);

    free_mem_matrix(m1);
    free_mem_matrix(m2);
}

void test_is_square_matrix() {
    int n_test_cases = 4;

    int sizes[][2] = {
            {1,  1},
            {2,  3},
            {10, 10},
            {2,  2}
    };

    bool expected_results[] = {
            true,
            false,
            true,
            true
    };

    for (int i = 0; i < n_test_cases; i++) {
        matrix_t m = get_mem_matrix(sizes[i][0], sizes[i][1]);
        bool expected_result = expected_results[i];

        bool result = is_square_matrix(m);
        assert(expected_result == result);
        free_mem_matrix(m);
    }
}

void test_matrix_get_min_value_pos() {

    int values[] = {
            1, 0, 0,
            0, 10, 0,
            0, -2, 1,
            0, 7, 0,
            1, 1, -3,
            10, 0, -3,
            0, 0, 1,
            -10, 1, 0,
            1, 1, 0
    };

    position_t expected_results[] = {
            {2, 1},
            {1, 2},
            {1, 0}
    };

    int n_test_cases = 3;

    matrix_t* test_cases = create_array_of_matrix_from_array(values, n_test_cases, 3,
                                                        3);

    for (int i = 0; i < n_test_cases; i++) {
        position_t result = get_min_value_pos(test_cases[i]);
        position_t expected_result = expected_results[i];

        assert(result.rowIndex == expected_result.rowIndex &&
               result.colIndex == expected_result.colIndex);
    }

    free_mem_matrices(test_cases, n_test_cases);
}

void test_matrix_get_max_value_pos() {
    int values[] = {
            1, 0, 0,
            0, 10, 0,
            0, -2, 1,
            
            0, 7, 0,
            1, 1, -3,
            10, 0, -3,
            
            0, 0, 1,
            -10, 1, 0,
            1, 1, 0
    };

    position_t expected_results[] = {
            {1, 1},
            {2, 0},
            {0, 2}
    };

    int n_test_cases = 3;

    matrix_t* test_cases = create_array_of_matrix_from_array(values, n_test_cases, 3,
                                                        3);

    for (int i = 0; i < n_test_cases; i++) {
        position_t result = get_max_value_pos(test_cases[i]);
        position_t expected_result = expected_results[i];

        assert(result.rowIndex == expected_result.rowIndex &&
               result.colIndex == expected_result.colIndex);
    }

    free_mem_matrices(test_cases, n_test_cases);
}