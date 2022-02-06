#ifndef INC__TEST_VECTOR_VOID_H
#define INC__TEST_VECTOR_VOID_H

#include "../vector_void/vector_void.h"
#include <assert.h>

/*
 * Тест проверяет, может ли пользователь создать нулевой вектор
 */
void test_create_vector_zero_void();

/*
 * Тест проверяет, выделяется ли нужный параметр 'capacity'
 */
void test_create_vector_non_zero_vector_void();

/*
 * Тест должен вывести ошибку и выйти из программы с кодом '1'
 * на данный момент закомментирован.
 * Необходим для проверки вспомогательной функции 'check_malloc'
 */
void test_create_vector_float_vector_void();

/*
 * Тест проверяет, возможно ли создать вектор типа double
 */
void test_create_vector_double_vector_void();

/*
 * Тест проверяет, можно ли резервировать память так,
 * чтобы на выходе мы получили пустой вектор
 */
void test_reserve_to_empty_vector_void();

/*
 * Тест проверяет, можно ли резервировать память так,
 * чтобы мы получили вектор меньшей длины, чем искомый
 */
void test_reserve_from_long_to_short_vector_void();

/*
 * Тест проверяет, можно ли резервировать память так,
 * чтобы мы получили вектор больше длины, чем искомый
 */
void test_reserve_from_short_to_long_vector_void();

/*
 * Тест проверяет, можно ли резервировать память так,
 * чтобы мы получили из нулевого вектора ненулевой вектор.
 */
void test_reserve_from_zero_to_long_void();

/*
 * Тест проверяет, возможно ли резервировать вектор типа double
 */
void test_reserve_double_void();

/*
 * Тест проверяет, можно ли очистить не полный вектор
 */
void test_clear_non_full_vector_void();

/*
 * Тест проверяет, можно ли очистить полный вектор
 */
void test_clear_full_vector_void();

/*
 * Тест проверяет, можно ли очистить нулевой вектор
 */
void test_clear_zero_vector_void();

/*
 * Тест проверяет, можно ли очистить вектор типа double
 */
void test_clear_double_vector_void();

/*
 * Тест проверяет, можно ли подрезать не полный вектор
 */
void test_shrink_to_fit_non_full_vector_void();

/*
 * Тест проверят, можно ли подрезать пустой вектор
 */
void test_shrink_to_fit_empty_vector_void();

/*
 * Тест проверяет, можно ля подрезать полный вектор
 */
void test_shrink_to_fit_full_vector_void();

/*
 * Тест проверят, можно ли подрезать вектор типа double
 */
void test_shrink_to_fit_double_vector_void();

void test_vector_void();

#endif
