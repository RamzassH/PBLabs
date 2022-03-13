#include "sort_functions.h"

#define RFACTOR 1.24733

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void flip(int *a, int m, int n)
{
    for(register int i = m; i < --n; i++) {
        int tmp = a[i];
        a[i] = a[n];
        a[n] = tmp;
    }
}

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

void shaker_sort(int *array, size_t n) {
    int leftPos = 0;
    int rightPos = (int)n - 1;
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

void comb_sort(int *array, size_t n) {
    size_t gap = n;
    int isSwaped = 1;
    size_t j;
    size_t countComparison = 0;
    while (gap > 1 || isSwaped) {
        gap = (size_t) ((double)gap / RFACTOR);

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

void bingo_sort(int *array, size_t n) {
    int max = (int)n - 1;
    int nextValue = array[max];

    size_t countComparison = 0;

    // первый проход
    for (register int i = max - 1; i >= 0; --i) {
        ++countComparison;
        if (array[i] > nextValue) {
            nextValue = array[i];
        }
    }

    while (max && array[max] == nextValue) {
        ++countComparison;
        --max;
    }

    // последующие проходы
    while (max) {
        ++countComparison;
        int value = nextValue;
        nextValue = array[max];
        for (int i = max - 1; i >= 0; --i) {
            ++countComparison;
            if (array[i] == value) {
                swap(&array[i], &array[max]);
                --max;
            } else if (array[i] > nextValue) {
                ++countComparison;
                nextValue = array[i];
            }
        }
        while (max && array[max] == nextValue) {
            ++countComparison;
            --max;
        }
    }

    printf("\ncomb_sort comparison count = %lld \n", countComparison);
}

void pancake_sort(int *array, size_t n) {
    // если длинна массива меньше 2, то сортировка не потребуется
    if (n < 2) {
        return;
    }

    int i;
    int maxNumPos;
    for (i = (int)n; i > 1; --i) {
        maxNumPos = 0;
        for (register size_t j = 0; j < i; ++j) {
            if (array[j] > array[maxNumPos]) {
                maxNumPos = j;
            }
        }

        if (maxNumPos == i - 1) {
            continue;
        }

        if (maxNumPos >= 0) {
            flip(array, maxNumPos, i);
        }
    }
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void insertion_sort(int *array, size_t n) {
    int newElement, location;

    size_t countComparison = 0;

    for (register size_t i = 1; i < n; ++i) {
        ++countComparison;
        newElement = array[i];
        location = (int)i - 1;

        while (location  >= 0 && array[location] > newElement) {
            ++countComparison;
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = newElement;
    }

    printf("\ninsertion_sort comparison count = %lld \n", countComparison);
}

void insertion_binary_sort(int * array, size_t n) {
    size_t countComparison = 0;

    for (register int i = 0; i < n; ++i) {
        int key = array[i];
        int left = 0;
        int right = i;

        while (right - left > 0) {
            int mid = left + (right - left) / 2;

            ++countComparison;
            if (key < array[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        for (int j = i; j >= left + 1; --j) {
            ++countComparison;
            array[j] = array[j - 1];
        }
        array[left] = key;
    }

    printf("\ninsertion_binary_sort comparison count = %lld \n", countComparison);
}

void shell_sort(int *array, size_t n) {
    size_t countComparison = 0;
    int interval = (int)n / 2;
    while (interval > 0) {
        ++countComparison;
        for (register int i = interval; i < n; i++) {
            ++countComparison;
            int tmp = array[i];
            int j = i;
            while (j >= interval && array[j - interval] > tmp) {
                ++countComparison;
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = tmp;
        }
        interval /= 2;
    }
    printf("\nshell_sort comparison count = %lld \n", countComparison);
}

typedef struct {
    int a;              // данные
    struct tree *left;  // левый дочерний объект
    struct tree *right; // правый дочерний объект
}tree_t;

tree_t *add_to_tree(tree_t *root, int newValue, size_t *countComparison) {
    (*countComparison)++;
    if (root == NULL) { // если нет дочерних - создаем новый элемент
        root = (tree_t*) malloc(sizeof(tree_t));
        (root)->a = newValue;
        (root)->left = (root)->right = 0;
        return root;
    }

    (*countComparison)++;
    if ((root)->a < newValue) {             // добавляем новую ветвь
        (root)->right = add_to_tree((root)->right, newValue, countComparison);
    } else {
        (*countComparison)++;
        (root)->left = add_to_tree((root)->left, newValue, countComparison);
    }

    return root;
}

void tree_to_array(tree_t *root, int *a,  size_t *countComparison) {
    static int max2 = 0;
    (*countComparison)++;
    if (root == NULL) {
        return;
    }

    tree_to_array((root)->left, a, countComparison);
    a[max2++] = (root)->a;
    tree_to_array((root)->right, a, countComparison);
    free(root);
}

void tree_sort(int *array, size_t n) {
    tree_t *root;
    root = NULL;
    size_t countComparison = 0;
    for (int i = 0; i < n; ++i) {
        ++countComparison;
        root = add_to_tree(root, array[i], &countComparison);
    }

    tree_to_array(root, array, &countComparison);

    printf("\ntree_sort comparison count = %lld \n", countComparison);
}



