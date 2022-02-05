#ifndef INC__VECTOR_VOID_H
#define INC__VECTOR_VOID_H

#include <limits.h>

typedef struct {
    void *data;             /*указатель на нулевой элемент вектора*/
    size_t size;            /*размер вектора*/
    size_t capacity;        /*вместимость вектора*/
    size_t baseTypeSize;    /*размер базового типа*/
}vectorVoid_t;

#endif
