#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ordered_array_set.h"

ordered_array_set ordered_array_set_create(size_t capacity)
{
    return (ordered_array_set)
            {
                    malloc(sizeof(int) * capacity),
                    0,
                    capacity
            };
}

static void ordered_array_set_shrinkToFit(ordered_array_set *a)
{
    if (a->size != a->capacity)
    {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);

        a->capacity = a->size;
    }
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size)
{
    ordered_array_set set = ordered_array_set_create(size);

    for (register size_t i = 0; i < size; i++)
    {
        ordered_array_set_insert(&set, a[i]);
    }

    ordered_array_set_shrinkToFit(&set);

    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value)
{
    size_t posOfNeedElement = binarySearch_(set->data, set->size, value);

    if (posOfNeedElement < set->size)
        return posOfNeedElement;
    else
        return set->size;
}

int ordered_array_set_is_element_in(ordered_array_set *set, int value)
{
    return (binarySearch_(set->data, set->size, value) < set->size);
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2)
{
    if (set1.size != set2.size)
        return false;

    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0; // компаратор, сравнивающий
    // побитово элементы массива
    // если все элементы равны - вернет 0
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set)
{
    return ordered_array_set_isEqual(ordered_array_set_intersection(subset, set), subset);
}

void ordered_array_set_isAbleAppend(ordered_array_set *set)
{
    assert(set->size < set->capacity);
}

int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}

void ordered_array_set_insert(ordered_array_set *set, int value)
{
    if ((binarySearch_(set->data, set->size, value) >= set->size))
    {
        ordered_array_set_isAbleAppend(set);

        append_(set->data, &set->size, value);
        qsort(set->data, set->size, sizeof(int), compare_ints);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value)
{
    size_t deleteElementPos = binarySearch_(set->data, set->size, value);

    assert(deleteElementPos < set->size);

    deleteByPosSaveOrder_(set->data, &set->size, deleteElementPos);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2)
{
    size_t unionSetSize = set1.size + set2.size;

    int *unionSet = (int *) malloc(unionSetSize * sizeof(int));

    memcpy(unionSet, set1.data, set1.size * sizeof(int));

    size_t j = 0;
    for (register size_t i = 0; i < set2.size; i++)
    {
        if (binarySearch_(set1.data, set1.size, set2.data[i]) == set1.size)
        {
            unionSet[j + set1.size] = set2.data[i];
            j++;
        }
        else
        {
            unionSetSize -= 1;
        }
    }

    unionSet = realloc(unionSet, unionSetSize * sizeof(int));

    qsort(unionSet, unionSetSize, sizeof(int), compare_ints);

    return (ordered_array_set) {unionSet, unionSetSize, set1.capacity};
}

size_t getMinOrdered(size_t a, size_t b)
{
    return a < b ? a : b;
}

void ordered_array_set_insert_intersection(ordered_array_set *set, ordered_array_set setToCheck, int value)
{
    if ((ordered_array_set_in(&setToCheck, value) != setToCheck.size &&
         !ordered_array_set_is_element_in(set, value)))
    {
        ordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2)
{
    size_t intersectionSetSize = getMinOrdered(set1.size, set2.size);
    ordered_array_set intersectionSet = ordered_array_set_create(intersectionSetSize);

    for (register size_t i = 0; i < set2.size; i++)
    {
        ordered_array_set_insert_intersection(&intersectionSet, set1, set2.data[i]);
    }

    return intersectionSet;
}

void ordered_array_set_insert_difference(ordered_array_set *set, ordered_array_set setToCheck, int value)
{
    if ((!ordered_array_set_is_element_in(&setToCheck, value) && !ordered_array_set_is_element_in(set, value)))
    {
        ordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2)
{
    size_t differenceSetSize = set1.size;

    ordered_array_set SetOfDifference = ordered_array_set_create(differenceSetSize);

    for (register size_t i = 0; i < set1.size; i++)
    {
        ordered_array_set_insert_difference(&SetOfDifference, set2, set1.data[i]);
    }

    return SetOfDifference;
}

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2)
{
    ordered_array_set part1 = ordered_array_set_difference(set1, set2);
    ordered_array_set part2 = ordered_array_set_difference(set2, set1);

    return ordered_array_set_union(part1, part2);
}

// возвращает дополнение до универсума universumSet множества set
ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet)
{
    return ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(ordered_array_set set)
{
    printf("{");

    for (register size_t i = 0; i < set.size; i++)
    {
        printf("%d, ", set.data[i]);
    }

    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}\n");
}

void ordered_array_set_delete(ordered_array_set set)
{
    free(set.data);
}


