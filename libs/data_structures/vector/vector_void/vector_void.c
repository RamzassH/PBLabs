#include "vector_void.h"

vectorVoid_t create_vector_void(const size_t needCapacity, const size_t baseTypeSize) {
    void *data = NULL;

    if (needCapacity > 0) {
        size_t needMemorySize = needCapacity * sizeof(baseTypeSize);
        data = (void *) malloc(needMemorySize);

        check_malloc(data, needMemorySize);
    }

    return (vectorVoid_t) {data, 0, needCapacity, baseTypeSize};
}

void reserve_void(vectorVoid_t *v, const size_t newCapacity) {
    (v)->capacity = newCapacity;

    if (newCapacity < (v)->size) {
        (v)->size = newCapacity;
    }

    if (newCapacity > 0) {
        size_t needMemorySize = newCapacity * sizeof((v)->baseTypeSize);
        (v)->data = (void *) realloc((v)->data, needMemorySize);

        check_malloc((v)->data, needMemorySize);
    } else {
        (v)->data = NULL;
    }
}

void shrink_to_fit_void(vectorVoid_t *v) {
    reserve_void(v, (v)->size);
}

void clear_void(vectorVoid_t *v) {
    (v)->size = 0;
}

void delete_vector_void(vectorVoid_t *v) {
    free((v)->data);
}

