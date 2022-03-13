#include "libs/experiments_and_measurements/big_O/big_O.h"
#include "libs/experiments_and_measurements/sort_functions/sort_functions.h"


int main() {
    int a[] = {5, -3, 0, 10, 1, 5};
    tree_sort(a, 6);
    outputArray_(a, 6);
}
