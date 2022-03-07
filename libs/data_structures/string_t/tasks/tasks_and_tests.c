#include "task_manager.h"

void remove_non_letters(char *s) {
    char *endSource = get_end_of_string(s);
    char *destination = copy_if(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_task1_default_case() {
    char testString1[] = "H E L L O";
    char expectedResult[] = "HELLO";

    remove_non_letters(testString1);

    ASSERT_STRING(expectedResult, testString1);
}

void test_task1_escapes() {
    char testString1[] = "H\tE\tL\tL\tO";
    char expectedResult[] = "HELLO";

    remove_non_letters(testString1);

    ASSERT_STRING(expectedResult, testString1);
}

void test_task1_more_then_one_space() {
    char testString1[] = "HELLO_     WORL    D";
    char expectedResult[] = "HELLO_WORLD";

    remove_non_letters(testString1);

    ASSERT_STRING(expectedResult, testString1);
}

void task1() {
    test_task1_default_case();
    test_task1_escapes();
    test_task1_more_then_one_space();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void remove_adjacent_equal_letters(char *s) {
    if (*s == '\0') {
        return;
    }

    char *currentLetter = s;
    while (*s != '\0') {
        if (*currentLetter != *s){
            *(++currentLetter) = *s;
        }
        s++;
    }

    *(++currentLetter) = '\0';
}

void remove_extra_spaces(char *s) {
    if (*s == '\0') {
        return;
    }

    char *posToWrite = s;
    s++;
    while (*s !='\0') {
        if (isspace(*posToWrite) && isspace(*s)){
            *posToWrite = ' ';
        }
        else{
            *(++posToWrite) = *s;
        }
        s++;
    }
    *(++posToWrite) = '\0';
}


void test_task2_default_case() {
    char testString[] = "aaaallllloooo";
    char expectedString[] = "alo";

    remove_adjacent_equal_letters(testString);

    ASSERT_STRING(expectedString, testString);
}

void test_task2_default_case2() {
    char testString[] = "a     l     o";
    char expectedString[] = "a l o";

    remove_extra_spaces(testString);

    ASSERT_STRING(expectedString, testString);
}

void task2() {
    test_task2_default_case();
    test_task2_default_case2();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct{
    char *begin;
    char *end;
} word_descriptor_t;

int true() {
    return 1;
}

int get_word(char *beginSearch, word_descriptor_t *word) {
    (word)->begin = find_non_space(beginSearch);
    if (*(word)->begin == '\0') {
        return 0;
    }

    (word)->end = find_space((word)->begin);

    return 1;
}

//int get_word_reverse(char *rbegin, char *rend, word_descriptor_t *word) {
//    (word)->end = find_non_space_reverse(rbegin, rend);
//    if((word)->begin == rend) {
//        return 0;
//    }
//
//    (word)->begin = find_space_reverse((word)->end, rend) + 1;
//
//    return 1;
//}


//int get_word_reverse(char *rbegin, char *rend, word_descriptor_t *word) {
//    (word)->end = find_non_space_reverse(rbegin, rend) + 1;
//
//    (word)->begin = find_space_reverse((word)->end - 1, rend);
//
//    if ((word)->end == rend) {
//        return 0;
//    }
//
//    return 1;
//}

int get_word_reverse(char *rbegin, char *rend, word_descriptor_t *word) {
    (word)->end = find_non_space_reverse(rbegin, rend) - 1;
    if((word)->end == rend) {
        return 0;
    }

    (word)->begin = find_space_reverse((word)->end, rend) + 1;

    return 1;
}

void digit_to_start(word_descriptor_t word) {
    char *endStringBuffer = copy((word).begin, (word).end, _stringBuffer);
    char *recPosition = copy_if(_stringBuffer - 1,
                                        endStringBuffer,
                                        (word).begin, isdigit);

    copy_if(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void replace_words_and_digits(char *stringBegin) {
    word_descriptor_t word;
    char *beginSearch = stringBegin;
    while(get_word(beginSearch, &word)) {
        digit_to_start(word);
        beginSearch = (word).end;
    };
}

void test_task3_default_case() {
    char testString1[] = "allo123";
    char expectedString[] = "123allo";

    replace_words_and_digits(testString1);

    ASSERT_STRING(expectedString, testString1);
}

void test_task3_few_words() {
    char testString1[] = "allo123 hello wor321ld";
    char expectedString[] = "123allo hello 321world";

    replace_words_and_digits(testString1);

    ASSERT_STRING(expectedString, testString1);

}

void task3() {
    test_task3_default_case();
    test_task3_few_words();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char digits_to_spaces(char *stringBegin) {
    char *endSource = get_end_of_string(stringBegin);
    char *endStringBuffer = copy(stringBegin, endSource, _stringBuffer);
    *endStringBuffer = '\0';

    char *startStringBuffer = _stringBuffer;
    while (*startStringBuffer != *endStringBuffer) {
        if (isalpha(*startStringBuffer)) {
            *(stringBegin++) = *startStringBuffer;
        } else if (isdigit(*startStringBuffer)) {
            unsigned char digitValue = *startStringBuffer - '0';
            while (digitValue--) {
                *(stringBegin++) = ' ';
            }
        }
        startStringBuffer++;
    }
    *stringBegin = '\0';
}

void test_task4_default_case() {
    char testString1[] = "2allo2da2darova";
    char expectedString[] = "  allo  da  darova";

    digits_to_spaces(testString1);

    ASSERT_STRING(expectedString, testString1);
}

void test_task4_only_spaces() {
    char testString1[] = "5";
    char expectedString[] = "     ";

    digits_to_spaces(testString1);

    ASSERT_STRING(expectedString, testString1);
}

void task4() {
    test_task4_default_case();
    test_task4_only_spaces();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int areWordsEqual(word_descriptor_t w1,word_descriptor_t w2) {
//    while ((w1).begin != (w2).end && (w2).begin != (w2).end && *(w1).begin != *(w2).begin) {
//        (w1).begin++;
//        (w2).begin++;
//    }
//
//    return (*(w1).begin == ' ' || *(w1).begin == '\0') && (*(w2).begin == ' ' || *(w2).begin == '\0');
//}

int wordsAreEqual(word_descriptor_t w1, word_descriptor_t w2) {
    while (*(w2).begin == *(w1).begin && (w1).begin != w1.end && (w2).begin != w2.end) {
        (w1).begin++;
        (w2).begin++;
    }

    return ((*(w1).begin == ' ' || *(w1).begin == '\0') && (*(w2).begin == ' ' || *(w2).begin == '\0'));
}

void replace(char *source, char *wordToReplace, char *newWord) {
    size_t wordToReplaceSize = strlen(wordToReplace);
    size_t newWordSize = strlen(newWord);

    word_descriptor_t wordToReplace_t = {wordToReplace, wordToReplace + wordToReplaceSize};
    word_descriptor_t newWord_t = {newWord, newWord + newWordSize};

    char *readPtr;
    char *recPtr;
    if (wordToReplaceSize >= newWordSize) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, get_end_of_string(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    word_descriptor_t word;
    while (get_word(readPtr, &word) && *recPtr != '\0') {
        if (wordsAreEqual(word, wordToReplace_t)) {
            recPtr = copy(newWord_t.begin, newWord_t.end, recPtr);
        } else {
            recPtr = copy(word.begin, word.end, recPtr);
        }

        if (*recPtr != '\0') {
            *recPtr = ' ';
        }

        ++recPtr;
        readPtr = word.end;
    }

    *(--recPtr) = '\0';
}

void test_task5_default_case()
{
    char s1[] = "hello world";
    replace(s1, "world", "hello");

    ASSERT_STRING("hello hello", s1);
}

void test_task5_replace_all() {
    char testString1[] = "hello hello hello";
    replace(testString1, "hello", "darova");

    ASSERT_STRING("darova darova darova", testString1);
}

void task5() {
    test_task5_default_case();
    test_task5_replace_all();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int word_cmp(word_descriptor_t w1, word_descriptor_t w2) {
    while (*(w1).begin == *(w2).begin && *(w1).begin != '\0') {
        (w1).begin++;
        (w2).begin++;
    }
    if (*(w2).begin == '\0') {
        return -1;
    }

    return *(w1).begin - *(w2).begin;
}

int is_string_lexicographically_correct(char *stringToCheck) {
    char *begin = stringToCheck;

    word_descriptor_t currentWord;
    word_descriptor_t nextWord;

    if (!get_word(begin, &currentWord)) {
        return 1;
    }

    begin = (currentWord).end;
    while (get_word(begin, &nextWord)) {
        begin = (currentWord).end;

        if ((word_cmp(currentWord, nextWord) > 0)) {
            return 0;
        }

        (currentWord).begin = (nextWord).begin;
        (currentWord).end = (nextWord).end;
    }

    return 1;
}

void test_task6_default_case() {
    char testString[] = "abc abc";
    assert(is_string_lexicographically_correct(testString) == 1);
}

void test_task6_mono_symbols() {
    char testString[] = "a b c d e";
    assert(is_string_lexicographically_correct(testString) == 1);
}

void test_task6_one_word() {
    char read[] = "abc";
    assert(is_string_lexicographically_correct(read) == 1);
}



void task6() {
    test_task6_default_case();
    test_task6_mono_symbols();
    test_task6_one_word();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int getWordRevers(char *rbegin, char *rend, word_descriptor_t *word) {
    char* word_end = find_non_space_reverse(rbegin, rend);

    if (word_end == rend)
        return 0;

    char* word_begin = find_space_reverse(word_end, rend);

    word->begin = word_begin + 1;
    word->end = word_end + 1;

    return 1;
}

typedef struct {
    word_descriptor_t words[MAX_N_WORDS_IN_STRING];
    size_t size;
}bagOfWords_t;

int count_words(char *s) {
    word_descriptor_t word;
    int counter = 0;
    char *begin = s;
    while (get_word(begin, &word)) {
        begin = (word).end;
        ++counter;
    }

    return counter;
}

//void get_bag_of_words(bagOfWords_t *bag, char *s) {
//    int nWords = count_words(s);
//    word_descriptor_t word_array[nWords];
//    (bag)->size = count_words(s);
//    char *begin = get_end_of_string(s);
//
//    for (register size_t i = 0; i <= (bag)->size; ++i) {
//        word_descriptor_t word;
//        get_word_reverse(begin - 1, s, &word);
//        (bag)->words[i] = word;
//        begin = (word).begin;
//    }
//}

void get_bag_of_words(bagOfWords_t *bag, char *s) {
    bag->size = 0;
    word_descriptor_t w;

    while (get_word(s, &w)) {
        bag->words[bag->size++] = w;
        s = w.end;
    }
}

void test_task7_default_case() {
    char testString[] = "hello world";
    bagOfWords_t sobaka;
    get_bag_of_words(&sobaka, testString);
}
void task7() {
//    test_task7_default_case();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int is_palindromic_word(word_descriptor_t w)
{
    char *leftPos = w.begin;
    char *rightPos = w.end - 1;
    for (; leftPos - rightPos > 0; ++leftPos, ++rightPos) {
        if (*leftPos != *rightPos) {
            return 0;
        }
    }

    return 1;
}

void test_task8() {
    char testString[] = "abdba";
    word_descriptor_t testWord;
    get_word(testString, &testWord);
    assert(is_palindromic_word(testWord) == 1);
}

void task8() {
    test_task8();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void split_strings(char *s1, char *s2, char *stringToSplit) {
    word_descriptor_t word1, word2;
    int isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2, *beginSearch3 = stringToSplit;


    while ((isW1Found = get_word(beginSearch1, &word1),
            isW2Found = get_word(beginSearch2, &word2),
            isW1Found || isW2Found)) {

        if (isW1Found) {
            beginSearch3 = copy(word1.begin, word1.end, beginSearch3);
            *(beginSearch3) = ' ';
            beginSearch3++;
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            beginSearch3 = copy(word2.begin, word2.end, beginSearch3);
            *(beginSearch3) = ' ';
            beginSearch3++;
            beginSearch2 = word2.end;
        }
    }
    *(beginSearch3 - 1) = '\0';
}

void test_task9_default_case() {
    char testString1[] = "hello I'm";
    char testString2[] = "world here";
    char testString3[21];

    split_strings(testString1, testString2, testString3);

    char expectedString1[] = "hello world I'm here";
    ASSERT_STRING(expectedString1, testString3);
}

void test_task9_is_first_word_less () {
    char testString1[] = "hello";
    char testString2[] = "world here";
    char testString3[17];

    split_strings(testString1, testString2, testString3);

    char expectedString1[] = "hello world here";
    ASSERT_STRING(expectedString1, testString3);
}
void test_task9_is_second_word_less () {
    char testString1[] = "hello here";
    char testString2[] = "I'm";
    char testString3[17];

    split_strings(testString1, testString2, testString3);

    char expectedString1[] = "hello I'm here";
    ASSERT_STRING(expectedString1, testString3);
}

void task9() {
    test_task9_default_case();
    test_task9_is_first_word_less();
    test_task9_is_second_word_less();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int is_non_space(char s) {
    return !isspace(s);
}

void reverse_string_order(char *stringToReverse) {
    char *endStringBuffer = copy(stringToReverse, get_end_of_string(stringToReverse), _stringBuffer);

    word_descriptor_t word;

    char *beginCopy = stringToReverse;
    while (get_word_reverse(endStringBuffer, _stringBuffer, &word)) {

        beginCopy = copy_if((word).begin - 1, (word).end + (*(word).end != '\0'), beginCopy, is_non_space);

        *beginCopy = ' ';
        beginCopy++;
        endStringBuffer = (word).begin - 1;
    }

    *(beginCopy - 1) = '\0';
}

void test_get_word_reverse() {
    char s[] = "da be ru";
    word_descriptor_t word;
    int i = 0;
    char *begin = get_end_of_string(s);
    while (i < 3) {
        get_word_reverse(begin, s, &word);
        i++;
        begin = (word).begin - 1;
    }

}

void test_task10_default_case() {
    char testString[] = "world hello allo darova";
    char expectedString[] = "darova allo hello world";

    reverse_string_order(testString);

    ASSERT_STRING(expectedString, testString);
}

void task10() {
    test_get_word_reverse();
    test_task10_default_case();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_word(char *begin, const char *end) {
    for ( ; begin < end ; ++begin) {
        printf("%c", *begin);
    }
}

void print_word_before_word_with_a(char *s) {
    if (find (s, get_end_of_string(s), 'a') == get_end_of_string(s)) {
        printf("string not contains A\n");
    }

    word_descriptor_t currentWord;
    get_word(s, &currentWord);
    if (find(currentWord.begin, currentWord.end, 'a') != currentWord.end) {
        printf("first word contains A\n");
        return;
    }

    word_descriptor_t nextWord;

    while(get_word(currentWord.end, &nextWord)) {
        if (find(nextWord.begin, nextWord.end, 'a') != nextWord.end) {
            print_word(currentWord.begin, currentWord.end);
            printf("\n");
            return;
        }
        else {
            currentWord.begin = nextWord.begin;
            currentWord.end = nextWord.end;
        }
    }
}

void test_task11_default_case() {
    char s1[] = "allo hello privet";

    print_word_before_word_with_a(s1);
}

void test_task11_default_case2() {
    char s1[] = "hello allo privet";

    print_word_before_word_with_a(s1);
}

void test_task11_default_case3() {
    char s1[] = "hello privet";

    print_word_before_word_with_a(s1);
}

void task11() {
//    test_task11_default_case();
//    test_task11_default_case2();
//    test_task11_default_case3();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void word_descriptor_to_string(word_descriptor_t word, char *destination) {
    char *end = copy((word).begin, (word).end, destination);
    *end = '\0';
}

word_descriptor_t last_of_first_in_second(char *s1, char *s2) {
    bagOfWords_t bag1;
    get_bag_of_words(&bag1, s1);

    bagOfWords_t bag2;
    get_bag_of_words(&bag2, s2);

    word_descriptor_t w;
    for (int j = 0; j < bag1.size; j++) {
        for (int i = 0; i < bag2.size; i++) {
            if (strcmp(bag1.words[j].begin, bag2.words[i].begin) == 0) {
                w.begin = bag1.words[j].begin, w.end = bag1.words[j].end;
            }
        }
    }
    return w;
}

void test_task12_last_of_first_in_second_default_case() {
    char testString1[] = "hello world";
    char testString2[] = "hello world";

    word_descriptor_t res = last_of_first_in_second(testString1, testString2);
    char result[5];
    word_descriptor_to_string(res, result);

    char expected_string[] = "world";
    ASSERT_STRING(expected_string, result);
}

void test_task12_last_of_first_in_second_not_same_strings() {
    char testString1[] = "hello world";
    char testString2[] = "hola world";

    word_descriptor_t res = last_of_first_in_second(testString1, testString2);
    char result[5];
    word_descriptor_to_string(res, result);

    char expected_string[] = "world";
    ASSERT_STRING(expected_string, result);
}

void task12() {
    test_task12_last_of_first_in_second_default_case();
    test_task12_last_of_first_in_second_not_same_strings();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int are_words_unique(char *s1) {
    bagOfWords_t bag;
    get_bag_of_words(&bag, s1);

    word_descriptor_t *currentWord = (bag).words;
    word_descriptor_t *endWord = (bag).words + (bag).size - 1;

    while (currentWord < endWord) {
        word_descriptor_t *w = currentWord + 1;
        while (w <= endWord) {
            if (wordsAreEqual(*currentWord, *w)) {
                return 1;
            }
            w++;
        }
        currentWord++;
    }

    return 0;
}

void test_task13_default_case() {
    char testString1[] = "hello world hello";

    assert(are_words_unique(testString1) == 1);
}

void test_task13_non_contains_unique_word() {
    char testString1[] = "hola amigos";

    assert(are_words_unique(testString1) == 0);
}

void test_task13_empty_string() {
    char testString1[] = "    ";

    assert(are_words_unique(testString1) == 0);
}

void task13() {
    test_task13_default_case();
    test_task13_non_contains_unique_word();
    test_task13_empty_string();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


