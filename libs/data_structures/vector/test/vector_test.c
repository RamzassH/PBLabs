#include "vector_test.h"
#include <assert.h>

void create_vector_test1() {
    vector_t v = create_vector(0);

    assert((v).data == NULL && (v).size == 0 && (v).capacity == 0);
    delete_vector(&v);
}

void create_vector_test2() {
    vector_t v = create_vector(5);

    assert((v).data != NULL && (v).size == 0 && (v).capacity == 5);
    delete_vector(&v);
}

/*void create_vector_test3() {
    vector_t v = create_vector(SIZE_MAX);
}*/

void create_vector_test() {
    create_vector_test1();
    create_vector_test2();
/*  create_vector_test3(); */
}

void reserve_vector_test1() {
    vector_t v = create_vector(5);
    (v).size = 4;
    reserve(&v, 0);

    assert((v).data == NULL && (v).size == 0 && (v).capacity == 0);
    delete_vector(&v);
}

void reserve_vector_test2() {
    vector_t v = create_vector(5);
    (v).size = 4;
    reserve(&v, 3);

    assert((v).data != NULL && (v).size == 3 && (v).capacity == 3);
    delete_vector(&v);
}

void reserve_vector_test3() {
    vector_t v = create_vector(3);
    (v).size = 2;
    reserve(&v, 5);

    assert((v).data != NULL && (v).size == 2 && (v).capacity == 5);
    delete_vector(&v);
}

void reserve_vector_test4() {
    vector_t v = create_vector(0);
    (v).size = 0;
    reserve(&v, 5);

    assert((v).data != NULL && (v).size == 0 && (v).capacity == 5);
    delete_vector(&v);
}

/*
 * Тест необходим для проверки корректной работы функции check_malloc.
 * При корректной работе, программа выдает ошибку.
 */
/*
void reserve_vector_test5() {
    vector_t v = create_vector(3);
    (v).size = 2;
    reserve(&v, SIZE_MAX);

    assert((v).data != NULL && (v).size == 2 && (v).capacity == 5);
    delete_vector(&v);
}
*/

void reserve_vector_test() {
    reserve_vector_test1();
    reserve_vector_test2();
    reserve_vector_test3();
    reserve_vector_test4();
    /* reserve_vector_test5(); */
}

void clear_vector_test1() {
    vector_t v = create_vector(5);
    (v).size = 2;
    clear(&v);

    assert((v).data != NULL && (v).size == 0 && (v).capacity == 5);
    delete_vector(&v);
}

void clear_vector_test2() {
    vector_t v = create_vector(5);
    (v).size = 5;
    clear(&v);

    assert((v).data != NULL && (v).size == 0 && (v).capacity == 5);
    delete_vector(&v);
}

void clear_vector_test() {
    clear_vector_test1();
    clear_vector_test2();
}

void shrink_to_fit_test1() {
    vector_t v = create_vector(5);
    (v).size = 2;
    shrink_to_fit(&v);

    assert((v).data != NULL && (v).size == 2 && (v).capacity == 2);
    delete_vector(&v);
}

void shrink_to_fit_test2() {
    vector_t v = create_vector(5);
    (v).size = 0;
    shrink_to_fit(&v);

    assert((v).data == NULL && (v).size == 0 && (v).capacity == 0);
    delete_vector(&v);
}

void shrink_to_fit_test3() {
    vector_t v = create_vector(5);
    (v).size = 5;
    shrink_to_fit(&v);

    assert((v).data != NULL && (v).size == 5 && (v.capacity) == 5);
    delete_vector(&v);
}

void shrink_to_fit_test() {
    shrink_to_fit_test1();
    shrink_to_fit_test2();
    shrink_to_fit_test3();
}

void vector_test() {
    create_vector_test();
    reserve_vector_test();
    clear_vector_test();
    shrink_to_fit_test();
}