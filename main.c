#include "libs/data_structures/vector/test_vector/vector_test.h"
#include "libs/data_structures/vector/test_vector_void/test_vector_void.h"
#include "libs/data_structures/matrix/test_matrix/test_matrix.h"
#include "libs/data_structures/matrix/task_matrix/task/task.h"
#include "libs/data_structures/matrix/task_matrix/test_task/test_task.h"
#include "libs/data_structures/string_t/test/test_string.h"
#include "libs/data_structures/string_t/tasks/task_manager.h"
#include "libs/data_structures/string_t/test/test_task_string.h"
#include "libs/experiments_and_measurements/big_O/big_O.h"
#include "libs/experiments_and_measurements/sort_functions/sort_functions.h"


int main() {
    int a[] = {5, -3, 0, 10, 1, 5};
    tree_sort(a, 6);
    outputArray_(a, 6);
}
