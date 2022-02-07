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

vectorVoid_t create_vector_void(size_t needCapacity, size_t baseTypeSize);

void reserve_void(vectorVoid_t *v, size_t newCapacity);

void shrink_to_fit_void(vectorVoid_t *v);

void clear_void(vectorVoid_t *v);

void delete_vector_void(vectorVoid_t *v);

bool is_empty_void(vectorVoid_t *v);

bool is_full_void(vectorVoid_t *v);

void get_vector_value_void(vectorVoid_t *v, size_t index, void *destination);

void set_vector_value_void(vectorVoid_t *v, size_t index, void *source);

void pop_back_void(vectorVoid_t *v);

void push_back_void(vectorVoid_t *v, void *source);

#endif
