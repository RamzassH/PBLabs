#ifndef INC__BIG_O_H
#define INC__BIG_O_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Z:/course_/libs/algorithms/array/array.h"
#include "../random_generation_functions/random_generation_functions.h"

// функция сортировки
typedef struct{
    void (*sort) (int *array, size_t sizeOfArray);      // указатель на функцию сортировки
    char name[64];                                      // имя функции сортировки
}sort_functions_t;

// функция генерации
typedef struct{
    void (*generate) (int *array, size_t sizeOfArray); // указатель на функцию генерации
    char name[64];                                     // имя функции генерации
}generating_functions_t;

/// макрофункция для замера времени работы функции сортировки
/// testFunction - функция сортировки, подверженная замеру
/// time - переменная куда будет сохранен результат замера
#define TIME_TEST(testFunction, time) {\
    clock_t startTime = clock();\
                                       \
    testFunction\
                                       \
    clock_t endTime = clock();\
    clock_t sortTime = endTime - startTime;\
                                       \
    time = (double) sortTime / CLOCKS_PER_SEC; \
}

// определяет размер массива, если он определен в функции
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

void checkTime(void(*sort_functions_t) (int *, size_t),
               void(*generating_functions_t) (int *, size_t),
               size_t size, char *experimentName);

void timeMeasure();

#endif