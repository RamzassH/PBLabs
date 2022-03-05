#ifndef INC__TASK_MANAGER_H
#define INC__TASK_MANAGER_H

#include <ctype.h>
#include <memory.h>
#include <assert.h>
#include <stdio.h>

#include "../str_lib/string.h"

#define ASSERT_STRING(expected, got) assert_string(expected, got, \
                                __FILE__, __FUNCTION__, __LINE__)

static void assert_string(const char* expected, const char* got,
                          const char* file, const char* func,
                          const int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, "Exception file: %s\n", file);
        fprintf(stderr, "Function: %s - line: %d\n", func, line);
        fprintf(stderr, "Got:      \"%s\"\n", got);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
    } else
        fprintf(stderr, "%s - OK!\n", func);
}



void task1();

void task2();

void task3();

void task4();

void task5();

void task6();

void task7();

void task8();

#endif
