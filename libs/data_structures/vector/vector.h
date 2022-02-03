#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct {
    int *data;            /*указатель на элемент вектора*/
    size_t size;          /*размер вектора*/
    size_t capacity;      /*вместимость вектора*/
}vector_t;

/*
 * Выделяет нужное количество памяти для хранения вектора размером needCapacity.
 */
vector_t create_vector(size_t needCapacity);

/*
 * Изменяет количество памяти, выделенное под хранение элементов вектора.
 */
void reserve(vector_t *v, size_t newCapacity);

/*
 * Удаляет элементы из контейнера, но не освобождает выделенную память.
 */
void clear(vector_t *v);

/*
 * Освобождает память, выделенную под неиспользуемые элементы.
 */
void shrink_to_fit(vector_t *v);


void delete_vector(vector_t *v);
/*
 * Проверяет, является ли вектор пустым.
 */
bool is_empty(vector_t *v);

/*
 * Проверяет, является ли вектор полным.
 */
bool is_full(vector_t *v);

/*
 * возвращает i-й элемент вектора v.
 */
int get_vector_value(vector_t *v, size_t i);

/*
 * Добавляет элемент x в конец вектора v.
 */
void push_back(vector_t *v, int x);

/*
 * Удаляет последний элемент из вектора v.
 */
void pop_back(vector_t *v);

/*
 * Возвращает указатель на index-ый элемент вектора.
 */
int* at_vector(vector_t *v, size_t index);

/*
 * Возвращает указатель на последний элемент вектора.
 */
int* back(vector_t *v);

/*
 * Возвращает указатель на нулевой элемент вектора.
 */
int* front(vector_t *v);

#endif
