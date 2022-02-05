#include "vector_test.h"
#include <assert.h>

void test_create_vector_zero_vector() {
    vector_t v = create_vector(0);

    assert((v).data == NULL);
    assert((v).size == 0);
    assert((v).capacity == 0);

    delete_vector(&v);
}

void test_create_vector_non_zero_vector() {
    vector_t v = create_vector(5);

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);

    delete_vector(&v);
}

/*void test_create_vector_oversize_memory() {
    vector_t v = create_vector(SIZE_MAX);
}*/

void test_create_vector() {
    test_create_vector_zero_vector();
    test_create_vector_non_zero_vector();
/*  test_create_vector_oversize_memory(); */
}

void test_reserve_to_empty_vector() {
    vector_t v = create_vector(5);
    (v).size = 4;

    reserve(&v, 0);

    assert((v).data == NULL);
    assert((v).size == 0);
    assert((v).capacity == 0);

    delete_vector(&v);
}

void test_reserve_from_long_to_short_vector() {
    vector_t v = create_vector(5);
    (v).size = 4;

    reserve(&v, 3);

    assert((v).data != NULL);
    assert((v).size == 3);
    assert((v).capacity == 3);

    delete_vector(&v);
}

void test_reserve_from_short_to_long_vector() {
    vector_t v = create_vector(3);
    (v).size = 2;

    reserve(&v, 5);

    assert((v).data != NULL);
    assert((v).size == 2);
    assert((v).capacity == 5);

    delete_vector(&v);
}

void test_reserve_from_zero_to_long() {
    vector_t v = create_vector(0);
    (v).size = 0;

    reserve(&v, 5);

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);

    delete_vector(&v);
}

/*
 * Тест необходим для проверки корректной работы функции check_malloc.
 * При корректной работе, программа выдает ошибку.
 */
/*
void test_reserve_oversize_vector() {
    vector_t v = create_vector(3);
    (v).size = 2;
    reserve(&v, SIZE_MAX);

    assert((v).data != NULL);
    assert((v).size == 2);
    assert((v).capacity == 5);

    delete_vector(&v);
}
*/

void test_reserve() {
    test_reserve_to_empty_vector();
    test_reserve_from_long_to_short_vector();
    test_reserve_from_short_to_long_vector();
    test_reserve_from_zero_to_long();
    /* test_reserve_oversize_vector(); */
}

void test_clear_non_full_vector() {
    vector_t v = create_vector(5);
    (v).size = 2;

    clear(&v);

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);

    delete_vector(&v);
}

void test_clear_full_vector() {
    vector_t v = create_vector(5);
    (v).size = 5;

    clear(&v);

    assert((v).data != NULL);
    assert((v).size == 0);
    assert((v).capacity == 5);

    delete_vector(&v);
}

void test_clear_zero_vector() {
    vector_t v = create_vector(0);
    (v).size = 0;

    clear(&v);

    assert((v).data == NULL);
    assert((v).size == 0);
    assert((v).capacity == 0);

    delete_vector(&v);
}

void test_clear() {
    test_clear_non_full_vector();
    test_clear_full_vector();
    test_clear_zero_vector();
}

void test_shrink_to_fit_non_full_vector() {
    vector_t v = create_vector(5);
    (v).size = 2;

    shrink_to_fit(&v);

    assert((v).data != NULL);
    assert((v).size == 2);
    assert((v).capacity == 2);

    delete_vector(&v);
}

void test_shrink_to_fit_empty_vector() {
    vector_t v = create_vector(5);
    (v).size = 0;

    shrink_to_fit(&v);

    assert((v).data == NULL);
    assert((v).size == 0);
    assert((v).capacity == 0);

    delete_vector(&v);
}

void test_shrink_to_fit_full_vector() {
    vector_t v = create_vector(5);
    (v).size = 5;

    shrink_to_fit(&v);

    assert((v).data != NULL);
    assert((v).size == 5);
    assert((v.capacity) == 5);

    delete_vector(&v);
}

void test_shrink_to_fit() {
    test_shrink_to_fit_non_full_vector();
    test_shrink_to_fit_empty_vector();
    test_shrink_to_fit_full_vector();
}

void test_is_empty() {
    vector_t v = create_vector(5);
    (v).size = 0;

    assert(is_empty(&v) == true);

    delete_vector(&v);
}

void test_is_full_non_zero_vector() {
    vector_t v = create_vector(5);
    (v).size = 5;

    assert(is_full(&v) == true);

    delete_vector(&v);
}

void test_is_full_zero_vector() {
    vector_t v = create_vector(0);
    (v).size = 0;

    assert(is_full(&v) == true);

    delete_vector(&v);
}

void test_is_full() {
    test_is_full_non_zero_vector();
    test_is_full_zero_vector();
}

void test_vector_push_back_empty_vector() {
    vector_t v = create_vector(5);
    (v).size = 0;

    for (int i = 1; i < 6; ++i) {
        push_back(&v, i);
    }

    assert(get_vector_value(&v, 0) == 1);
    assert(get_vector_value(&v, 1) == 2);
    assert(get_vector_value(&v, 2) == 3);
    assert(get_vector_value(&v, 3) == 4);
    assert(get_vector_value(&v, 4) == 5);

    delete_vector(&v);
}

void test_vector_push_back_zero_vector() {
    vector_t v = create_vector(0);

    push_back(&v, 1);
    push_back(&v, 2);

    assert(get_vector_value(&v, 0) == 1);
    assert(get_vector_value(&v,1) == 2);

    delete_vector(&v);
}

void test_vector_push_back_full_vector() {
    vector_t v = create_vector(5);
    (v).size = 5;

    push_back(&v, 7);
    push_back(&v, 8);

    assert(get_vector_value(&v, 5) == 7);
    assert(get_vector_value(&v, 6) == 8);

    delete_vector(&v);
}

void test_vector_push_back() {
    test_vector_push_back_empty_vector();
    test_vector_push_back_zero_vector();
    test_vector_push_back_full_vector();
}

void test_vector_pop_back_non_zero_vector () {
    vector_t v = create_vector(1);
    push_back(&v, 1);

    assert(v.size == 1);

    pop_back(&v);

    assert((v).size == 0);
    assert((v).capacity == 1);
}

void test_vector_pop_back_zero_vector() {
    vector_t v = create_vector(0);

    push_back(&v, 10);

    assert(v.size == 1);

    pop_back(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);

    delete_vector(&v);
}

void test_vector_pop_back() {
    test_vector_pop_back_non_zero_vector();
    test_vector_pop_back_zero_vector();
}

void vector_test() {
    test_create_vector();
    test_reserve();
    test_clear();
    test_shrink_to_fit();
    test_is_empty();
    test_is_full();
    test_vector_push_back();
    test_vector_pop_back();
}