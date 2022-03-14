#include "sort_functions.h"

#define RFACTOR 1.24733

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void flip(int *a, int m, int n) {
    for (register int i = m; i < --n; i++) {
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
            if (array[j - 1] > array[j]) {
                swap(&array[j - 1], &array[j]);
            }
        }
    }
    printf("\nbubble_sort comparison count = %lld\n", countComparison);
}

void shaker_sort(int *array, size_t n) {
    int leftPos = 0;
    int rightPos = (int) n - 1;
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
        gap = (size_t) ((double) gap / RFACTOR);

        ++countComparison;
        if (gap < 1) {
            gap = 1;
        }
        isSwaped = 0;

        for (register size_t i = 0; i < n - gap; ++i) {
            j = i + gap;
            ++countComparison;
            if (array[i] > array[j]) {
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
        ++countComparison;
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
    int max = (int) n - 1;
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

    size_t countComparison = 0;

    // если длинна массива меньше 2, то сортировка не потребуется
    if (n < 2) {
        return;
    }

    int i;
    int maxNumPos;
    for (i = (int) n; i > 1; --i) {
        ++countComparison;
        maxNumPos = 0;
        for (register size_t j = 0; j < i; ++j) {
            ++countComparison;
            if (array[j] > array[maxNumPos]) {
                maxNumPos = j;
            }
        }

        ++countComparison;
        if (maxNumPos == i - 1) {
            continue;
        }

        ++countComparison;
        if (maxNumPos >= 0) {
            flip(array, maxNumPos, i);
        }
    }

    printf("\npancake_sort comparison count = %lld \n", countComparison);
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void insertion_sort(int *array, size_t n) {
    int newElement, location;

    size_t countComparison = 0;

    for (register size_t i = 1; i < n; ++i) {
        ++countComparison;
        newElement = array[i];
        location = (int) i - 1;

        while (location >= 0 && array[location] > newElement) {
            ++countComparison;
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = newElement;
    }

    printf("\ninsertion_sort comparison count = %lld \n", countComparison);
}

void insertion_binary_sort(int *array, size_t n) {
    size_t countComparison = 0;

    for (register int i = 0; i < n; ++i) {
        ++countComparison;
        int key = array[i];
        int left = 0;
        int right = i;

        while (right - left > 0) {
            ++countComparison;
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
    int interval = (int) n / 2;
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

struct btreenode {
    int data;
    struct btreenode *leftchild;
    struct btreenode *rightchild;
};

void insert(struct btreenode **, int);

void inorder(struct btreenode *, int **);

void tree_sort(int *array, int arr_size) {
    struct btreenode *bt = NULL;
    int i, *p = array;

    for (i = 0; i < arr_size; i++)
        insert(&bt, array[i]);

    inorder(bt, &p);
}

void insert(struct btreenode **sr, int num) {
    if (*sr == NULL) {
        *sr = malloc(sizeof(struct btreenode));

        (*sr)->leftchild = NULL;
        (*sr)->data = num;
        (*sr)->rightchild = NULL;
    } else {
        if (num < (*sr)->data) {
            insert(&((*sr)->leftchild), num);
        } else {
            insert(&((*sr)->rightchild), num);
        }
    }
}

void inorder(struct btreenode *sr, int **array) {
    if (sr != NULL) {
        inorder(sr->leftchild, array);
        **array = sr->data;
        ++*array;
        inorder(sr->rightchild, array);
    }
}



