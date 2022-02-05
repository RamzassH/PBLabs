#ifndef COURSE_VECTOR_TEST_H
#define COURSE_VECTOR_TEST_H

#include <assert.h>
#include "../vector.h"

/*
 * Тест проверяет, может ли пользователь создать нулевой вектор
 */
void test_create_vector_zero_vector();

/*
 * Тест проверяет, выделяется ли нужный параметр 'capacity'
 */
void test_create_vector_non_empty_vector();

/*
 * Тест должен вывести ошибку и выйти из программы с кодом '1'
 * на данный момент закомментирован.
 * Необходим для проверки вспомогательной функции 'check_malloc'
 */
void test_create_vector_oversize_memory();

/*
 * Тест проверяет, можно ли резервировать память так,
 * чтобы на выходе мы получили пустой вектор
 */
void test_reserve_to_empty_vector();

/*
 * Тест проверяет, можно ли резервировать память так,
 * чтобы мы получили вектор меньшей длины, чем искомый
 */
void test_reserve_from_long_to_short_vector();

/*
 * Тест проверяет, можно ли резервировать память так,
 * чтобы мы получили вектор больше длины, чем искомый
 */
void test_reserve_from_short_to_long_vector();

/*
 * Тест проверяет, можно ли резервировать память так,
 * чтобы мы получили из нулевого вектора ненулевой вектор.
 */
void test_reserve_from_zero_to_long();

/*
 * Тест проверяет, можно ли очистить не полный вектор
 */
void test_clear_non_full_vector();

/*
 * Тест проверяет, можно ли очистить полный вектор
 */
void test_clear_full_vector();

/*
 * Тест проверяет, можно ли очистить нулевой вектор
 */
void test_clear_zero_vector();

/*
 * Тест проверяет, можно ли подрезать не полный вектор
 */
void test_shrink_to_fit_non_full_vector();

/*
 * Тест проверят, можно ли подрезать пустой вектор
 */
void test_shrink_to_fit_empty_vector();

/*
 * Тест проверяет, можно ля подрезать полный вектор
 */
void test_shrink_to_fit_full_vector();

void test_is_empty();

/*
 * Тест проверяет, является ли полным ненулевой вектор
 */
void test_is_full_non_zero_vector();

/*
 * Тест проверяет, является ли полным нулевой вектор
 */
void test_is_full_zero_vector();

/*
 * Тест проверяет, правильно ли добавляется элемент в пустой вектор
 */
void test_vector_push_back_empty_vector();

/*
 * Тест проверяет, правильно ли добавляется элемент в нулевой вектор
 */
void test_vector_push_back_zero_vector();

/*
 * Тест проверяет, правильно ли добавляется элемент в полный вектор
 */
void test_vector_push_back_full_vector();

/*
 * Тест проверяет, правильно ли добавляется элемент в ненулевой вектор
 */
void test_vector_pop_back_non_zero_vector();

/*
 * Тест проверяет, правильно ли добавляется элемент в нулевой вектор
 */
void test_vector_pop_back_zero_vector();

/*
 * Тест проверяет, может ли найти последний элемент
 * в изначально пустом векторе
 */
void test_at_vector_empty_vector();

/*
 * Тест проверяет обращение к последнему элементу
 */
void test_at_vector_request_to_last_element();

/*
 * Тест проверяет, может ли функция найти последний элемент
 * в изначально нулевом векторе
 */
void test_at_vector_zero_vector();

/*
 * Тест проверяет, может ли функция найти последний элемент
 * в векторе с одним элементом
 */
void test_back_one_element_in_vector();

/*
 * Тест проверяет, может ли функция найти последний элемент
 * в изначально нулевом векторе
 */
void test_back_zero_vector();

/*
 * Тест проверяет, может ли функция найти последний элемент
 * в полном векторе
 */
void test_back_full_vector();

/*
 * Тест проверяет, может ли функция найти первый элемент
 * в изначально нулевом векторе
 */
void test_front_one_element_in_vector();

/*
* Тест проверяет, может ли функция найти первый элемент
* в изначально нулевом векторе
*/
void test_front_zero_vector();

/*
* Тест проверяет, может ли функция найти первый элемент
* в полном векторе
*/
void test_front_full_vector();

void vector_test();

#endif //COURSE_VECTOR_TEST_H
