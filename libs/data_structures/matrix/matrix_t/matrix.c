#include <assert.h>
#include <math.h>
#include <stdlib.h>

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

    return max;
}

void insertion_sort_matrix(matrix_t *m, int *aRows, void (f)(matrix_t *, int, int), int rowOrCols){
    for (int i = 1; i < rowOrCols; ++i) {
        int temp = aRows[i];
        for (int j = i - 1; j >= 0; --j) {
            if (aRows[j] < temp) {
                break;
            }

            aRows[j + 1] = aRows[j];
            f(m, j + 1, j);
            aRows[j] = temp;
        }
    }
}

void insertion_sort_rows_matrix_by_row_criteria(matrix_t (m),
                                                int (*criteria)(int *, int)) {
    int aRows[(m).nRows];

    for (register size_t i = 0; i < (m).nRows; ++i) {
        aRows[i] = criteria((m).values[i], (m).nCols);
    }

    insertion_sort_matrix(&m, aRows, swap_rows, (m).nRows);
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

    insertion_sort_matrix(&m, aCols, swap_columns, (m).nCols);
}

double get_distance(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(a[i], 2);
    }

    return sqrt(sum);
}

void insertion_sort_rows_matrix_by_row_criteria_float(matrix_t m,
                                                      double(*criteria)(int *, int)) {
    int aRows[(m).nRows];

    for (register size_t i = 0; i < (m).nRows; ++i) {
        aRows[i] = criteria((m).values[i], (m).nCols);
    }

    insertion_sort_matrix(&m, aRows, swap_rows, (m).nRows);
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

    int mul_element = 0;
    for(size_t i = 0; i < (m1).nRows; ++i) {
        for (size_t j = 0; j < (m2).nCols; j++) {
            for (size_t k = 0; k < (mul_result).nRows; k++) {
                mul_element += (m1).values[i][k] * (m2).values[k][j];
            }
            (mul_result).values[i][j] = mul_element;
            mul_element = 0;
        }
    }

    return (mul_result);
}

void get_square_of_matrix_if_symmetric(matrix_t *(m)) {
    *m = mul_matrices(*m, *m);
}

long long get_sum(int *a, int n) {
    int sum = 0;
    for (register size_t i = 0; i < n; ++i) {
        sum += a[i];
    }

    return (sum);
}

bool is_unique(long long *a, int n) {
    for (register size_t i = 0; i < n; ++i) {
        for (register size_t j = n - 1; j > i; --j) {
            if (a[i] == a[j]) {
                return false;
            }
        }
    }

    return true;
}

void transpose_if_matrix_has_not_equal_of_rows(matrix_t m) {
    long long arraySum[(m).nRows];
    for (register size_t i = 0; i < (m).nRows; ++i) {
        arraySum[i] = get_sum((m).values[i], (m).nRows);
    }

    if (!(is_unique(arraySum, (m).nRows))) {
        printf("\a");
        fprintf(stderr, "elements are not unique");
        exit(504);
    }

    transpose_square_matrix(m);
}

bool is_mutually_inverse_matrices(matrix_t m1, matrix_t m2) {

    matrix_t mul_result = mul_matrices(m1, m2);

    return is_e_matrix(mul_result);
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long find_sum_of_maxes_of_pseudo_diagonal(matrix_t m) {
    int nMaxes = (m).nCols + (m).nRows - 2;
    int arrayOfMaxes[nMaxes];

    size_t iWrite = (m).nRows - 1;
    for (size_t i = 0; i < (m).nRows - 1; ++i) {
        arrayOfMaxes[i] = (m).values[iWrite][0];
        iWrite--;
    }

    iWrite = 1;
    for (size_t j = (m).nRows - 1; j < nMaxes; ++j) {
        arrayOfMaxes[j] = (m).values[0][iWrite];
        iWrite++;
    }

    size_t tmp = 1;
    size_t leftPos = tmp;
    for (size_t i = (m).nRows - 1; i > 0; --i) {
        size_t j = 1;
        while (j < (m).nCols) {
            if (i != j) {
                arrayOfMaxes[leftPos] = max(arrayOfMaxes[leftPos], (m).values[i][j]);
                leftPos++;
                j++;
            } else {
                j++;
            }
        }
        tmp++;
        leftPos = tmp;
    }

    return get_sum(arrayOfMaxes, nMaxes);
}

position_t get_max_in_matrix(matrix_t m) {
    position_t maxPos = {0, 0};
    for (size_t i = 0; i < (m).nRows; ++i) {
        for (size_t j = 0; j < (m).nCols; ++j) {
            if ((m).values[i][j] > (m).values[(maxPos).rowIndex][(maxPos).colIndex]) {
                (maxPos).rowIndex = i;
                (maxPos).colIndex = j;
            }
        }
    }

    return maxPos;
}

int min (int a, int b) {
    return a < b ? a : b;
}

int get_min_in_matrix_row(matrix_t m ,int rowIndex, int leftPos, int rightPos) {
    int minElement = (m).values[rowIndex][leftPos];
    for (size_t j = leftPos; j < rightPos; ++j) {
        if ((m).values[rowIndex][j] < minElement) {
            minElement = (m).values[rowIndex][j];
        }
    }

    return minElement;
}

int get_min_in_area(matrix_t m) {

    position_t maxPos = get_max_in_matrix(m);

    int minElement = (m).values[0][0];
    int rightPos = maxPos.colIndex;
    int leftPos = maxPos.colIndex;
    for (int i = (maxPos).rowIndex - 1; i >= 0; --i) {
        if(rightPos < (m).nCols - 1) {
            rightPos ++;
        }
        if(leftPos > 0) {
            leftPos --;
        }

        minElement = min(get_min_in_matrix_row((m), i, leftPos, rightPos), minElement);
    }

    return minElement;
}

void insertion_sort_matrix_by_row_criteria_f(matrix_t m) {
    insertion_sort_rows_matrix_by_row_criteria_float(m, get_distance);
}

void sort_by_distance(matrix_t m) {
    double arrayDistance[(m).nRows];

    for (size_t i = 0; i < (m).nRows; ++i) {
        arrayDistance[i] = get_distance((m).values[i], (m).nCols);
    }

    insertion_sort_matrix_by_row_criteria_f(m);
}

int get_n_special_element(matrix_t m) {

    int countUniqueElements = 0;
    for (size_t j = 0; j < (m).nCols; ++j) {
        int max = (m).values[0][j];
        int sum = 0;

        for (size_t i = 0; i < (m).nRows; ++i) {
            if((m).values[i][j] > max) {
                max = (m).values[i][j];
            }
            sum += (m).values[i][j];
        }
        if (max > sum - max) {
            countUniqueElements++;
        }
    }

    return countUniqueElements;
}

int compare_long_long(const void *a, const void *b) {
    long long arg1 = *(const long long *) a;
    long long arg2 = *(const long long *) b;

    if (arg1 < arg2) {
        return -1;
    }

    if (arg1 > arg2) {
        return 1;
    }

    return 0;
}

int count_n_unique(long long *a, int n)
{
    int uniqueElements = 0;
    for(int i = 0; i < n; i++) {
        bool isFound = false;

        for (int j = 0; j < n; j++) {
            if (i != j && a[i] == a[j]) {
                isFound = true;
                break;
            }
        }

        if (!isFound) {
            uniqueElements++;
        }
    }

    return uniqueElements;
}

int count_eq_classes_by_rows_sum(matrix_t m)
{
    long long aSumRows[(m).nRows];

    for (size_t i = 0; i < (m).nRows; ++i) {
        aSumRows[i] = get_sum((m).values[i], (m).nCols);
    }

    qsort(aSumRows, (m).nRows, sizeof(long long), compare_long_long);

    int countDifferences = 0;

    for (size_t i = 1; i < (m).nRows; ++i) {
        if (aSumRows[i] != aSumRows[i - 1]) {
            if (countDifferences == 0) {
                countDifferences++;
            }

            countDifferences++;
        }
    }

    int countUnique = count_n_unique(aSumRows, (m).nRows);

    return countDifferences - countUnique;
}

position_t get_left_min(matrix_t m) {
    return get_min_value_pos(m);
}

void swap_penultimate_row(matrix_t m, int n) {

    if (!(is_square_matrix(m))) {
        fprintf(stderr, "is not square matrix");
        exit(604);
    }

    position_t minColPos = get_left_min(m);

        for (int i = n - 1; i >= 0; --i) {
            (m).values[n - 2][i] = (m).values[i][(minColPos).colIndex];
            output_matrix(m);
            printf("\n");
        }
}