#ifndef INC__RANDOM_GENERATION_FUNCTIONS_H
#define INC__RANDOM_GENERATION_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/// генерирует случайную последовательность из n символов
/// \param array - массив в который будет записана последовательность
/// \param n - количество элементов в последовательности
void generate_random_sequence(int *array, size_t n);

/// генерирует упорядоченную по неубыванию последовательность из n символов
/// \param array - массив в который будет записана последовательность
/// \param n - количество элементов в последовательности
void generate_ordered_sequence(int *array, size_t n);

/// генерирует упорядоченную по убыванию последовательность из n символов
/// \param array - массив в который будет записана последовательность
/// \param n - количество элементов в последовательности
void generate_ordered_backward(int *array, size_t n);


#endif