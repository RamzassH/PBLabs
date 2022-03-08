#ifndef INC__STRING_H
#define INC__STRING_H

#include <stdlib.h>
#include <limits.h>

# define MAX_STRING_SIZE 100
# define MAX_N_WORDS_IN_STRING 100


char _stringBuffer[MAX_STRING_SIZE + 1];

size_t strlen(const char *s);

char *get_end_of_string(char *s);

char *find(char *beginOfString, const char *endOfSting, int charToFind);

char *find_space(char *beginOfString);

char *find_non_space(char *begin);

char *find_non_space_reverse(char *rbegin, const char *rend);

char *find_space_reverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copy_reverse(const char *beginSource, const char *endSource, char *beginDestination);

char *copy_if(const char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copy_if_reverse(const char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

void print_word(char *begin, const char *end);

#endif
