#ifndef INC__VECTOR_VOID_H
#define INC__VECTOR_VOID_H

#include "../vector_t/vector.h"

#include <string.h>

typedef struct {
    void *data;             /*указатель на нулевой элемент вектора*/
    size_t size;            /*размер вектора*/
    size_t capacity;        /*вместимость вектора*/
    size_t baseTypeSize;    /*размер базового типа*/
}vectorVoid_t;

/*
 * Выделяет нужное количество памяти для хранения вектора размером needCapacity.
 */
vectorVoid_t create_vector_void(size_t needCapacity, size_t baseTypeSize);


/*
 * Изменяет количество памяти, выделенное под хранение элементов вектора.
 */
void reserve_void(vectorVoid_t *v, size_t newCapacity);

/*
 * Освобождает память, выделенную под неиспользуемые элементы.
 */
void shrink_to_fit_void(vectorVoid_t *v);

/*
 * Удаляет элементы из контейнера, но не освобождает выделенную память.
 */
void clear_void(vectorVoid_t *v);

/*
 * Освобождает память, выделенную под вектор v
 */
void delete_vector_void(vectorVoid_t *v);

/*
 * Проверяет, является ли вектор пустым.
 */
bool is_empty_void(vectorVoid_t *v);

/*
 * Проверяет, является ли вектор полным.
 */
bool is_full_void(vectorVoid_t *v);

/*
 * возвращает index-й элемент вектора v.
 */
void get_vector_value_void(vectorVoid_t *v, size_t index, void *destination);

/*
 * записывает в index-й элемент вектора v значение из source.
 */
void set_vector_value_void(vectorVoid_t *v, size_t index, void *source);

/*
 * Удаляет последний элемент из вектора v.
 */
void pop_back_void(vectorVoid_t *v);

/*
 * Добавляет элемент x в конец вектора v.
 */
void push_back_void(vectorVoid_t *v, void *source);

#endif
