#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "unordered_array_set.h"

unordered_array_set unordered_array_set_create(size_t capacity)
{
    return (unordered_array_set)
            {
                    malloc(sizeof(int) * capacity),
                    0,
                    capacity
            };
}

static void unordered_array_set_shrinkToFit(unordered_array_set *a)
{
    if (a->size != a->capacity)
    {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

unordered_array_set unordered_array_set_create_from_array(const int *a,
                                                          size_t size)
{
    unordered_array_set set = unordered_array_set_create(size);
    for (register size_t i = 0; i < size; i++)
    {
        unordered_array_set_insert(&set, a[i]);
    }
    unordered_array_set_shrinkToFit(&set);
    return set;
}

size_t unordered_array_set_in(unordered_array_set *set, int value)
{
    size_t posOfNeedElement = linearSearch_(set->data, set->size, value);
    if (posOfNeedElement < set->size)
    {
        return posOfNeedElement;
    }
    else
    {
        return set->size;
    }
}

int unordered_array_set_is_element_in(unordered_array_set *set, int value)
{
    return (linearSearch_(set->data, set->size, value) < set->size);
}

int compare_ints1(const void *a, const void *b)
{
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2)
    {
        return -1;
    }
    if (arg1 > arg2)
    {
        return 1;
    }
    return 0;
}

bool unordered_array_set_isEqual(unordered_array_set set1,
                                 unordered_array_set set2)
{
    if (set1.size != set2.size)
    {
        return false;
    }
    qsort(set1.data, set1.size, sizeof(int), compare_ints1);
    qsort(set2.data, set2.size, sizeof(int), compare_ints1);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0; //компаратор, сравнивающий
                                                                            // побитово элементы массива
                                                                            // если все элементы равны - вернет 0
}

void unordered_array_set_isAbleAppend(unordered_array_set *set)
{
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value)
{
    if ((linearSearch_(set->data, set->size, value) >= set->size))
    {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value)
{
    size_t deleteElementPos = linearSearch_(set->data, set->size, value);
    assert(deleteElementPos < set->size);
    deleteByPosUnsaveOrder_(set->data, &set->size, deleteElementPos);
}

unordered_array_set unordered_array_set_union(unordered_array_set set1,
                                              unordered_array_set set2)
{
    size_t unionSetSize = set1.size + set2.size;
    int *unionSet = (int *) malloc(unionSetSize * sizeof(int));
    memcpy(unionSet, set1.data, set1.size * sizeof(int));
    size_t j = 0;
    for (register size_t i = 0; i < set2.size; i++)
    {
        if (linearSearch_(set1.data, set1.size, set2.data[i]) == set1.size)
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
    return (unordered_array_set) {unionSet, unionSetSize, set1.capacity};
}

size_t getMinUnordered(size_t a, size_t b)
{
    return a < b ? a : b;
}

void unordered_array_set_insert_intersection(unordered_array_set *set,
                                             unordered_array_set setToCheck, int value)
{
    if ((unordered_array_set_in(&setToCheck, value) != setToCheck.size &&
         !unordered_array_set_is_element_in(set, value)))
    {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

unordered_array_set unordered_array_set_intersection(unordered_array_set
                                                     set1, unordered_array_set set2)
{
    size_t intersectionSetSize = getMinUnordered(set1.size, set2.size);
    unordered_array_set intersectionSet =
            unordered_array_set_create(intersectionSetSize);
    for (register size_t i = 0; i < set2.size; i++)
    {
        unordered_array_set_insert_intersection(&intersectionSet, set1,
                                                set2.data[i]);
    }
    return intersectionSet;
}

void unordered_array_set_insert_difference(unordered_array_set *set,
                                           unordered_array_set setToCheck, int value)
{
    if ((!unordered_array_set_is_element_in(&setToCheck, value) &&
         !unordered_array_set_is_element_in(set, value)))
    {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1,
                                                   unordered_array_set set2)
{
    size_t differenceSetSize = set1.size;
    unordered_array_set SetOfDifference =
            unordered_array_set_create(differenceSetSize);
    for (register size_t i = 0; i < set1.size; i++)
    {
        unordered_array_set_insert_difference(&SetOfDifference, set2,
                                              set1.data[i]);
    }
    return SetOfDifference;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1,
                                        unordered_array_set set2)
{
    unordered_array_set part2 = unordered_array_set_difference(set1, set2);
    unordered_array_set part1 = unordered_array_set_difference(set2, set1);
    return unordered_array_set_union(part1, part2);
}

unordered_array_set unordered_array_set_complement(unordered_array_set set,
                                                   unordered_array_set universumSet)
{
    return unordered_array_set_difference(universumSet, set);
}

void unordered_array_set_print(unordered_array_set set)
{
    printf("{");
    for (register size_t i = 0; i < set.size; i++)
    {
        printf("%d, ", set.data[i]);
    }
    if (set.size == 0)
    {
        printf("}");
    }
    else
    {
        printf("\b\b}\n");
    }
}

void unordered_array_set_delete(unordered_array_set set)
{
    free(set.data);
}