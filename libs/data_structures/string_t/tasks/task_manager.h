#ifndef INC__TASK_MANAGER_H
#define INC__TASK_MANAGER_H

#include <ctype.h>
#include <memory.h>
#include <assert.h>
#include <stdio.h>

#include "../str_lib/string.h"

#define ASSERT_STRING(expected, got) assert_string(expected, got, \
                                __FILE__, __FUNCTION__, __LINE__)

static void assert_string(const char* expected, const char* got,
                          const char* file, const char* func,
                          const int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, "Exception file: %s\n", file);
        fprintf(stderr, "Function: %s - line: %d\n", func, line);
        fprintf(stderr, "Got:      \"%s\"\n", got);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
    } else
        fprintf(stderr, "%s - OK!\n", func);
}

typedef struct{
    char *begin;
    char *end;
} word_descriptor_t;

typedef struct {
    word_descriptor_t words[MAX_N_WORDS_IN_STRING];
    size_t size;
}bagOfWords_t;


void task1();

void remove_non_letters(char *s);

void task2();

void remove_adjacent_equal_letters(char *s);

void remove_extra_spaces(char *s);

void task3();

int get_word(char *beginSearch, word_descriptor_t *word);

int get_word_reverse(char *rbegin, char *rend, word_descriptor_t *word);

void digit_to_start(word_descriptor_t word);

void replace_words_and_digits(char *stringBegin);

void task4();

char digits_to_spaces(char *stringBegin);

void task5();

int are_words_equal(word_descriptor_t w1, word_descriptor_t w2);

void replace(char *source, char *wordToReplace, char *newWord);

void task6();

int word_cmp(word_descriptor_t w1, word_descriptor_t w2);

int is_string_lexicographically_correct(char *stringToCheck);

void task7();

int getWordRevers(char *rbegin, char *rend, word_descriptor_t *word);

void get_bag_of_words(bagOfWords_t *bag, char *s);

void task8();

int is_palindromic_word(word_descriptor_t w);

void task9();

char *copy_if_found(char *begin, char *end, char *beginSearch);

void split_strings(char *s1, char *s2, char *stringToSplit);

void task10();

int is_non_space(char s);

void reverse_string_order(char*stringToReverse);

void task11();

void print_word_before_word_with_a(char *s);

void task12();

void word_descriptor_to_string(word_descriptor_t word, char *destination);

word_descriptor_t last_of_first_in_second(char *s1, char *s2);

void task13();

int is_string_contains_same_words(char *s1);

void task14();

int compare_char(const void *a, const void *b);

void letters_sort(word_descriptor_t* word);

int is_word_contains_same_letters_words_pair(char *s);

void task15();

void get_string_without_last_word_like(char *defString);

void task16();

word_descriptor_t last_of_first_in_second_search(char *s1, char *s2);

void task17();

int is_non_palindromic(word_descriptor_t word);

void delete_palindromic_words(char *s);

void task18();

void add_words_to_less_string_(bagOfWords_t *greaterString, bagOfWords_t *lessString);

void add_words_to_less_string(char *s1, char *s2);

void task19();

int is_string_contains_every_symbol(char *s1, word_descriptor_t *word);

#endif
