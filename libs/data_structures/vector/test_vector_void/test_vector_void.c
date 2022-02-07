#include "test_vector_void.h"

#include <float.h>

void test_create_vector_zero_void() {
    vectorVoid_t v = create_vector_void(0, sizeof(int));

    assert((v).data == NULL);
    assert((v).size == 0);
    assert((v).capacity == 0);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_create_vector_non_zero_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_create_vector_double_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(double));

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);
    assert((v).baseTypeSize == sizeof(double));

    delete_vector_void(&v);
}

void test_create_vector_void() {
    test_create_vector_zero_void();
    test_create_vector_non_zero_vector_void();
    test_create_vector_double_vector_void();
}

void test_reserve_to_empty_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));
    (v).size = 4;

    reserve_void(&v, 0);

    assert((v).data == NULL);
    assert((v).size == 0);
    assert((v).capacity == 0);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_reserve_from_long_to_short_vector_void() {
    vectorVoid_t v = create_vector_void(5,sizeof(int));
    (v).size = 4;

    reserve_void(&v, 3);

    assert((v).data != NULL);
    assert((v).size == 3);
    assert((v).capacity == 3);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_reserve_from_short_to_long_vector_void() {
    vectorVoid_t v = create_vector_void(3, sizeof(int));
    (v).size = 2;

    reserve_void(&v, 5);

    assert((v).data != NULL);
    assert((v).size == 2);
    assert((v).capacity == 5);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_reserve_from_zero_to_long_void() {
    vectorVoid_t v = create_vector_void(0, sizeof(int));
    (v).size = 0;

    reserve_void(&v, 5);

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_reserve_double_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(double));
    (v).size = 5;

    reserve_void(&v, 1);

    assert((v).data != NULL);
    assert((v).size == 1);
    assert((v).capacity == 1);
    assert((v).baseTypeSize == sizeof(double));

    delete_vector_void(&v);
}

/*
 * Тест необходим для проверки корректной работы функции check_malloc.
 * При корректной работе, программа выдает ошибку.
 */
/*
void test_reserve_void_oversize_vector() {
    vectorVoid_t v = create_vector_void(3, sizeof(int));
    (v).size = 2;
    reserve_void(&v, SIZE_MAX);

    assert((v).data != NULL);
    assert((v).size == 2);
    assert((v).capacity == 5);
    assert((v).baseTypeSize == sizeof(int);

    delete_vector_void(&v);
}
*/

void test_reserve_void() {
    test_reserve_to_empty_vector_void();
    test_reserve_from_long_to_short_vector_void();
    test_reserve_from_short_to_long_vector_void();
    test_reserve_from_zero_to_long_void();
    test_reserve_double_void();
    /* test_reserve_oversize_vector_void(); */
}

void test_clear_non_full_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));
    (v).size = 2;

    clear_void(&v);

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_clear_full_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));
    (v).size = 5;

    clear_void(&v);

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_clear_zero_vector_void() {
    vectorVoid_t v = create_vector_void(0, sizeof(int));
    (v).size = 0;

    clear_void(&v);

    assert((v).data == NULL);
    assert((v).size == 0);
    assert((v).capacity == 0);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_clear_double_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(double));
    (v).size = 5;

    clear_void(&v);

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);
    assert((v).baseTypeSize == sizeof(double));

    delete_vector_void(&v);
}

void test_clear_void() {
    test_clear_non_full_vector_void();
    test_clear_full_vector_void();
    test_clear_zero_vector_void();
    test_clear_double_vector_void();
}

void test_shrink_to_fit_non_full_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));
    (v).size = 2;

    shrink_to_fit_void(&v);

    assert((v).data != NULL);
    assert((v).size == 2);
    assert((v).capacity == 2);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_shrink_to_fit_empty_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));
    (v).size = 0;

    shrink_to_fit_void(&v);

    assert((v).data == NULL);
    assert((v).size == 0);
    assert((v).capacity == 0);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_shrink_to_fit_full_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));
    (v).size = 5;

    shrink_to_fit_void(&v);

    assert((v).data != NULL);
    assert((v).size == 5);
    assert((v.capacity) == 5);
    assert((v).baseTypeSize == sizeof(int));

    delete_vector_void(&v);
}

void test_shrink_to_fit_double_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(double));
    v.size = 2;

    shrink_to_fit_void(&v);

    assert((v).data != NULL);
    assert((v).size == 2);
    assert((v).capacity == 2);
    assert((v).baseTypeSize == sizeof(double));

    delete_vector_void(&v);
}

void test_shrink_to_fit_void() {
    test_shrink_to_fit_non_full_vector_void();
    test_shrink_to_fit_empty_vector_void();
    test_shrink_to_fit_full_vector_void();
    test_shrink_to_fit_double_vector_void();
}

void test_vector_push_back_zero_vector_void() {
    vectorVoid_t v = create_vector_void(0, sizeof(int));

    for (int i = 1; i < 6; ++i) {
        push_back_void(&v, &i);
    }

    int expectedNumber = 1;
    for (register int j = 0; j < 5; ++j) {
        int testNumber;
        get_vector_value_void(&v, j, &testNumber);

        assert(testNumber == expectedNumber);

        expectedNumber++;
    }

    delete_vector_void(&v);
}

void test_vector_push_back_empty_vector_void() {
    vectorVoid_t v = create_vector_void(3, sizeof(int));

    for (int i = 1; i < 3; ++i) {
        push_back_void(&v, &i);
    }

    int expectedNumber = 1;
    for (register int j = 0; j < 2; ++j) {
        int testNumber;
        get_vector_value_void(&v, j, &testNumber);

        assert(testNumber == expectedNumber);

        expectedNumber++;
    }

    delete_vector_void(&v);
}

void test_vector_push_back_full_vector_void() {
    vectorVoid_t v = create_vector_void(3, sizeof(int));
    (v).size = 5;

    for (int i = 1; i < 6; ++i) {
        push_back_void(&v, &i);
    }


    int expectedNumber = 1;
    for (register int j = 5; j < 10; ++j) {
        int testNumber;
        get_vector_value_void(&v, j, &testNumber);

        assert(testNumber == expectedNumber);

        expectedNumber++;
    }

    delete_vector_void(&v);
}

void test_vector_push_back_double_vector_void() {
    vectorVoid_t v = create_vector_void(0, sizeof(double));

    for (int i = 1; i < 6; ++i) {
        push_back_void(&v, &i);
    }

    double expectedNumber = 1;
    for (register int j = 0; j < 5; ++j) {
        double testNumber;
        get_vector_value_void(&v, j, &testNumber);

        assert(testNumber - expectedNumber <= DBL_EPSILON);

        expectedNumber++;
    }

    delete_vector_void(&v);
}

void test_vector_push_back_void() {
    test_vector_push_back_empty_vector_void();
    test_vector_push_back_zero_vector_void();
    test_vector_push_back_full_vector_void();
    test_vector_push_back_double_vector_void();
}

void test_vector_pop_back_zero_vector_void() {
    vectorVoid_t v = create_vector_void(0, sizeof(int));

    for (int i = 0; i < 5; ++i) {
        push_back_void(&v, &i);
    }

    for (int i = 0; i < 3; ++i) {
        pop_back_void(&v);
    }

    assert((v).size == 2);

    delete_vector_void(&v);
}

void test_vector_pop_back_empty_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));

    for (int i = 0; i < 5; ++i) {
        push_back_void(&v, &i);
    }

    for (int i = 0; i < 3; ++i) {
        pop_back_void(&v);
    }

    assert((v).size == 2);

    delete_vector_void(&v);
}

void test_vector_pop_back_full_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));
    (v).size = 5;

    for (int i = 0; i < 5; ++i) {
        push_back_void(&v, &i);
    }

    for (int i = 0; i < 5; ++i) {
        pop_back_void(&v);
    }

    assert((v).size == 5);

    delete_vector_void(&v);
}

void test_vector_pop_back_double_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(double));
    (v).size = 5;

    for (int i = 0; i < 5; ++i) {
        push_back_void(&v, &i);
    }

    for (int i = 0; i < 5; ++i) {
        pop_back_void(&v);
    }

    assert((v).size == 5);

    delete_vector_void(&v);
}

void test_vector_pop_back_void() {
    test_vector_pop_back_zero_vector_void();
    test_vector_pop_back_empty_vector_void();
    test_vector_pop_back_full_vector_void();
    test_vector_pop_back_double_vector_void();
}


void test_vector_set_vector_value_zero_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));

    int numberToWrite = 1;
    for (register int i = 0; i < 5; i++) {
        set_vector_value_void(&v, i, &numberToWrite);
        numberToWrite++;
    }

    int expectedNumber = 1;
    for (register int j = 0; j < 5; ++j) {
        int testNumber;
        get_vector_value_void(&v, j, &testNumber);

        assert(testNumber == expectedNumber);

        expectedNumber++;
    }

    delete_vector_void(&v);
}

void test_vector_set_vector_value_double_vector_void() {
    vectorVoid_t v = create_vector_void(5, sizeof(int));

    double numberToWrite = 1;
    for (register int i = 0; i < 5; i++) {
        set_vector_value_void(&v, i, &numberToWrite);
        numberToWrite++;
    }

    double expectedNumber = 1;
    for (register int j = 0; j < 5; ++j) {
        double testNumber;
        get_vector_value_void(&v, j, &testNumber);

        assert(testNumber - expectedNumber <= DBL_EPSILON);

        expectedNumber++;
    }

    delete_vector_void(&v);
}


void test_vector_set_vector_value_void() {
    test_vector_set_vector_value_zero_vector_void();
    test_vector_set_vector_value_double_vector_void();
}

void test_vector_void() {
    test_create_vector_void();
    test_reserve_void();
    test_clear_void();
    test_shrink_to_fit_void();
    test_vector_push_back_void();
    test_vector_pop_back_void();
    test_vector_set_vector_value_void();
}