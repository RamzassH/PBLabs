#include "vector.h"

void check_malloc(int *data,
                  const size_t maxMemorySize) {
    if (_msize(data) != maxMemorySize) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vector_t create_vector(const size_t needCapacity) {
    int *data = NULL;

    if (needCapacity > 0) {
        size_t needMemorySize = needCapacity * sizeof(int);
        data = (int *) malloc(needMemorySize);
        check_malloc(data, needMemorySize);
    }

    return (vector_t) {data, 0, needCapacity};
}

void reserve(vector_t *v, const size_t newCapacity) {
    (v)->capacity = newCapacity;

    if (newCapacity < (v)->size) {
        (v)->size = newCapacity;
    }

    if (newCapacity > 0) {
        size_t needMemorySize = newCapacity * sizeof(int);
        (v)->data = (int *) realloc((v)->data, needMemorySize);
        check_malloc((v)->data, needMemorySize);
    } else {
        (v)->data = NULL;
    }
}

void clear(vector_t *v) {
    (v)->size = 0;
}

void shrink_to_fit(vector_t *v) {
    reserve(v, (v)->size);
}

void delete_vector(vector_t *v) {
    free(v->data);
}

