#include "sort_functions.h"

#define RFACTOR 1.24733

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/// глупая сортировка, является самым примитивным
/// представителем обменных сортировок
/// \param array - сортируемый массив
/// \param n - количество элементов массива
void silly_sort(int *array, size_t n) {
    int i = 0;
    size_t countComparison = 0;
    while (i < n - 1) {
        ++countComparison;
        if (array[i + 1] < array[i]) {
            swap(&array[i + 1], &array[i]);
            i = 0;
        } else {
            ++i;
        }
    }
    printf("\nsilly_sort comparison count = %lld\n", countComparison);
}

/// пузырьковая сортировка.
/// классическая обменная сортировка
/// \param array - сортируемый массив
/// \param n - размер массива
void bubble_sort(int *array, size_t n) {
    size_t countComparison = 0;
    for (register size_t i = 0; i < n - 1; ++i) {
        for (register size_t j = (n - 1); j > i; --j) {
            ++countComparison;
            if (array[j - 1] < array[j]) {
                swap(&array[j - 1], &array[j]);
            }
        }
    }
    printf("\nbubble_sort comparison count = %lld\n", countComparison);
}

/// шейкерная сортировка.
/// одна из модификаций сортировки пузырьком
/// \param array - сортируемый массив
/// \param n - размер массива
void shaker_sort(int *array, size_t n) {
    int leftPos = 0;
    int rightPos = n - 1;
    int flag = 1;
    size_t countComparison = 0;
    while ((rightPos - leftPos > 0) && (flag > 0)) {
        flag = 0;
        for (register size_t i = leftPos; i < rightPos; ++i) {
            ++countComparison;
            if (array[i] > array[i + 1]) {
                swap(&array[i + 1], &array[i]);
                flag = 1;
            }
        }
        --rightPos;

        for (register size_t i = rightPos; i > leftPos; --i) {
            ++countComparison;
            if (array[i - 1] > array[i]) {
                swap(&array[i - 1], &array[i]);
                flag = 1;
            }
        }
        ++leftPos;
    }

    printf("\nshaker_sort comparison count = %lld \n", countComparison);
}

/// сортировка расческой.
/// считается лучшей вариацией обменных сортировок
/// \param array - сортируемый массив
/// \param n - размер массива
void comb_sort(int *array, size_t n) {
    size_t gap = n;
    int isSwaped = 1;
    size_t j;
    size_t countComparison = 0;
    while (gap > 1 || isSwaped) {
        gap = (size_t) (gap / RFACTOR);

        ++countComparison;
        if (gap < 1) {
            gap = 1;
        }
        isSwaped = 0;

        for (register size_t i = 0; i < n - gap; ++i) {
            j = i + gap;
            ++countComparison;
            if(array[i] > array[j]) {
                swap(&array[i], &array[j]);
                isSwaped = 1;
            }
        }
    }

    printf("\ncomb_sort comparison count = %lld \n", countComparison);
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

/// сортировка выбором
/// \param array - сортируемый массив
/// \param n - размер массива
void selection_sort(int *array, size_t n) {
    size_t min;
    size_t countComparison = 0;
    for (register size_t i = 0; i < n; ++i) {
        min = i;

        for (register size_t j = i + 1; j < n; ++j) {
            ++countComparison;
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
    printf("\ncomb_sort comparison count = %lld \n", countComparison);
}

void dual_sort(int);

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void insertion_sort(int *array, size_t n) {
    int newElement, location;

    size_t countComparison = 0;

    for (register size_t i = 1; i < n; ++i) {
        ++countComparison;
        newElement = array[i];
        location = i - 1;

        while (location  >= 0 && array[location] > newElement) {
            ++countComparison;
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = newElement;
    }

    printf("\ninsertion_sort comparison count = %lld \n", countComparison);
}

