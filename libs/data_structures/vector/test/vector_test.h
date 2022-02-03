#ifndef COURSE_VECTOR_TEST_H
#define COURSE_VECTOR_TEST_H

#include <assert.h>
#include "../vector.h"

/*
 * Тест проверяет, может ли пользователь создать нулевой вектор
 */
void create_vector_test1();

/*
 * Тест проверяет, выделяется ли нужный параметр 'capacity'
 */
void create_vector_test2();

/*
 * Тест должен вывести ошибку и выйти из программы с кодом '1'
 * на данный момент закомментирован.
 * Необходим для проверки вспомогательной функции 'check_malloc'
 */
void create_vector_test3();

void create_vector_test();

void reserve_vector_test1();

void reserve_vector_test2();

void reserve_vector_test3();

void reserve_vector_test();

void vector_test();

#endif //COURSE_VECTOR_TEST_H
