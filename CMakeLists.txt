cmake_minimum_required(VERSION 3.20)
project(course_ C)

set(CMAKE_C_STANDARD 11)

add_executable(course_ main.c libs/data_structures/vector/vector_void/vector_void.c
        libs/data_structures/vector/vector_void/vector_void.c
        libs/data_structures/vector/test_vector_void/test_vector_void.c
        libs/data_structures/vector/test_vector_void/test_vector_void.h
        libs/data_structures/matrix/matrix_t/matrix.c
        libs/data_structures/matrix/matrix_t/matrix.h
        libs/data_structures/matrix/task_matrix/task/task.c
        libs/data_structures/string_t/str_lib/string.c
        libs/data_structures/string_t/str_lib/string.h
        libs/data_structures/string_t/test/test_string.c
        libs/data_structures/string_t/test/test_string.h
        libs/data_structures/string_t/test/test_task_string.c
        libs/data_structures/string_t/test/test_task_string.h libs/experiments_and_measurements/big_O/big_O.c libs/experiments_and_measurements/big_O/big_O.h libs/experiments_and_measurements/random_generation_functions/random_generation_functions.c libs/experiments_and_measurements/random_generation_functions/random_generation_functions.h)

add_subdirectory(libs)

target_link_libraries(course_ data_structures)
target_link_libraries(course_ algorithms)