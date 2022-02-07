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
        size_t needMemorySize = newCapacity * (v)->baseTypeSize;
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

bool is_zero_vector_void(vectorVoid_t *v) {
    return ((v)->capacity == 0);
}

bool is_empty_void(vectorVoid_t *v) {
    return ((v)->size == 0 && !is_zero_vector_void(v));
}

bool is_full_void(vectorVoid_t *v) {
    return (v)->size == (v)->capacity;
}

bool is_element_in_vector_void(const vectorVoid_t *v, const size_t checkElementIndex) {
    return (checkElementIndex >= 0 && checkElementIndex <= (v)->size - 1);
}

bool is_element_index_in_capacity(const vectorVoid_t *v, const size_t checkElementIndex) {
    return (checkElementIndex >= 0) && checkElementIndex <= (v)->capacity - 1;
}

void get_vector_value_void(vectorVoid_t *v, const size_t index, void *destination) {
    if (is_element_in_vector_void(v, index)) {
        char *source = (char *) (v)->data + index * (v)->baseTypeSize;
        memcpy(destination, source, (v)->baseTypeSize);
        return;
    }

    printf("\a");
    fprintf(stderr, "IndexError: a[%llu] is not exists", index);

    exit(604);
}

void set_vector_value_void(vectorVoid_t *v, const size_t index, void *source) {
    if (is_element_index_in_capacity(v, index)) {
        char *destination = (char *) (v)->data + index * (v)->baseTypeSize;
        memcpy(destination, source, (v)->baseTypeSize);
        return;
    }

    printf("\a");
    fprintf(stderr, "IndexError: a[%llu] is not exists", index);

    exit(604);
}


void push_back_void(vectorVoid_t *v, void *source) {
    if (is_full_void(v) && !is_zero_vector_void(v)) {
        size_t newCapacity = (v)->capacity * 2;
        reserve_void(v, newCapacity);
    } else if (is_zero_vector_void(v)) {
        reserve_void(v, 1);
    }

    char *lastElement = (char *) (v)->data + (v)->size * (v)->baseTypeSize;
    memcpy(lastElement, source, v->baseTypeSize);

    (v)->size++;
}

void pop_back_void(vectorVoid_t *v) {
    if (is_empty_void(v)) {
        printf("\a");
        fprintf(stderr, "vector is empty");

        exit(1);
    }

    (v)->size--;
}

